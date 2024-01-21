include_directories(${CMAKE_BINARY_DIR}/protoc)

add_subdirectory(graph)
add_subdirectory(storage)
add_subdirectory(virtual_memory)

add_library(${PROJECT_NAME}_lib STATIC ${ALL_OBJECT_FILES})
target_link_libraries(${PROJECT_NAME}_lib PUBLIC fmt::fmt)
# target_link_libraries(${PROJECT_NAME}_lib PUBLIC fmt::fmt ${Protobuf_LIBRARIES})
# target_link_libraries(${PROJECT_NAME}_lib PUBLIC fmt::fmt protobuf_objects)
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include ${Protobuf_INCLUDE_DIRS})
