#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;
const int N = 1000001;

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second 

void solve(int t) {
	while (t--) {
		int n,k,q; cin>>n>>k>>q;
		int arr[N]={0};
		for(int i=0;i<n;i++) {
			int l,r; cin>>l>>r;
			arr[l]+=1;
			arr[r+1]-=1;
		}
		
		for(int i=1;i<N;i++) {
			arr[i]+=arr[i-1];
		} 
		
		for(int i=0;i<N;i++) {
			arr[i] = arr[i]>=k?1:0;
		}
		
		// int prefix[N];
		// prefix[0]=arr[0];
		// for(int i=1;i<N;i++) {
		// 	prefix[i] = prefix[i-1]+arr[i];
		// }
		// while(q--) {
		// 	int l,r; cin>>l>>r;
		// 	cout<<prefix[r]-prefix[l-1]<<'\n';
		// }
		
		for(int i=1;i<N;i++) {
			arr[i]+=arr[i-1];
		}
		
		while(q--) {
			int l,r; cin>>l>>r;
			cout<<arr[r]-arr[l-1]<<'\n';
		}
	}
}

int main() {
	FAST_IO;
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
	int t = 1; 
	// cin>>t;
	solve(t);
}