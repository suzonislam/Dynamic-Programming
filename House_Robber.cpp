#include<bits/stdc++.h>
using namespace std;

//Global vector;
    vector<int> dp;
    int f(vector<int> &arr,int i){
        //Base case
        if(i == arr.size()-1) return arr[i]; //Single house
        if(i == arr.size()-2) return max(arr[i],arr[i+1]);//Double house

        return max(arr[i] + f(arr,i+2), 0+f(arr,i+1));
    }

    // Top down
    int ftd(vector<int> &arr,int i){
        //Base case
        if(i == arr.size()-1) return arr[i]; //Single house
        if(i == arr.size()-2) return max(arr[i],arr[i+1]);//Double house
        //Already calculated
        if(dp[i] != -1) return dp[i];
        // Not calculated
        return dp[i] = max(arr[i] + ftd(arr,i+2), 0+ftd(arr,i+1));
        
    }

    // Bottom up
    int fbu(vector<int> &arr,int n){
        // Base case
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-1],arr[n-2]);
        // iterate
        for(int i = n-3; i >= 0; i--){
            dp[i] = max(arr[i]+dp[i+2],0+dp[i+1]);

        }
        return dp[0];
    }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
  	cin >> nums[i];
  }
  
  dp.clear();
  dp.resize(105,-1);
  //edge case for bottom up when n == 1
  
  if(n == 1) cout << nums[0] <<"\n";
  //cout << f(nums,0) << endl;
  //cout << ftd(nums,0) << endl;
  cout << fbu(nums,n) << endl;
  return 0;
}
