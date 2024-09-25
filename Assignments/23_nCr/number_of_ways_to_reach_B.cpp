#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;
const int N = 2e5;

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second kb

ll factorial[N+1];

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

void precompute() {
	factorial[0]=1;
	for(int i=1;i<=N;i++) {
		factorial[i] = factorial[i-1]*i%MOD;
	}
}

void solve(int t) {
	precompute();
	while (t--) {
		int n, m; cin>>n>>m;
		ll result = (factorial[n+m]%MOD * binpow(factorial[n], MOD-2)%MOD)%MOD;
		result = (result%MOD * binpow(factorial[m], MOD-2)%MOD)%MOD;
		cout<<result<<'\n';
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