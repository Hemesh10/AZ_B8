#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second 

void solve(int t) {
    while(t--) {
        int n, q; cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        for(int i=1;i<n;i++) {
            arr[i]+=arr[i-1];
        } 
        while(q--) {
            int m; cin>>m;
            cout<<upper_bound(arr, arr+n, m)-arr<<'\n';
        }
        cout<<'\n';
    }
}
        
int main() {
    FAST_IO;
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
    int t = 1; 
    // cin>>t;
    solve(t);
}
