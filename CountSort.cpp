#include <iostream>
#include <vector>
#include <algorithm>

template <typename ForwardIt>
void CountSort(ForwardIt first, ForwardIt last) {
    int max = *std::max_element(first, last);
    int min = *std::min_element(first, last);
    using T = typename std::iterator_traits<ForwardIt>::value_type;
    T* freq = new T[max - min + 1];
    for(ForwardIt it = first; it != last; ++it) {
        ++freq[*it - min];
    }
    int i = 0;
    for(int i = 0; i <= max - min; ++i) {
        while(freq[i]--) {
            *(first+i++) = i + min;
        }
    }
}

template <typename BidirIt>
void StableCountSort(BidirIt first, BidirIt last) {
    int max = *std::max_element(first, last);
    int min = *std::min_element(first, last);
    using T = typename std::iterator_traits<BidirIt>::value_type;
    T* freq = new T[max - min + 1]();
    for(BidirIt it = first; it != last; ++it) {
        ++freq[*it - min];
    }
    for(int i = 1; i <= max- min; ++i) {
        freq[i] += freq[i - 1];
    }
    int i = 0;
    T* out = new T[std::distance(first, last)];
    for(BidirIt it = std::prev(last); it != std::prev(first); --it, ++i) {
        int pos = freq[*it - min];
        out[pos - 1] = *it;
        --freq[*it - min];
    }
    i = 0;
    for(BidirIt it = first; it != last; ++it, ++i) {
        *it = out[i];
    }
    delete[] freq;
    delete[] out;
}

int main() {
    std::vector<int>  v{5, 4, 3, 2, 1};
    CountSort(v.begin(), v.end());
    for(int& i : v) {
        std::cout << i << " ";
    }
    std::vector<int>  v1{5, 4, 3, 3, 2, 2};
    StableCountSort(v1.begin(), v1.end());
    std::cout << "\nStable ";
    for(int& i : v1) {
        std::cout << i << " ";
    }
    return 0;
}