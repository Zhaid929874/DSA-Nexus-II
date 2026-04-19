#include<iostream>
using namespace std;

int main()
{

    int arr1[100], arr2[100], merged[200];
    int n1, n2, i, j, k;

    cout << "Enter size of first array: ";
    cin >> n1;

    cout << "Enter elements of first array: ";
    for(i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    cout << "Enter elements of second array: ";
    for(i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    // Merge process
    k = 0;

    for(i = 0; i < n1; i++)
    {
        merged[k++] = arr1[i];
    }

    for(j = 0; j < n2; j++)
    {
        merged[k++] = arr2[j];
    }

    cout << "Merged Array: ";
    for(i = 0; i < k; i++)
    {
        cout << merged[i] << " ";
    }

    return 0;
}
