#include <iostream>

typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll W = 0;

    while(cin >> W){
        ll N = 0;
        cin >> N;
        ll area =0;
        for(int i = 0; i < N; i++){
            ll w,l;
            cin >> w >>l;
            area += w*l;
        }
        ll L = (area/W);
        cout << L << "\n";
    }
}