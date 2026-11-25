#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string x,y;
    cout << "Enter X: ";
    if(!getline(cin,x)) return 1;
    cout << "Enter Y: ";
    if(!getline(cin,y)) return 1;
    int m=x.size(), n=y.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(x[i-1]==y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int i=m,j=n;
    while(i>0 && j>0) {
        if(x[i-1]==y[j-1]) {
            ans+=x[i-1];
            i--; j--;
        } else if(dp[i-1][j]>=dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    cout << "LCS length: " << dp[m][n] << endl;
    cout << "LCS: " << ans << endl;
}
