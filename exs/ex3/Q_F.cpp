#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ll;
typedef vector<vector<ll>> vvll;
vector<ll> stats(36);

struct Matrix{
    ll mat[36][36];

    Matrix(){
        for(int i = 0; i < 36; i++){
            for(int j = 0; j < 36; j++){
                mat[i][j] = 0;
            }
        }
    }
};

Matrix pre[32];


Matrix make_stats(){
    int idx =0;
    for(int i = 0; i < 10; i++){
        for(int j = i+2; j < 10; j++){
            stats[idx++] = (1 << i) | (1 << j);
        }
    }

    Matrix M;
    for(int i = 0; i < 36; i++){
        for(int j = 0; j < 36; j++){
            if(((stats[i] & stats[j]) == 0) && ((stats[i] & (stats[j] << 1)) == 0) && ((stats[i] & (stats[j] >> 1)) == 0)){
                M.mat[i][j] = 1;
            }
        }
    }

    return M;
}

Matrix mul(Matrix& A, Matrix& B){
    Matrix C;

    for(int i = 0; i < 36; i++){
        for(int k = 0; k < 36; k++){
            if(A.mat[i][k] == 0) continue;
            for(int j = 0; j < 36; j++){
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j]));
            }
        }
    }
    return C;
}

void precompute(Matrix base) {
    pre[0] = base;
    for (int i = 1; i < 32; i++) {
        pre[i] = mul(pre[i-1], pre[i-1]);
    }
}


Matrix power(Matrix M, long long p){
    Matrix res;
    for(int i = 0; i < 36; i++){
        res.mat[i][i] = 1;
    }
    for(int i = 0; i< 32; i++){
        if((p>>i) & 1){
            res = mul(res,pre[i]);
        }
    }
    return res;
}

ll solve(Matrix M, long long n){
    M = power(M,n-1);
    ll sum = 0;
    for(int i = 0; i < 36; i++){
        for(int j = 0; j < 36; j++){
            sum = (sum + M.mat[i][j]);
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Matrix M = make_stats();
    precompute(M);
    
    long long T;
    cin >>T;
    for( int i = 1; i<= T; i++){
        long long n;
        cin >> n;
        cout << "Case " << i << ": " << solve(M,n) << "\n";
    }


}