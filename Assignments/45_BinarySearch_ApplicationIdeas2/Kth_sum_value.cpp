#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mod = 1e9+7;
const long long inf = 1e18;
const double pi = 3.1415926535897932384626;

bool check(int x, ll k, int *arr, int n, int *brr, int m) {
    if(n>m) {
        int *temp = arr;
        arr = brr;
        brr = temp;
        swap(n, m);
    }
    ll count = 0;
    for(int i=0;i<n;i++) {
        int y = x - arr[i];
        if(y<0) break;
        count += (upper_bound(brr, brr+m, y)-brr);
    }
    return count>=k?true:false;
}

void solve(int t) {
    while(t--) {
        int n, m; cin>>n>>m;
        ll k; cin>>k;
        int arr[n], brr[m];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(int i=0;i<m;i++) {
            cin>>brr[i];
        }
        sort(arr, arr+n);
        sort(brr, brr+m);
        int low = arr[0]+brr[0], high = arr[n-1]+brr[m-1], ans = -1;
        while(low<=high) {
            int mid = low + ((high-low)/2);
            if(check(mid, k, arr, n, brr, m)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
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
