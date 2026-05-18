#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b>a) return gcd(b,a);
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int i =0;i<T;i++){
        ll Ax,Ay,Bx,By;
        cin >> Ax >> Ay >> Bx >> By;
        ll dx = abs(Ax-Bx);
        ll dy = abs(Ay-By);
        cout << "Case " << (i+1) << ": " << (gcd(dx,dy)+1) << "\n";
    }
   

}