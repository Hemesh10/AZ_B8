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
		int N,M,Q; cin>>N>>M>>Q;
		
		int arr[N][M] = {};
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				cin>>arr[i][j];
				if(arr[i][j]>=0) {
					cerr<<' '<<arr[i][j]<<'\t';
				} else {
					cerr<<arr[i][j]<<'\t';
				}
			}
			cerr<<'\n';
		}
		
		cerr<<'\n';
		
		int P[N][M]={};
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				P[i][j]+=arr[i][j];
				if(i) P[i][j]+=P[i-1][j];
				if(j) P[i][j]+=P[i][j-1];
				if(i&&j) P[i][j]-=P[i-1][j-1];
				if(P[i][j]>=0) {
					cerr<<' '<<P[i][j]<<'\t';
				} else {
					cerr<<P[i][j]<<'\t';
				}
			}
			cerr<<'\n';
		}
		
		for(int i=0;i<Q;i++) {
			int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
			x1--; y1--;
			x2--; y2--;
			int ans = P[x2][y2];
			if(x1) ans-=P[x1-1][y2];
			if(y1) ans-=P[x2][y1-1];
			if(x1&&y1) ans+=P[x1-1][y1-1];
			cout<<((ans%MOD)+MOD)%MOD<<'\n';
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