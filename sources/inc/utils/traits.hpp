#pragma once

#include <type_traits>

namespace cdl
{
    namespace utils
    {
        namespace traits
        {
            template <typename T>
            struct canCallStdToString
            {
                static constexpr bool value = !std::is_same<T, bool>::value &&
                    (std::is_integral<T>::value ||
                     std::is_unsigned<T>::value ||
                     std::is_floating_point<T>::value);
            };

            template<bool...> struct bool_pack;

            template <bool ...bs>
            using all_true = std::is_same<bool_pack<bs..., true>, bool_pack<true, bs...>>;

            template <bool ...bs>
            using all_false = std::is_same<bool_pack<bs..., false>, bool_pack<false, bs...>>;

            template <bool ...bs>
            using any_true = std::integral_constant<bool, !all_false<bs...>::value>;

            template <typename T, typename ...Args>
            using is_any_of = any_true<std::is_same<T, Args>::value...>;

            template <typename T, typename ...Args>
            constexpr bool is_any_of_v = is_any_of<T, Args...>::value;
        }
    }
}
