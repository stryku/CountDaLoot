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
                    : mapByCharacter{ fromVector(chars) }
                    , charsVector{ chars }
                {}

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

                    std::sort(std::begin(chars), std::end(chars));

                    return CharactersDb(chars);
                }
                
                const std::vector<Character>& chars() const
                {
                    return charsVector;
                }

            private:
                static std::map<char, Character> fromVector(const std::vector<Character>& charsVector)
                {
                    std::map<char, Character> map;

                    for (const auto c : charsVector)
                        map[c.character] = c;

                    return map;
                }

                const std::map<char, Character> mapByCharacter;
                const std::vector<Character> charsVector;
            };
        }
    }
}
