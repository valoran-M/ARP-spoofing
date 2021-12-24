cmake_minimum_required(VERSION 3.0)

project(arp VERSION 0.0.1)

set(SRCS
    src/network/packet.c
    src/network/network.c

    src/utils/utils.c
)

set(HEADERS
    src/network/network.h
    src/network/packet.h

    src/utils/debug.h
    src/utils/utils.h
)

add_executable(arp src/main.c ${SRCS} ${HEADERS})
target_compile_features(arp PRIVATE cxx_std_17)
target_include_directories(arp PUBLIC src/)
