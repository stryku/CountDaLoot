#pragma once

#include "structs/Pos.hpp"

#include <Windows.h>

namespace cdl
{

    struct Rect
    {
        int x, y;
        size_t w, h;

        void setPos(Pos pos)
        {
            x = pos.x;
            y = pos.y;
        }

        bool operator==(const Rect &rhs) const
        {
            return x == rhs.x && y == rhs.y && w == rhs.w && h == rhs.h;
        }

        bool operator!=(const Rect &rhs) const
        {
            return !(*this == rhs);
        }

        static Rect fromWindowsRect(const RECT &rc)
        {
            Rect rect;

            rect.x = rc.left;
            rect.y = rc.top;
            rect.w = rc.right - rc.left;
            rect.h = rc.bottom - rc.top;

            return rect;
        }

        Pos topLeft() const
        {
            return Pos{ x, y };
        }

        Pos topRight() const
        {
            return Pos{ x + static_cast<int>(w), y };
        }

        Pos bottomLeft() const
        {
            return Pos{ x, y + static_cast<int>(h) };
        }

        Pos bottomRight() const
        {
            return Pos{ x + static_cast<int>(w), y + static_cast<int>(h) };
        }

        Pos pos() const
        {
            return topLeft();
        }

        Rect operator+(const Offset &pos) const
        {
            return *this + Pos::from(pos);
        }

        Rect operator+(const Pos &pos) const
        {
            Rect ret = *this;

            ret.x += pos.x;
            ret.y += pos.y;

            return ret;
        }
    };
}
