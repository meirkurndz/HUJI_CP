#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool check(const vector<ll>& presum, int n, int f, double target) {
    double min_val = 0;
    for (int i = f; i <= n; i++) {
        double s_j = (double)presum[i - f] - (double)(i - f) * target;
        if (s_j < min_val) min_val = s_j;

        double s_i = (double)presum[i] - (double)i * target;
        if (s_i >= min_val - 1e-10) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, f;
    cin >> n >> f;

    vector<ll> presum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll val;
        cin >> val;
        presum[i] = presum[i - 1] + val;
    }

    ll low = 0, high = 2000000;
    ll ans = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(presum, n, f, mid / 1000.0)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}