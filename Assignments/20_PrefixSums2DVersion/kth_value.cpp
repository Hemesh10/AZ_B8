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

void solve(int t) {
	while (t--) {
		int n,m,q; cin>>n>>m>>q;
		int arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		ll P[n]={};
		for(int i=0;i<m;i++) {
			int l, r; cin>>l>>r;
			P[l-1]++;
			if(r<n)P[r]--;
		}
		
		for(int i=1;i<n;i++) {
			P[i]+=P[i-1];
		}
		
		map<ll, ll> mp;
		for(int i=0;i<n;i++) {
			mp[arr[i]] += P[i];
		}
		
		// for(auto& it:mp) {
		// 	cout<<it.F<<" : "<<it.S<<'\n';
		// }
		
		int k = mp.size();
		pair<ll, ll> result[k];
		int j=0;
		for(auto& it:mp) {
			result[j].F = it.S;
			result[j].S = it.F;
			if(j) result[j].F += result[j-1].F;
			j++;
		}
		
		while(q--) {
			ll x; cin>>x;
			auto it = lower_bound(result, result+k, x, [](pair<ll, ll>& p, ll val) {
				return p.F < val;
			});
			if(it != result+k) {
				cout<< it->S <<' ';
			} else {
				cout<<-1<<' ';
			}
		}
		cout<<'\n';
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