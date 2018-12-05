cmake_minimum_required (VERSION 2.6)

# project name
project (project_name)

# set compile flag
# add_definitions ("-Wall -g")

# set extern libraries
# set (libraries libm.so)
# set source directory
aux_source_directory(src SRC_LIST)

# head files
include_directories(include)

# set prefix
set(ps_build_binary_prefix  "ps_")

add_executable(${ps_build_binary_prefix}${PROJECT_NAME}  ${SRC_LIST})
