#include "algorithmTests.h"

bool binarySearchTest()
{
    short arr[10] = { 1, 3, 5, 8, 9, 14, 56, 102, 304, 400 };
    if (binarySearch((short) 3, arr, 0, 10) &&
        binarySearch((short) 400, arr, 0, 10) &&
        !binarySearch((short) 103, arr, 0, 10))
    {
        return true;
    }

    return false;
}

bool selectionSortTest()
{
    short arr1[10] = { 7,4,2,10,2,50,5,21,40,25 };
    short arrCorrect1[10] = { 2, 2, 4, 5, 7, 10, 21, 25, 40, 50 };
    selectionSort(arr1, 0, 9);
    for (short i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<short> arr2 = { 6, 3, 18, 9, 11, 23, 10, 33 };
    std::vector<short> arrCorrect2 = { 3, 6, 9, 10, 11, 18, 23, 33 };
    selectionSort(arr2.data(), 0, 7);
    for (short i = 0; i < 8; i++)
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
    short arr1[10] = { 7,4,2,10,2,50,5,21,40,25 };
    short arrCorrect1[10] = { 2, 2, 4, 5, 7, 10, 21, 25, 40, 50 };
    insertionSort(arr1, 0, 9);
    for (short i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<short> arr2 = { 6, 3, 18, 9, 11, 23, 10, 33 };
    std::vector<short> arrCorrect2 = { 3, 6, 9, 10, 11, 18, 23, 33 };
    insertionSort(arr2.data(), 0, 7);
    for (short i = 0; i < 8; i++)
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
    short arr1[10] = { 7,3,6,10,2,50,5,21,40,25 };
    short arrCorrect1[10] = { 2, 3, 5, 6, 7, 10, 21, 25, 40, 50 };
    mergeSort(arr1, 0, 9);
    for (short i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<short> arr2 = { 6, 3, 18, 9, 12, 23, 10, 33 };
    std::vector<short> arrCorrect2 = { 3, 6, 9, 10, 12, 18, 23, 33 };
    mergeSort(arr2.data(), 0, 7);
    for (short i = 0; i < 8; i++)
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
    short arr1[10] = { 7,3,6,10,2,50,5,21,40,25 };
    short arrCorrect1[10] = { 2, 3, 5, 6, 7, 10, 21, 25, 40, 50 };
    quickSort(arr1, 0, 9);
    for (short i = 0; i < 10; i++)
    {
        if (arr1[i] != arrCorrect1[i])
        {
            return false;
        }
    }

    std::vector<short> arr2 = { 6, 3, 18, 9, 12, 23, 10, 33 };
    std::vector<short> arrCorrect2 = { 3, 6, 9, 10, 12, 18, 23, 33 };
    quickSort(arr2.data(), 0, 7);
    for (short i = 0; i < 8; i++)
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
    short arr[10] = { 7,6,6,10,2,2,5,6,40,6 };
    std::map<short, std::size_t> dict = countEqualKeys(arr, 0, 9);
    if (dict[6] == 3 && dict[7] == 1 && dict[2] == 2)
    {
        return true;
    }

    return false;
}

bool countCommonSubsequenceTest()
{
    short arr1[10] = { 7,6,6,10,2,2,5,6,40,6 };
    short arr2[10] = { 7,6,7,10,2,2,5,6,41,6 };
    std::size_t count = countCommonSubsequence(arr1, 10, arr2, 10);
    if (count == 8)
    {
        return true;
    }

    return false;
}

bool containsTest()
{
    short collection[10] = { 7,6,6,10,2,2,5,6,40,6 };
    short subCollection1[4] = { 10, 2, 2, 5 };
    short subCollection2[4] = { 7, 2, 2, 40 };

    if (contains(collection, 10, subCollection1, 4) &&
    !contains(collection, 10, subCollection2, 4))
    {
        return true;
    }

    return false;
}

bool indexAtTest()
{
    short collection[10] = { 7,6,6,10,2,2,5,6,40,6 };
    short subCollection1[4] = { 10, 2, 2, 5 };
    short subCollection2[4] = { 7, 2, 2, 40 };

    if (indexAt(collection, 10, subCollection1, 4) == 3)
    {
        try
        {
            indexAt(collection, 10, subCollection2, 4);
        }
        catch (std::domain_error)
        {
            return true;
        }
    }

    return false;
}