#pragma once

#include <boost/property_tree/ptree.hpp>

#include <vector>

namespace cdl
{
    namespace font
    {
        namespace db
        {
            struct Character
            {
                size_t width;
                size_t height;
                std::vector<bool> layout;
                char character;

                static std::vector<bool> simpleStringToLayout(const std::string& str);
                static Character fromPtree(const boost::property_tree::ptree &tree);
            };
        }
    }
}
