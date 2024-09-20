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
		int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
		int x3, y3, x4, y4; cin>>x3>>y3>>x4>>y4;
		
		int x5 = max(x1, x3);
		int y5 = max(y1, y3);
		int x6 = min(x2, x4);
		int y6 = min(y2, y4);
		
		int intersection_area = 0;
		if(!(x5>=x6 || y5>=y6)) {
			intersection_area = (x6-x5)*(y6-y5);
		}
		// cout<<intersection_area<<'\n';
		int area1 = (x2-x1)*(y2-y1);
		int area2 = (x4-x3)*(y4-y3);
		cout<<intersection_area<<' '<<area1+area2-intersection_area<<'\n';
		
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