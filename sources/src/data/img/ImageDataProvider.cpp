#include "data/img/ImageDataProvider.hpp"

#include "consts/consts.hpp"
#include "graphics/Image.hpp"

namespace cdl
{

    namespace data
    {
        namespace img
        {
            graphics::Image ImageDataProvider::getLootTabActive() const
            {
                return graphics::Image::load(consts::img::kLootActivePath);
            }

            graphics::Image ImageDataProvider::getLootTabInactive() const
            {
                return graphics::Image::load(consts::img::kLootInactivePath);
            }

            graphics::Image ImageDataProvider::getLootTabInactiveRed() const
            {
                return graphics::Image::load(consts::img::kLootInactiveRedPath);
            }
            graphics::Image ImageDataProvider::getInputFieldPattern() const
            {
                return graphics::Image::load(consts::img::kInputFieldPatternPath);
            }

            graphics::Image ImageDataProvider::getUpArrowPattern() const
            {
                return graphics::Image::load(consts::img::kUpArrowPatternPathPath);
            }
        }
    }
}
