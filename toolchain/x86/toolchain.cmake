set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR i686)
set(CMAKE_TOOLCHAIN_PREFIX i686-elf)

set(CMAKE_ASM-ATT-COMPILER as)

include(CMakeForceCompiler)
set(CMAKE_C_COMPILER ${CMAKE_TOOLCHAIN_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${CMAKE_TOOLCHAIN_PREFIX}-g++)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_FLAGS "-O3 -ffreestanding" CACHE STRING "C flags" FORCE)
set(CMAKE_C_FLAGS_DEBUG "-ggdb -W -Wall -Wextra -Winline" CACHE STRING "C flags for debug version" FORCE)
set(CMAKE_CXX_FLAGS "-O3 -ffreestanding" CACHE STRING "C flags" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb -W -Wall -Wextra -Winline" CACHE STRING "C flags for debug version" FORCE)
set(CMAKE_ASM-ATT_FLAGS "-32")

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/toolchain/x86/linker.ld)
set(CMAKE_EXE_LINKER_FLAGS "-ffreestanding -nostdlib -T${LINKER_SCRIPT}" CACHE STRING "Linker flags" FORCE)

set(CMAKE_FIND_ROOT_PATH ${CMAKE_SOURCE_DIR})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(ZenithOS_ARCH x86)
