# test cmake 

set(GOLDSCRIPT_TEST_DIR ${PROJECT_SOURCE_DIR}/test)
set(GOLDSCRIPT_TEST_DIR ${GOLDSCRIPT_TEST_DIR} PARENT_SCOPE)

include_directories(${GOLDSCRIPT_SRC_DIR})

add_executable(test_golds_memory test_gs-memory.c)
target_link_libraries(test_golds_memory PUBLIC GoldScripts)
add_test(test_goldscript_memory test_golds_memory)