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
        }
    }
}
