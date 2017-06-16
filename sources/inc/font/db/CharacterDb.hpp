#pragma once

#include "font/db/Character.hpp"

#include <vector>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace cdl
{
    namespace font
    {
        namespace db
        {
            class CharactersDb
            {
            public:
                CharactersDb(const std::vector<Character>& chars)
                {
                    for (const auto c : chars)
                        mapByCharacter[c.character] = c;
                }

                bool exist(char character) const
                {
                    return mapByCharacter.find(character) != mapByCharacter.cend();
                }

                const Character& getByCharacter(char character) const
                {
                    return mapByCharacter.at(character);
                }

                static CharactersDb load(const std::string& path)
                {
                    std::vector<Character> chars;
                    boost::property_tree::ptree tree;
                    boost::property_tree::xml_parser::read_xml(std::ifstream(path), tree);

                    for (const auto &child : tree.get_child("db.characters"))
                    {
                        const auto character = Character::fromPtree(child.second);
                        chars.push_back(character);
                    }

                    return CharactersDb(chars);
                }
            private:
                std::map<char, Character> mapByCharacter;
            };
        }
    }
}
