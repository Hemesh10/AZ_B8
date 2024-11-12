#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

ll check(int x, int n, int arr[]) {
    ll totalPoints = 0;
    for(int i=1;i<n;i++) {
        int d = arr[i]-arr[i-1];
        totalPoints += ((d+x-1)/x)-1; // ceil - 1
    }
    return totalPoints;
}

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int arr[n];
        int low = 1, high = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            high = max(high, arr[i]);
        }
        int ans = high;
        while(low<=high) {
            int mid = low + ((high-low)/2);
            if(check(mid, n, arr)<=k) {
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
