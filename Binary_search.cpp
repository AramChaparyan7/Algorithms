#include <vector>
#include <iostream>
#include <list>

template <typename BidirIt, class T = typename std::iterator_traits<BidirIt>::value_type>
bool BinarySearch(BidirIt first, BidirIt last, const T& val) {
    BidirIt left = first;
    BidirIt right = last;
    while(left != right) {
        BidirIt mid = left;
        std::advance(mid, std::distance(left, right)/2);
        if(*mid == val) {
            return true;
        } 
        if(*mid > val) {
            right = mid;
        }
        else{
            left = std::next(mid);
        }
    }
    return false;
}

template <typename BidirIt, class T = typename std::iterator_traits<BidirIt>::value_type>
bool BinarySearchRec(BidirIt left, BidirIt right, const T& val) {
    BidirIt mid = left;
    std::advance(mid, std::distance(left, right)/2);
    if(*mid == val) {
        return true;
    }
    if(left==right) {
        return false;
    }
    if(*mid < val) {
        return BinarySearchRec(std::next(left), right,  val);
    }
    if(*mid > val) {
        return BinarySearchRec(left, right,  val);
    }
    return 0;
}

int main() {
    std::vector<int>  vec{1, 5, 6, 9, 15, 20};
    std::list<int>  ls{1, 5, 6, 7, 9, 15, 20};
    std::cout << BinarySearch(vec.begin(), vec.end(), 6) << std::endl;
    std::cout << BinarySearchRec(vec.begin(), vec.end(), 9) << std::endl;
    std::cout << BinarySearch(ls.begin(), ls.end(), 7) << std::endl;
    return 0;
}