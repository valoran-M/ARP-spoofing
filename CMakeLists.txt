cmake_minimum_required(VERSION 3.0)

project(arp_poissoning VERSION 0.0.1)

set(SRCS
    src/network/send.c
    )

set(HEADERS
    )

add_executable(arp src/main.c ${SRCS} ${HEADERS})
