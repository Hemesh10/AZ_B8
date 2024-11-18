#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;
const int N = 0;


void solve(int t) {
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        vector<int> charArr(26, -1);
        vector<int> prev_occurrence_idx(n, -1), next_occurrence_idx(n, n);
        for(int i=0;i<n;i++) {
            if(charArr[s[i]-'a']!=-1) {
                prev_occurrence_idx[i] = charArr[s[i]-'a'];
            }
            charArr[s[i]-'a'] = i;
        }
        for(int i=0;i<26;i++) {charArr[i]=n;}
        for(int i=n-1;i>=0;i--) {
            if(charArr[s[i]-'a']!=n) {
                next_occurrence_idx[i] = charArr[s[i]-'a'];
            }
            charArr[s[i]-'a'] = i;
        }

        ll res = 0;
        for(int i=0;i<n;i++) {
            ll x = next_occurrence_idx[i], y = prev_occurrence_idx[i];
            res += ((x-i) + (i-y-1)*(x-i));
        }
        cout<<res<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1; 
    cin>>t;
    solve(t);
}
