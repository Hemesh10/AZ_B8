#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

void solve(int t) {
    while(t--) {
        int n, x; cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll res=0;
        for(int i=0;i<n;i++) {
            int j = x-arr[i];
            auto it = upper_bound(arr, arr+n, j);
            if(it-(arr+i) > 1) res += it-(arr+i)-1;
        }
        cout<<res*2<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cout.tie(nullptr);cerr.tie(nullptr);
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
    int t = 1; 
    cin>>t;
    solve(t);
}
