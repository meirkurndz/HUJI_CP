#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void gen_sums(vll& A, vll& sums, ll T, ll curr_sum, int index){
    if(curr_sum > T) return;
    if(index == A.size()){
        sums.push_back(curr_sum);
        return;
    }
    gen_sums(A,sums,T,curr_sum,index+1);
    gen_sums(A,sums,T,curr_sum + A[index],index+1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T;
    cin >> N>>T;

    vll A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vll left, right;
    for(int i = 0; i < N; i++){
        if(i < N/2)left.push_back(A[i]);
        else right.push_back(A[i]);
    }
 
    vll sums_left, sums_right;
    gen_sums(left, sums_left,T,0,0);
    gen_sums(right, sums_right,T,0,0);

    sort(sums_right.begin(),sums_right.end());

    ll max_t = 0;
    for(ll s: sums_left){
        auto it = upper_bound(sums_right.begin(),sums_right.end(), T-s);
        if(it != sums_right.begin()){
            ll s_pair = *(--it);
            max_t = max(s+s_pair,max_t);
        }
    }
    cout << max_t << "\n";

    return 0;
}