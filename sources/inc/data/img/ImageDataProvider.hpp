#pragma once

namespace cdl
{
    namespace graphics
    {
        struct Image;
    }

    namespace data
    {
        namespace img
        {
            class ImageDataProvider
            {
            public:
                graphics::Image getLootTabActive() const;
                graphics::Image getLootTabInactive() const;
                graphics::Image getLootTabInactiveRed() const;
                graphics::Image getInputFieldPattern() const;
                graphics::Image getUpArrowPattern() const;
            };
        }
    }
}
