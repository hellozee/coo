set(SOURCES
    vector.h vector.c
    ray.h ray.c)

add_library( math ${LIBRARY_TYPE} ${SOURCES} )
set_target_properties( math PROPERTIES OUTPUT_NAME "coo_math" )
