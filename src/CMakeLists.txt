# src cmake 

set(GOLDSCRIPT_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(GOLDSCRIPT_SRC_DIR ${GOLDSCRIPT_SRC_DIR} PARENT_SCOPE)

set(GOLDSCRIPT_SRC_SOURCES 
       gs-memory.c
       gs-linked.c
       gs-items.c
)

add_library(GoldScripts STATIC "${GOLDSCRIPT_SRC_SOURCES}")

add_library(GoldScriptd SHARED "${GOLDSCRIPT_SRC_SOURCES}")