#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll,ll>> state;
ll INF = 1e10;

void solve(ll C, ll V){

    vector<pair<ll,ll>> adj[C+1];
    ll dist[C+1][2];
    priority_queue<state, vector<state>, greater<state>> pq;

    for(int i = 0; i < V; i++){
        int c1,c2,w;
        cin >> c1>>c2>>w;
        adj[c1].push_back({c2,w});
        adj[c2].push_back({c1,w});
    }

    for(int i = 1; i <= C; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[1][0] = 0;

    pq.push({0,{1,0}});

    while(!pq.empty()){
        state next = pq.top();
        pq.pop();

        ll d = next.first;
        ll c = next.second.first;
        ll p = next.second.second;
        if(dist[c][p] < d) continue;

        for(pair<ll,ll> neighbor : adj[c]){
            ll nei = neighbor.first;
            ll w = neighbor.second;
            ll new_p = 1-p;

            if(dist[c][p] + w < dist[nei][new_p]){
                dist[nei][new_p] = dist[c][p] + w;
                pq.push({dist[nei][new_p],{nei,new_p}});
            }
        }
    }

    if(dist[C][0] == INF){
        cout << "-1\n";
    }else{
        cout << dist[C][0] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll C,V;
    while(cin >> C >> V){
        solve(C,V);
    }

}