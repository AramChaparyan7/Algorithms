#include <vector>
#include <iostream>

template <typename ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type>
void SelectionSort(ForwardIt fisrt, ForwardIt last){
    for(ForwardIt it = fisrt; it != last; ++it) {
        ForwardIt min = it;
        for(ForwardIt jt = std::next(it); jt != last; ++jt) {
            if(*jt < *min) {
                min = jt;
            }
        }
        std::swap(*it, *min);
    }
}

int main() {
    std::vector<int> vec{1, 8, 9, 6, 65, 61, 5 ,77};
    SelectionSort(vec.begin(), vec.end());
    for(int &i : vec) {
        std::cout << i << " ";
    }
    return 0;
}