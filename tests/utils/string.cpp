#include "utils/string.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

TEST(utils_string, removeSurroundingWhitespaces_empty_emptyResult)
{
    const auto expected{ "" };
    const auto result = cdl::utils::removeSurroundingWhitespaces("");

    ASSERT_EQ(expected, result);
}

TEST(utils_string, removeSurroundingWhitespaces_allWhitespaces_emptyResult)
{
    const auto expected{ "" };
    const auto result = cdl::utils::removeSurroundingWhitespaces("   \t\t  \t\t  \n\n\n   ");

    ASSERT_EQ(expected, result);
}

TEST(utils_string, removeSurroundingWhitespaces_noWhitespaces_sameResult)
{
    const auto expected{ "Lorem" };
    const auto result = cdl::utils::removeSurroundingWhitespaces(expected);

    ASSERT_EQ(expected, result);
}

TEST(utils_string, removeSurroundingWhitespaces_whitespacesInside_sameResult)
{
    const auto expected{ "Lo r\t\ne m" };
    const auto result = cdl::utils::removeSurroundingWhitespaces(expected);

    ASSERT_EQ(expected, result);
}

TEST(utils_string, removeSurroundingWhitespaces_surrounding_removedSurrounding)
{
    const auto expected{ "Lo r\t\ne m" };
    const auto result = cdl::utils::removeSurroundingWhitespaces("\t\n\t  Lo r\t\ne m  \n\n\t\t");

    ASSERT_EQ(expected, result);
}
