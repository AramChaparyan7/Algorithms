#include <iostream>
#include <vector>

template <typename ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type>
ForwardIt LowerBound(ForwardIt left, ForwardIt right, const T& val) {
    while(left != right) {
        ForwardIt mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        if(*mid < val) {
            left = std::next(mid);
        }
        else {
            right = mid;
        }
    }
    return left;
}

template <typename ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type>
ForwardIt UpperBound(ForwardIt left, ForwardIt right, const T& val) {
    while(left != right) {
        ForwardIt mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        if(*mid <= val) {
            left = std::next(mid);
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main() {
    std::vector<int> vec{0, 1, 3, 4, 5};
    std::cout << *LowerBound(vec.begin(), vec.end(), 2) << std::endl;
    std::cout << *UpperBound(vec.begin(), vec.end(), 2) << std::endl;
    return 0;
}