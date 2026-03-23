#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
    int n;
    cin >> n;
    vll heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    heights.push_back(0);

    stack<ll> S;
    ll max_area = 0;

    for(int i = 0; i <= n ;i++){
        
        while(!S.empty() && heights[S.top()] > heights[i]){
            ll curr_h = heights[S.top()];
            S.pop();

            ll w;
            if(S.empty()){
                w = i;
            }else{
                w = i - S.top() - 1;
            }
            max_area = max(max_area, curr_h*w);

        }

        S.push(i);
    }
    cout << max_area << endl;
    return 0;
}