#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function that works (your optimized solution)
pair<vector<int>, vector<vector<int>>> correct_solution(int n, int m, int q, int x1, int y1, int x2, int y2, int c) {
   // long long n, m, q;
   // cin >> n >> m >> q;
   
   // Initialize the difference array (1-based indexing)
   vector<vector<long long>> pre(n+5, vector<long long>(m+5, 0));
   
    pair<vector<int>, vector<vector<int>>> output_and_cases;
    output_and_cases.first.resize(2);
    output_and_cases.second.resize(q, vector<int>(5));
    
    int a = 0;
   
   // Process the queries
   for(int i = 1; i <= q; i++) {        
        output_and_cases.second[a][0] = x1;
        output_and_cases.second[a][1] = y1;
        output_and_cases.second[a][2] = x2;
        output_and_cases.second[a][3] = y2;
        output_and_cases.second[a][4] = c;
        a++;
        
        pre[x1][y1] += c;
        pre[x1][y2+1] -= c;  
        pre[x2+1][y1] -= c;  
        pre[x2+1][y2+1] += c; 
   }
   
   // Apply prefix sum to get the actual matrix values
   long long max_val = LLONG_MIN;
   long long count = 0;
   
   for(int i = 1; i <= n; i++) {
       for(int j = 1; j <= m; j++) {
           // Build the prefix sum matrix
           pre[i][j] = pre[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
           
           // Find the maximum value and its count
           if(pre[i][j] > max_val) {
               max_val = pre[i][j];
               count = 1; // Reset the count
           } else if (pre[i][j] == max_val) {
               count++; // Increment the count
           }
       }
   }
   
   output_and_cases.first[0] = max_val;
   output_and_cases.first[1] = count;
   
   return output_and_cases;
}

// Brute-force solution (simple and correct but inefficient)
pair<vector<int>, vector<vector<int>>> wrong_solution(int N, int M, int Q, int x1, int y1, int x2, int y2, int C) {
    // int N,M,Q; cin>>N>>M>>Q;
    ll arr[N+2][M+2]={};
    
    pair<vector<int>, vector<vector<int>>> output_and_cases;
    output_and_cases.first.resize(2);
    output_and_cases.second.resize(Q, vector<int>(5));
    
    int a = 0;
    
    while(Q--) {        
        output_and_cases.second[a][0] = x1;
        output_and_cases.second[a][1] = y1;
        output_and_cases.second[a][2] = x2;
        output_and_cases.second[a][3] = y2;
        output_and_cases.second[a][4] = C;
        a++;
        
        arr[x1][y1]+=C;
        arr[x2+1][y1]-=C;
        arr[x1][y2+1]-=C;
        arr[x2+1][y2+1]+=C;
    }
    
    ll P[N+2][M+2]={}, maxN=LLONG_MIN;
    for(int i=1;i<N+1;i++) {
        for(int j=1;j<M+1;j++) {
            // P[i][j]=(arr[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]);
            P[i][j] = arr[i][j];
            P[i][j]+=P[i-1][j];
            P[i][j]+=P[i][j-1];
            P[i][j]-=P[i-1][j-1];
            maxN = max(maxN, P[i][j]);
        }
    }
    
    ll cnt=0;
    for(int i=1;i<N+1;i++) {
        for(int j=1;j<M+1;j++) {
            if(P[i][j]==maxN) cnt++;
        }
    }
    
    output_and_cases.first[0] = maxN;
    output_and_cases.first[1] = cnt;
    return output_and_cases;
}

int main() {
#ifndef ONLINE_JUDGE
    (void)!freopen("error.txt", "w", stderr);
#endif
    srand(time(0));
    int test_case = 0; // Counter to track the number of test cases generated
    
    while (true) {
        test_case++;
        cerr << "Test case #" << test_case << '\n';
        
        int n = rand() % 25 + 1; 
        int m = rand() % 25 + 1;  
        int q = 1; 
        // cerr<<n<<", "<<m<<", "<<q<<'\n';
        
        int x1 = rand() % n + 1;
        int y1 = rand() % m + 1;
        
        int x2 = rand() % n + 1;
        int y2 = rand() % m + 1;
        
        if(x1>x2) swap(x1, x2);
        if(y1>y2) swap(y1, y2);
        
        int c = rand() % 100 + 1; 
        
        cout<<n<<' '<<m<<' '<<q<<'\n';
        cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
        cout<<c<<'\n';
        
        break;
        
        // Calculate result using both solutions
        // pair<vector<int>, vector<vector<int>>> correct = correct_solution(n, m, q, x1, y1, x2, y2, c);
        // pair<vector<int>, vector<vector<int>>> wrong = wrong_solution(n, m, q, x1, y1, x2, y2, c);

        // // Compare the results
        // if (!(correct.first[0] == wrong.first[0] && correct.first[1] == wrong.first[1])) {
        //     cerr << "Mismatch found!\n";
        //     cerr << "Correct Result: " << correct.first[0] << ' ' << correct.first[1] << '\n';
        //     cerr << "Wrong Result: " << wrong.first[0] << ' ' << wrong.first[1] << '\n';
            
        //     // Print the failing test case details
        //     cerr << "Failing Test Case: "<<'\n';
        //     cerr<<n<<' '<<m<<' '<<q<<'\n';
        //     for(int i=0;i<q;i++) {
        //         for(int j=0;j<5;j++) {
        //             cerr<<correct.second[i][j]<<' ';
        //         }
        //         cerr<<'\n';
        //     } cerr<<'\n';
        //     break;  // Stop testing after finding the first mismatch
        // } else {
        //     if(test_case > 1000) {
        //         cerr<<"ok!"<<'\n';
        //         break;
        //     }
        // }
    }

    return 0;
}
