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
		int num, den; cin>>num>>den;
		string result;
		
		if((num<0) ^ (den<0)) result+='-';
		num = abs(num);
		den = abs(den);
		
		result+=to_string(num/den);
		int rem = num%den;
		if(!rem) {
			cout<<result<<'\n';
			continue;
		}

		result+='.';
		unordered_map<int, int> rem_positions;
		string decimal_part;
		int pos = 0;
		
		while(rem!=0) {
			if(rem_positions.count(rem)) {
				int recurrence_start = rem_positions[rem];
				decimal_part.insert(recurrence_start, "(");
				decimal_part+=")";
				break;
			}
			rem_positions[rem] = pos;
			rem *= 10;
			decimal_part += to_string(rem/den);
			rem %= den;
			pos++;
		}
		
		result+=decimal_part;
		cout<<result<<'\n';
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