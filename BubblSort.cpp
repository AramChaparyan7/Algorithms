#include <vector>
#include <iostream>

template <typename ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type>
void BubbleSort(ForwardIt first, ForwardIt last){
    bool swaped = true;
    while(swaped) {
        swaped = false;
        for(ForwardIt it = first; std::next(it) != last; ++it) {
            if(*it > *std::next(it)) {
                std::swap(*it, *std::next(it));
                swaped = true;
            }
        }
    }
}

int main() {
    std::vector<int> vec{1, 8, 9, 6, 65, 61, 5 ,77};
    BubbleSort(vec.begin(), vec.end());
    for(int &i : vec) {
        std::cout << i << " ";
    }
    return 0;
}