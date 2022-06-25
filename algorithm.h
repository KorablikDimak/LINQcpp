#ifndef LINQCPP_ALGORITHM_H
#define LINQCPP_ALGORITHM_H

#include <map>
#include <stdexcept>

template <typename T>
bool binarySearch(const T current, const T *collection, const std::size_t start, const std::size_t end)
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
void selectionSort(T *collection, const std::size_t start, const std::size_t end)
{
    for (std::size_t i = start; i <= end; ++i)
    {
        T smallest = *(collection + i);
        std::size_t smallestIndex = i;

        for (std::size_t j = i; j <= end; ++j)
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
void insertionSort(T *collection, const std::size_t start, const std::size_t end)
{
    for (unsigned i = start + 1; i <= end; ++i)
    {
        T select = *(collection + i);
        long long int j = i - 1;

        while (j >= 0 && *(collection + j) > select)
        {
            *(collection + j + 1) = *(collection + j);
            --j;
        }

        *(collection + j + 1) = select;
    }
}

template <typename T>
void merge(T *collection, std::size_t start, std::size_t mid, std::size_t end);

template <typename T>
void mergeSort(T *collection, const std::size_t start, const std::size_t end)
{
    if (start >= end) return;
    std::size_t mid = (start + end) / 2;
    mergeSort(collection, start, mid);
    mergeSort(collection, mid + 1, end);

    merge(collection, start, mid, end);
}

template <typename T>
void merge(T *collection, const std::size_t start, const std::size_t mid, const std::size_t end)
{
    const std::size_t n1 = mid - start + 1;
    const std::size_t n2 = end - mid;

    T arr1[n1], arr2[n2];

    for (std::size_t i = start, j = 0; i < mid + 1; ++i, ++j)
    {
        arr1[j] = *(collection + i);
    }
    for (std::size_t i = mid + 1, j = 0; i <= end; ++i, ++j)
    {
        arr2[j] = *(collection + i);
    }

    std::size_t i = 0, j = 0;
    for (std::size_t k = start; k <= end; ++k)
    {
        if ((j == n2 || arr1[i] <= arr2[j]) && i != n1)
        {
            *(collection + k) = arr1[i];
            ++i;
        }
        else if ((i == n1 || arr1[i] > arr2[j]) && j != n2)
        {
            *(collection + k) = arr2[j];
            ++j;
        }
    }
}

template <typename T>
std::size_t partition(T *collection, std::size_t start, std::size_t end);

template <typename T>
void quickSort(T *collection, const std::size_t start, const std::size_t end)
{
    if (start >= end) return;
    const std::size_t mid = partition(collection, start, end);
    if (mid != 0) quickSort(collection, start, mid - 1);
    quickSort(collection, mid + 1, end);
}

template <typename T>
std::size_t partition(T *collection, const std::size_t start, const std::size_t end)
{
    std::size_t mid = start;

    for (std::size_t i = start; i < end; ++i)
    {
        if (*(collection + i) <= *(collection + end))
        {
            T select = *(collection + mid);
            *(collection + mid) = *(collection + i);
            *(collection + i) = select;
            ++mid;
        }
    }

    T select = *(collection + mid);
    *(collection + mid) = *(collection + end);
    *(collection + end) = select;

    return mid;
}

template <typename T>
std::map<T, std::size_t> countEqualKeys(T *collection, const std::size_t start, const std::size_t end)
{
    std::map<T, std::size_t> equalKeyCounts;

    for (std::size_t i = start; i < end - start; ++i)
    {
        if (!equalKeyCounts.contains(*(collection + i)))
        {
            equalKeyCounts[*(collection + i)] = 0;
        }

        ++equalKeyCounts[*(collection + i)];
    }

    return equalKeyCounts;
}

template <typename T>
std::size_t countCommonSubsequence(const T *firstSequence, const std::size_t firstSize,
                                    const T *secondSequence, const std::size_t secondSize)
{
    std::size_t* LCSTable[firstSize + 1];
    for (std::size_t i = 0; i <= firstSize; ++i)
    {
        std::size_t line[secondSize + 1];
        for (std::size_t j = 0; j <= secondSize; ++j)
        {
            line[j] = 0;
        }
        LCSTable[i] = line;
    }

    for (std::size_t i = 1; i <= firstSize; ++i)
    {
        for (std::size_t j = 1; j <= secondSize; ++j)
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

template <typename T>
bool contains(const T *collection, const std::size_t collectionSize,
                const T *subCollection, const std::size_t subCollectionSize)
{
    std::size_t prefixSizeSubCollection[subCollectionSize];
    prefixSizeSubCollection[0] = 0;

    for (std::size_t i = 1; i < subCollectionSize; ++i)
    {
        std::size_t j = prefixSizeSubCollection[i - 1];
        while ((j > 0) && (subCollection[i] != subCollection[j]))
        {
            j = prefixSizeSubCollection[j - 1];
        }
        if (subCollection[i] == subCollection[j])
        {
            ++j;
        }
        prefixSizeSubCollection[i] = j;
    }

    std::size_t j = 0;
    for (std::size_t i = 0; i < collectionSize; ++i)
    {
        while ((j > 0) && (collection[i] != subCollection[j]))
        {
            j = prefixSizeSubCollection[j-1];
        }
        if (collection[i] == subCollection[j])
        {
            ++j;
        }
        if (j == subCollectionSize)
        {
            return true;
        }
    }

    return false;
}

template <typename T>
std::size_t indexAt(const T *collection, const std::size_t collectionSize,
              const T *subCollection, const std::size_t subCollectionSize)
{
    std::size_t prefixSizeSubCollection[subCollectionSize];
    prefixSizeSubCollection[0] = 0;

    for (std::size_t i = 1; i < subCollectionSize; ++i)
    {
        std::size_t j = prefixSizeSubCollection[i - 1];
        while ((j > 0) && (subCollection[i] != subCollection[j]))
        {
            j = prefixSizeSubCollection[j - 1];
        }
        if (subCollection[i] == subCollection[j])
        {
            ++j;
        }
        prefixSizeSubCollection[i] = j;
    }

    std::size_t j = 0;
    for (std::size_t i = 0; i < collectionSize; ++i)
    {
        while ((j > 0) && (collection[i] != subCollection[j]))
        {
            j = prefixSizeSubCollection[j - 1];
        }
        if (collection[i] == subCollection[j])
        {
            ++j;
        }
        if (j == subCollectionSize)
        {
            return i + 1 - subCollectionSize;
        }
    }

    throw std::domain_error("not found sub collection");
}

#endif