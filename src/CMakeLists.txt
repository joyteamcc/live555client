
include_directories(
    ../include
    ${TOPDIR}/frameworks/include
    ${TOPDIR}/stream/include
    ${TOPDIR}/wize/include
    ${TOPDIR}/opensources/miniboost
    ${TOPDIR}/opensources/live555/liveMedia/include
    ${TOPDIR}/opensources/live555/groupsock/include
    ${TOPDIR}/opensources/live555/BasicUsageEnvironment/include
    ${TOPDIR}/opensources/live555/UsageEnvironment/include
)

file(GLOB_RECURSE HEADERFILES "../include/*" "*.h")
aux_source_directory(. DIR_SRCS)
add_library(live555client ${DIR_SRCS} ${HEADERFILES})

