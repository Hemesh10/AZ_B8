#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second 

ll binpow(ll a, ll b) {
	a%=MOD;
	ll result=1;
	while(b) {
		if(b&1) result = result*a%MOD;
		a = a*a%MOD;
		b>>=1;
	}
	return result;
}

// ll multiply(ll a, ll b) {
// 	return (a%MOD * b%MOD)%MOD;
// }

void solve(int t) {
	while (t--) {
		int n; cin>>n;

		ll result = (n * ((n-1)*1LL))%MOD;
		result = (result * ((n-2)*1LL))%MOD;
		result = (result * ((n-3)*1LL))%MOD;
		result = (result * binpow(24, MOD-2))%MOD;

		cout<<(result+MOD)%MOD<<'\n';
		
		// ll result = multiply(n, n-1);
		// result = multiply(result, n-2);
		// result = multiply(result, n-3);
		// result = multiply(result, binpow(24, MOD-2));
		// cout<<(result+MOD)%MOD<<'\n';
	}
}

int main() {
	FAST_IO;
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
	int t = 1; 
	cin>>t;
	solve(t);
}