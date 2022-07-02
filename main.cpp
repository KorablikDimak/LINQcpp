#pragma once

#include <iostream>
#include "LINQ.h"
#include "algorithmTests.h"

void testAll();

int main()
{
    std::vector<int> vect1 = { 1, 4, 5, 9, 2 };
    std::vector<int> vect2 = { 4, 4, 5, 6, 2 };
    std::array<int, 3> deque = { 4, 7, 6 };
    std::vector<int> subVect = { 4, 4 };

    auto a = from(vect1)
            .join<int, int, int>(vect2, [](int v1){ return v1; }, [](int v2){ return v2; }, [](int v1, int v2){ return v1; })
            .orderBy<int>([](int var){ return -var; }, DESC)
            .select<int>([](int var){ return var * 2; })
            .skipLast(2)
            .toVector();

    auto b = from(deque).orderBy().toVector();
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