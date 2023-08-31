// The implementation of Merge Sort Algorithm in C++

#include <iostream>
#include <ctime>
#include <chrono>
#include <stdio.h>
#include  <fstream>
#include  <string>
#include <vector>

using namespace std;
using namespace std::chrono;

// Insertion Sort
void insertionSort(int A[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;
        
        
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

// Merge Sort
void merge(int A[], int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;

    // Create temporary arrays to store the left and right subarrays
    int* new_LeftArray = new int[nL];
    int* new_RightArray = new int[nR];

    // Copy data to temporary arrays
    for (int i = 0; i < nL; ++i) {
        new_LeftArray[i] = A[p + i];
    }
    for (int j = 0; j < nR; ++j) {
        new_RightArray[j] = A[q + 1 + j];
    }

    // Merge the temporary arrays back into A[p..r]
    int i = 0, j = 0, k = p;
    //i indexes the smallest remaining element in the new_LeftArray
    //j indexes the smallest element in the new_RightArray
    //k indexes the position in A to fill
    while (i < nL && j < nR) {
        if (new_LeftArray[i] <= new_RightArray[j]) {
            A[k] = new_LeftArray[i];
            ++i;
        }
        else {
            A[k] = new_RightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of new_LeftArray[], if there are any
    while (i < nL) {
        A[k] = new_LeftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of new_RightArray[], if there are any
    while (j < nR) {
        A[k] = new_RightArray[j];
        ++j;
        ++k;
    }

    // Free the memory allocated for new_LeftArray[] and new_RightArray[]
    delete[] new_LeftArray;
    delete[] new_RightArray;
}

void mergeSort(int A[], int p, int r) {
    if (p >= r) {
        return;
    }
    else {
        int q = p + (r - p) / 2;
        mergeSort(A, p, q); // Sort left half
        mergeSort(A, q + 1, r); // Sort right half
        merge(A, p, q, r); // Merge the two sorted halves

    }
}




// Test Cases
void printTestedArray(int A[], int n) {
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

bool testIfSorted(int A[], int n) {
    for (int i = 1; i < n; ++i) {
        if (A[i-1] <= A[i])
            return true;
    }
    return false;
}


int main() {
    int testArray[] = { 1, 9, 6, 3, 1, 2, 1, 1, 1, 6, 5, 8 };
    int L1[] = { 3, 1, 5, 10, 8, 7 };
    int L2[] = {5, 2, 9, 6, 1, 2};
    const int n = sizeof(testArray) / sizeof(testArray[0]);
    const int n2 = sizeof(L1) / sizeof(L1[0]);
    // Test Insertion Sort
    int insertionSorted[n];
    int insertionSortedL1[n2];
    int insertionSortedL2[n2];
    for (int i = 0; i < n; ++i)
        insertionSorted[i] = testArray[i];
    insertionSort(insertionSorted, n);
    cout << "Insertion Sort is applied to array [196312111658],this algorithm transforms array to: ";
    printTestedArray(insertionSorted, n);
    cout << "Is sorted: " << (testIfSorted(insertionSorted, n) ? "Yes" : "No") << endl;

    for (int i = 0; i < n2; ++i)
        insertionSortedL1[i] = L1[i];
    insertionSort(insertionSortedL1, n2);
    cout << "Insertion Sort is applied to array [3, 1, 5, 10, 8, 7], this algorithm transforms array to: ";
    printTestedArray(insertionSortedL1, n2);
    cout << "Is sorted: " << (testIfSorted(insertionSortedL1, n2) ? "Yes" : "No") << endl;

    for (int i = 0; i < n2; ++i)
        insertionSortedL2[i] = L2[i];
    insertionSort(insertionSortedL2, n2);
    cout << "Insertion Sort is applied to array [5, 2, 9, 6, 1, 2], this algorithm transforms array to: ";
    printTestedArray(insertionSortedL2, n2);
    cout << "Is sorted: " << (testIfSorted(insertionSortedL2, n2) ? "Yes" : "No") << endl;

    // Test Merge Sort
    int mergeSorted[n];
    for (int i = 0; i < n; ++i)
        mergeSorted[i] = testArray[i];
    mergeSort(mergeSorted, 0, n - 1);
    cout << "MergeSort is applied to array [196312111658], this algorithm transforms array to:" << endl;
    printTestedArray(mergeSorted, n);
    cout << "Is sorted: " << (testIfSorted(mergeSorted, n) ? "Yes" : "No") << endl;

    int mergeSortedL1[n2];
    for (int i = 0; i < n2; ++i)
        mergeSortedL1[i] = L1[i];
    mergeSort(mergeSortedL1, 0, n2 - 1);
    cout << "MergeSort is applied to array [3, 1, 5, 10, 8, 7], this algorithm transforms array to:";
    printTestedArray(mergeSortedL1, n2);
    cout << "Is sorted: " << (testIfSorted(mergeSortedL1, n2) ? "Yes" : "No") << endl;

    int mergeSortedL2[n2];
    for (int i = 0; i < n2; ++i)
        mergeSortedL2[i] = L2[i];
    mergeSort(mergeSortedL2, 0, n2 - 1);
    cout << "MergeSort is applied to array [5, 2, 9, 6, 1, 2], this algorithm transforms array to:";
    printTestedArray(mergeSortedL2, n2);
    cout << "Is sorted: " << (testIfSorted(mergeSortedL2, n2) ? "Yes" : "No") << endl;


    ifstream input_file("test-10000-1-problem"); // open the input file
    vector<int> integers; // create a vector to store the integers

    int number;
    while (input_file >> number) { // read integers from the file
        integers.push_back(number); // add the integer to the vector
    }

    input_file.close(); // close the input file

    // convert the vector to an array
    int size = integers.size();
    int* Insertion_array = new int[size];
    int* Merge_array = new int[size];
    for (int i = 0; i < size; i++) {
        Insertion_array[i] = integers[i];
    }

    for (int i = 0; i < size; i++) {
        Merge_array[i] = integers[i];
    }

    // print the unsorted original array
    /*std::cout << "Try to print unsorted original array" << endl;
    for (int i = 0; i < size; i++) {
        std::cout << Insertion_array[i] << " ";
    }*/
    std::cout << "" << endl;

    auto startTime = high_resolution_clock::now();
    insertionSort(Insertion_array, size);
    
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime).count();
    cout << "Insertion Sort took " << duration << " milliseconds." << endl;

    auto startTimeMerge = high_resolution_clock::now();
    mergeSort(Merge_array, 0,size-1);

    auto endTimeMerge = high_resolution_clock::now();
    auto durationMerge = duration_cast<milliseconds>(endTimeMerge - startTimeMerge).count();
    cout << "Merge Sort took " << durationMerge << " milliseconds." << endl;
    

    std::cout << "Try to print the array after Insert sort have been applied" << endl;

    for (int i = 0; i < size; i++) {
        std::cout << Insertion_array[i] << " ";
    }
    std::cout << "Try to print the array after Merge sort have been applied" << endl;

    for (int i = 0; i < size; i++) {
        std::cout << Merge_array[i] << " ";
    }
    // free the memory allocated for the array
    delete[] Insertion_array;
    delete[] Merge_array;
    return 0;

}
