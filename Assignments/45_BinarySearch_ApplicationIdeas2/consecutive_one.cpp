#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

bool check(int x, int k, int *prefix, int n) {
    int start = 0, end = x-1;
    while(end<n) {
        if(x-(prefix[end]-(start>0?prefix[start-1]:0)) <= k) return true;
        ++start; ++end;
    }
    return false;
}

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int prefix[n];
        for(int i=0;i<n;i++) {
            prefix[i] = arr[i];
            if(i) prefix[i] += prefix[i-1];
        }
        int low = 1, high = n, ans = 0;
        while(low<=high) {
            int mid = low + ((high-low)/2);
            if(check(mid, k, prefix, n)) {
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
