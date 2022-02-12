<img src="Photos/neural.png" alt="Algo" width="100"/>  

# Sorting Algorithms

#### This is a simple summary of the most popular sorting algorithm


- selection sort
- Bubble sort
- Insertion sort
- Quick sort
- Merge sort

#### I hope this helps you :smiley:
---
---

## Selection sort

**finding the minimum element from the unsorted part in an array and putting it at the beginning.**

| Best case | Worst case |  Stable | In-place |
| :-------: | :---------:| :-----: | :------: |
| O(*n<sup>2</sup>*)      | O(*n<sup>2</sup>*)     | :heavy_multiplication_x: | :heavy_check_mark: |

## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std ;

int main(){
      code();
      int n; cin >> n;
      vector <int> arr(n);
      for (auto& i : arr) cin >> i;  //get elements of the array from user

      for(int i = 0; i < n-1; i++){ //sorting elements by using selection sort Algorithm 
            int minElementIdx = i; 
            for(int j = i+1; j < n; j++){
                  if (arr[j] < arr[minElementIdx]) minElementIdx = j; //find the minimum element in array  
            }

            swap(arr[minElementIdx], arr[i]); //swap the minimum element with the first element 
      }

      for (auto& i : arr) cout << i << " ";  //print the elements in the array after sorting
      cout << "\n";
    
    return 0;
}
```

---

## Bubble sort

**works by repeatedly swapping the adjacent elements if they are in wrong order.**

| Best case | Worst case |  Stable | In-place |
| :-------: | :---------:| :-----: | :------: |
| O(*n*)      | O(*n<sup>2</sup>*)     | :heavy_check_mark: | :heavy_check_mark: |

## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std ;

int main(){
      code();
      int n; cin >> n;
      vector <int> arr(n);
      for (auto& i : arr) cin >> i;  //get the elements of array from user

      for (int i = 0; i < n-1; i++){  //sorting elements by using Bubble sort Algorithm
            bool ok = true;
            for (int j = 1; j < n-i; j++){
                  if (arr[j] < arr[j-1]){
                        swap(arr[j], arr[j-1]); 
                        ok = false;
                  }
            }

            if (ok) break;
      }

      for (auto& i : arr) cout << i << " ";  //print the elements in the array after sorting
      cout << "\n";
    
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
using namespace std ;

int main(){
      code();
      int n; cin >> n;
      vector <int> arr(n);
      for (auto& i : arr) cin >> i;  //get the elements of array from user

      int k , j;
      for (int i = 1; i < n; i++){
            k = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > k){
                  arr[j+1] = arr[j];
                  j--;
            }
            arr[j+1] = k;
      }
      
      for (auto& i : arr) cout << i << " ";  //print the elements in the array after sorting
      cout << "\n";
    
    return 0;
}
```

---

## Quick sort

**QuickSort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot**

| Best case | Worst case | Algorithmic Paradigm |  Stable | In-place |
| :-------: | :---------:| :------------------: | :-----: | :------: |
| O(*nlogn*) | O(*n<sup>2</sup>*)  | Divide and Conquer | :heavy_multiplication_x: | :heavy_check_mark: |

## *`image`*

<img src="Photos/QuickSort2.png" alt="QuickSort" width="500"/> 


## *`code`*

```cpp
#include<bits/stdc++.h>
using namespace std ;

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
      code();
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
using namespace std ;

int n; 
vector <int> arr;

void merge(int l, int m , int r){

    int size_of_sub1 = m - l + 1;
    int size_of_sub2 = r-m;
    vector <int> sub1(size_of_sub1), sub2(size_of_sub2);

    for (int i = 0; i < size_of_sub1; i++) sub1[i] = arr[l+i];
    for (int i = 0 ; i < size_of_sub2; i++) sub2[i] = arr[m + 1 + i];

    int p1 = 0, p2= 0, k = l;

    while (p1 < size_of_sub1 && p2 < size_of_sub2){
        if (sub1[p1] < sub2[p2]){
            arr[k] = sub1[p1];
            p1++;
        }
        else {
            arr[k] = sub2[p2];
            p2++;
        } 

        k++;
    }

    while(p1 < size_of_sub1){
        arr[k] = sub1[p1];
        p1++;
        k++;
    }
    while(p2 < size_of_sub2){
        arr[k] = sub2[p2];
        p2++;
        k++;
    }

}

void mergeSort(int l, int r){
    if (l < r){

        int m = l + (r-l)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);

        merge(l, m, r);
    }
}

int main(){
      code();
      cin >> n;
      arr.resize(n);
      for (auto& i : arr) cin >> i; 
      mergeSort(0, n-1);

      for (auto& i : arr) cout << i << " ";  
      cout << "\n";
    
    return 0;
}
```

---
