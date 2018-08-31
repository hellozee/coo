set(SOURCES
    vector.h vector.c
    ray.h ray.c)


add_library( math SHARED ${SOURCES} )
set_target_properties( math PROPERTIES OUTPUT_NAME "c_math" )
