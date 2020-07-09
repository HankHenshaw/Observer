cmake_minimum_required(VERSION 3.5)

project(bulky VERSION 0.0.1$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(bulk observer.h observer.cpp main.cpp)
add_executable(tests observer.h observer.cpp test_main.cpp)

set_target_properties(bulk tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wall;-Wpedantic;-Wextra"
)

set_target_properties(tests PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(tests
    ${Boost_LIBRARIES}
)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_PACKAGE_VERSION_MAJOR "{PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "{PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "{PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT "HankHenshaw at github.com")

include(CPack)

enable_testing()

add_test(tests tests)