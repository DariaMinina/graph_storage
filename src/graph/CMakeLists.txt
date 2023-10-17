add_library(${PROJECT_NAME}_graph OBJECT Node.cpp)

set(ALL_OBJECT_FILES
        ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:${PROJECT_NAME}_graph>
        PARENT_SCOPE)

target_include_directories(${PROJECT_NAME}_graph PUBLIC ${PROJECT_SOURCE_DIR}/include)
