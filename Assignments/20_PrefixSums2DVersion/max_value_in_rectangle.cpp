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
		ll arr[N+2][M+2]={};
		while(Q--) {
			int x1,y1,x2,y2,C;
			cin>>x1>>y1>>x2>>y2>>C;
			arr[x1][y1]+=C;
			arr[x2+1][y1]-=C;
			arr[x1][y2+1]-=C;
			arr[x2+1][y2+1]+=C;
		}
		
		ll P[N+2][M+2]={}, maxN=LLONG_MIN;
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<M+1;j++) {
				// P[i][j]=(arr[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]);
				P[i][j] = arr[i][j];
				P[i][j]+=P[i-1][j];
				P[i][j]+=P[i][j-1];
				P[i][j]-=P[i-1][j-1];
				maxN = max(maxN, P[i][j]);
			}
		}
		
		ll cnt=0;
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<M+1;j++) {
				if(P[i][j]==maxN) cnt++;
			}
		}
		
		cout<<maxN<<' '<<cnt<<'\n';
	}
}

int main() {
	FAST_IO;
// #ifndef ONLINE_JUDGE
//     (void)!freopen("error.txt", "w", stderr);
// #endif
	int t = 1; 
	// cin>>t;
	solve(t);
}