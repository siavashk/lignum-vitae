file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(core ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_precompiled_header(core pch.h)

target_link_libraries(core ${Boost_LIBRARIES})
