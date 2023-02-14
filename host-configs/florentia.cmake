set(ENABLE_SYCL ON CACHE BOOL "")

set(CMAKE_C_COMPILER   "icx" CACHE PATH "")
set(CMAKE_CXX_COMPILER "icpx" CACHE PATH "")
set(BLT_CXX_STD "c++17" CACHE STRING "")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fsycl -fsycl-unnamed-lambda" CACHE STRING "")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO " -O3 -g -fsycl -fsycl-unnamed-lambda" CACHE STRING "")
set(CMAKE_CXX_FLAGS_DEBUG " -O0 -g -fsycl -fsycl-unnamed-lambda" CACHE STRING "")
set(CMAKE_CXX_LINK_FLAGS "-fsycl"  CACHE STRING "")
