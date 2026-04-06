#include <iostream>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll nx,ny;
    ld w;
    while (cin >> nx >> ny >> w){
        if(nx ==0 && ny ==0 && w == 0.0) break;
        ld p_x[nx], p_y[ny];

        for(int i = 0; i < nx ; i++){
            cin >> p_x[i];
        }
        for(int i = 0; i < ny ; i++){
            cin >> p_y[i];
        }

        sort(p_x,p_x+nx);
        sort(p_y,p_y+ny);

        bool x_covered = true;
        bool y_covered = true;

        if(p_x[0] > w/2.0) x_covered = false;
        for(int i = 0; i < nx-1; i++){
            if(p_x[i+1] - p_x[i] > w) {
                x_covered = false;}
        }
        if(75 - p_x[nx-1] > w/2.0) x_covered =false;

        if(p_y[0] > w/2) y_covered = false;
        for(int i = 0; i < ny-1; i++){
            if(p_y[i+1] - p_y[i] > w){
                 y_covered = false;
                }
        }
        if(100 - p_y[ny-1] > w/2.0) y_covered =false;

        if(x_covered && y_covered){
            cout << "YES\n";    
        }else{
            cout << "NO\n";
        }
    }
}