set(TARGETLIB "TemperatureMonitor")

set(LIB_SOURCE_FILES 
    temperature_reader.cpp
    filter.cpp
    codings.cpp
    temperature_monitor_app.cpp)

set(ADDITIONAL_INCLUDE_DIRS ../inc)

add_library(${TARGETLIB} STATIC ${LIB_SOURCE_FILES})
target_include_directories(${TARGETLIB} PUBLIC ${ADDITIONAL_INCLUDE_DIRS})
