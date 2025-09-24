#include <iostream>
#include <vector>

template <typename It>
void print(It i, It j) {
    std::cout << "start printing\n";
    while(i != j) {
        std::cout << *i << " ";
        ++i;
    } 
    std::cout << "\nend printing\n";
}

template <class BidirIt>
void Merge(BidirIt left1, BidirIt right1, BidirIt left2, BidirIt right2) {
    std::vector<typename std::iterator_traits<BidirIt>::value_type> arr;
    arr.resize(std::distance(left1, right1) + std::distance(left2, right2));
    BidirIt dest = left1;
    int c = 0;
    while(left1 != right1 && left2 != right2) {
        arr[c++] = *left1 < *left2 ? *left1 : *left2;
        *left1 < *left2 ? ++left1 : ++left2;
    }
    if(left1 == right1) {
        while(left2 != right2) {
            arr[c++] = *left2;
            ++left2;
        }
    } 
    else {
        while(left1 != right1) {
            arr[c++] = *left1;
            ++left1;
        }
    }
    for(int i = 0; i < arr.size(); ++i, ++dest) {
        *dest = arr[i];
    }
} 

template <class BidirIt>
void MergeSort(BidirIt first, BidirIt last) {
    if(std::next(first) == last ) {
        return;
    }
    BidirIt mid = first;
    std::advance(mid, std::distance(first, last) / 2);
    //print(first, mid);
    MergeSort(first, mid);
    //print(mid, last);
    MergeSort(mid, last);
    Merge(first, mid, mid, last);
}

int main() {
    std::vector<int> vec{5, 8, 4, 1, 18, 9, 6, 3};
    MergeSort(vec.begin(), vec.end());
    print(vec.begin(), vec.end());
    return 0;
}