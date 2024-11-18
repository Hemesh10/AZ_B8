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
        ll target; cin>>target;
        ll arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll res = arr[0]+arr[1]+arr[2];
        for(int j=0;j<n;j++) {
            int i = 0, k = n-1;
            while(i<j && k>j) {
                ll sum = arr[i]+arr[j]+arr[k];
                if(abs(sum-target)<abs(res-target)) {
                    res = sum;
                }
                if(sum<target) {
                    i++;
                } else {
                    k--;
                }
            }
        }
        cout<<abs(res-target)<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
