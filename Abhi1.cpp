#include <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
int smallest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && a[left] < a[smallest])
    smallest = left;
if (right < n && a[right] < a[smallest])
    smallest = right;
if (smallest != i) {
        int temp = a[i];
a[i] = a[smallest];
    a[smallest] = temp;

    heapify(a, n, smallest);
    }
}

void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}
int kthSmallest(int a[], int n, int k)
{
    heapSort(a, n);
    return a[k - 1];
}

int main()
{
    int a[] = {35, 12, 24, 56, 23, 71, 83};
    int n = 5;
    int k = 6;
    cout << "The " << k << "th smallest element is: " << kthSmallest(a, n, k) << endl;
    return 0;
}
