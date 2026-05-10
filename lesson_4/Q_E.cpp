#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double solve(ll n, ll a, ll b){


    vector<vector<double>> dp(n+1,vector<double>(6*n+1,0.0));

    dp[0][0] = 1.0;

    for(int i = 1; i <=n; i++){
        for(int j = i; j <= 6*n; j++){
            for(int k = 1; k<=6; k++){
                if(j-k >=0){
                    dp[i][j] += dp[i-1][j-k] / 6.0;
                }
            }
        }
    }

    double res = 0.0;
    for(int i = a; i <= b; i++){
        res += dp[n][i];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,a,b;
    cin >> n >> a>>b;

    cout << fixed << std::setprecision(6) << solve(n,a,b) << "\n";

    return 0;
}