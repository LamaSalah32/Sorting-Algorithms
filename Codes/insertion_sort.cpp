#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(vec) vec.begin(), vec.end()
#define cin(v) for (auto& i : v) cin >> i
#define cout(v) for (auto& i : v) cout << i << " "; cout << "\n"
#define ceil(a, b) ((a / b) + (a % b ? 1 : 0))
#define mod 1000000007

using namespace std ;

void code (){
    ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    #endif
}



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
