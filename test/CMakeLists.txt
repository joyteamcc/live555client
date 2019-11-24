set(EXECUTABLE_OUTPUT_PATH ${OUTDIR}/bin)


INCLUDE_DIRECTORIES(
    ../include
    ${TOPDIR}/stream/include
    ${TOPDIR}/wize/include
    ${TOPDIR}/opensources/miniboost
)

LINK_DIRECTORIES(
    ${BOARD_LIBDIRS}
)

add_executable(test_rtsp_client
    test_rtsp_client.cpp
)

target_link_libraries(test_rtsp_client
    live555client
    stream wize miniboost
    liveMedia BasicUsageEnvironment UsageEnvironment groupsock
    ${BOARD_LIBS}
)

