#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

typedef deque<long long> dqll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    dqll dq;
    bool is_reversed = false;
    
    while(Q--){
        string oper;
        cin >> oper;
        if(oper == "reverse"){
            is_reversed = !is_reversed;
        }else if(oper == "front"){
            if(dq.empty()){
                cout << "No job for Ada?\n";
            }else{
                if(!is_reversed){
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }else{
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
            }
            
        }else if(oper == "back"){
            if(dq.empty()){
                cout << "No job for Ada?\n";
            }else{
                if(is_reversed){
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }else{
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
            }
        }else if(oper == "toFront"){
            int n;
            cin >> n;
            if(!is_reversed){
                dq.push_front(n);
            }else{
                dq.push_back(n);
            }
        }else if(oper == "push_back"){
            int n;
            cin >> n;
            if(is_reversed){
                dq.push_front(n);
            }else{
                dq.push_back(n);
            }
        }

    }



    return 0;
}