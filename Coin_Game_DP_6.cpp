#include<bits/stdc++.h>
using namespace std;
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int k , l , m;
  cin >> k >> l >> m;
 
  vector<bool> dp(1000005,0);
 
  //Precompute all games which l and k are same
  dp[1] = 1;
  dp[k] = 1;
  dp[l] = 1;
  for(int i = 2; i <= 1000000; i++){
  	//already known this value dp[k] = 1 and dp[l] = 1
  	if(i == k or i == l) continue;
 
  	dp[i] = !(dp[i-1] and ((i-k) >= 1 ? dp[i-k] : 1 ) and ((i-l) >= 1 ? dp[i-l] : 1 ));
 
  }
 
  // answer each game
  for(int i = 0; i < m; i++){
  	int a; cin >> a;
  	if(dp[a] == 1){
  		cout << "A";
  	}
  	else cout << "B";
  }
  cout << endl;
 
  return 0;
}
 