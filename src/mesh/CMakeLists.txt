set(SOURCES
    object.h object.c
    sphere.h sphere.c
    plane.h plane.c)


add_library( mesh SHARED ${SOURCES} )
