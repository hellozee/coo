set(SOURCES
    image.h image.c
    color.h color.c)

add_library( image SHARED ${SOURCES} )
set_target_properties( image PROPERTIES OUTPUT_NAME "c_image" )
