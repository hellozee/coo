set(SOURCES
    camera.h camera.c
    light.h light.c)

add_library( camera SHARED ${SOURCES} )
