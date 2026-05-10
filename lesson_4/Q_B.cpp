#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
const ll MAX = 1000001;
ll fact_mod[MAX];
ll invFact[MAX];

ll power(ll a, ll p){
    ll res = 1;
    while(p > 0){
        if(p&1) res = (res*a) % MOD;
        a = a*a % MOD;
        p >>= 1;
    }
    return res;
}

ll invMod(ll num){
    return power(num, MOD-2);
}

void calc_fact(){
    fact_mod[0] = 1;
    for(ll i = 1; i < size(fact_mod); i++){
        fact_mod[i] = (i*fact_mod[i-1]) % MOD;
    }

    invFact[MAX -1] = invMod(fact_mod[MAX-1]);
    for(ll i = MAX-2; i>=0; i--){
        invFact[i] = (invFact[i+1] *(i+1)) %MOD;
    }
}

ll choose(ll a, ll b){
    return (((fact_mod[a] * invFact[b])% MOD) * invFact[a-b]) % MOD;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc_fact();

    ll n;
    cin >> n;

    while(n--){
        ll a,b;
        cin >> a >> b;
        cout << choose(a,b) << "\n";
    }



}