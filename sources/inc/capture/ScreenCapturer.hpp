#pragma once

namespace cdl
{
    struct Rect;

    namespace graphics
    {
        struct Image;
    }

    namespace capture
    {
        class ScreenCapturer
        {
        public:
            graphics::Image capture();
            graphics::Image capture(const Rect& rect);
        };
    }
}
