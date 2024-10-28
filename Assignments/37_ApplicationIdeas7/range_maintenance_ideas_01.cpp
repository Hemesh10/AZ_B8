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
        int n, q; cin>>n>>q;
        pii ranges[n];
        for(int i=0;i<n;i++) {
            cin>>ranges[i].first>>ranges[i].second;
        }
        
        int start[n], end[n];
        for(int i=0;i<n;i++) {
            start[i] = ranges[i].first;
            end[i] = ranges[i].second;
        }
        sort(start, start+n);
        sort(end, end+n);

        int valid_ranges = 0;
        while(q--) {
            int x; cin>>x;
            int start_count = n - (upper_bound(start, start+n, x) - start); // kitne intervals x point ke baad shuru hue
            int end_count = lower_bound(end, end+n, x) - end; // kitne intervals x point ke pehle he end ho haye
            valid_ranges = n - (start_count+end_count); // intervals jo above two conditions ko satisfy karte h, unko chhorke baaki sabhi intervals valid rhene agar dekha jaye to
            cout<<valid_ranges<<'\n'<<'\n';
        }
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
