#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

int sum_of_digits(ll x) {
    int sum = 0;
    while(x) {
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int check(ll x, ll s) {
    if(x-sum_of_digits(x) >= s) {
        return 1;
    } else {
        return 0;
    }
}

void solve(int t) {
    while(t--) {
        ll n, s; cin>>n>>s;
        ll low = 1, high = n, ans = 0;
        while(low<=high) {
            ll mid = low + ((high-low)/2);
            if(check(mid, s)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        cout<<(ans?n-ans+1:ans)<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
