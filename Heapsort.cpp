#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements (N): ";
    cin >> n;

    vector<int> arr(n);
    int choice;
    cout << "Enter 1 to manually enter elements, 2 to generate random elements: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    } else if (choice == 2) {
        unsigned seed = steady_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);

        uniform_int_distribution<int> distribution(1, 5000); 
        for (int i = 0; i < n; i++) {
            arr[i] = distribution(generator);
        }
    } else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    
    auto start = high_resolution_clock::now();
    heapSort(arr);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTime taken by function: " << duration.count() << " nanoseconds" << endl;

    return 0;
}
