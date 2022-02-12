#include<bits/stdc++.h>
using namespace std ;

int main(){
      code();
      int n; cin >> n;
      vector <int> arr(n);
      for (auto& i : arr) cin >> i; 

      for(int i = 0; i < n-1; i++){ 
            int minElementIdx = i; 
            for(int j = i+1; j < n; j++){
                  if (arr[j] < arr[minElementIdx]) minElementIdx = j; 
            }

            swap(arr[minElementIdx], arr[i]);
      }

      for (auto& i : arr) cout << i << " ";
      cout << "\n";
    
    return 0;
}
