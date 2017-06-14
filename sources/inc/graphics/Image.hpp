#pragma once

#include "structs/Rgba.hpp"

#include <vector>
#include <array>

namespace cdl
{
    namespace graphics
    {
        struct Image
        {
            size_t w{ 0 }, h{ 0 };
            std::vector<Rgba> pixels;

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
        };
    }
}
