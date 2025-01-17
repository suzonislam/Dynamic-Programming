#include<bits/stdc++.h>
using namespace std;

vector<int> get_digit(int n){
	vector<int> d;
	while(n > 0){
		if(n % 10 != 0){
            d.push_back(n % 10);
		}
		n = n / 10;
	}
	return d;
}

int f(int n){
	//Base case
	if(n == 0) return 0;
	if(n <= 9) return 1;
	
	vector<int> digt = get_digit(n);
	int ans = INT_MAX;
	for(int i = 0; i < digt.size(); i++){
		ans = min(ans,f(n-digt[i]));
	}
	return 1+ans;

}
// globally declare dp
vector<int> dp;


int f_bottom_up(int num){
	// Base case
	dp[0] = 0;
	for(int i = 1; i <= 9; i++)
		dp[i] = 1;
     
    for(int n = 10; n <= num; n++){
    	vector<int> digt = get_digit(n);
	    int ans = INT_MAX;
	    for(int i = 0; i < digt.size(); i++){
		   ans = min(ans,dp[n-digt[i]]);
	    }
	    dp[n] = 1+ans;
    }
    return dp[num];



}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;

  dp.clear();
  // Initialize with -1;
  dp.resize(1e6+5,-1);
  //cout << f(n) << '\n';
  cout << f_bottom_up(n) << '\n';
  return 0;
}
