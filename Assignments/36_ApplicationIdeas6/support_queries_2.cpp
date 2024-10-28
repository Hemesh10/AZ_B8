#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

struct DataStructure {
    multiset<int> st1, st2;
    ll sum = 0;
    size_t k;
    void init(int _k) {
        k = _k;
    }

    void _print() {
        cout<<"first: ";
        for(auto& it:st1) {
            cout<<' '<<it;
        } cout<<'\n';
        cout<<"second: ";
        for(auto& it:st2) {
            cout<<' '<<it;
        } cout<<'\n'<<'\n'<<'\n';
    }
    
    void insert(int x) {
        sum += x;
        st1.insert(x);
        if(st1.size() > k) {
            sum -= *st1.begin();
            st2.insert(*st1.begin());
            st1.erase(st1.begin());
        }
    }

    void remove(int x) {
        bool flag = false;
        multiset<int>::iterator it;
        if(!st1.empty() && x <= *st1.rbegin()) {
            it = st1.find(x);
            flag = true;
        } else {
            it = st2.find(x);
        }

        if(it==st1.end() || it==st2.end()) return;

        if(flag) {
            sum -= x;
            st1.erase(it);
            if(!st2.empty()) {
                sum += *st2.rbegin();
                st1.insert(*st2.rbegin());
                st2.erase(--(st2.end()));
            } 
        } else st2.erase(it);
    }

    ll getSum() {
        return sum;
    }

};

void solve(int t) {
    while(t--) {
        int q, k; cin>>q>>k;
        DataStructure d;
        d.init(k);
        while(q--) {
            int n; cin>>n;
            if(n==1) {
                int x; cin>>x;
                d.insert(x);
                // cout<<"Inserted "<<x<<'\n';
                // d._print();
            } else if(n==2) {
                int x; cin>>x;
                d.remove(x);
                // cout<<"Removed "<<x<<'\n';
                // d._print();
            } else {
                char ch; cin>>ch;
                cout<<d.getSum()<<'\n';
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cout.tie(nullptr);cerr.tie(nullptr);
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
    int t = 1; 
    // cin>>t;
    solve(t);
}
