#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll gcd(ll a, ll b){
    if(b > a) return gcd(b,a);
    if(b==0 ) return a;
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;
    vector<ll> X(N);

    for(int i = 0; i < N; i++){
        cin >> X[i];
    }

    sort(X.begin(), X.end());
    ll g = X[1]-X[0];
    for(int i = 2; i< N;i++){
        g = gcd(g,X[i] - X[i-1]);
    }

    vector<ll> M;
    for(ll i = 1; i*i <= g; i++){
        if(g % i == 0){
            if(i > 1) M.push_back(i);
            if(g/i > 1 && g/i != i) M.push_back(g/i);
        }
    }

    for(int i = 0; i < size(M)-1; i++){
        cout << M[i] << " ";
    }
    cout << M[size(M) - 1] << "\n";
    
}