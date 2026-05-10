#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
struct M{
    ll m[2][2];
    M(ll a, ll b, ll c, ll d){
        m[0][0] = a %MOD;
        m[0][1] = b%MOD;
        m[1][0] = c%MOD;
        m[1][1] = d%MOD;
    }
};



M mul(const M& m1,const  M& m2){
    ll a = (m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0]) %MOD;
    ll b = (m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1]) %MOD;
    ll c = (m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0]) %MOD;
    ll d = (m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1]) %MOD;

    return M(a,b,c,d);
}

M power(M& A, ll p){
    M res(1,0,0,1);

    while(p>0){
        if(p&1) res = mul(res,A);
        A = mul(A,A);
        p >>= 1;
    }
    return res;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    M tranMat(19, 7,6,20);
    ll n;
    cin >> n;
    cout << power(tranMat,n).m[0][0] << "\n"; 

}