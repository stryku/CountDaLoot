#pragma once

namespace cdl
{
    namespace details
    {
        template <typename T>
        struct PosImpl
        {
            T x, y;
            bool operator==(const PosImpl &rhs) const
            {
                return x == rhs.x && y == rhs.y;
            }

            bool operator!=(const PosImpl &rhs) const
            {
                return !(*this == rhs);
            }

            PosImpl operator+(const PosImpl &rhs)
            {
                return PosImpl{ x + rhs.x, y + rhs.y };
            }

            PosImpl operator+(const PosImpl &rhs) const
            {
                return PosImpl{ x + rhs.x, y + rhs.y };
            }

            PosImpl& operator+=(const PosImpl &rhs)
            {
                x += rhs.x;
                y += rhs.y;
                return *this;
            }

            template <typename RhsPointType>
            static PosImpl from(const PosImpl<RhsPointType> &rhs)
            {
                return PosImpl{ static_cast<T>(rhs.x), static_cast<T>(rhs.y) };
            }
        };
    }

    using Pos = details::PosImpl<int>;
    using Offset = details::PosImpl<size_t>;
}
