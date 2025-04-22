check_include_file_cxx(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
    add_definitions(-DHAVE_STDINT_H)
endif()

set(examples_as_tests_sources)
if(${ENABLE_EXAMPLES})
    set(examples_as_tests_sources
        #test/new-module-examples-test-suite.cc
        )
endif()

build_lib(
    LIBNAME new-module
    SOURCE_FILES model/tdma-mac.cc
                 model/tdma-net-device.cc
                 helper/tdma-helper.cc
    HEADER_FILES model/tdma-mac.h
                 model/tdma-net-device.h
                 helper/tdma-helper.h
    LIBRARIES_TO_LINK ${libcore}
    TEST_SOURCES test/new-module-test-suite.cc
                 ${examples_as_tests_sources}
)
