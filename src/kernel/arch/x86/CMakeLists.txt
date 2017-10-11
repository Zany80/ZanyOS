add_subdirectory(VGA)

set(SOURCES
	${SOURCES}
	"${CMAKE_CURRENT_SOURCE_DIR}/kernel.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/multiboot.asm"
	"${CMAKE_CURRENT_SOURCE_DIR}/start.asm"
	PARENT_SCOPE
)
