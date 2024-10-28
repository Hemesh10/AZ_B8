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
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        int pse[n], nge[n];
        for(int i=0;i<n;i++) {
            int prev_idx = i-1;
            while(prev_idx >= 0 && arr[prev_idx] >= arr[i]) {
                prev_idx = pse[prev_idx];
            }
            pse[i] = prev_idx;
        }
        for(int i=n-1;i>=0;i--) {
            int next_idx = i+1;
            while(next_idx < n && arr[next_idx] >= arr[i]) {
                next_idx = nge[next_idx];
            }
            nge[i] = next_idx;
        }

        ll maxArea = 0;
        for(int i=0;i<n;i++) {
            int height = arr[i], width = nge[i]-pse[i]-1;
            maxArea = max(maxArea, 1LL*height*width);
        }
        cout<<maxArea<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
