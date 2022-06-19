cmake_minimum_required(VERSION 3.21)
project(structure_source C)

set(CMAKE_C_STANDARD 99)

add_executable(structure_source main.c sortBubble.c sortInsert.c sortSelect.c sortQuick.c sortHeap.c sortMerge.c sortBucket.c sortRadix.c sortCounting.c sortShell.c list-array.c list-link.c list-stack.c list-queue.c tree1.c)