#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MOD = 1e9+7;
const long long INF = 1e18;
const double PI = 3.1415926535897932384626;

class Dashboard {
    void balance(multiset<int>& first, multiset<int>& second) {
        while(first.size() > second.size()+1) {
        	cerr<<"dd before"<<" -- "<<"first size: "<<first.size()<<", second size: "<<second.size()<<'\n';
            auto it = first.end();
            --it;
            second.insert(*it);
            first.erase(it);
            cerr<<"dd after"<<" -- "<<"first size: "<<first.size()<<", second size: "<<second.size()<<'\n'<<'\n';
        }

        while(first.size() < second.size()) {
        	cerr<<"ff"<<" -- "<<"first size: "<<first.size()<<", second size: "<<second.size()<<'\n';
            auto it = second.begin();
            first.insert(*it);
            second.erase(it);
            cerr<<"ff after"<<" -- "<<"first size: "<<first.size()<<", second size: "<<second.size()<<'\n'<<'\n';
        }

        if(!first.empty() && !second.empty() && *first.rbegin() > *second.begin()) {
        	cout<<"gg"<<'\n';
            auto it1 = first.end(), it2 = second.begin();
            --it1;
            second.insert(*it1);
            first.erase(it1);
            first.insert(*it2);
            second.erase(it2);
        }
    }

    multiset<int> first, second;
    public:
        void print_multisets() {
            cout<<"first: ";
            for(auto& it:first) cout<<it<<' ';
            cout<<'\n'<<"second: ";
            for(auto& it:second) cout<<it<<' ';
            cout<<'\n'<<'\n';
        }


        void insert_element(int x) {
            first.insert(x);
            // if(first.empty()) {
            //     first.insert(x);
            //     return;
            // }
            // if(second.empty()) {
            //     second.insert(x);
            //     return;
            // }
            balance(first, second);
        }
        int remove_element(int x) {
            multiset<int>::iterator it;
            bool flag = false;
            if(x > *first.rbegin()) {
                flag = true;
                it = second.find(x);
            } 
            else it = first.find(x);

            if(it==first.end() || it==second.end()) {
                return 0;
            } else if(flag) second.erase(it);
            else first.erase(it);
            cerr<<"aa -- "<<"first size: "<<first.size()<<", second size: "<<second.size()<<'\n'<<'\n';
            balance(first, second);
            return 1;
        }
};



void solve(int t) {
    while(t--) {
        Dashboard d;
        d.insert_element(1);
        d.insert_element(2);
       
        d.print_multisets();
        
        d.remove_element(1);

        d.print_multisets();
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