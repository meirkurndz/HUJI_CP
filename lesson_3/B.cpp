#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
ll paskal[510][510];
ll dp[510][510];
ll MOD = 1e9+7;

void build_paskal(){
    for(int i = 0; i < 510; i++){
        paskal[i][0] = 1;
        for(int j = 1; j <= i; j++){
            paskal[i][j] = (paskal[i-1][j-1] + paskal[i-1][j]) % MOD;
        }
    }
}

void solve(string s){
    int n = s.length();
    if(n % 2 == 1){
        cout << 0 << "\n";
        return;
    }
    
    build_paskal();

    for (int i = 0; i < 510; i++) {
        for (int j = 0; j < 510; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i < 510; i++) {
        dp[i][i - 1] = 1;
    }
    dp[0][0] = 0;

    for(int len = 2; len <= n; len += 2){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;

            for(int k = i + 1; k <= j; k += 2){
                if(s[i] == s[k]){
                    int in_pairs = (k - i - 1) / 2;
                    int out_pairs = (j - k) / 2;
                    int total = len / 2;

                    ll left = (i + 1 > k - 1) ? 1 : dp[i + 1][k - 1];
                    ll right = (k + 1 > j) ? 1 : dp[k + 1][j];
                    
                    ll ways = (left * right) % MOD;
                    ll comb = paskal[total - 1][in_pairs];
                    
                    ll res = (ways * comb) % MOD;
                    dp[i][j] = (dp[i][j] + res) % MOD;
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string spell;
    if (cin >> spell) {
        solve(spell);
    }
    return 0;
}