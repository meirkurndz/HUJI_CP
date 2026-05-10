#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;
typedef vector<ll> vll; 

ll largest_rect(vll hist){
    hist.push_back(0);

    stack<ll> S;
    ll max_area = 0;

    for(int i = 0; i < hist.size(); i++){
        
        while(!S.empty() && hist[i] < hist[S.top()]){
            ll h = hist[S.top()];
            S.pop();

            ll w;
            if(S.empty()){
                w=i;
            }else{
                w = i - S.top() - 1;
            }

            max_area = max(max_area,h*w);
        }

        S.push(i);
    
    }

    return max_area;

}

vector<int> s_to_vec(string s){
    int N = s.length();
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        vec[i] = s[i] - '0';
    }
    return vec;
}

void solve(bool is_last){
    string line;
    cin >> line;
    int N = line.length();

    vector<vector<int>> grid(N,vector<int>(N));
    grid[0] = s_to_vec(line);

    for(int i = 1; i < N; i++){
        cin >> line;
        grid[i] = s_to_vec(line);
    }

    ll max_area = 0;
    vector<ll> hist(N,0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 1){
                hist[j]++;
            }else{
                hist[j] = 0;
            }
        }
        max_area = max(max_area, largest_rect(hist));
    }


    cout << max_area << "\n";
    if(!is_last) cout <<"\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        
        solve(T==0);
    }
    return 0;
}