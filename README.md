<img src="Photos/neural.png" alt="Algo" width="100"/>  


# Sorting Algorithms

#### This is a simple summary of the most popular sorting algorithm.


- [Selection sort](#selection-sort)
- [Bubble sort](#bubble-sort)
- [Insertion sort](#insertion-sort)
- [Quick sort](#quick-sort)
- [Merge sort](#merge-sort)

#### I hope this helps you :smiley:
---
---

## Selection sort

**Finding the minimum element from the unsorted part in an array and putting it at the beginning.**

| Best case | Worst case |  Stable | In-place |
| :-------: | :---------:| :-----: | :------: |
| O(*n<sup>2</sup>*)      | O(*n<sup>2</sup>*)     | :heavy_multiplication_x: | :heavy_check_mark: |

## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    int arr[n];

    // get the elements of array from user.
    for (int i = 0; i < n; i++){ 
        cin >> arr[i];
    }

    // sorting elements by using selection sort Algorithm.     
    for(int i = 0; i < n-1; i++){ 
        int minElementIdx = i; 

        // find the minimum element in array.
        for(int j = i + 1; j < n; j++){
            if (arr[j] < arr[minElementIdx]) minElementIdx = j;   
        }

        // swap the minimum element with the first element.
        swap(arr[minElementIdx], arr[i]);  
    }

    // Print the sorted array.s
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

---

## Bubble sort

**Works by repeatedly swapping the adjacent elements if they are in wrong order.**

| Best case | Worst case |  Stable | In-place |
| :-------: | :---------:| :-----: | :------: |
| O(*n*)      | O(*n<sup>2</sup>*)     | :heavy_check_mark: | :heavy_check_mark: |

## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    int arr[n];

    // get the elements of array from user.
    for (int i = 0; i < n; i++){ 
        cin >> arr[i];
    }

    // Sorting elements by using Bubble sort Algorithm.
    for (int j = 0; j < n; j++){ 
        for (int i = 1; i < n; i++){

            // Compare adjacent elements in the array and swap them if they are out of order.
            if (arr[i] < arr[i-1])
                swap(arr[i], arr[i-1]);
        }
    }

    // Print the sorted array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

---

## Insertion sort

**The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed at the correct
position in the sorted part.**

| Best case | Worst case | Algorithmic Paradigm |  Stable | In-place |
| :-------: | :---------:| :------------------: | :-----: | :------: |
| O(*n*)      | O(*n<sup>2</sup>*)   | Incremental Approach | :heavy_check_mark: | :heavy_check_mark: |

## *`image`*

<img src="Photos/insertionsort.png" alt="insertionsort" width="300"/> 


## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    int arr[n];

    // get the elements of array from user.
    for (int i = 0; i < n; i++){ 
        cin >> arr[i];
    }

    // Sorting elements by using Insertion sort Algorithm.
    for (int i = 1; i< n; i++){
        int j = i-1, k = arr[i];
        while (j >= 0 && arr[j] > k){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = k;
    }

    // Print the sorted array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

---

## Quick sort

**QuickSort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.**

| Best case | Worst case | Algorithmic Paradigm |  Stable | In-place |
| :-------: | :---------:| :------------------: | :-----: | :------: |
| O(*nlogn*) | O(*n<sup>2</sup>*)  | Divide and Conquer | :heavy_multiplication_x: | :heavy_check_mark: |

## *`image`*

<img src="Photos/QuickSort2.png" alt="QuickSort" width="500"/> 


## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std;

int n;
vector <int> arr;

int part(int low, int high){
      int p = arr[high], k = low-1;

      for (int i = low; i <= high-1 ; i++){
            if (arr[i] < p){
                  k++;   // increment index of smaller element
                  swap(arr[i], arr[k]);
            }
      }

      swap (arr[k+1] , arr[high]);

      return k+1;
}

void QuickSort(int low, int high){
      if (low < high){
            int x = part(low, high);

            QuickSort(low, x-1);
            QuickSort(x+1, high);
      }
}

int main(){
      cin >> n;
      arr.resize(n);
      for (auto& i : arr) cin >> i;  //get the elements of array from user
      QuickSort(0, n-1);
      
      for (auto& i : arr) cout << i << " ";  //print the elements in the array after sorting
      cout << "\n";
    
    return 0;
}
```

---

## Merge sort

**Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.**

| Best case | Worst case | Algorithmic Paradigm |  Stable | In-place |
| :-------: | :--------: | :------------------: | :-----: | :------: |
| O(*nlogn*) | O(*nlogn*)  | Divide and Conquer | :heavy_check_mark: | :heavy_multiplication_x: |


## *`image`*

<img src="Photos/Merge-Sort-Tutorial.png" alt="Merge-Sort" width="450"/> 

## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std;

int arr[1000005];

// Merge function to merge two sorted subarrays.
ll merge(int l, int mid, int r){
    ll i = l, j = mid, cnt = 0;
    vector<int> temp;

    while (i < mid && j < r){
        if (arr[i] > arr[j]){
            cnt += mid - i;
            temp.push_back(arr[j]);
            j++;
        }
        else {
            temp.push_back(arr[i]);
            i++;
        }
    }

    // If there are remaining elements in the left subarray, add them to temp.
    while (i < mid){
        temp.push_back(arr[i]);
        i++;
    }

    // If there are remaining elements in the right subarray, add them to temp.
    while (j < r){
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = l; i < r; i++){
        arr[i] = temp[i - l];
    }

    return cnt;
}

// Divide function to recursively split the array into smaller subarrays.
ll divide(int l, int r){
    if (l != r-1){
        int mid = l + (r - l) / 2;

        int inversion = divide(l, mid);
        inversion += divide(mid, r);
        inversion += merge(l, mid, r);

        return inversion;
    }

    return 0;
}

int main(){
    int n;  cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "The number of inversions = " << divide(0, n) << "\n";

    // Print the sorted array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
```

---
