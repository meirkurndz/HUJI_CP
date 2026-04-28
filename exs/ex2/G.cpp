#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
int memo[514][514][10];
int presum[514][514];
char image[514][514];
short best_w[514][514][10];
short best_b[514][514][10];

int count1(int r, int c, int s){
    return presum[r+s-1][c+s-1] - presum[r-1][c+s-1] - presum[r+s-1][c-1] + presum[r-1][c-1];
}

int solve(int r, int c, int s){
    if(s==1) return 0;

    int k = log2(s);
    if(memo[r][c][k] != -1) return memo[r][c][k];
    
    int min_cost = 1000000000;
    int r_offset[] = {0,0,s/2,s/2};
    int c_offset[] = {0,s/2,0,s/2};
    int area = (s*s)/4;

    for(int w = 0; w < 4; w++){
        for(int b = 0; b < 4;b++){
            if(b==w)continue;
            int cost = count1(r+r_offset[w],c+c_offset[w], s/2) +
                 (area - count1(r+r_offset[b], c+c_offset[b],s/2));

            for(int i = 0; i < 4; i++){
                if(i == w || i == b) continue;
                cost += solve(r+r_offset[i], c + c_offset[i], s/2);
            }

            if(cost < min_cost){
                min_cost = cost;
                best_w[r][c][k] = w;
                best_b[r][c][k] = b;

            }
        }
    }
    memo[r][c][k] = min_cost;
    return min_cost;
}

void build_image(int r, int c, int s){
    if(s == 1)return;
    int k = log2(s);
    int r_offset[] = {0,0,s/2,s/2};
    int c_offset[] = {0,s/2,0,s/2};

    int w = best_w[r][c][k];
    int b = best_b[r][c][k];

    for(int i = 0; i < s/2; i++){
        for(int j = 0; j < s/2; j++){
            image[r+r_offset[w]+i][c+c_offset[w]+j] = '0';
            image[r+r_offset[b]+i][c+c_offset[b]+j] = '1';
        }
    }

    for(int i = 0; i < 4; i++){
        if(i == w || i == b)continue;
        build_image(r + r_offset[i], c+c_offset[i], s/2);
    }
        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 1 ;i <= N; i++){
        string row_i;
        cin >> row_i;
        for(int j = 1 ;j <= N; j++){
           image[i][j] = row_i[j-1];
           presum[i][j] = (row_i[j-1] - '0') + presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1];
        }   
    }
    for(int i = 0 ;i < 514; i++){
        for(int j = 0 ;j < 514; j++){
            for(int k = 0; k < 10; k++){
                memo[i][j][k] = -1;
            }
        }   
    }

    cout << solve(1,1,N) << "\n";
    build_image(1,1,N);

    for(int i =1; i<= N; i++){
        for(int j =1; j<= N; j++){
            cout << image[i][j];
        }
        cout << "\n";
    }

    return 0;
}