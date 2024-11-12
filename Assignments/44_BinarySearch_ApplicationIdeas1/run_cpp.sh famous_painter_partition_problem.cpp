#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

int check(ll x, int arr[], int n) {
    int painters = 1;
    ll paint_threshold = x;
    for(int i=0;i<n;i++) {
        if(arr[i] <= paint_threshold) {
            paint_threshold -= arr[i];
        } else {
            ++painters;
            paint_threshold = x - arr[i];
        }
    }
    return painters;
}

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int arr[n];
        ll low = 0, high = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            low = max(low, static_cast<ll>(arr[i]));
            high += arr[i];
        }
        ll ans = high;
        while(low<=high) {
            ll mid = low + ((high-low)/2);
            if(check(mid, arr, n) <= k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        cout<<ans<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
