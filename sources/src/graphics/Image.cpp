#include "graphics/Image.hpp"

#include "structs/Rect.hpp"
#include "structs/Size.hpp"
#include "structs/Pos.hpp"

#include <Windows.h>

#include <fstream>

namespace cdl
{
    namespace graphics
    {
        Rgba& Image::pixel(size_t x, size_t y)
        {
            return pixels[x + (h - 1 - y)*w];
        }

        const Rgba& Image::cpixel(size_t x, size_t y) const
        {
            return pixels[x + (h - 1 - y)*w];
        }

        Rgba& Image::pixel(const Offset& offset) { return pixel(offset.x, offset.y); }
        const Rgba& Image::cpixel(const Offset& offset) const { return cpixel(offset.x, offset.y); }

        bool Image::operator==(const Image& other) const
        {
            return w == other.w && h == other.h && pixels == other.pixels;
        }

        template <size_t N>
        bool Image::operator==(const std::array<Rgba, N> &pixelsArray) const
        {
            return N == pixels.size() &&
                std::memcmp(pixels.data(), pixelsArray.data(), N * sizeof(Rgba)) == 0;
        }

        void Image::resize()
        {
            pixels.resize(w*h);
        }

        void* Image::pixelsPtr()
        {
            return &pixels[0];
        }

        const void* Image::cpixelsPtr() const
        {
            return pixels.data();
        }

        void Image::toCb() const
        {
#ifdef USE_CLIPBOARD
            BITMAPINFOHEADER bmih;
            bmih.biSize = sizeof(BITMAPINFOHEADER);
            bmih.biWidth = w;
            bmih.biHeight = h;
            bmih.biPlanes = 1;
            bmih.biBitCount = 32;
            bmih.biCompression = BI_RGB;
            bmih.biSizeImage = 0;
            bmih.biXPelsPerMeter = 10;
            bmih.biYPelsPerMeter = 10;
            bmih.biClrUsed = 0;
            bmih.biClrImportant = 0;

            BITMAPINFO dbmi;
            ZeroMemory(&dbmi, sizeof(dbmi));
            dbmi.bmiHeader = bmih;
            dbmi.bmiColors->rgbBlue = 0;
            dbmi.bmiColors->rgbGreen = 0;
            dbmi.bmiColors->rgbRed = 0;
            dbmi.bmiColors->rgbReserved = 0;

            HDC hdc = ::GetDC(NULL);

            HBITMAP hbmp = CreateDIBitmap(hdc, &bmih, CBM_INIT, pixels.data(), &dbmi, DIB_RGB_COLORS);
            if (hbmp == NULL) {
                ::MessageBox(NULL, "Could not load the desired image image", "Error", MB_OK);
                return;
            }

            ::ReleaseDC(NULL, hdc);

            // a little test if everything is OK
            OpenClipboard(NULL);
            EmptyClipboard();
            SetClipboardData(CF_BITMAP, hbmp);
            CloseClipboard();

            // cleanup
            DeleteObject(hbmp);
#endif
        }

        Image Image::getSprite(const Rect &rect) const
        {
            return getSprite(rect.x, rect.y, rect.w, rect.h);
        }

        Image Image::getSprite(size_t reqx, size_t reqy, size_t reqw, size_t reqh) const
        {
            Image img;

            img.w = reqw;
            img.h = reqh;

            img.pixels.reserve(reqw*reqh);

            Pos base = { static_cast<int>(reqx),
                static_cast<int>(reqy + reqh - 1) };

            auto it = img.pixels.begin();
            for (size_t y = 0; y < reqh; ++y)
                for (size_t x = 0; x < reqw; ++x)
                    img.pixels.emplace_back(cpixel(base.x + x, base.y - y));

            return img;
        }

        Image Image::load(const std::string& path)
        {
            Image ret;

            int i;
            std::ifstream file{ path,  std::ifstream::binary };

            char info[54];
            file.read(info, 54);

            int width = *(int*)&info[18];
            int height = *(int*)&info[22];

            ret.w = width;
            ret.h = height;
            ret.resize();

            int row_padded = (width * 3 + 3) & (~3);
            char* data = new char[row_padded];
            
            size_t pixelIndex{ 0 };

            for (int i = 0; i < height; i++)
            {
                file.read(data, row_padded);
                int read = file.gcount();
                for (int j = 0; j < width * 3; j += 3)
                {

                    const Rgba pixel{ data[j], data[j + 1], data[j + 2], 255 };
                    ret.pixel(j/3,height - 1 - i) = pixel;
                }
            }

            ret.toCb();

            return ret;
        }

        boost::optional<Pos> Image::find(const graphics::Image& img, 
                                          Corner startCorner) const
        {
            const auto deltas = getFindDeltas(startCorner);
            const auto xDelta = deltas.first;
            const auto yDelta= deltas.second;

            auto pos = Pos::from(getFindStartPos(startCorner, { img.w, img.h }));
            
            for (; isInside(pos) && pos.y + img.h <= h; ++pos.y)
                for (pos.x = 0; isInside(pos) && pos.x + img.w <= w; ++pos.x)
                    if (isImageThere(pos, img))
                        return pos;

            return{};
        }

        std::pair<int, int> Image::getFindDeltas(Corner startCorner) const
        {
            switch (startCorner)
            {
                case Corner::BottomRight: return{ -1, -1 };
                case Corner::BottomLeft: return{ 1, -1 };
                case Corner::TopRight: return{ -1, 1 };
                case Corner::TopLeft: return{ 1, 1 };

                default:
                    throw std::runtime_error("Unknow start corner passed: " + std::to_string(static_cast<int>(startCorner)));
            }
        }

        Offset Image::getFindStartPos(Corner startCorner, const Size& findImgSize) const
        {
            switch (startCorner)
            {
                case Corner::BottomRight: return{ w - findImgSize.w, h - findImgSize.h };
                case Corner::BottomLeft: return{ 0, h - findImgSize.h };
                case Corner::TopRight: return{ w - findImgSize.w, 0 };
                case Corner::TopLeft: return{ 0, 0 };

                default:
                    throw std::runtime_error("Unknow start corner passed: " + std::to_string(static_cast<int>(startCorner)));
            }
        }

        bool Image::isImageThere(const Pos& pos, const Image& img) const
        {
            const auto currentPos = pos;
            for (size_t y = 0; y < img.h; ++y)
            {
                for (size_t x = 0; x < img.w; ++x)
                {
                    const auto imgPos = Offset{ x, y };
                    const auto pxCurr = cpixel(currentPos + imgPos);
                    const auto imgPixel = img.cpixel(imgPos);

                    if (cpixel(currentPos + imgPos) != img.cpixel(imgPos))
                        return false;
                }
            }

            return true;
        }

        bool Image::isInside(const Pos& pos) const
        {
            return 0 <= pos.x && pos.x < w &&
                   0 <= pos.y && pos.y < h;
        }

        boost::optional<Offset> Image::findOneOf(const std::vector<Image>& images) const
        {
            Pos pos{ 0, 0 };

            for (; isInside(pos); ++pos.y)
            {
                for (; isInside(pos); ++pos.x)
                {
                    for (const auto& img : images)
                    {
                        if (isInside(pos + Pos{ static_cast<int>(img.w), 
                                                static_cast<int>(img.h) }) &&
                            isImageThere(pos, img))
                        {
                            return Offset::from(pos);
                        }
                    }
                }
                pos.x = 0;
            }

            return{};
        }
    }
}
