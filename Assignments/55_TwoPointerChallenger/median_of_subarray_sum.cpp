#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;
const int N = 0;

bool check(ll x, ll k, ll *arr, int n) {
    ll sum = 0, count = 0;
    int tail = 0, head = -1;
    while(tail<n) {
        while(head+1<n && sum+arr[head+1]<=x) {
            head++;
            sum+=arr[head];
            count += head-tail+1;
        }
        if(tail>head) {
            tail++;
            head=tail-1;
        } else {
            sum-=arr[tail];
            tail++;
        }
    }
    // cout<<"x: "<<x<<", count: "<<count<<'\n';
    return count>=k;
}

void solve(int t) {
    while(t--) {
        int n; cin>>n;
        ll arr[n];
        ll low = 1e9, high = 0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            low = min(low, arr[i]);
            high += arr[i];
        }
        // sort(arr, arr+n);
        ll total = 1LL*n*(n+1)/2;
        ll k = (total+1)/2;

        ll res = low;
        // cerr<<"k: "<<k<<'\n';
        while(low<=high) {
            ll mid = low + ((high-low)/2);
            // cerr<<"mid: "<<mid<<'\n';
            if(check(mid, k, arr, n)) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            } 
        }
        cout<<"\n\nres: "<<res<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
