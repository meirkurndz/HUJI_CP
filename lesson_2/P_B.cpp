#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

struct Movie{
    int start,end;
};

bool compMovies(Movie& m1,Movie& m2){
    if(m1.end == m2.end){
        return m1.start < m2.start;
    }
    return m1.end < m2.end;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<Movie> movs(n);
    for(int i = 0; i < n; i++){
        cin >> movs[i].start >> movs[i].end; 
    }

    sort(movs.begin(),movs.end(),compMovies);

    multiset<int> last_movie_end;
    for(int i = 0; i < k; i++){
        last_movie_end.insert(0);
    }

    int total_movies = 0;
    for(int i = 0; i < n; i++){
        auto it = last_movie_end.upper_bound(movs[i].start);
        if(it == last_movie_end.begin()) continue;
        it--;
        last_movie_end.erase(it);
        last_movie_end.insert(movs[i].end);
        total_movies++;
    }
    cout << total_movies;
    return 0;
}