find_library(CRITERION_LIB criterion)
find_path(CRITERION_INCLUDE
    NAMES criterion
    PATHS "/usr/local/include"
    )

# Include module which provides the convenience function to test the variable 
# set by find_library and find_path
include(FindPackageHandleStandardArgs)

# It will check the variable set and give default error message in case any one
# is not set.
find_package_handle_standard_args(Criterion DEFAULT_MSG
    CRITERION_LIB
    CRITERION_INCLUDE
    )

if (Criterion_FOUND AND NOT TARGET Criterion::criterion)
    # SHARED - it will be used as dynamic shared library
    # IMPORTED - it is not provided/built in current project
    add_library(Criterion::criterion SHARED IMPORTED)
    set_target_properties(
        Criterion::criterion
        PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${CRITERION_INCLUDE}"
            IMPORTED_LOCATION "${CRITERION_LIB}"
            )
endif()

