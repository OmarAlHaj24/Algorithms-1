#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

//A modified insertion sort that returns the number of swaps performed.
int insertionSort(int arr[], int n) {
    int i, key, j;
    int ans = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            ans++;
        }
        arr[j + 1] = key;
    }
    return ans;
}

int main() { _
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#endif
    int arr[] = {2, 1, 3, 1, 2};
    cout << insertionSort(arr, 5);
}