#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll MOD = 1e9+7;
const int MAX_N = 100;

struct Matrix{
    ll mat[MAX_N][MAX_N];
    ll size;

    Matrix(int s) : size(s){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                mat[i][j] = 0;
            }   
        }
    }
};


Matrix mul(const Matrix& A,const  Matrix& B, ll mod){
    Matrix C(A.size);

    for(int i = 0; i < A.size; i++){
        for(int k = 0; k < A.size; k++){
            if(A.mat[i][k] == 0) continue;
            for(int j = 0; j < A.size; j++){
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % mod;
            }
        }
    }
    return C;
}

Matrix fast_exp(Matrix A, ll p, ll mod){
    Matrix res(A.size);
    for(int i = 0; i < A.size; i++){
        res.mat[i][i]=1;

    }

    while(p > 0 ){
        if(p&1) res = mul(res,A,mod);
        A = mul(A,A,mod);
        p >>= 1;
    }
    return res;
}

ll solve(Matrix& M, ll k){
    return fast_exp(M,k,MOD).mat[0][M.size-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k;
    cin >> n >> m >> k;
    Matrix M(n);

    for(int i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        M.mat[a-1][b-1]++;
    }

    cout <<  solve(M,k) << "\n";

}