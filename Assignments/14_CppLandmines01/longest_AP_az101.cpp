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
		int n; cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];	
		}
		int length = 2, max_length = 2;
		int current_diff = arr[1]-arr[0];
		cerr<<current_diff<<'\n';
		for(int i=2;i<n;i++) {
			if(arr[i]-arr[i-1]==current_diff) {
				length++;
			} else {
				// cerr<<'('<<i<<", "<<i-1<<')'<<" : "<<arr[i]-arr[i-1]<<'\n';
				current_diff = arr[i]-arr[i-1];
				length = 2;
			}
			max_length = max(length, max_length);
		}
		cout<<max_length<<'\n';
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