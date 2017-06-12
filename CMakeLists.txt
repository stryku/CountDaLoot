cmake_minimum_required (VERSION 2.8.12)

set(PROJECT_NAME_STR CountDaLoot)

project(${PROJECT_NAME_STR})

set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/external_projects)

option(USE_CLIPBOARD "Copy images to clipboard" OFF)
if (PREVENT_DEBUG)
    add_definitions(-DAMB_USE_CLIPBOARD)
endif()

set( CMAKE_PREFIX_PATH C:/Qt/Qt5.9.0/5.9/msvc2015)

set(TLC_VERSION "v0.4.0-tests" CACHE STRING "Version tag")
add_definitions(-DAMB_VERSION=${AMB_VERSION})

set (program_name "Count Da Loot")

find_package (Qt5Widgets)
find_package (Qt5UiTools REQUIRED)

set (src_root ${CMAKE_CURRENT_SOURCE_DIR})
set (src_dir_qt ${src_root}/gui/CountDaLoot)
set (inc_dir_qt ${src_root}/gui/CountDaLoot)
set (src_dir ${src_root}/sources/src)
set (inc_dir ${src_root}/sources/inc)
set (ui_dir ${src_root}/gui/CountDaLoot)
set (resources_dir ${src_root}/resources)
set (install_dir ${src_root}/bin)

message (${program_name} " will be installed in:")
message (${install_dir})

include_directories (${inc_dir} 
                     ${inc_dir_qt}
                     ${Qt5UiTools_INCLUDE_DIRS})
           
set (src_qt	${src_dir_qt}/main.cpp
            ${src_dir_qt}/mainwindow.cpp)
					
set (inc_qt ${inc_dir_qt}/mainwindow.h)
					

add_subdirectory(sources)                    
             
set (hdr ${inc_dir_qt}/mainwindow.h)
set (ui  ${ui_dir}/mainwindow.ui)
set (gui_src ${src_dir_qt}/main.cpp)

qt5_wrap_cpp(hdr_moc ${hdr})
qt5_wrap_ui (ui_moc  ${ui})

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_BINARY_DIR})

add_library (MocObjects OBJECT 
    ${hdr_moc}
    ${ui_moc}  
)

add_executable(${PROJECT_NAME_STR} ${src_qt}
                                   ${inc_qt}
                                   ${src}
                                   ${inc} 
                                   $<TARGET_OBJECTS:MocObjects>)
						  
target_link_libraries (${PROJECT_NAME_STR} Qt5::Widgets Qt5::UiTools ntdll.lib)


add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
add_subdirectory(tests)  

install(TARGETS ${PROJECT_NAME_STR} DESTINATION  ${install_dir}/)
install(
    DIRECTORY ${resources_dir}/
    DESTINATION ${install_dir}
)
