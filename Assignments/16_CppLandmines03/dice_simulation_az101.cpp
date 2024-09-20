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
		int arr[6];
		for(int i=0;i<6;i++) {
			cin>>arr[i];
		}
		string moves; cin>>moves;
		int up=arr[0], mid=arr[1], right=arr[2], left=arr[3], back=arr[4], down=arr[5];
		for(char ch:moves) {
			if(ch=='N') {
				int temp = up;
				up = mid;
				mid = down;
				down = back;
				back = temp;
			} else if(ch=='S') {
				int temp = up;
				up = back;
				back = down;
				down = mid;
				mid = temp;
			} else if(ch=='W') {
				int temp = up;
				up = right;
				right = down;
				down = left;
				left = temp;
			} else {
				int temp = up;
				up = left;
				left = down;
				down = right;
				right = temp;
			}
		}
		cout<<up<<'\n';
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