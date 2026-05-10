#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
const ll MAX_N = 101;
ll Mat[MAX_N][MAX_N];

ll power(ll base, ll p, ll K){
    ll res = 1;
    base %= K;
    while(p>0){
        if(p&1) res = (res * base) % K;
        base = (base * base) % K;
        p >>= 1;

    }
    return res;
}

ll invMod(ll num, ll K){
    return power(num, K-2, K);
}

void swap_row( int rank, int i, int N){
    for(int col = 0; col  < N; col++){
        swap(Mat[rank][col],Mat[i][col]);
    }
}


ll guass(ll N, ll K){

    ll rank = 0;
    for(int j = 0; j < N; j++){
        for(int i = rank; i < N; i++){
            if(Mat[i][j] != 0){
                swap_row(rank, i, N);
                ll inv = invMod(Mat[rank][j], K);

                for(int col = j; col < N; col++){
                    Mat[rank][col] = (Mat[rank][col] * inv) % K; 
                }
                
                for(int row = 0; row < N; row++){
                    if(row != rank && Mat[row][j] != 0){
                        ll factor = Mat[row][j];
                        for(int col = j; col < N; col++){
                                Mat[row][col] = ((Mat[row][col] - (Mat[rank][col] * factor) % K) + K) % K;
                        }
                    }
                }
                rank++;
                break;
            }
        }
    }
    return rank;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    for(int c = 1; c <= T; c++){
        ll N,M,K;
        cin >> N >> M >> K;
       
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Mat[i][j] = 0;
            } 
            Mat[i][i] = 1;
        }

        for(int i = 0; i< M; i++){
            int u,v;
            cin >> u >> v;
            Mat[u-1][v-1] = (K-1) % K;
            Mat[v-1][u-1] = (K-1) % K;
        }

        ll res = guass(N,K);
        res = power(K, N-res, MOD) %MOD;
        cout << "Case " << c << ": " << res<< "\n";
    }

}