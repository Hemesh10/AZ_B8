#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr)
#define ALL(x) (x).begin(), (x).end()
#define PB push_back
#define MP make_pair
#define F first
#define S second 

void solve(int t) {
    while(t--) {
        int n; cin>>n;
        multiset<int> st;
        ll sum=0;
        while(n--) {
            int q; cin>>q;
            if(q==1 || q==2) {
                int x; cin>>x;
                if(q==1) {
                    sum+=x;
                    st.insert(x);
                } else {
                    auto it = st.find(x);
                    if(it!=st.end()) {
                        sum-=x;
                        st.erase(it);
                    }
                }
            } else {
                char ch; cin>>ch;
                if(q==3) {
                    cout<<(st.empty()?-1:*st.begin())<<'\n';
                } else if(q==4) {
                    cout<<(st.empty()?-1:*st.rbegin())<<'\n';
                } else cout<<sum<<'\n';
            }
        }
    }
}

int main() {
    FAST_IO;
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
    int t = 1; 
    // cin>>t;
    solve(t);
}
