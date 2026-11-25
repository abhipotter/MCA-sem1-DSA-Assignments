#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter n (0-93): ";
    if (!(cin >> n) || n < 0 || n > 93) {
        cout << "Invalid input\n";
        return 1;
    }
    vector<unsigned long long> dp(n + 1, 0);
    if (n >= 1) dp[1] = 1;
    for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    for (int i = 0; i <= n; ++i) cout << dp[i] << (i == n ? '\n' : ' ');
    cout << "F(" << n << ") = " << dp[n] << endl;
}
