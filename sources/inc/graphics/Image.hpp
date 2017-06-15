#pragma once

#include "structs/Rgba.hpp"
#include "structs/Pos.hpp"

#include <boost/assert.hpp>
#include <boost/optional.hpp>

#include <vector>
#include <array>

namespace cdl
{
    struct Rect;
    struct Size;

    namespace graphics
    {
        struct Image
        {
            enum class Corner
            {
                BottomRight,
                BottomLeft,
                TopRight,
                TopLeft
            };

            size_t w{ 0 }, h{ 0 };
            std::vector<Rgba> pixels;

            template <typename Off>
            Rgba& pixel(const Off& offset) { return pixel(Offset::from(offset)); }

            template <typename Off>
            const Rgba& cpixel(const Off& offset) const { return cpixel(Offset::from(offset)); }

            Rgba& pixel(const Offset& offset);
            const Rgba& cpixel(const Offset& offset) const;
            Rgba& pixel(size_t x, size_t y);
            const Rgba& cpixel(size_t x, size_t y) const;

            bool operator==(const Image& other) const;
            template <size_t N>
            bool operator==(const std::array<Rgba, N> &pixelsArray) const;

            void resize();

            void* pixelsPtr();
            const void* cpixelsPtr() const;

            void toCb() const;

            Image getSprite(const Rect &rect) const;
            Image getSprite(size_t reqx, size_t reqy, size_t reqw, size_t reqh) const;

            static Image load(const std::string& path);

            boost::optional<Pos> find(const graphics::Image& img,
                                      Corner startCorner = Corner::TopLeft) const;

        private:
            std::pair<int, int> getFindDeltas(Corner startCorner) const;
            Offset getFindStartPos(Corner startCorner, const Size& findImgSize) const;
            bool isImageThere(const Pos& pos, const Image& img) const;
            bool isInside(const Pos& pos) const;
        };
    }
}
