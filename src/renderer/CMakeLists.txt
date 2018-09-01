set(SOURCES
    tracer.h tracer.c)

add_library( renderer ${LIBRARY_TYPE} ${SOURCES} )
set_target_properties( renderer PROPERTIES OUTPUT_NAME "coo_renderer" )
