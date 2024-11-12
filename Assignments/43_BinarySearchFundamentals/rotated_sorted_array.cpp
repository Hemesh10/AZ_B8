#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

int check(int arr[], int n, int mid) {
    if(arr[mid]<=arr[n-1]) {
        return 1;
    } else {
        return 0;
    }
}

void solve(int t) {
    while(t--) {
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int low = 0, high = n-1, ans = -1;
        while(low<=high) {
            int mid = low + ((high-low) / 2);
            if(check(arr, n, mid)) {
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
