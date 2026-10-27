#include <bits/stdc++.h>
using namespace std;
// Vansh Vaibhav 25/DA/062

int main() {
    string s1 = "longest";
    string s2 = "stone";

    int n = s1.size(), m = s2.size();

    vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            i--;
            j--;
        } else if (DP[i - 1][j] >= DP[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<"String 1: "<<s1<<endl<<"String 2: "<<s2<<endl;
    cout << "Length of LCS: " << DP[n][m] << endl;
    cout << "LCS: " << ans << endl;

    cout << "Vansh Vaibhav 25/DA/062";

    return 0;
}