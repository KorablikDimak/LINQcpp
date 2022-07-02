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

    std::vector<T> select()
    {
        return collection;
    }

    std::vector<T> select(std::function<T(T)> selector)
    {
        auto current = collection.begin();
        do
        {
            *current = selector(*current);
            current++;
        } while (current != collection.end());
        return collection;
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

    T sum()
    {
        if (collection.empty()) throw std::domain_error("collection is empty");
        T sum = collection[0];
        for (int i = 1; i < collection.size(); ++i)
        {
            sum += collection[i];
        }
        return sum;
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