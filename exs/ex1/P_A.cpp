#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare_latters(char a, char b){
    char lower_a = tolower(a);
    char lower_b = tolower(b);

    if(lower_a != lower_b){
        return lower_a < lower_b;
    }
    return a <b;
}

void print_perms(){
    string word;
    cin >> word;

    sort(word.begin(),word.end(),compare_latters);
    do{
        cout << word << "\n";
    }while(next_permutation(word.begin(),word.end(),compare_latters));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        print_perms();
    }
    return 0;
}