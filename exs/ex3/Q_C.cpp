#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll MOD = 1000000;
ll catalan[1004];

void precompute(){
    catalan[0] = 1;
    catalan[1] = 1;

    for(int i = 2; i < 1004; i++){
        for(int j = 0; j < i; j++){
            ll temp = (catalan[j] * catalan[i-j-1]) % MOD;
            catalan[i] = (catalan[i] + temp) % MOD;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    ll n;
    cin >> n;
    while(n){
        cout << catalan[n] << "\n";
        cin >> n;
    }
}