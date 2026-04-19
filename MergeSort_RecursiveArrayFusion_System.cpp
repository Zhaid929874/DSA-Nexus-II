#include<iostream>
using namespace std;

void mergearray(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];

    // copy left part
    for(int i=0; i<n1; i++)
        arr1[i] = arr[left + i];

    // copy right part
    for(int j=0; j<n2; j++)
        arr2[j] = arr[mid + 1 + j];

    int i=0, j=0, k=left;

    // merging
    while(i<n1 && j<n2) {
        if(arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // copy remaining arr1
    while(i<n1) {
        arr[k] = arr1[i];
        i++; k++;
    }

    // copy remaining arr2
    while(j<n2) {
        arr[k] = arr2[j];
        j++; k++;
    }
}

void dividearray(int arr[], int left, int right) {
    if(left >= right) return;

    int mid = left + (right-left)/2;

    dividearray(arr, left, mid);
    dividearray(arr, mid+1, right);

    mergearray(arr, left, mid, right);
}

int main() {
    int arr[] = {5, 4, 6, 7, 1, 63, 5, 7, 8, 93, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    dividearray(arr, 0, n-1);

    cout << "Sorted Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
