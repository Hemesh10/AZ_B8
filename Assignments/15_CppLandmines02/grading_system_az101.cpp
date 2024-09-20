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
		int m, f, r; cin>>m>>f>>r;
		int total_marks = m+f;
		char grade;
		if(m==-1 || f==-1 || total_marks<30) {
			grade='F';
		} else if(total_marks<50) {
			grade=r>=50?'C':'D';
		} else if(total_marks<65) {
			grade='C';
		} else if(total_marks<80) {
			grade='B';
		} else grade='A';
		cout<<grade<<'\n';
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