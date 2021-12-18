#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

vector <int> arr;
int solve(int idx){
    if(idx >= arr.size()){
        return 0;
    }
    int ans = 0;
    ans = max(solve(idx + 2) + arr[idx], solve(idx + 1));
    return ans;
}

int main() { _
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#endif
    arr = {-2, 1, 3, -4, 5};
    cout << solve(0);
}