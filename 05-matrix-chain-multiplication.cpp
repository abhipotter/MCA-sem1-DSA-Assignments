#include <iostream>
#include <climits>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string order(const vector<vector<int>>& s, int i, int j) {
    if(i==j) return "A"+to_string(i);
    int k=s[i][j];
    return "("+order(s,i,k)+" x "+order(s,k+1,j)+")";
}

int main() {
    int p[]={30,35,15,5,10,20,25};
    int n=sizeof(p)/sizeof(p[0])-1;
    vector<vector<long long>> m(n+1,vector<long long>(n+1,0));
    vector<vector<int>> s(n+1,vector<int>(n+1,0));
    for(int len=2;len<=n;len++) {
        for(int i=1;i<=n-len+1;i++) {
            int j=i+len-1;
            m[i][j]=LLONG_MAX;
            for(int k=i;k<j;k++) {
                long long cost=m[i][k]+m[k+1][j]+1LL*p[i-1]*p[k]*p[j];
                if(cost<m[i][j]) {
                    m[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    cout << "m table (cost):\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(j<i) cout << setw(8) << "-";
            else cout << setw(8) << m[i][j];
        }
        cout << endl;
    }
    cout << "s table (split):\n";
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(j<=i) cout << setw(8) << "-";
            else cout << setw(8) << s[i][j];
        }
        cout << endl;
    }
    cout << "Minimum cost: " << m[1][n] << endl;
    cout << "Optimal parenthesization: " << order(s,1,n) << endl;
}
