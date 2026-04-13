    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <utility>

    using namespace std;
    typedef long long ll;
    typedef vector<ll> vll;
    typedef pair<vll,ll> P;

    P merge(vll& left, vll& right){

        ll count = 0;

        
        vll mer;
        size_t l = 0;
        size_t r = 0;
        
        while(l < left.size() && r < right.size()){
            if(left[l] <= right[r]){
                mer.push_back(left[l]);
                l++;
            }else if(left[l] > right[r]){
                count+=left.size() - l;
                mer.push_back(right[r]);
                r++;
            }
        }
        while(l < left.size()){
            mer.push_back(left[l]);
            l++;
        }
        while(r < right.size()){
            mer.push_back(right[r]);
            r++;
        }
        return {mer,count};
    }

    P div_and_con(vll arr){
        if(arr.size()==1){
            return {arr,0};
        }
        int size = arr.size();

        auto mid = arr.begin() + arr.size() / 2;
        vll left(arr.begin(), mid);
        vll right(mid, arr.end());

        P left_p = div_and_con(left);
        P right_p = div_and_con(right);

        P res = merge(left_p.first,right_p.first);
        ll total = res.second + left_p.second + right_p.second;

        return {res.first, total};
    }


    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        while(n!=0){
            vll arr(n);
            for(int i = 0; i < n; i++){
                cin >> arr[i];
            }
            cout << div_and_con(arr).second << "\n";
            cin >> n;
        }


        return 0;
    }

