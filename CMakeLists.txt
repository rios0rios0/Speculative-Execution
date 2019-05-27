cmake_minimum_required(VERSION 3.13)
project(Speculative-Execution C)

set(CMAKE_C_STANDARD 99)

#Completed exploits
add_executable(jan_horn Spectre/jann_horn_et_al/script.c)
add_executable(rootkea Spectre/rootkea/script.c)
add_executable(paboldin Meltdown/paboldin/script.c)
#Testing exploits
add_executable(victim Spectre/rios0rios0/victim.c)
add_executable(victim2 Spectre/rios0rios0/victim2.c)
add_executable(attacker Spectre/rios0rios0/attacker.c)
#Scripts to test
add_executable(cache_time Tests/CacheTime.c)
add_executable(kernel_table Tests/KernelTable.c)
add_executable(virt_address Tests/VirtAddress.c)