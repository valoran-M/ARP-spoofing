cmake_minimum_required(VERSION 3.0)

project(arp-poison VERSION 0.0.1)

set(SRCS
    src/network/interface.c
    src/network/packet.c
    src/network/network.c

    src/utils/utils.c
)

set(HEADERS
    src/network/interface.h
    src/network/network.h
    src/network/packet.h

    src/utils/utils.h
)

add_executable(arp-poison src/main.c ${SRCS} ${HEADERS})
add_compile_options(-Wall -Wextra -pedantic -Werror)
target_compile_features(arp-poison PRIVATE cxx_std_17)
target_include_directories(arp-poison PUBLIC src/)
