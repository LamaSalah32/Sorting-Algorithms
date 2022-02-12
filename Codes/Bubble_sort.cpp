#include<bits/stdc++.h>
using namespace std ;

int main(){
      code();
      int n; cin >> n;
      vector <int> arr(n);
      for (auto& i : arr) cin >> i; 

      for (int i = 0; i < n-1; i++){  
            bool ok = true;
            for (int j = 1; j < n-i; j++){
                  if (arr[j] < arr[j-1]){
                        swap(arr[j], arr[j-1]); 
                        ok = false;
                  }
            }

            if (ok) break;
      }

      for (auto& i : arr) cout << i << " "; 
      cout << "\n";
    
    return 0;
}
