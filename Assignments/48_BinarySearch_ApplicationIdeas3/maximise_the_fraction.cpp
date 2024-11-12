#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using ld = long double;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

bool check(ld x, int k, int *A, int * B, int n) {
    priority_queue<ld> pq;
    for(int i=0;i<n;i++) {
        pq.push(-1*(A[i]-(x*B[i])));
        if(pq.size()>k) pq.pop();
    }
    ld sum = 0;
    while(pq.size()) {
        sum+=(-1*pq.top());
        pq.pop();
    }
    // cerr<<sum<<'\n';
    return sum>=0;
}

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int A[n], B[n];
        for(int i=0;i<n;i++) cin>>A[i];
        for(int i=0;i<n;i++) cin>>B[i];

        ld low = 0.0, high = 10000.0;
        ld ans = low;
        while(abs(low-high)>1e-9) {
            // cerr<<"ff"<<'\n';
            ld mid = (low+high)/2.0;
            if(check(mid, k, A, B, n)) {
                ans = mid;
                low = mid;
            } else {
                high = mid;
            }
        }
        cout<<fixed<<setprecision(6)<<ans<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1;
    cin>>t;
    solve(t);
}
