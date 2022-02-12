#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(vec) vec.begin(), vec.end()
#define cin(v) for (auto& i : v) cin >> i
#define cout(v) for (auto& i : v) cout << i << " "; cout << "\n"
#define ceil(a, b) ((a / b) + (a % b ? 1 : 0))
#define mod 1000000007

using namespace std ;

int n;
vector <int> arr;

int part(int low, int high){

      int p = arr[high], k = low-1;

      for (int i = low; i <= high-1 ; i++){
            if (arr[i] < p){
                  k++;       
                  swap(arr[i], arr[k]);
            }
      }

      swap (arr[k+1] , arr[high]);
      cout(arr);

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
      for (auto& i : arr) cin >> i;  
      QuickSort(0, n-1);
      
      for (auto& i : arr) cout << i << " "; 
      cout << "\n";
    
    return 0;
}      
