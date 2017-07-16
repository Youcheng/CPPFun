#include <iostream>
#include <utility>

// avg performance O(n2)

template<typename T, int N>
int bubbleSort(T (&arr) [N]) {
    int iterTimes = 0;
    int endIndexForCheck = N - 2;

    while(endIndexForCheck > 1) {
        iterTimes++;
        for (int i =0; i <= endIndexForCheck; i++) {
            iterTimes++;
            if (arr[i] > arr[i+1]) std::swap(arr[i], arr[i+1]);
        }
        endIndexForCheck--;

    }

    return iterTimes;
};

int main() {
    int data[] = {2, 4, 40, 2, 1, 100, 7};
    int iterTimes = bubbleSort(data);
    for(auto x: data) {
        std::cout << x << std::endl;
    }

    std::cout << "iterTimes " << iterTimes << std::endl;
}



