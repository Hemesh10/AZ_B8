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
        int n; cin>>n;
        pair<string, int> students[n];
        for(int i=0;i<n;i++) {
            cin>>students[i].first>>students[i].second;
        }
        sort(students, students+n, [](pair<string, int>& a, pair<string, int>& b){
            return a.second<b.second;   
        });
        for(auto& it:students) {
            cout<<it.first<<' '<<it.second<<'\n';
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
