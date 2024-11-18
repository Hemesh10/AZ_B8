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
        int n, k, d; cin>>n>>k>>d;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int prefix[n];
        for(int i=0;i<n;i++) {
            prefix[i] = arr[i];
            if(i) prefix[i]+=prefix[i-1];
            // cout<<prefix[i]<<' ';
        }
        // cout<<'\n';
        int res = INT_MIN;
        multiset<int> st;
        int oddCount = 0;
        int tail = 0, head = -1;
        while(tail<n) {
            while(head+1<n && oddCount+(arr[head+1]&1?1:0)<=k) {
                head++;
                if(arr[head]%2) oddCount++;
                st.insert(prefix[head]);
            }
            int l = tail>0?prefix[tail-1]:0;
            auto it = st.upper_bound(d+l);
            if(it!=st.begin()) {
                --it;
                res = max(res, *it-l);
            }
            if(tail>head) {
                tail++;
                head = tail-1;
            } else {
                oddCount -= arr[tail]&1?1:0;
                st.erase(st.find(prefix[tail]));
                tail++;
            }
        }
        if(res == INT_MIN) cout<<"IMPOSSIBLE"<<'\n';
        else cout<<res<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
