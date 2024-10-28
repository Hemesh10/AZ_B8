#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

struct comp {
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b) const {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while(b) {
        if(b&1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

class Dashboard {
    void balance(multiset<int>& first, multiset<int>& second) {
        while(first.size() > second.size()+1) {
            auto it = first.end();
            --it;
            second.insert(*it);
            first.erase(it);
        }

        while(first.size() < second.size()) {
            auto it = second.begin();
            first.insert(*it);
            second.erase(it);
        }

        if(!first.empty() && !second.empty() && *first.rbegin() > *second.begin()) {
            auto it1 = first.end(), it2 = second.begin();
            --it1;
            second.insert(*it1);
            first.erase(it1);
            first.insert(*it2);
            second.erase(it2);
        }
    }

    ll sum = 0;
    multiset<int> first, second; // taking two multisets for efffectively calculating the medain value

    // for calculating mode optimally 
    map<int, ll> mp;
    multiset<pair<ll, int>, comp> st; 
    public:
        void print_multisets() {
            cout<<"first: ";
            for(auto& it:first) cout<<it<<' ';
            cout<<'\n'<<"second: ";
            for(auto& it:second) cout<<it<<' ';
            cout<<'\n'<<'\n';
        }

        void print_freqMap() {
            cout<<"key and frequency:-"<<'\n';
            for(auto& it:mp) cout<<it.first<<" : "<<it.second<<'\n';
            cout<<'\n'<<'\n';
        }

        void print_freqTable() {
            cout<<"frequency and key:-"<<'\n';
            for(auto& it:st) cout<<it.first<<" : "<<it.second<<'\n';
            cout<<'\n'<<'\n';
        }

        int getMean() {
            if(first.empty()) return -1;
            return 1LL * (sum%MOD* binpow(first.size()+second.size(), MOD-2)%MOD) % MOD;
        }

        int getMedian() {
            if(first.empty()) return -1;
            if((first.size()+second.size())&1) return *first.rbegin();
            return 1LL * ((*first.rbegin() + *second.begin())%MOD * binpow(2, MOD-2)%MOD) % MOD;
        }

        int getMode() {
            if(first.empty()) return -1;
            return st.rbegin()->second;
        }

        void insert_element(int x) {
            first.insert(x);
            sum+=x;
            balance(first, second);
            auto it = st.find({mp[x], x});
            if(it != st.end()) st.erase(it);
            mp[x]++;
            st.insert({mp[x], x});
        }

        void remove_element(int x) {
            sum-=x; //since it is guaranteed that x will br present in the remove query
            st.erase({mp[x], x});
            auto p = mp.find(x);
            if(p->second == 1) {
                mp.erase(p);
            } else {
                mp[x]--;
                st.insert({mp[x], x});
            }

            multiset<int>::iterator it;
            bool flag = false;
            if(x > *first.rbegin()) {
                flag = true;
                it = second.find(x);
            } 
            else it = first.find(x);

            if(flag) second.erase(it);
            else first.erase(it);
            balance(first, second);
        }
};



void solve(int t) {
    while(t--) {
        Dashboard d;
        int q; cin>>q;
        while(q--) {
            string query; cin>>query;
            if(query=="insert") {
                int x; cin>>x;
                d.insert_element(x);
            } else if(query=="remove") {
                int x; cin>>x;
                d.remove_element(x);
            } else if(query=="getMean") {
                cout<<d.getMean()<<'\n';
            } else if(query=="getMedian") {
                cout<<d.getMedian()<<'\n';
            }else {
                cout<<d.getMode()<<'\n';
            }
        }
        // d.print_freqMap();
        // d.print_freqTable();
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cout.tie(nullptr);cerr.tie(nullptr);
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
    int t = 1; 
    cin>>t;
    solve(t);
}
