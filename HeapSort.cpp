#include <iostream>
#include <vector>

template <typename RandomIt>
void heapify(RandomIt first, RandomIt last, RandomIt it) {
    RandomIt index = it;
    RandomIt l = first + (it - first) * 2 + 1;
    RandomIt r = l + 1;
    if(l < last && *index < *l) {
        index = l;
    }
    if(r < last && *index < *r) {
        index = r;
    }
    if(index == it) {
        return;
    }
    std::iter_swap(it, index);
    heapify(first, last, index);
}

template <typename RandomIt>
void BuildMaxHeap(RandomIt first, RandomIt last) {
    for(RandomIt it = first + (last - first )/2 - 1; it >= first; --it) {
        heapify(first, last, it);
    }
}

template <typename RandomIt>
void HeapSort(RandomIt first, RandomIt last) {
    BuildMaxHeap(first, last);
    RandomIt it = last - 1;
    while(it != first) {
        std::iter_swap(first, it);
        heapify(first, it, first);
        --it;
    }
}

int main() {
    std::vector<int> v{4, 9, 3, 8, 10, 48};
    HeapSort(v.begin(), v.end());
    for(int i : v) {
        std::cout << i << " ";
    }

    return 0;
}