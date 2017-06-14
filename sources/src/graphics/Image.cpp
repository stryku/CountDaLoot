#include "graphics/Image.hpp"

#include <Windows.h>

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
    }
}
