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

void solve(int t) {
	//for (int i=0;i<7;i++) {
	//	cout<<"33"<<'\n';
	//}

	while (t--) {
		int n; cin>>n;
		ll result=1;
		for(int i=1;i<=4;i++) {
			result = result*(n-i+1) % MOD;
		}
		result = result * binpow(24, MOD-2) % MOD;
		result = 1 + result + (((n*1LL)*((n-1)*1LL))%MOD * binpow(2, MOD-2)%MOD) - n;
		cout<<((result%MOD)+MOD)%MOD<<'\n';
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
