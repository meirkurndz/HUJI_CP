#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

bool try_sub(vll& arr,int k, ll max){
    ll curr_sum = 0;
    int subs_count = 1;
    for(ll num : arr){
        if(num > max) return false;
        if(curr_sum + num <= max){
            curr_sum += num;
        }else{
            subs_count++;
            if(subs_count > k) return false;
            curr_sum = num;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    vll arr(n);
    ll low = 0;
    ll high = 0;
    for(ll i = 0; i < n ;i++){
        cin >> arr[i];
        low = max(low,arr[i]);
        high += arr[i];
    }

    ll answer = high;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(try_sub(arr,k,mid)){
            answer = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << answer << "\n";

    return 0;
}