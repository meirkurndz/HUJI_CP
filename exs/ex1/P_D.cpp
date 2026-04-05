#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    ll total = 0;

    vll top(N);
    vll core(N);
    vll base(N);

    for(int i = 0 ; i < N; i++){
        cin >> top[i];
    }
    for(int i = 0 ; i < N; i++){
        cin >> core[i];
    }
    for(int i = 0 ; i < N; i++){
        cin >> base[i];
    }

    sort(top.begin(), top.end());
    sort(core.begin(), core.end());
    sort(base.begin(), base.end());

    for(int i= 0;i < N;i++){
        auto it_top = lower_bound(top.begin(),top.end(),core[i]);
        ll tops = distance(top.begin(),it_top);

        auto it_base = upper_bound(base.begin(),base.end(),core[i]);
        ll bases = distance(it_base,base.end());
        
        total += tops*bases;
    }
    cout << total << "\n";
}