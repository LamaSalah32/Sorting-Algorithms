#include<bits/stdc++.h>
using namespace std ;

int main(){
      code();
      int n; cin >> n;
      vector <int> arr(n);
      for (auto& i : arr) cin >> i; 

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
      
      for (auto& i : arr) cout << i << " "; 
      cout << "\n";
    
    return 0;
}
