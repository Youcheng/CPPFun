// complexity O( log2(N) )

#include <algorithm>
#include <iostream>

template<typename T, int N>
int binarySearch(T (&a) [N], T searchValue) {
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == searchValue) {
            return mid;
        } else if (a[mid] < searchValue) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
};

int main() {

    int arr[] = {4, 6, 19, 25, 30, 45, 66};
    int target = 66;
    int index = binarySearch(arr, target);

    if (index == -1 ) {
        std::cout << target << " is not found" << std::endl;
    } else if (index >= 0 ) {
        std::cout << "index is " << index << std::endl;
    } else {
        std::cout << "should not be here" << std::endl;
    }
}