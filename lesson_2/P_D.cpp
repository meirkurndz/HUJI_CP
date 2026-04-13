#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;

typedef long long ll;

struct Point{
    double x,y;
};

double d(Point p1, Point p2){
    return sqrt(
        pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2)
    );
}

Point inter(double t,Point p1, Point p2){
    Point ret = {p1.x*(1-t) + t*p2.x, p1.y*(1-t) + t*p2.y};
    return ret;
}

double d_at_t(double t,Point A, Point B,Point C,Point D){
    Point temp1 = inter(t,A,B);
    Point temp2 = inter(t,C,D);
    return d(temp1,temp2);
}

//P_1(t) = tA+(1-t)B
//P_2(t) = tC+(1-t)D
//f(t) = |P_1(t) - P_2(t)| 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    double e = 1e-9;

    for(int i = 1; i<=T;i++){
        Point A,B,C,D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        double low = 0.0, high = 1.0;
        while(high-low > e){
            double mid1 = low + ((high-low)/3.0);
            double mid2 = high - ((high-low)/3.0);
            if(d_at_t(mid1,A,B,C,D) < d_at_t(mid2,A,B,C,D)){
                high = mid2;
            }else{
                low = mid1;
            }
        }

        cout << "Case " << i << ": " << fixed << setprecision(10) <<  d_at_t(low,A,B,C,D) << "\n";
    }

    return 0;
}