get_filename_component(_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" _NAME ${_NAME})

add_executable(${_NAME} main.cpp)

target_link_libraries(${_NAME} core)

add_precompiled_header(${_NAME} pch.h)
