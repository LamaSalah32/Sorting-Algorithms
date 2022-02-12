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