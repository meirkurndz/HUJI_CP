#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
typedef map<long long, int> mlli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll dist_keys = 0;
    ll doub_keys = 0;
    mlli q;

    int n;
    cin >> n;
    while(n--){
        string oper;
        int num;
        cin >> oper >> num;
        if(oper == "insert"){
            if(q.count(num) == 0){
                q[num] = 1;
                dist_keys++;
            }else{
                q[num]++;
                if(q[num] == 2){
                    doub_keys++;
                }
            }
        }else if(oper == "delete"){
            if(q.count(num) != 0){
                q[num]--;
                if(q[num] == 1){
                    doub_keys--;
                }
                else if(q[num] == 0){
                    dist_keys--;
                    q.erase(num);
                }
            }
        }

        if(dist_keys > 1){
            if(doub_keys > 0){
                cout << "both\n";
            }else{
                cout << "hetero\n";
            }
        }else if(doub_keys > 0){
            cout << "homo\n";
        }else{
            cout  << "neither\n";
        }

    }
}