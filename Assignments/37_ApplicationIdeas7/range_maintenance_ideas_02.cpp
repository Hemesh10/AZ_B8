#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

#define F first
#define S second

struct range_maintenance {
    set<pii> _ranges;

    void print_ranges() {
        if(_ranges.empty()) {
            cout<<"No filled range."<<'\n';
            return;
        }

        for(auto& it:_ranges) {
            cout<<"{"<<it.F<<", "<<it.S<<"}, ";
        }
        cout<<'\n';
    }
    
    void insert_range(int l, int r) {
        auto it = _ranges.upper_bound({l, 1e9});
        if(it != _ranges.begin()) {
            --it;
            if(it->S >= l) {
                l = it->F;
                r = max(r, it->S);
                auto tmp = it;
                _ranges.erase(tmp);
            }
            ++it;
        }

        while(it != _ranges.end() && it->F <= r) {
            r = max(r, it->S);
            auto tmp = it;
            _ranges.erase(tmp);
            ++it;
        }

        _ranges.insert({l, r});
    }

    void clear_range(int l, int r) {
        if(_ranges.empty() || !check_range_any(l, r)) return; // check_range_any(l, r) makes sure that the range (l, r) has at least some portion filled in order to clear

        auto it = _ranges.upper_bound({l, 1e9});
        if(it != _ranges.begin()) --it;
        if(it->F < l && it->S > r) {
            int l1 = it->F, r1 = l;
            int l2 = r, r2 = it->S;
            _ranges.erase(it);
            _ranges.insert({l1, r1});
            _ranges.insert({l2, r2});
            return;
        }
        while(it != _ranges.end() && it->F < r) {
            auto tmp = it;
            if(it->F >= l && it->S <= r) {
                // ranges that getting fully erased
                _ranges.erase(tmp);
            } else if(it->F < l) {
                // ranges that are getting partially erased from their right
                int l1 = it->F, r1 = l;
                _ranges.erase(tmp);
                _ranges.insert({l1, r1});
            } else {
                // ranges that are getting partially erased from their left
                int l1 = r, r1 = it->S;
                _ranges.erase(tmp);
                _ranges.insert({l1, r1});
            }
            ++it;
        }
    }

    bool check_x(int x) {
        auto it = _ranges.upper_bound({x, 1e9});
        if(it != _ranges.begin()) {
            --it;
            return it->S>=x;
        }
        return false;
    }

    bool check_range_any(int x, int y) {
        auto it = _ranges.upper_bound({x, 1e9});
        if(it != _ranges.end()) {
            if(it->F <= y) return true;
        }
        return check_x(x);
    }
    
    bool check_range_all(int x, int y) {
        auto it = _ranges.upper_bound({x, 1e9});
        if(it == _ranges.begin()) return false;
        --it;
        return it->S >= y;
    }

};

void solve(int t) {
    while(t--) {
        range_maintenance bag;

        int q; cin>>q;
        while(q--) {
            string query; cin>>query;
            if(query=="insert") {
                int l, r; cin>>l>>r;
                bag.insert_range(l, r);
            } else if(query=="clear") {
                int l, r; cin>>l>>r;
                bag.clear_range(l, r);
            } else if(query=="check_x") {
                int x; cin>>x;
                if (bag.check_x(x)) {
                    cout<<"YES"<<'\n';
                } else cout<<"NO"<<'\n';
            } else if(query=="check_any") {
                int l, r; cin>>l>>r;
                if(bag.check_range_any(l, r)) {
                    cout<<"YES"<<'\n'; 
                } else cout<<"NO"<<'\n';
            } else if(query=="check_range_all") {
                int l, r; cin>>l>>r;
                if(bag.check_range_all(l, r)) {
                    cout<<"YES, all range is filled"<<'\n';
                } else cout<<"NO, whole range is not filled"<<'\n';
            } else bag.print_ranges();
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
