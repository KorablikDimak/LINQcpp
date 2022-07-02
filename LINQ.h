#ifndef LINQCPP_LINQ_H
#define LINQCPP_LINQ_H

#include "algorithm.h"

enum OrderType
{
    ASC = true,
    DESC = false
};

template <typename T>
class LinqObject
{
public:
    LinqObject(std::vector<T> collection)
    {
        this->collection = collection;
    }

    std::vector<T> toVector()
    {
        return collection;
    }

    // selected methods

    template<typename TKey>
    LinqObject select(std::function<TKey(T)> selector)
    {
        std::vector<TKey> newCollection;
        auto current = collection.begin();
        do
        {
            newCollection.push_back(selector(*current));
            current++;
        } while (current != collection.end());

        LinqObject linqObject(newCollection);
        return linqObject;
    }

    LinqObject where(std::function<bool(T)> predicate)
    {
        auto current = collection.begin();
        std::vector<T> newCollection;
        do
        {
            if (predicate(*current))
            {
                newCollection.push_back(*current);
            }
            current++;
        } while (current != collection.end());

        LinqObject linqObject(newCollection);
        return linqObject;
    }

    LinqObject orderBy(OrderType orderType = ASC)
    {
        algorithm::mergeSort(&collection, 0, collection.size() - 1, orderType);
        LinqObject linqObject(collection);
        return linqObject;
    }

    template<typename TKey>
    LinqObject orderBy(std::function<TKey(T)> orderFunction, OrderType orderType = ASC)
    {
        algorithm::mergeSort(&collection, 0, collection.size() - 1, orderFunction, orderType);
        LinqObject linqObject(collection);
        return linqObject;
    }

    template<typename TOther, typename TKey, typename TResult>
    LinqObject join(std::vector<TOther> other,
                    std::function<TKey(T)> innerKeySelector,
                    std::function<TKey(TOther)> outerKeySelector,
                    std::function<TResult(T,TOther)> resultSelector)
    {
        std::vector<TResult> result;

        auto currentInner = collection.begin();
        do
        {
            auto currentOther = other.begin();
            do
            {
                if (innerKeySelector(*currentInner) == outerKeySelector(*currentOther))
                {
                    result.push_back(resultSelector(*currentInner, *currentOther));
                }
                currentOther++;
            } while (currentOther != other.end());

            currentInner++;
        } while (currentInner != collection.end());

        LinqObject linqObject(result);
        return linqObject;
    }

    // bool methods

    bool all(std::function<bool(T)> predicate)
    {
        auto current = collection.begin();
        do
        {
            if (!predicate(*current))
            {
                return false;
            }
            current++;
        } while (current != collection.end());

        return true;
    }

    bool any(std::function<bool(T)> predicate)
    {
        auto current = collection.begin();
        do
        {
            if (predicate(*current))
            {
                return true;
            }
            current++;
        } while (current != collection.end());

        return false;
    }

    bool contains(std::vector<T> subCollection)
    {
        return algorithm::contains(&collection, collection.size(), &subCollection, subCollection.size());
    }

    bool contains(T element)
    {
        auto current = collection.begin();
        do
        {
            if (*current == element)
            {
                return true;
            }
            current++;
        } while (current != collection.end());

        return false;
    }

    // aggregate methods

    T sum()
    {
        T sum;
        auto current = collection.begin();
        do
        {
            sum += *current;
            current++;
        } while (current != collection.end());
        return sum;
    }

    template<typename TResult>
    TResult sum(std::function<TResult(T)> sumFunction)
    {
        TResult sum;
        auto current = collection.begin();
        do
        {
            sum += sumFunction(*current);
            current++;
        } while (current != collection.end());
        return sum;
    }

    template<typename TResult>
    TResult aggregate(std::function<TResult(TResult, T)> aggregateFunction)
    {
        TResult result;
        auto current = collection.begin();
        do
        {
            result = aggregateFunction(result, *current);
            current++;
        } while (current != collection.end());

        return result;
    }

    T min()
    {
        auto current = collection.begin();
        T min = *current;
        current++;
        if (current == collection.end()) return min;
        do
        {
            if (*current < min)
            {
                min = *current;
            }
            current++;
        } while (current != collection.end());

        return min;
    }

    template<typename TResult>
    TResult min(std::function<TResult(T)> minFunction)
    {
        auto current = collection.begin();
        TResult min = minFunction(*current);
        current++;
        if (current == collection.end()) return min;
        do
        {
            if (minFunction(*current) < min)
            {
                min = *current;
            }
            current++;
        } while (current != collection.end());

        return min;
    }

    T max()
    {
        auto current = collection.begin();
        T max = *current;
        current++;
        if (current == collection.end()) return max;
        do
        {
            if (*current > max)
            {
                max = *current;
            }
            current++;
        } while (current != collection.end());

        return max;
    }

    template<typename TResult>
    TResult max(std::function<TResult(T)> maxFunction)
    {
        auto current = collection.begin();
        TResult max = maxFunction(*current);
        current++;
        if (current == collection.end()) return max;
        do
        {
            if (maxFunction(*current) > max)
            {
                max = *current;
            }
            current++;
        } while (current != collection.end());

        return min;
    }

private:
    std::vector<T> collection;
};

template <typename T>
LinqObject<T> from(std::vector<T> collection)
{
    LinqObject linqObject(collection);
    return linqObject;
}

#endif