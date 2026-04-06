#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;


multiset<ll> butt, top;
ll butt_sum, top_sum;

void fix_median(){
    if(butt.size() > top.size() + 1){
        ll temp = *prev(butt.end());
        butt_sum -= temp;
        butt.erase(prev(butt.end()));
        top.insert(temp);
        top_sum += temp;
    }else if(top.size() > butt.size()){
        ll temp = *top.begin();
        top_sum -= temp;
        top.erase(top.begin());
        butt.insert(temp);
        butt_sum += temp;
    }
}

void add(ll new_num){
    if(butt.empty() || new_num < *prev(butt.end())){
        butt.insert(new_num);
        butt_sum += new_num;
    }else{
        top.insert(new_num);
        top_sum += new_num;
    }
    fix_median();
}

void rm(ll num){
    auto it = butt.find(num);
    if(it != butt.end()){
        butt.erase(it);
        butt_sum -= num;
    }else{
        it = top.find(num);
        top.erase(it);
        top_sum -= num;
    }
    fix_median();
}

ll calc_work(){
    ll median = *prev(butt.end());
    return (((ll)butt.size()*median) - butt_sum) 
        + (top_sum - ((ll)top.size()*median));  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int k;
    cin >> n >> k;
    vll g_hei(n);
    for(int i = 0; i < n; i++) cin >> g_hei[i];

    for(int i = 0; i < n; i++){
        add(g_hei[i]);
        if(i >=k) rm(g_hei[i-k]);
        if(i > k-2){
            ll work = calc_work();
            cout << work << " ";
        }
    }
    cout << "\n";


}