#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> arr;
    int val;
    while(cin >> val){
        arr.push_back(val);
    } 

    int n = arr.size();
    vector<int> dp(n,1);
    vector<int> parent(n,-1);

    ll max_len = 0;
    ll last_idx = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && dp[j] + 1 >= dp[i]){
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if(dp[i] >= max_len){
            max_len = dp[i];
            last_idx = i;
        }
    }

    cout << max_len << "\n-\n";

    vector<int> path;
    int curr = last_idx;
    while(curr != -1){
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(),path.end());
    for(int idx : path){
        cout << arr[idx] << "\n";
    }
    return 0;
}