#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
  int N = arr.size(); // Find size of array

  // Loop across the array
  for (int step = 0; step < N - 1; step++) { // O(n)

    // Loop for comparing array elements
    for (int i = 0; i < N - step - 1; i++) { // O(n)

      // Compare adjacent elements and swap if its in the wrong order
      if (arr[i] > arr[i + 1]) { // O(1)

        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }
} // O(n) * O(n) * O(1)
// = O(n^2)

void merge(vector<int>& arr, int left, int mid, int right) { // O(n)
  // Find sizes of each arrays
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temp vectors
  vector<int> left_arr(n1), right_arr(n2);

  // Copy data to temp vectors
  for (int i = 0; i < n1; i++)
    left_arr[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    right_arr[j] = arr[mid + 1 + j];

  int i = 0, j = 0;
  int k = left;

  // Merge the left and right vectors
  while (i < n1 && j < n2) {
    if (left_arr[i] <= right_arr[j]) {
      arr[k] = left_arr[i];
      i++;
    } else {
      arr[k] = right_arr[j];
      j++;
    }
    k++;
  }

  // Copy any remaining elements in the left array
  while (i < n1) {
      arr[k] = left_arr[i];
      i++;
      k++;
  }

  // Copy any remaining elements in the right array
  while (j < n2) {
      arr[k] = right_arr[j];
      j++;
      k++;
  }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2; // Calculate middle of array // O(1)

    mergeSort(arr, left, mid); // Recur down the left array // O(log n)
    mergeSort(arr, mid + 1, right); // Recur down the right array // O(log n)
    merge(arr, left, mid, right); // Merge the left and right arrays // O(n)
} // O(1) * O(log n) * O(log n) * O(n)
// = O(log n) * O(n)
// = O(n log n)

// print array
void printArray(vector<int>& arr) {
  int size = arr.size();

  for (int i = 0; i < size; i++) {
    cout << "  " << arr[i];
  }
  cout << endl;
}

// Main code
int main() {
  // Initialize variables
  int N;
  int add_element;
  vector<int> arr_bubble;
  vector<int> arr_merge;

  cout << "Number of Deliveries to be made: ";
  cin >> N; // Get N from user input
  cout << endl;

  // Build an array to be sorted from user input
  for (int i = 0; i < N; i++) {
    cout << "Enter minutes needed to make Delivery " << i + 1 << ": ";
    cin >> add_element;

    arr_bubble.push_back(add_element);
    arr_merge.push_back(add_element);
  }

  cout << endl;
  cout << "Array of Delivery Times (in minutes):" << endl;
  printArray(arr_bubble); // Display array before being sorted
  cout << endl;

  // Sort the array via the 2 algorithms
  bubbleSort(arr_bubble);
  mergeSort(arr_merge, 0, N - 1);
  
  cout << "Array of Delivery Times (in minutes) sorted via Bubble Sort, in Ascending Order:" << endl;  
  printArray(arr_bubble); // Print bubble sort results
  cout << "Time Complexity: O(n^2)";
  cout << endl;
  
  cout << "Array of Delivery Times (in minutes) sorted via Merge Sort, in Ascending Order:" << endl;  
  printArray(arr_merge); // Print merge sort results
  cout << "Time Complexity: n(n log n)";

  return 0;
}