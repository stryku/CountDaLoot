set(root ${CMAKE_CURRENT_SOURCE_DIR})

set (qt_utils_inc
        ${root}/inc/updater/TextEditUpdater.hpp
        ${root}/inc/updater/LabelUpdater.hpp
PARENT_SCOPE)

set (qt_utils_src
        ${root}/src/updater/TextEditUpdater.cpp
        ${root}/src/updater/LabelUpdater.cpp
PARENT_SCOPE)