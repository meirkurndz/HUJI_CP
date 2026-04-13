#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,A,B,C;
    cin >> N;
    while(N--){
        int A,B,C;
        cin >>A>>B>>C;
        bool is_solved = false;
        for(int x = -100; x < 100; x++){
            for(int y = x+1; y < 100; y++){
                int z = A-x-y;
                if(z > y){
                    if(x*y*z == B && (x*x + y*y + z*z == C)){
                        cout << x << " " << y << " " << z << "\n";
                        is_solved = true;
                        break;
                    }
                }
            }
            if(is_solved) break;
        }
        if(!is_solved){
            cout << "No solution.\n";
        }
    }

    return 0;
}