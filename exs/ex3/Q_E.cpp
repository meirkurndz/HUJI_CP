    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;

    vector<ll> nums(64);

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ll N;
        cin >>N;
        for(int i = 0; i < N; i++){
            ll a;
            cin >> a;

            for(int b = 63; b >=0; b--){
                if((a >> b) & 1){
                    if(nums[b] == 0){
                        nums[b] = a;
                        break;
                    }else{
                        a ^= nums[b];
                    }
                }
            }
        }
        ll max_xor = 0;
        for(int i = 63; i >= 0; i--){
            if((max_xor ^ nums[i]) > max_xor){
                max_xor = max_xor ^ nums[i];
            }
        } 
        cout << max_xor << "\n";
    }