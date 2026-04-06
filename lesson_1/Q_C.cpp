#include <iostream> 
#include <algorithm>
#include <string>
#include "vector"

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    while(cin >> S){
        S += "@";
        ll count = 0;
        vll mod3(3,0);
        mod3[0]=1;
        ll prefix_sum = 0;

        for(ll i = 0; i < S.size(); ++i){
            ll dig = char(S[i]) - '0';
            if(dig <= 9 && dig >= 0){
                prefix_sum += dig;
                prefix_sum %= 3;
                mod3[prefix_sum]++;
            }else{
                for(int j = 0; j < 3; j++){
                    count += (mod3[j]*(mod3[j]-1))/2;
                    mod3[j] = 0;
                }
                mod3[0]=1;
                prefix_sum = 0;
            }
        }
        cout << count << "\n"; 
    }
    return 0;
}