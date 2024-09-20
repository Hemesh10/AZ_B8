#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;
const int N = 1e7;

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second 

void precompute(vector<ll>& squares, vector<ll>& cubes) {
	squares.PB(1);
	cubes.PB(1);
	ll sqr, i = 2;
	while(true) {
		sqr = i*i;
		if(sqr>N) break;
		squares.PB(sqr);
		i++;
	}
	
	ll cube;
	int j = 2;
	while(true) {
		cube = j*j*j;
		if(cube>N) break;
		cubes.PB(cube);
		j++;
	}
}

void solve(int t) {
	vector<ll> squares, cubes;
	precompute(squares, cubes);
	while (t--) {
		int q, n; cin>>q>>n;	
		if(q==1) {
			cout<<(binary_search(squares.begin(), squares.end(), n)?"YES":"NO")<<'\n';
		} else {
			cout<<(binary_search(cubes.begin(), cubes.end(), n)?"YES":"NO")<<'\n';
		}
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