set(SOURCES
    camera.h camera.c
    light.h light.c)

add_library( camera ${LIBRARY_TYPE} ${SOURCES} )
set_target_properties( camera PROPERTIES OUTPUT_NAME "coo_camera" )
