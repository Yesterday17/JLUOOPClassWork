cmake_minimum_required(VERSION 3.13)
project(OOPClassWork)

set(CMAKE_CXX_STANDARD 17)

# Menu
aux_source_directory(menu menu)

# Week 6
aux_source_directory(week6 week6)
aux_source_directory(week6/1 week6)
aux_source_directory(week6/2 week6)
aux_source_directory(week6/3 week6)
aux_source_directory(week6/4 week6)
aux_source_directory(week6/5 week6)
aux_source_directory(week6/6 week6)

# Week 7
aux_source_directory(week7 week7)
aux_source_directory(week7/1 week7)
aux_source_directory(week7/2 week7)
aux_source_directory(week7/3 week7)
aux_source_directory(week7/4 week7)
aux_source_directory(week7/5 week7)
aux_source_directory(week7/6 week7)

# Week 8
aux_source_directory(week8 week8)
aux_source_directory(week8/1 week8)
aux_source_directory(week8/2 week8)
aux_source_directory(week8/3 week8)
aux_source_directory(week8/4 week8)
aux_source_directory(week8/5 week8)

# Week 9
aux_source_directory(week9 week9)
aux_source_directory(week9/1 week9)
aux_source_directory(week9/2 week9)
aux_source_directory(week9/3 week9)

# Week 10
aux_source_directory(week10 week10)
aux_source_directory(week10/1 week10)
aux_source_directory(week10/2 week10)
aux_source_directory(week10/3 week10)
aux_source_directory(week10/4 week10)

set(modules
        ${menu}
        ${week6}
        ${week7}
        ${week8}
        ${week9}
        ${week10})

add_executable(OOPClassWork main.cpp ${modules})