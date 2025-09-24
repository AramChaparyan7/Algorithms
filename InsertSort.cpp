#include <iostream>
#include <vector>

template <class BidirIt>
void InsertionSort(BidirIt first, BidirIt last) {  
    for(BidirIt i = std::next(first); i != last; ++i) {
    typename std::iterator_traits<BidirIt>::value_type val = *i;
        BidirIt j = i; 
        while(j != first && *std::prev(j) > val) {
            *j = *std::prev(j);
            --j;
        }
        *j = val;
    }
}

int main() {
    std::vector<int> vec{5, 8, 4, 1, 18, 9, 6, 3};
    InsertionSort(vec.begin(), vec.end());
    for(int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}