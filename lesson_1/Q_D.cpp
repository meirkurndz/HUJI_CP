#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<pair<ll,ll>> vpll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    for(ll i = 0; i < T; i++){
        ll N;
        cin >> N;
        vpll ranges(N);
        for(ll r = 0; r < N; r++){
            cin >> ranges[r].first >> ranges[r].second; 
        }

        sort(ranges.begin(), ranges.end());
        
        priority_queue<ll , vector<ll>, greater<ll>> pq;
        ll curr_box = ranges[0].first;
        ll index = 0;
        bool is_pack = true;

        while(index < N || !pq.empty()){

            while(index < N && ranges[index].first <= curr_box){
                pq.push(ranges[index].second);
                index++;
            }

            if(!pq.empty() && pq.top() < curr_box){
                is_pack = false;
                break;
            }

            if(!pq.empty()){
                pq.pop();
                curr_box++;
            }else if(index < N){
                curr_box = ranges[index].first;
            }
        }

        if(is_pack){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}