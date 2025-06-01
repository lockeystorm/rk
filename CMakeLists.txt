cmake_minimum_required(VERSION 3.30)
project(proxy_map LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

set(LIB_SOURCE 
    source/resource.h source/maptile.h
    source/maptileproxy.h source/map.h
    source/maptile.cpp source/maptileproxy.cpp source/map.cpp)
    
add_library(map STATIC ${LIB_SOURCE})
target_include_directories(map PUBLIC ../source)

add_executable(main source/main.cpp)
target_link_libraries(main map)

install(TARGETS map
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
)

install(DIRECTORY source/
    DESTINATION include/proxy-map
    FILES_MATCHING PATTERN "*.h"
)


# сборка тестов
if(BUILD_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)
  add_executable(test0 tests/test0.cpp)
  target_link_libraries(test0 map GTest::GTest GTest::Main)
  include(GoogleTest)
  gtest_discover_tests(test0)
endif()

# настройка пакетирования
include(InstallRequiredSystemLibraries)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

set(CPACK_PACKAGE_NAME "map")
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_PACKAGE_VENDOR "company")
set(CPACK_PACKAGE_CONTACT "email")
set(CPACK_PACKAGE_DESCRIPTION "Proxy Map Tiles")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

set(CPACK_GENERATOR "DEB")

set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "owner")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.14), libstdc++6 (>= 4.8.1)")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_RELEASE 1)

include(CPack)


