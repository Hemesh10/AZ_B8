#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

// bool check(int start, int end, int k, int *prefix) {
//     return prefix[end]-(start>0?prefix[start-1]:0) <= k;
// }
bool check(int start, int end, int k, int *prefix) {
    int count = prefix[end] - (start > 0 ? prefix[start - 1] : 0);
    return count <= k;  // Now check if count is within the limit of k
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
            prefix[i] = arr[i]^1;
            if(i) prefix[i]+=prefix[i-1];
            // cerr<<prefix[i]<<' ';
        }
        ll total = 0;
        for(int st=0;st<n;st++) {
            int low = st;
            int high = n-1;
            int ans = st-1; // st-1 in case ans never updates
            while(low<=high) {
                int mid = low + ((high-low)/2);
                if(check(st, mid, k, prefix)) {
                    ans = mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            total += ans-(st-1);
        }
        cout<<total<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
