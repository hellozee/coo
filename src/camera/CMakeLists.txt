set(SOURCES
    camera.h camera.c
    light.h light.c)

add_library( camera SHARED ${SOURCES} )
set_target_properties( camera PROPERTIES OUTPUT_NAME "c_camera" )
