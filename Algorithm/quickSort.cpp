#include <iostream>
#include <utility>

// avg performance O(nlogn)

int iterTimes = 0;

int findPivotIndex(int *a, int lIndex, int rIndex) {
    int pIndex = lIndex;
    bool useLIndex = false;
    bool useRIndex = true;

    while (lIndex < rIndex) {
        iterTimes++;

        if (useRIndex) {
            if (a[rIndex] < a[pIndex]) {
                std::swap(a[rIndex], a[pIndex]);
                pIndex = rIndex;
                useRIndex = false;
                useLIndex = true;
            } else {
                rIndex--;
            }
        }

        if (useLIndex) {
            if (a[lIndex] > a[pIndex]) {
                std::swap(a[lIndex], a[pIndex]);
                pIndex = lIndex;
                useRIndex = true;
                useLIndex = false;
            } else {
                lIndex++;
            }
        }
    }

    return pIndex;
}


int quickSort(int *a, int start, int end) {
    if(start < end) {
        int pIndex = findPivotIndex(a, start, end);
        quickSort(a, start, pIndex-1);
        quickSort(a, pIndex+1, end);
    }

    return iterTimes;

}

int main() {

    int arr[7] = {2, 4, 40, 2, 1, 100, 7};
    int iterTimes = quickSort(arr, 0, 6);

    for (auto x: arr) {
        std::cout << x << " " << std::endl;
    }

    std::cout << "iterTimes " << iterTimes << std::endl;

}
