#include <bits/stdc++.h>
using namespace std;

vector <int> arr;
int dp[100000];
int solve(int idx){
    if(idx >= arr.size()){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }
    int ans;
    ans = max(solve(idx + 2) + arr[idx], solve(idx + 1));
    return dp[idx] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    arr = {-2, 1, 3, -4, 5};
    cout << solve(0);
}