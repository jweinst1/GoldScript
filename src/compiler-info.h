#ifndef SRC_GOLDSCIRPT_COMPILER_INFO_H
#define SRC_GOLDSCIRPT_COMPILER_INFO_H

#if defined(__STDC__)

#  if defined(__STDC_VERSION__)
#    if (__STDC_VERSION__ >= 199409L)
#        if (__STDC_VERSION__ >= 199901L)
#           if (__STDC_VERSION__ >= 201112L)
#              define GOLDSCRIPT_CVERS_11
#           else // !(__STDC_VERSION__ >= 201112L)
#              define GOLDSCRIPT_CVERS_99
#           endif // (__STDC_VERSION__ >= 201112L)
#        else // !(__STDC_VERSION__ >= 199901L)
#           define GOLDSCRIPT_CVERS_94
#        endif // (__STDC_VERSION__ >= 199901L)
#    else // (__STDC_VERSION__ >= 199409L)
#       define GOLDSCRIPT_CVERS_90
#    endif // !(__STDC_VERSION__ >= 199409L)
#  else // defined(__STDC_VERSION__)
#    define GOLDSCRIPT_CVERS_89
#  endif // !defined(__STDC_VERSION__)
#else // defined(__STDC__)
#  ifdef _WIN32
#     pragma message("__STDC__ is not defined, this is a non-standard C version.")
#  else
#     warn "__STDC__ is not defined, this is a non-standard C version."
#  endif
#endif

#if defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
#  define GOLDSCRIPT_OS_UNIX
#endif

#ifdef _WIN32
#  define GOLDSCRIPT_OS_WIN
#endif

#ifdef SAPPHIRE_STD_C_1999
#  define GOLDSCRIPT_HAS_VARIADIC_ARGS
#  define GOLDSCRIPT_HAS_STDINT
#endif

#endif // SRC_GOLDSCIRPT_COMPILER_INFO_H