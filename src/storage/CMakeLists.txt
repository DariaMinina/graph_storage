add_library(${PROJECT_NAME}_storage OBJECT FileUtils.cpp)

set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:${PROJECT_NAME}_storage>
        PARENT_SCOPE)

target_link_libraries(${PROJECT_NAME}_storage PUBLIC fmt::fmt)
target_include_directories(${PROJECT_NAME}_storage PUBLIC ${PROJECT_SOURCE_DIR}/include)
