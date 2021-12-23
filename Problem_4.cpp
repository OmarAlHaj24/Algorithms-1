#include <bits/stdc++.h>
using namespace std;

const int max_sz = 1e5;
int arr[max_sz];

int solve(int l, int r) {
    if (l > r){
        return 0;
    }

    int minIdx = min_element(arr + l, arr + r + 1) - arr;
    int minVal = arr[minIdx];

    for (int i = l; i <= r; ++i){
        arr[i] -= minVal;
    }

    return min(r - l + 1, solve(l, minIdx - 1) + solve(minIdx + 1, r) + minVal);
}

int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    cout << solve(1, n) << endl;\
}