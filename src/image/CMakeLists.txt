set(SOURCES
    image.h image.c
    color.h color.c)

add_library( image ${LIBRARY_TYPE} ${SOURCES} )
set_target_properties( image PROPERTIES OUTPUT_NAME "coo_image" )
