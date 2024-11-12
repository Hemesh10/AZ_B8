#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

int check(int arr[], int n, int mid) {
    if(mid == n) return 1;
    if(arr[mid] > arr[mid+1]) {
        return 1;
    } else {
        return 0;
    }
}

void solve(int t) {
    while(t--) {
        int n, q; cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        int low = 0, high = n-1, peak = -1;
        while(low<=high) {
            int mid = low + ((high-low)/2);
            if(check(arr, n, mid)) {
                peak = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        vector<int> left, right;
        for(int i=0;i<=peak;i++) {
            left.push_back(arr[i]);
        }

        for(int i=n-1;i>peak;i--) {
            right.push_back(arr[i]);
        }
        
        while(q--) {
            int k; cin>>k;
            auto it = lower_bound(left.begin(), left.end(), k);
            if(it!=left.end() && *it==k) cout<<it-left.begin()+1<<' ';
            it = lower_bound(right.begin(), right.end(), k);
            if(it!=right.end() && *it==k) cout<<n-(it-right.begin());
            cout<<'\n';

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
