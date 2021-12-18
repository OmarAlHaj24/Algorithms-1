#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

vector <int> nums;
const int MAX_SZ = 1e5;
int found[MAX_SZ];

void find(int n){
    bool flag = false;
    //One for loop, so that's linear time.
    for(int i = 0; i < nums.size(); i++){
        int x = min(nums[i], n - nums[i]);
        int y = max(nums[i], n - nums[i]);
        if(found[n - nums[i]] && n - nums[i] >= nums[i]){
            if(x == y){
                if(found[nums[i]] > 1){
                    if(flag){
                        cout << "Or ";
                    }
                    cout << "Pair found (" << y << ", " << x << ") ";
                    flag = true;
                }
            }else{
                if(flag){
                    cout << "Or ";
                }
                cout << "Pair found (" << y << ", " << x << ") ";
                flag = true;
            }
        }
    }
    if(!flag){
        cout << "Pair not found" << endl;
    }
}

int main() { _
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#endif
    nums = {8, 7, 2, 5, 3, 1};
    for(int i = 0; i < nums.size(); i++){
        found[nums[i]]++;
    }
    int target = 10;
    find(target);
}