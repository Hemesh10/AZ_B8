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
	string temp; getline(cin, temp);
	while (t--) {
		 string s;
		 getline(cin, s);
		
		 string x, y, z;
		 bool space=false, dot=false;
		 for(size_t i=0;i<s.size();i++) {
		 	if(s[i]==' ') {
		 		space=true;
		 		continue;
		 	}
		 	if(s[i]=='.') {
		 		dot=true;
		 		continue;
		 	}
		  
		 	if(!space) x+=s[i];
		 	else if(!dot) y+=s[i];
		 	else z+=s[i];
		 }
		
		 int a=stoll(x, nullptr, 10), b=stoll(y, nullptr, 10), c=stoll(z, nullptr, 10);
		 cout<<a+c<<'.'<<a+b<<'\n';
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
