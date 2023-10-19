add_library(${PROJECT_NAME}_virtual_memory OBJECT Serializer.cpp)

set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:${PROJECT_NAME}_virtual_memory>
        PARENT_SCOPE)

target_include_directories(${PROJECT_NAME}_virtual_memory PUBLIC ${PROJECT_SOURCE_DIR}/include)
