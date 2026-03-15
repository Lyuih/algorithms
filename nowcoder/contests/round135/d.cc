#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<ll> a(n);
    ll total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    ll x = total_sum / n;
    if (x * n < total_sum) {
        x++;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < x) {
            ans += (x - a[i]);
        }
    }
    cout << ans << "\n";
}

int main() {

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}