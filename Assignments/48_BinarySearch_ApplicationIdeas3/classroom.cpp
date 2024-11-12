#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

bool check(int d, int k, int *arr, int n) {
    int minD = INT_MAX, prevPoint = 0;
    for(int i=1;i<n-1&&k;i++) {
        if(arr[i]-arr[prevPoint]>=d && arr[n-1]-arr[i]>=d) {
            --k;
            prevPoint = i;
        }
    }
    return !k;
}

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int low = INT_MAX, high = arr[n-1]-arr[0];
        for(int i=1;i<n;i++) {
            low = min(low, arr[i]-arr[i-1]);
        }
        // cout<<"low: "<<low<<", high: "<<high<<'\n';
        // for(int i=0;i<n;i++) {
        //     cerr<<arr[i]<<' ';
        // } cerr<<'\n';
        // for(int i=0;i<n;i++) {
        //     if(i) cerr<<arr[i]-arr[i-1]<<' ';
        // } cerr<<'\n';
        int ans = high;
        while(low<=high) {
            int mid = low + ((high-low)/2);
            if(check(mid, k-2, arr, n)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
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
