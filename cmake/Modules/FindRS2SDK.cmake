
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")

endif  ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")



find_path(RS2SDK_INCLUDE_DIRS librealsense2/rs.hpp
  HINTS "C:/Program Files (x86)/Intel RealSense SDK 2.0/include")

find_path(RS2SDK_LIBRARY_DIRS x64
  HINTS "C:/Program Files (x86)/Intel RealSense SDK 2.0/lib")

find_library(RS2SDK_LIBRARY realsense2.lib
  HINTS "C:/Program Files (x86)/Intel RealSense SDK 2.0/lib/x64/")