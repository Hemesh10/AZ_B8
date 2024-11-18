#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

ll numberOfSubarraysLessThanEqualTo(int k, int *arr, int n) {
    ll sum = 0, total = 0;
    int tail = 0, head = -1;
    while(tail<n) {
        while(head+1<n && sum+arr[head+1]<=k) {
            head++;
            sum+=arr[head];
        }
        total += (head-tail+1);
        if(tail>head) {
            tail++;
            head = tail-1;
        } else {
            sum-=arr[tail];
            tail++;
        }
    }
    // cout<<total<<'\n';
    return total;
}

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        // ll sum = 0, total = 0;
        // int tail = 0, head = -1;
        // while(tail<n) {
        //     while(head+1<n && sum+arr[head+1]<k) {
        //         head++;
        //         sum+=arr[head];
        //     }
        //     total += n-head-1;
        //     // cerr<<"Tail: "<<tail<<", count: "<<(((n-1)-tail+1) - (head-tail+1))<<'\n';
        //     if(tail>head) {
        //         tail++;
        //         head = tail-1;
        //     } else {
        //         sum-=arr[tail];
        //         tail++;
        //     }
        // }
        // cout<<total<<'\n';

        // Number of subarrays greater than or equal to K can be termed as: (Total number of subarrays) - (Number of subarays with sum less than or equal to K-1)
        cout<<(1LL*(n*(n+1)/2) - numberOfSubarraysLessThanEqualTo(k-1, arr, n))<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
