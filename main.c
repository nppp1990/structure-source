#include <sys/timeb.h>
#include <string.h>
#include <stdlib.h>
#include <printf.h>

#define MAX 100
#define N 5

testBubbleSort();
testInsertSort();
testSelectSort();
testQuickSort();
testHeapSort();
testMergeSort();
testBucketSort();
testRadixSort();
testCountingSort();
testShellSort();

testListArray();
testListLink();
testListStack();
testListQueue();

testTreeOrder();

testFindLinear();
testFindBinary();
testFindInterpolation();
testFindHash();

testKmp();

testDfs();
testBfs();
testDijkstra();
testFloyd();
testDagSort();
testPrim();
testKruskal();

int main() {
    testBubbleSort();
    testInsertSort();
    testSelectSort();
    testQuickSort();
    testHeapSort();
    testMergeSort();
    testBucketSort();
    testRadixSort();
    testCountingSort();
    testShellSort();

    testListArray();
    testListLink();
    testListStack();
    testListQueue();

    testTreeOrder();

    testFindLinear();
    testFindBinary();
    testFindInterpolation();
    testFindHash();
    testKmp();

    testDfs();
    testBfs();

    testDijkstra();
    testFloyd();
    testDagSort();
    testPrim();
    testKruskal();


    return 0;
}



