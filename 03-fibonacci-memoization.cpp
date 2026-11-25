#include <iostream>
#include <vector>
using namespace std;

unsigned long long fib(int n, vector<unsigned long long>& dp) {
    if (n <= 1) return n;
    if (dp[n] != 0) return dp[n];
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter n (0-93): ";
    if (!(cin >> n) || n < 0 || n > 93) {
        cout << "Invalid input\n";
        return 1;
    }
    vector<unsigned long long> dp(n + 1, 0);
    for (int i = 0; i <= n; ++i) cout << fib(i, dp) << (i == n ? '\n' : ' ');
    cout << "F(" << n << ") = " << fib(n, dp) << endl;
}
