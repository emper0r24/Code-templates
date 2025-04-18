#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int min_bits(int N) {
    return (N > 0) ? (int)log2(N) + 1 : 1;
}

void merge(int a[], int low, int mid, int high){
    int i = low, j = mid + 1;
    vector <int> temp;
    while(i <= mid && j <= high){
        if(a[i] <= a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j <= high){
        temp.push_back(a[j]);
        j++;
    }
    for(int i = low; i <= high; i++){
        a[i] = temp[i - low];
    }
}

void merge_sort(int a[], int low, int high){
    if(low >= high)     return;
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)      cin >> a[i];
        merge_sort(a, 0, n - 1);
        for(int i = 0; i < n; i++)      cout << a[i] << ' ';
        cout << "\n";
    }
    return 0;
}