set(BINARY TemperatureMonitor_Tests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false test_*.cpp ut_*.cpp)
add_executable(${BINARY} ${TEST_SOURCES} private_method_test.cpp)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC 
    gtest
    gmock
    TemperatureMonitor
    MocksTemperatureMonitorApp
)
