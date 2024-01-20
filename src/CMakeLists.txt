add_subdirectory(graph)
add_subdirectory(storage)
add_subdirectory(virtual_memory)

add_library(${PROJECT_NAME}_lib STATIC ${ALL_OBJECT_FILES})
target_link_libraries(${PROJECT_NAME}_lib PUBLIC fmt::fmt)
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
