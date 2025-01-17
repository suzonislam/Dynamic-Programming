#include<bits/stdc++.h>
using namespace std;

vector<int> coins;
vector<int> dp(1000005,-2);
int n,x;

int f(int x){
	//Base case;
	if(x == 0) return 0;
	//Already calculated
	if(dp[x] != -2) return dp[x];

	int result = INT_MAX;
	for(int i = 0; i < n; i++){
		if(x-coins[i] < 0) 
			continue;
        result = min(result,f(x-coins[i]));
	}
	if(result == INT_MAX) 
		return dp[x] = INT_MAX;
	return dp[x] = 1 + result;

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> x;
  for(int i = 0; i < n; i++){
      int a; cin >> a;
      coins.push_back(a);
  }
  int ans = f(x);
  if(ans == INT_MAX)
  	cout << -1 << endl;
  else
  	cout << ans << endl;
  return 0;
}
