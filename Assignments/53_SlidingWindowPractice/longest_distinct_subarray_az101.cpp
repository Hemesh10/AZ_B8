#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;
const int N = 0;

void solve(int t) {
    while(t--) {
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        map<int, int> mp;
        int ans = 0;
        int tail = 0, head = -1;
        while(tail<n) {
            while(head+1<n && mp[arr[head+1]]==0) {
                head++;
                mp[arr[head]]++;
            }
            ans = max(ans, head-tail+1);
            if(tail>head) {
                tail++;
                head = tail-1;
            } else {
                mp[arr[tail]]--;
                tail++;
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
