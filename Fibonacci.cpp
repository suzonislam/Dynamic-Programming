#include<bits/stdc++.h>
using namespace std;

int f(int n){
        // Base case
        if(n <= 1){
            return n;
        }
        return f(n-1)+f(n-2);
 }
 //Globally Initialize a vector
vector<int> dp;
int f_top_down(int n){
        if(n <= 1){
            return n;
        }
        //already calculated
        if(dp[n] != -1){
            return dp[n];
        }
        // First time calculation
        return dp[n] = f_top_down(n-1) + f_top_down(n-2);

  }
 //Bottom up approach
 int fbu(int n){
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
 }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  dp.clear();
  dp.resize(35,-1);
  
  int n; cin >> n;

  //cout << f(n) << '\n';
  //cout << f_top_down(n) <<'\n';
  cout << fbu(n) << '\n';
  return 0;
}
