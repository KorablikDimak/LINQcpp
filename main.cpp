#include <iostream>
#include "algorithmTests.h"

void testAll();

int main()
{
    testAll();
}

void testAll()
{
    std::cout << "binary search: " << binarySearchTest() << std::endl;
    std::cout << "selection sort: " << selectionSortTest() << std::endl;
    std::cout << "insertion sort: " << insertionSortTest() << std::endl;
    std::cout << "merge sort: " << mergeSortTest() << std::endl;
    std::cout << "quick sort: " << quickSortTest() << std::endl;
    std::cout << "count equal keys: " << countEqualKeysTest() << std::endl;
    std::cout << "count common subsequence: " << countCommonSubsequenceTest() << std::endl;
    std::cout << "contains: " << containsTest() << std::endl;
    std::cout << "index at: " << indexAtTest() << std::endl;
}