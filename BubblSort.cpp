#include <vector>
#include <iostream>

template <typename RandomIt, class T = typename std::iterator_traits<RandomIt>::value_type>
void BubbleSort(RandomIt first, RandomIt last){
    for(RandomIt fi = first; fi != last; ++fi) {
        for(RandomIt it = first; it != last - (fi - first) - 1; ++it) {
            if(*it > *std::next(it)) {
                std::swap(*it, *std::next(it));
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