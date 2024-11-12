#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

void solve(int t) {
    while(t--) {
        int n; cin>>n;
        int arr[n], brr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int C[n];
        for(int i=0;i<n;i++) {
            cin>>brr[i];
            C[i] = arr[i]-brr[i];
        }
        sort(C, C+n);

        ll res = 0;
        for(int i=0;i<n;i++) {
            if(C[i]>0) {
                res += n-i-1;
            } else {
                auto it = upper_bound(C+i, C+n, C[i]*-1);
                if(it-C != n) res += n-(it-C);
            }
        }
        cout<<res<<'\n';

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
