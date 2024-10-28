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
        int fgi_l[n], fgi_r[n];
        int curr_fgi = 0;
        for(int i=0;i<n;i++) {
            if(arr[i] > arr[curr_fgi]) curr_fgi = i;
            fgi_l[i] = curr_fgi==i?-1:curr_fgi;
        }
        curr_fgi = n-1;
        for(int i=n-1;i>=0;i--) {
            if(arr[i] > arr[curr_fgi]) curr_fgi = i;
            fgi_r[i] = curr_fgi==i?-1:curr_fgi;
        }

        ll total = 0;
        for(int i=0;i<n;i++) {
            if(fgi_l[i]!=-1 && fgi_r[i]!=-1) {
                total += min(arr[fgi_l[i]], arr[fgi_r[i]]) - arr[i];
            }
        }
        cout<<total<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
