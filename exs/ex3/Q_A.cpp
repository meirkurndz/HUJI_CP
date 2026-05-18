#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvll;

ll solve(ll C, ll V){
    vvll adj(C,vector<ll>(C,0));

    for(int i = 0; i < V; i++){
        ll C1, C2, G;
        cin >> C1 >> C2 >> G;
        vvll[C1][C2] = G;
    }

    priority_queue<pair>

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll C,V;
    cin >> C >> V;
    solve(C,V);

}