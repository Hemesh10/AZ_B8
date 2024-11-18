#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

void solve(int t) {
    while(t--) {
        int n, k; cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
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
