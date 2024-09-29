#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

#define int ll

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second

int primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
    307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
    401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
    503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599,
    601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
    701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
    809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997
};

char operators[] = {'*', '+', '-', '/'};

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

inline ll add(ll a, ll b, ll MOD) {
    ll ans = (a % MOD + b % MOD) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

inline ll sub(ll a, ll b, ll MOD) {
    ll ans = (a % MOD - b % MOD) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

inline ll mul(ll a, ll b, ll MOD) {
    ll ans = (a % MOD * b % MOD) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

inline ll power(ll a, ll b, ll M) {
    a %= M;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (((res % M) * (a % M)) % M);
        }
        a = (((a % M) * (a % M)) % M);
        b >>= 1;
    }
    return res;
}
ll modmultiply(ll a, ll b, ll mod)
{
    ll ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}
ll modadd(ll a, ll b, ll mod)
{
    ll ans = ((a % mod) + (b % mod)) % mod;
    return ans;
}
ll modpower(ll n, ll p, ll mod)
{
    ll ans = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            n = (n * n) % mod;
            p /= 2;
        }
        else
        {
            ans *= n;
            ans %= mod;
            p -= 1;
        }
    }
    return ans;
}
ll moddivide(ll a, ll b, ll mod)
{
    ll ans = ((a % mod) * (modpower(b, mod - 2, mod) % mod)) % mod;
    return ans;
}
ll modsubtract(ll a, ll b, ll mod)
{
    ll ans = (a - b + mod) % mod;
    return ans;
}

ll right(ll a, ll b, ll c, ll mod, char op1, char op2) {
    ll m = mod;
    char o1 = op1, o2 = op2;
    if (o1 == '/' or o2 == '/')
    {
        ll ans;
        if (o1 == '/')
        {
            ans = moddivide(a, b, m);
            if (o2 == '/')
            {
                ans = moddivide(ans, c, m);
            }
            else if (o2 == '*')
            {
                ans = modmultiply(ans, c, m);
            }
            else if (o2 == '+')
            {
                ans = modadd(ans, c, m);
            }
            else
            {
                ans = modsubtract(ans, c, m);
            }
        }
        else
        {
            ans = moddivide(b, c, m);
            if (o1 == '/')
            {
                ans = moddivide(a, ans, m);
            }
            else if (o1 == '*')
            {
                ans = modmultiply(ans, a, m);
            }
            else if (o1 == '+')
            {
                ans = modadd(ans, a, m);
            }
            else
            {
                ans = modsubtract(a, ans, m);
            }
        }
        // cout << (ans + m) % m << endl;
        return (ans+m)%m;
    }
    if (o1 == '*' or o2 == '*')
    {
        ll ans;
        if (o1 == '*')
        {
            ans = modmultiply(a, b, m);
            if (o2 == '*')
            {
                ans = modmultiply(ans, c, m);
            }
            else if (o2 == '+')
            {
                ans = modadd(ans, c, m);
            }
            else
            {
                ans = modsubtract(ans, c, m);
            }
        }
        else
        {
            ans = modmultiply(b, c, m);
            if (o1 == '*')
            {
                ans = modmultiply(ans, a, m);
            }
            else if (o1 == '+')
            {
                ans = modadd(ans, a, m);
            }
            else
            {
                ans = modsubtract(a, ans, m);
            }
        }
        // cout << (ans + m) % m << endl;
        return (ans+m)%m;
    }
    ll ans;
    if (o1 == '+')
    {
        ans = modadd(b, a, m);
        if (o2 == '-')
        {
            ans = modsubtract(ans, c, m);
        }
        else
        {
            ans = modadd(ans, c, m);
        }
    }
    else
    {
        ans = modsubtract(a, b, m);
        if (o2 == '-')
        {
            ans = modsubtract(ans, c, m);
        }
        else
        {
            ans = modadd(ans, c, m);
        }
    }
    // cout << (ans + m) % m << endl;
    return (ans+m)%m;
}

