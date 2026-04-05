#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Point{
    ll x;
    ll y;
};

bool compareX(Point a, Point b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

ll findMaxSavedArea(vector<Point>& ps, int N){
    vector<ll> pre_min(N);
    vector<ll> pre_max(N);
    vector<ll> suf_min(N);
    vector<ll> suf_max(N);

    ll curr_min = 1e10;
    ll curr_max = 0;
    for(int i = 0; i < N; i++){
        curr_min = min(curr_min, ps[i].y);
        curr_max = max(curr_max, ps[i].y);
        pre_min[i] = curr_min;
        pre_max[i] = curr_max;
    }
    
    curr_min = 1e10;
    curr_max = 0;
    for(int i = N-1; i >=0 ; i--){
        curr_min = min(curr_min, ps[i].y);
        curr_max = max(curr_max, ps[i].y);
        suf_min[i] = curr_min;
        suf_max[i] = curr_max;
    }

    ll oneRectArea = (ps[N-1].x - ps[0].x)*(pre_max[N-1] - pre_min[N-1]);
    
    ll minTowRects = oneRectArea;
    for(int i = 0; i < N-1; i++){
        if(ps[i].x == ps[i+1].x) continue;
        ll leftArea = (pre_max[i] - pre_min[i]) * (ps[i].x-ps[0].x);
        ll rightArea = (suf_max[i+1] - suf_min[i+1])*(ps[N-1].x-ps[i+1].x);
        minTowRects = min(minTowRects, leftArea + rightArea);
    }

    return oneRectArea - minTowRects;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("split.in", "r", stdin); 
    freopen("split.out", "w", stdout);

    int N;
    cin >> N;

    vector<Point> points(N);
    
    for(int i = 0; i < N; i++){
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(),points.end(), compareX);
    ll savedAreaX = findMaxSavedArea(points, N);
    for(auto &p: points)swap(p.x,p.y);
    sort(points.begin(),points.end(), compareX);
    ll savedAreaY = findMaxSavedArea(points, N);

    cout << max(savedAreaX, savedAreaY) << "\n";


    return 0;
}