#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX_N = 101;
const ll INF = 1e18;

struct Matrix{
    vector<vector<ll>> m;
    int size;

    Matrix(int s) : size(s), m(s, vector<ll>(s, INF)) {}

};

Matrix mul(Matrix& A,Matrix& B){
    Matrix C(A.size);

    for(int i = 0; i < A.size; i++){
        for(int k = 0; k < A.size; k++){
            if(A.m[i][k] == INF) continue;
            for(int j = 0; j < A.size; j++){
                if(B.m[k][j] == INF) continue;
                if(A.m[i][k] + B.m[k][j] < C.m[i][j])
                    C.m[i][j] = A.m[i][k] + B.m[k][j];
            }
        }
    }
    return C;
}

Matrix power(Matrix& A, ll p){
    Matrix res(A.size);
    for(int i = 0; i < A.size; i++){
        res.m[i][i]= 0;
    }

    while(p>0){
        if((p&1)==1) res = mul(res, A);
        A = mul(A,A);
        p >>= 1;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k; 
    cin >> n >> m >> k;
    Matrix M(n);

    for(int i = 0;i < m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        M.m[a-1][b-1] = c;
    }
    ll sol = power(M,k).m[0][n-1];
    if(sol >= INF/2)
        cout  << "-1\n";
    else
        cout << sol << "\n";

}