cmake_minimum_required(VERSION 3.22)
find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)
    MESSAGE("CCACHE support enabled")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_BUILD_TYPE "Debug")

# add_compile_definitions(DEBUG)
function(add_code name path)
    add_executable(${name} ${path})
    target_link_libraries(${name})
    target_include_directories(${name} PUBLIC "src/")
    target_compile_definitions(${name} PRIVATE DEBUG=1)
endfunction()

set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_code(HelloWorld "src/HelloWorld.cpp")

#add_code(InvertBinaryTree "src/tree/InvertBinaryTree.cpp")

#add_code(BW94_Q1 "src/leetcode/biweekly/BW94_Q1.cpp")
#add_code(BW94_Q2 "src/leetcode/biweekly/BW94_Q2.cpp")
#add_code(BW94_Q3 "src/leetcode/biweekly/BW94_Q3.cpp")
#add_code(BW94_Q4 "src/leetcode/biweekly/BW94_Q4.cpp")

#add_code(W325_Q1 "src/leetcode/weekly/W325_Q1.cpp")
#add_code(W325_Q2 "src/leetcode/weekly/W325_Q2.cpp")
#add_code(W325_Q3 "src/leetcode/weekly/W325_Q3.cpp")
#add_code(W325_Q4 "src/leetcode/weekly/W325_Q4.cpp")

add_code(TwoSum "src/patterns/TwoSum.cpp")
add_code(ValidParentheses "src/patterns/ValidParentheses.cpp")