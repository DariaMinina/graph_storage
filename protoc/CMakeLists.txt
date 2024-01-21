include(FindProtobuf)
find_package(protobuf CONFIG REQUIRED)
# find_package(Protobuf REQUIRED)

# check if protobuf was found
if(PROTOBUF_FOUND)
        message("-- protobuf found")
else()
        message(FATAL_ERROR "-- Cannot find Protobuf")
endif()

file(GLOB PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.proto)

foreach(proto ${PROTO_FILES})
    # Get filename without extension
    get_filename_component(PROTO_NAME_WE ${proto} NAME_WE)
    get_filename_component(PROTO_NAME ${proto} NAME)
    # message(STATUS "Generating Protobuf Code for ${PROTO_NAME}")
    # message(STATUS "Generating Protobuf Code for ${PROTO_NAME_WE}")
    protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${proto})
    protobuf_generate_python(PROTO_PYS ${proto})
    add_library(${PROTO_NAME_WE} STATIC ${PROTO_SRCS} ${PROTO_HDRS})
    target_include_directories(${PROTO_NAME_WE} PUBLIC ${Protobuf_INCLUDE_DIRS})
endforeach()

# INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})
#
# # Generate the .h and .cxx files
# PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS graph/Node.proto graph/Relationship.proto)
#
# # Add an executable
# add_library(protobuf_objects
#     ${PROTO_SRCS}
#     ${PROTO_HDRS})
#
# target_include_directories(protobuf_objects
#     PUBLIC
#     ${PROTOBUF_INCLUDE_DIRS}
#     ${CMAKE_CURRENT_BINARY_DIR}
# )
#
# # link the exe against the libraries
# target_link_libraries(protobuf_objects
#     PUBLIC
#     ${PROTOBUF_LIBRARIES}
# )

