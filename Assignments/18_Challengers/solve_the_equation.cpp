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

ll binpow(ll a, ll b, ll mod) {
	a%=mod;
	ll result = 1;
	while(b) {
		if(b&1) result = result * a % mod;
		a = a*a % mod;
		b>>=1;
	}
	return result;
}

void helper(string& s, char ch, ll& var, char& op, int& j) {
	while(s[j]!=ch) {
		var = var*10+(s[j]-'0');
		j++;
	}
	op = s[++j];
	j+=2;
}

ll reverse(ll mod) {
	ll rev=0;
	while(mod) {
		int digit = mod%10;
		rev = rev*10+digit;
		mod /= 10;
	}
	return rev;
}
void solve(int t) {
	string temp;
	getline(cin, temp);
	while (t--) {
		string s;
		getline(cin, s);
		// cout<<s<<'\n';
		
		ll var1=0, var2=0, var3=0;
		ll mod=0;
		char op1, op2;
		
		int j=1;
		helper(s, ' ', var1, op1, j);
		helper(s, ' ', var2, op2, j);
		char temp;
		helper(s, ')', var3, temp, j);
		
		cout<<var1<<' '<<var2<<' '<<var3<<'\n';
		// cout<<op1<<' '<<op2<<'\n';
		
		j = s.size()-1;
		while(s[j]!=' ') {
			mod = mod*10+(s[j]-'0');
			j--;
		}
		mod = reverse(mod);
		cout<<mod<<'\n';
		
		ll result;
		if(op1=='*') {
            if(op2=='*') result = (((var1%mod) * (var2%mod))%mod * (var3%mod))%mod;
            else if (op2=='/') result = (((var1%mod)*(var2%mod))%mod * binpow(var3, mod-2, mod))%mod;
            else if(op2=='+') result = (((var1%mod) * (var2%mod))%mod + (var3%mod))%mod;
            else result = (((((var1%mod)*(var2%mod))%mod - (var3%mod))%mod)+mod)%mod;
        } else if(op1=='/') {
            if(op2=='*') result = (((var1%mod) * (var3%mod))%mod * binpow(var2, mod-2, mod))%mod; 
            else if(op2=='/') result = (var1%mod * binpow(((var2%mod)*(var3%mod))%mod, mod-2, mod))%mod;
            else if(op2=='+') result = ((var1%mod + ((var2%mod)*(var3%mod)))%mod * binpow(var2, mod-2, mod))%mod;
            else result = ((((var1%mod - ((var2%mod)*(var3%mod))%mod)%mod)+mod)%mod * binpow(var2, mod-2, mod))%mod;
        } else if(op1=='+') {
            if(op2=='*') result = ((var1%mod) + ((var2%mod)*(var3%mod))%mod)%mod;
            else if(op2=='/') result = ((((var1%mod)*(var3%mod))%mod+(var2%mod))%mod * binpow(var3, mod-2, mod))%mod;
            else if(op2=='+') result = (var1%mod + var2%mod + var3%mod)%mod;
            else result = (((var1%mod + var2%mod - var3%mod)%mod)+mod)%mod;
        } else if(op1=='-') {
            if(op2=='*') result = ((((var1%mod) - ((var2%mod)*(var3%mod))%mod)%mod)+mod)%mod;
            else if(op2=='/') result = ((((((var1%mod)*(var3%mod))%mod - (var2%mod))%mod)+mod)%mod * binpow(var3, mod-2, mod))%mod;
            else if(op2=='+') result = (((var1%mod - var2%mod + var3%mod)%mod)+mod)%mod;
            else result = (((var1%mod - var2%mod - var3%mod)%mod)+mod)%mod;
        }
		cout<<(result+mod)%mod<<'\n';
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