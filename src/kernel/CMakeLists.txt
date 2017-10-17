add_subdirectory(arch/${ZenithOS_ARCH})

set(SOURCES
	${SOURCES}
	"${CMAKE_CURRENT_SOURCE_DIR}/string.c"
	PARENT_SCOPE
	)
