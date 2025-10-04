#include <iostream>
#include <vector>
#include <cstdlib>

template <typename RandomIt>
RandomIt leftpartition(RandomIt first, RandomIt last) {
    RandomIt left = first + 1;
    RandomIt pivot = first;
    RandomIt right = last - 1;
    while(true) {
        while(left < last && *left < *pivot) {
            ++left;
        }
        while(right > pivot && *right > *pivot) {
            --right;
        }
        if(left > right) {
            break;
        }
        std::swap(*left, *right);
        ++left;
        --right;
    }
    std::swap(*right, *pivot);
    return right;
}

template <typename RandomIt>
RandomIt rightpartition(RandomIt first, RandomIt last) {
    RandomIt left = first;
    RandomIt pivot = last - 1;
    RandomIt right = pivot - 1;
    while(true) {
        while(*left < *pivot) {
            ++left;
        }
        while(*right > *pivot) {
            --right;
        }
        if(left > right) {
            break;
        }
        std::swap(*left, *right);
        ++left;
        --right;
    }
    std::swap(*left, *pivot);
    return left;
}

template <typename RandomIt>
void RightQuickSort(RandomIt first, RandomIt last) {
    if(last - first < 2) {
        return;
    }
    RandomIt pivot = rightpartition(first, last);
    RightQuickSort(first, pivot);
    RightQuickSort(pivot + 1, last);
}

template <typename RandomIt>
void LeftQuickSort(RandomIt first, RandomIt last) {
    if(last - first < 2) {
        return;
    }
    RandomIt pivot = leftpartition(first, last);
    LeftQuickSort(first, pivot);
    LeftQuickSort(pivot + 1, last);
}

template <typename RandomIt>
void RandomQuickSort(RandomIt first, RandomIt last) {
    if(last - first < 2) {
        return;
    }
    RandomIt random = first + rand() % (last - first);
    std::iter_swap(random, last - 1);
    RandomIt pivot = rightpartition(first, last);
    RandomQuickSort(first, pivot);
    RandomQuickSort(pivot + 1, last);
}

template <typename RandomIt>
void MedianQuickSort(RandomIt first, RandomIt last) {
    if(last - first < 2) {
        return;
    }
    RandomIt mid = first + (last - first)/2;
    if (*mid < *first) std::swap(*first, *mid);
    if (*(last - 1) < *first) std::swap(*first, *(last - 1));
    if (*(last - 1) < *mid) std::swap(*mid, *(last - 1));
    if(mid < last - 2) std::swap(*mid, *(last - 2));
    RandomIt pivot = rightpartition(first, last - 1);
    MedianQuickSort(first, pivot);
    MedianQuickSort(pivot + 1, last);
}

int main() {
    std::vector<int> v1{5, 8, 1, 8, 9, 7};
    LeftQuickSort(v1.begin(), v1.end());
    for(int i : v1) {
        std::cout << i << " ";
    }
    std::cout <<std::endl;

    std::vector<int> v2{5, 8, 1, 8, 9, 7};
    RightQuickSort(v2.begin(), v2.end());
    for(int i : v2) {
    std::cout << i << " ";
    }
    std::cout <<std::endl;

    std::vector<int> v3{5, 8, 1, 8, 9, 7};
    RandomQuickSort(v3.begin(), v3.end());
    for(int i : v3) {
        std::cout << i << " ";
    }
    std::cout <<std::endl;

    std::vector<int> v4{5, 8, 1, 8, 9, 7};
    MedianQuickSort(v4.begin(), v4.end());
    for(int i : v4) {
        std::cout << i << " ";
    }
    std::cout <<std::endl;
    return 0;
}