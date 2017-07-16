#include <cstdlib>
#include <iostream>

// avg performance O(nlogn)

void merge(int* lArr, int lArrSize, int* rArr, int rArrSize, int* sortedArr) {
    int indexLArr = 0;
    int indexRArr = 0;
    int indexSortedArr = 0;

    while(indexLArr < lArrSize && indexRArr < rArrSize) {
        if (lArr[indexLArr] < rArr[indexRArr]) {
            sortedArr[indexSortedArr] = lArr[indexLArr];
            indexLArr++;
            indexSortedArr++;
        } else if (lArr[indexLArr] > rArr[indexRArr]){
            sortedArr[indexSortedArr] = rArr[indexRArr];
            indexRArr++;
            indexSortedArr++;
        } else {
            sortedArr[indexSortedArr] = lArr[indexLArr];
            indexSortedArr++;
            sortedArr[indexSortedArr] = lArr[indexLArr];
            indexSortedArr++;
            indexLArr++;
            indexRArr++;
        }
    }

    while(indexLArr < lArrSize) {
        sortedArr[indexSortedArr++] = lArr[indexLArr++];
    }

    while(indexRArr < rArrSize) {
        sortedArr[indexSortedArr] = rArr[indexRArr];
        indexSortedArr++;
        indexRArr++;

    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "lArr to be merged: " << std::endl;
    for(int i = 0; i < lArrSize; i++) {
        std::cout << lArr[i] << std::endl;
    }

    std::cout << "rArr to be merged: " << std::endl;
    for(int i = 0; i < rArrSize; i++) {
        std::cout << rArr[i] << std::endl;
    }

    std::cout << "sortedArr: " << std::endl;
    for(int i = 0; i < lArrSize + rArrSize; i++) {
        std::cout << sortedArr[i] << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;

};


void mergeSort(int *arr, int size) {
    if  (size < 2) {
        return;
    } else {
        int mid = size/2;
        int lArr[mid];
        int rArr[size-mid];

        // copy arr to lArr and rArr
        for(int i = 0; i < mid; i++) {
            lArr[i] = arr[i];
        }
        for(int i = mid; i< size; i++) {
            rArr[i-mid] = arr[i];
        }

        mergeSort(lArr, mid);
        // this function will return immediately when mid = 1
        // recursion will stop

        mergeSort(rArr, size-mid);
        // this function will return immediately when size-mid = 1
        // recursion will stop

        // lArr and rArr are partitions of arr
        merge(lArr, mid, rArr, size-mid, arr);
        // when this function returns, the values in arr will be sorted
    }

}

/* Driver program to test above functions */
int main()
{
    int arr[8] = {2,4,1,6,8,5,3,7};
    mergeSort(arr, 8);

}
