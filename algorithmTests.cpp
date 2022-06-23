#include "algorithmTests.h"

bool binarySearchTest()
{
    int arr[10] = { 1, 3, 5, 8, 9, 14, 56, 102, 304, 400 };
    if (binarySearch(3, arr, 0, 10) &&
        binarySearch(400, arr, 0, 10) &&
        !binarySearch(103, arr, 0, 10))
    {
        return true;
    }

    return false;
}

bool selectionSortTest()
{
    int arr1[10] = { 7,4,2,10,2,50,5,21,40,25 };
    int arrCorrect1[10] = { 2, 2, 4, 5, 7, 10, 21, 25, 40, 50 };
    selectionSort(arr1, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<int> arr2 = { 6, 3, 18, 9, 11, 23, 10, 33 };
    std::vector<int> arrCorrect2 = { 3, 6, 9, 10, 11, 18, 23, 33 };
    selectionSort(arr2.data(), 0, 7);
    for (int i = 0; i < 8; i++)
    {
        if (arr2[i] != arrCorrect2[i])
        {
            return false;
        }
    }

    return true;
}

bool insertionSortTest()
{
    int arr1[10] = { 7,4,2,10,2,50,5,21,40,25 };
    int arrCorrect1[10] = { 2, 2, 4, 5, 7, 10, 21, 25, 40, 50 };
    insertionSort(arr1, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<int> arr2 = { 6, 3, 18, 9, 11, 23, 10, 33 };
    std::vector<int> arrCorrect2 = { 3, 6, 9, 10, 11, 18, 23, 33 };
    insertionSort(arr2.data(), 0, 7);
    for (int i = 0; i < 8; i++)
    {
        if (arr2[i] != arrCorrect2[i])
        {
            return false;
        }
    }

    return true;
}

bool mergeSortTest()
{
    int arr1[10] = { 7,3,6,10,2,50,5,21,40,25 };
    int arrCorrect1[10] = { 2, 3, 5, 6, 7, 10, 21, 25, 40, 50 };
    mergeSort(arr1, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<int> arr2 = { 6, 3, 18, 9, 12, 23, 10, 33 };
    std::vector<int> arrCorrect2 = { 3, 6, 9, 10, 12, 18, 23, 33 };
    mergeSort(arr2.data(), 0, 7);
    for (int i = 0; i < 8; i++)
    {
        if (arr2[i] != arrCorrect2[i])
        {
            return false;
        }
    }

    return true;
}

bool quickSortTest()
{
    int arr1[10] = { 7,3,6,10,2,50,5,21,40,25 };
    int arrCorrect1[10] = { 2, 3, 5, 6, 7, 10, 21, 25, 40, 50 };
    quickSort(arr1, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<int> arr2 = { 6, 3, 18, 9, 12, 23, 10, 33 };
    std::vector<int> arrCorrect2 = { 3, 6, 9, 10, 12, 18, 23, 33 };
    quickSort(arr2.data(), 0, 7);
    for (int i = 0; i < 8; i++)
    {
        if (arr2[i] != arrCorrect2[i])
        {
            return false;
        }
    }

    return true;
}

bool countEqualKeysTest()
{
    int arr[10] = { 7,6,6,10,2,2,5,6,40,6 };
    std::map<int, unsigned int> dict = countEqualKeys(arr, 0, 9);
    if (dict[6] == 3 && dict[7] == 1 && dict[2] == 2)
    {
        return true;
    }

    return false;
}

bool countCommonSubsequenceTest()
{
    int arr1[10] = { 7,6,6,10,2,2,5,6,40,6 };
    int arr2[10] = { 7,6,7,10,2,2,5,6,41,6 };
    unsigned int count = countCommonSubsequence(arr1, 10, arr2, 10);
    if (count == 8)
    {
        return true;
    }

    return false;
}