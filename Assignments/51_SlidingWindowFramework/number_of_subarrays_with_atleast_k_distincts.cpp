#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;
const int N = 1e6;

int freqArr[N+1];

ll number_of_subarrays_with_at_most_k_distincts(int k, int *arr, int n) {
    int distinctCount = 0;
    int tail = 0, head = -1;
    ll ans = 0;
    while(tail<n) {
        while(head+1<n && (distinctCount<k || freqArr[arr[head+1]]>0)) { 
            head++;
            if(freqArr[arr[head]]==0) {
                distinctCount++;
            }
            freqArr[arr[head]]++;
        }
        ans += (head-tail+1);
        if(tail>head) {
            tail++;
            head = tail-1;
        } else {
            freqArr[arr[tail]]--;
            if(freqArr[arr[tail]] == 0) distinctCount--;
            tail++;
        }
    }
    // cout<<ans<<'\n';
    return ans;
}

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        // ll total = 0;
        // int distinctCount = 0;
        // int tail = 0, head = -1;
        // while(tail<n) {
        //     while(head+1<n && distinctCount<k) {
        //         head++;
        //         if(freqArr[arr[head]]==0) {
        //             distinctCount++;
        //         }
        //         freqArr[arr[head]]++;
        //     }
        //     if(distinctCount>=k) {
        //         total += n-head;
        //     }
        //     // if(head==tail) total--;
        //     // cerr<<"tail: "<<tail<<", count: "<<n-head<<'\n';
        //     if(tail>head) {
        //         tail++;
        //         head = tail-1;
        //     } else {
        //         freqArr[arr[tail]]--;
        //         if(freqArr[arr[tail]]==0) {
        //             distinctCount--;
        //         }
        //         tail++;
        //     }
        // }
        // cout<<total<<'\n';

        cout<<((n*(n+1)/2) - number_of_subarrays_with_at_most_k_distincts(k-1, arr, n))<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
