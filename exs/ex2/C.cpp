#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

typedef long long ll;
typedef vector<ll> vll;

struct Station{
    ll x,m;
};

ll solve(vector<Station>& pos, int k){
    ll path = 0;
    ll res = 0;

    for(Station& s : pos){
        if(res >= s.m){
            res -= s.m;
            continue;
        }
        ll remaining = s.m - res;
        ll loads = (remaining + k - 1)/k;
        path += 2 * loads * s.x;
        res = (loads * k) - remaining;
    }
    

    return path;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin >> n >> k;
    vector<Station> pos,neg;

    for(ll i = 0; i < n; i++){
        ll x , m;
        cin >> x >> m;
        if(x > 0){
            Station s = {x,m};
            pos.push_back(s);
        }else if(x < 0){
            Station s = {abs(x),m};
            neg.push_back(s);
        }
    }
    
    sort(pos.begin(),pos.end(),[](Station& s1,Station& s2){
        return s1.x>s2.x;
    });
    

    sort(neg.begin(),neg.end(),[](Station s1,Station s2){
         return s1.x>s2.x;
    });

    cout << solve(pos,k) + solve(neg,k) << "\n";
    return 0;
}

