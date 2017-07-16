#include <iostream>
#include <utility>

// avg performance O(n2)

template<typename T, int N>
int selectionSort(T (&arr) [N]) {
    int iterTimes = 0;

    int startIndex = 0;

    while (startIndex < N-1) {
        iterTimes++;

        int minIndex = startIndex;
        int min = arr[minIndex];

        for(int j = minIndex + 1; j < N; j++) {
            iterTimes++;
            if (arr[j] <  min) {
                minIndex = j;
                min = arr[j];
            }
        }

        std::swap(arr[startIndex], arr[minIndex]);

        startIndex++;
    }

    return iterTimes;

};

int main() {
    int data[] = {2, 4, 40, 2, 1, 100, 7};

    int iterTimes = selectionSort(data);

    for(auto x: data) {
        std::cout << x << std::endl;
    }


}