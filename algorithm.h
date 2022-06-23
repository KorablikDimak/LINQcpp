#ifndef LINQCPP_ALGORITHM_H
#define LINQCPP_ALGORITHM_H

#include <map>

template <typename T>
bool binarySearch(const T current, const T *collection, const unsigned int start, const unsigned int end)
{
    if (end - start <= 1)
    {
        if (current == *(collection + start)) return true;
        return false;
    }
    if (current == *(collection + (end + start) / 2)) return true;
    if (current < *(collection + (end + start) / 2)) return binarySearch(current, collection, start, (end + start) / 2);
    if (current > *(collection + (end + start) / 2)) return binarySearch(current, collection, (end + start) / 2, end);
    return false;
}

template <typename T>
void selectionSort(T *collection, const unsigned int start, const unsigned int end)
{
    for (unsigned i = start; i <= end; i++)
    {
        T smallest = *(collection + i);
        unsigned int smallestIndex = i;

        for (unsigned j = i; j <= end; j++)
        {
            if (*(collection + j) < smallest)
            {
                smallest = *(collection + j);
                smallestIndex = j;
            }
        }

        *(collection + smallestIndex) = *(collection + i);
        *(collection + i) = smallest;
    }
}

template <typename T>
void insertionSort(T *collection, const unsigned int start, const unsigned int end)
{
    for (unsigned i = start + 1; i <= end; i++)
    {
        T select = *(collection + i);
        long long int j = i - 1;

        while (j >= 0 && *(collection + j) > select)
        {
            *(collection + j + 1) = *(collection + j);
            j--;
        }

        *(collection + j + 1) = select;
    }
}

template <typename T>
void merge(T *collection, unsigned int start, unsigned int mid, unsigned int end);

template <typename T>
void mergeSort(T *collection, const unsigned int start, const unsigned int end)
{
    if (start >= end) return;
    unsigned int mid = (start + end) / 2;
    mergeSort(collection, start, mid);
    mergeSort(collection, mid + 1, end);

    merge(collection, start, mid, end);
}

template <typename T>
void merge(T *collection, const unsigned int start, const unsigned int mid, const unsigned int end)
{
    const unsigned int n1 = mid - start + 1;
    const unsigned int n2 = end - mid;

    T arr1[n1], arr2[n2];

    for (unsigned int i = start, j = 0; i < mid + 1; i++, j++)
    {
        arr1[j] = *(collection + i);
    }
    for (unsigned int i = mid + 1, j = 0; i <= end; i++, j++)
    {
        arr2[j] = *(collection + i);
    }

    unsigned int i = 0, j = 0;
    for (unsigned int k = start; k <= end; k++)
    {
        if ((j == n2 || arr1[i] <= arr2[j]) && i != n1)
        {
            *(collection + k) = arr1[i];
            i++;
        }
        else if ((i == n1 || arr1[i] > arr2[j]) && j != n2)
        {
            *(collection + k) = arr2[j];
            j++;
        }
    }
}

template <typename T>
unsigned int partition(T *collection, unsigned int start, unsigned int end);

template <typename T>
void quickSort(T *collection, const unsigned int start, const unsigned int end)
{
    if (start >= end) return;
    const unsigned int mid = partition(collection, start, end);
    if (mid != 0) quickSort(collection, start, mid - 1);
    quickSort(collection, mid + 1, end);
}

template <typename T>
unsigned int partition(T *collection, const unsigned int start, const unsigned int end)
{
    unsigned int mid = start;

    for (unsigned int i = start; i < end; i++)
    {
        if (*(collection + i) <= *(collection + end))
        {
            T select = *(collection + mid);
            *(collection + mid) = *(collection + i);
            *(collection + i) = select;
            mid++;
        }
    }

    T select = *(collection + mid);
    *(collection + mid) = *(collection + end);
    *(collection + end) = select;

    return mid;
}

template <typename T>
std::map<T, unsigned int> countEqualKeys(T *collection, const unsigned int start, const unsigned int end)
{
    std::map<T, unsigned int> equalKeyCounts;

    for (unsigned int i = start; i < end - start; i++)
    {
        if (!equalKeyCounts.contains(*(collection + i)))
        {
            equalKeyCounts[*(collection + i)] = 0;
        }

        equalKeyCounts[*(collection + i)]++;
    }

    return equalKeyCounts;
}

template <typename T>
unsigned int countCommonSubsequence(const T* firstSequence, const unsigned int firstSize,
                                    const T* secondSequence, const unsigned int secondSize)
{
    unsigned int* LCSTable[firstSize + 1];
    for (unsigned int i = 0; i <= firstSize; i++)
    {
        unsigned int line[secondSize + 1];
        for (unsigned int j = 0; j <= secondSize; j++)
        {
            line[j] = 0;
        }
        LCSTable[i] = line;
    }

    for (unsigned int i = 1; i <= firstSize; i++)
    {
        for (unsigned int j = 1; j <= secondSize; j++)
        {
            if (firstSequence[i - 1] == secondSequence[j - 1])
            {
                LCSTable[i][j] = LCSTable[i - 1][j - 1] + 1;
            }
            else
            {
                if (LCSTable[i][j - 1] > LCSTable[i - 1][j])
                {
                    LCSTable[i][j] = LCSTable[i][j - 1];
                }
                else
                {
                    LCSTable[i][j] = LCSTable[i - 1][j];
                }
            }
        }
    }

    return LCSTable[firstSize][secondSize];
}



#endif