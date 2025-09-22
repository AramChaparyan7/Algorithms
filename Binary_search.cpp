#include <vector>
#include <iostream>

template <typename ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type>
bool BinarySearch(ForwardIt fisrt, ForwardIt last, const T& val) {
    ForwardIt left = fisrt;
    ForwardIt right = last;
    while(left != std::next(right)) {
        ForwardIt mid = left;
        std::advance(mid, std::distance(left, right)/2);
        if(*mid == val) {
            return true;
        } 
        if(*mid > val) {
            right = std::prev(mid);
        }
        else{
            left = std::next(mid);
        }
    }
    return false;
}

template <typename ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type>
bool BinarySearchRec(ForwardIt left, ForwardIt right, const T& val) {
    ForwardIt mid = left;
    std::advance(mid, std::distance(left, right)/2);
    if(*mid == val) {
        return true;
    }
    if(*mid < val) {
        return BinarySearchRec(left + 1, right,  val);
    }
    if(*mid > val) {
        return BinarySearchRec(left, right - 1,  val);
    }
    return - 1;
}

int main() {
    std::vector<int>  vec{1, 5, 6, 9, 15, 20};
    std::cout << BinarySearch(vec.begin(), vec.end(), 6) << std::endl;
    std::cout << BinarySearchRec(vec.begin(), vec.end(), 9) << std::endl;
    return 0;
}