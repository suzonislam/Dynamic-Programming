#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

vector<ll> dp(1e6+5,-1);

// Top down 

ll f(int n){
	//Base case
	if(n == 0) return 1;
	if(dp[n] != -1) return dp[n];
    
    ll sum = 0;
    for(int i = 1; i <= 6; i++){
    	if((n - i) < 0) break;
    	sum = (sum % mod + f(n-i) % mod) % mod;
    }
    return dp[n] = sum % mod;

}

// Bottom up

ll fbu(int n){
	//Base case
	dp[0] = 1;
	for(int k = 1; k <= n; k++){
		ll sum = 0;
	    for(int i = 1; i <= 6; i++){
	    	if((k - i) < 0) break;
	    	sum = (sum % mod + dp[k-i] % mod) % mod;
	    }
	   dp[k] = sum % mod;
	}
	return dp[n];

}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cout << fbu(n) << '\n';

  return 0;
}
