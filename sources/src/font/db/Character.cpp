#include "font/db/Character.hpp"

namespace cdl
{
    namespace font
    {
        namespace db
        {
            std::vector<bool> Character::simpleStringToLayout(const std::string& str)
            {
                std::vector<bool> layout;
                std::istringstream iss(str);

                for (const auto& c : str)
                    layout.push_back(c == '1');

                return layout;
            }

            Character Character::fromPtree(const boost::property_tree::ptree &tree)
            {
                Character ret;
                const auto stringLayout = tree.get_child("layout").get_value<std::string>();

                ret.layout = simpleStringToLayout(stringLayout);
                ret.character = tree.get_child("character").get_value<char>();
                ret.width = tree.get_child("width").get_value<size_t>();
                ret.height = tree.get_child("height").get_value<size_t>();

                return ret;
            }
        }
    }
}
