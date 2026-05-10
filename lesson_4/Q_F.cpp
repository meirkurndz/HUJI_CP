#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n; i++) {
        if (i + 1 == n || a[i + 1] < (i + 2)) {
            
            ll right = a[i] - (i + 1);

            int down = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] >= (i + 1)) down++;
                else break;
            }

            if (right % 2 != 0 || down % 2 != 0) {
                cout << "first" << endl;
            } else {
                cout << "second" << endl;
            }
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}