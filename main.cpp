#include <iostream>
#include <vector>

void printVector(const std::vector<int>& v)
{
    for (int i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
}

void insertionSortNondecr(std::vector<int>& v)
{
    int key;
    for (int j = 1; j < v.size(); ++j)
    {
        key = v[j];
        int i = j - 1;
        while(i >= 0 and v[i] > key)
        {
            v[i + 1] = v[i];
            --i;
        }
        v[i + 1] = key;
    }
}

void insertionSortNonincr(std::vector<int>& v)
{
    int key;
    for(int j = 1; j < v.size(); ++j)
    {
        key = v[j];
        int i = j - 1;
        while(i >= 0 and v[i] < key)
        {
            v[i + 1] = v[i];
            --i;
        }
        v[i + 1] = key;
    }
}

int linearSearch(const std::vector<int> v, int val)
{
    for(int i = 0; i < v.size(); ++i)
    {
        if (v[i] == val)
            return i;
    }
    return -1;
}

std::vector<int> addBinary(const std::vector<int>& v1, const std::vector<int>& v2)
{
    std::vector<int> result(v1.size() + 1, 0);
    for(int i = v1.size() - 1; i >= 0; --i)
    {
        result[i + 1] += v1[i] + v2[i];
        if (result[i + 1] > 1)
        {
            ++result[i];
            result[i + 1] %= 2;
        }
    }
    return result;
}

void selectionSort(std::vector<int>& v)
{
    for(int j = 0; j < v.size() - 1; ++j)
    {
        int index = j;
        for (int i = j; i < v.size(); ++i)
        {
            if (v[index] > v[i])
                index = i;
        }
        std::swap(v[j], v[index]);
    }
}

void merge(std::vector<int>& v, int p, int q, int r)
{
    std::vector<int> left;
    std::vector<int> right;
    for(int i = p; i <= q; ++i)
        left.push_back(v[i]);
    for(int i = q + 1; i <= r; ++i)
        right.push_back(v[i]);
    int i = 0, j = 0;
    for(int index = p; index <= r; ++index)
    {
        if (i > q - p)
        {
            v[index] = right[j];
            ++j;
        }
        else if (j > r - q - 1)
        {
            v[index] = left[i];
            ++i;
        }
        else if (left[i] < right[j])
        {
            v[index] = left[i];
            ++i;
        }
        else
        {
            v[index] = right[j];
            ++j;
        }
    }
}

void mergeSort(std::vector<int>& v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

int binarySearch(std::vector<int>& v, int value, int first, int end)
{
    if (first > end)
    {
        return -1;
    }
    else
    {
        int index = (first + end) / 2;
        if (v[index] > value)
            return binarySearch(v, value, first, index - 1);
        else if (v[index] < value)
            return binarySearch(v, value, index + 1, end);
        else
            return index;
    }
}

int main()
{
    std::vector<int> test1 = {1, 3, 5, 4, 2};
    std::vector<int> test2 = {1, 0, 1, 1, 1};
    std::vector<int> test3 = {1, 0, 0, 0, 1};
    std::vector<int> test4 = {3, 1, 2, 3, 7, 10, 6, 5, 4,};

    //insertion sort test (1)
    insertionSortNondecr(test1);
    insertionSortNonincr(test1);
    printVector(test1);

    //linear search test (1)
    std::cout << linearSearch(test1, 3) << std::endl;
    std::cout << linearSearch(test1, 10) << std::endl;

    //binary addition test (2, 3)
    printVector(addBinary(test2, test3));

    //selection sort test (1)
    selectionSort(test1);
    printVector(test1);

    //merge sort test (4)
    merge(test4, 5, 6, 7);
    printVector(test4);
    mergeSort(test4, 0, 8);
    printVector(test4);

    //binary search test (4)
    std::cout << binarySearch(test4, 9, 0, 8);

    return 0;
}
