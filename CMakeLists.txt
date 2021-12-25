cmake_minimum_required(VERSION 3.0)

project(arp_poisoning VERSION 0.0.1)

set(SRCS
    arp_poisoning/network/interface.c
    arp_poisoning/network/packet.c
    arp_poisoning/network/network.c

    arp_poisoning/utils/utils.c
)

set(HEADERS
    arp_poisoning/network/interface.h
    arp_poisoning/network/network.h
    arp_poisoning/network/packet.h

    arp_poisoning/utils/utils.h
)

add_executable(arp_poisoning arp_poisoning/main.c ${SRCS} ${HEADERS})
add_compile_options(-Wall -Wextra -pedantic -Werror)
target_compile_features(arp-poison PRIVATE cxx_std_17)
target_include_directories(arp-poison PUBLIC arp_poisoning/)
