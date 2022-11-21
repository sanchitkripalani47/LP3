#include<iostream>
#include<time.h>
using namespace std;

/*
Quick Sort Algorithm (inplace sorting)
Best			Average				Worst
Ω(nlog(n))     Θ(nlog(n))  		   O(n^2)
APPLICATIONS: used when there is space constrain
Step 1 − Make any element as pivot
Step 2 − Partition the array on the basis of pivot
Step 3 − Apply quick sort on left partition recursively
Step 4 − Apply quick sort on right partition recursively
*/

int partition(int arr[], int s, int e) {
    int pivot = arr[e];
    int pIndex = s;

    for (int i=s; i<e; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[e], arr[pIndex]);
    return pIndex;
}

int partition_r(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high-low);

    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

void Quicksort(int arr[], int s, int e) {
    if (s<e) {
        int p = partition(arr, s, e);
        Quicksort(arr, s, p-1); // sort left side
        Quicksort(arr, p+1, e); // sort right side
    } 
}

int main() {

    int n = 5;
    int arr[n] = {4,1,3,2,5};

    Quicksort(arr, 0, n-1);

    for (auto it: arr) cout << it << " ";
    cout << "\n";

    return 0;
}