ll wrong(ll var1, ll var2, ll var3, ll mod, char op1, char op2) {
    ll result;
    if(op1=='*') {
            if(op2=='*') result = (((var1%mod) * (var2%mod))%mod * (var3%mod))%mod;
            else if (op2=='/') result = ((var1*var2)%mod * binpow(var3, mod-2, mod))%mod;
            else if(op2=='+') result = (((var1%mod) * (var2%mod))%mod + (var3%mod))%mod;
            else result = (((((var1%mod) * (var2%mod))%mod - (var3%mod))%mod)+mod)%mod;
        } else if(op1=='/') {
            if(op2=='*') result = (((var1%mod) * (var3%mod))%mod * binpow(var2, mod-2, mod))%mod; 
            else if(op2=='/') result = ((var1%mod + ((var2%mod)*(var3%mod)))%mod * binpow(var2, mod-2, mod))%mod;
            else if(op2=='+') result = (var1%mod * binpow(((var2%mod)*(var3%mod))%mod, mod-2, mod))%mod;
            else result = ((((var1%mod - ((var2%mod)*(var3%mod))%mod)%mod)+mod)%mod * binpow(var2, mod-2, mod))%mod;
        } else if(op1=='+') {
            if(op2=='*') result = ((var1%mod) + ((var2%mod)*(var3%mod))%mod)%mod;
            else if(op2=='/') result = ((((var1%mod)*(var3%mod))%mod+(var2%mod))%mod * binpow(var3, mod-2, mod))%mod;
            else if(op2=='+') result = (var1+var2+var3)%mod;
            else result = (((var1%mod + var2%mod - var3%mod)%mod)+mod)%mod;
        } else if(op1=='-') {
            if(op2=='*') result = ((((var1%mod) - ((var2%mod)*(var3%mod))%mod)%mod)+mod)%mod;
            else if(op2=='/') result = ((((var1%mod)*(var3%mod))%mod - (var2%mod))%mod * binpow(var3, mod-2, mod))%mod;
            else if(op2=='+') result = (((var1%mod - var2%mod + var3%mod)%mod)+mod)%mod;
            else result = (((var1%mod - var2%mod - var3%mod)%mod)+mod)%mod;
        }
    // cout<<(result+mod)%mod<<'\n';
    
    return (result+mod)%mod;
}

void solve(int t) {
    srand(time(0));
    while(true) {
        ll a, b, c, p;
        a = rand()%1000 + 1;
        b = rand()%1000 + 1;
        c = rand()%1000 + 1;
        
        int n = sizeof(primes)/sizeof(primes[0]);
        
        p = primes[rand()%(n-1)];
        
        char op1 = operators[rand()%3];
        char op2 = operators[rand()%3];
        
        ll right_sol = right(a, b, c, p, op1, op2);
        ll wrong_sol = wrong(a, b, c, p, op1, op2);
        
        if(right_sol != wrong_sol) {
            cerr<<"Test Case "<<t<<'\n';
            cerr<<"Right Sol: "<<right_sol<<'\n';
            cerr<<"Wrong Sol: "<<wrong_sol<<'\n';
            cerr<<'('<<a<<' '<<op1<<' '<<b<<' '<<op2<<' '<<c<<") mod "<<p<<'\n';
            break;
        }
        
        
        
        t++;
        if(t > 10000000) break;
        
        // cerr<<"( "<<a<<' '<<op1<<' '<<b<<' '<<op2<<' '<<c<<") mod "<<p<<'\n';
        // if(t>10) break;
        // t++;
    }
    cout<<t<<'\n';
    cout << "OK!!" << '\n';
}

signed main() {
    FAST_IO;
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
    int t = 1;
    solve(t);
    
    cerr<<binpow(8*99, 5-2, 5)<<'\n';
    cerr<<binpow(8*99%5, 5-2, 5)<<'\n';
    cerr<<binpow((8*99)%5, 5-2, 5)<<'\n';
    cerr<<binpow(((8%5)*(99%5))%5, 5-2, 5)<<'\n';
}
