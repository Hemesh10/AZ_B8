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

ll binpow(ll a, ll b, int P) {
	a%=P;
	ll result = 1;
	while(b) {
		if(b&1) result = result * a % P;
		a = a*a % P;
		b>>=1;
	}
	// cout<<result<<'\n';
	return result;
}

void solve(int t) {
	while (t--) {
		int a, b, c, p; cin>>a>>b>>c>>p;
		if(b==0) {
			if(c>0) {
				cout<<1<<'\n';
				continue;
			}
			cout<<a%p<<'\n';
			continue;
		}
		if(a%p==0) {
			cout<<0<<'\n';
			continue;
		}
		
		cout<<binpow(a, binpow(b, c, p-1), p)%p<<'\n';
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