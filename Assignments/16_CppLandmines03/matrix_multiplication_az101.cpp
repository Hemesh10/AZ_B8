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
		int n,m,p; cin>>n>>m>>p;
		int A[n][m], B[m][p];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>A[i][j];
			}
		}
		for(int i=0;i<m;i++) {
			for(int j=0;j<p;j++) {
				cin>>B[i][j];
			}
		}
		
		for (int i=0;i<n;i++) {
            for (int j=0;j<p;j++) {
                int sum=0;
                for (int k=0;k<m;k++) {
                    sum+=A[i][k]*B[k][j];
                }
                cout<<sum<<' ';
            }
            cout<<'\n';
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