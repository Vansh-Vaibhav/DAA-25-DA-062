#include <bits/stdc++.h>
using namespace std;
// Vansh Vaibhav 25/DA/062

int main() {
    vector<int> p = {30, 28, 20, 24};
    vector<int> w = {5, 7, 4, 2};
    int n = p.size(), m = 12;
    cout<<"Objects: ";
    for(int i=1;i<p.size()+1;i++){
        cout<<"O"<<i<<"\t";
    }
    cout<<endl;
    cout<<"Profits: ";
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<"\t";
    }
    cout<<endl;
    cout<<"Weights: ";
    for(int i=0;i<w.size();i++){
        cout<<w[i]<<"\t";
    }
    cout<<endl;
    cout<<"Capacity: "<<m<<endl;
    vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (w[i - 1] <= j) {
                DP[i][j] = max(
                    DP[i - 1][j],
                    p[i - 1] + DP[i - 1][j - w[i - 1]]
                );
            } else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    cout << "Maximum Profit: " << DP[n][m] << endl;

    cout << "Selected Items: ";
    int j = m;

    for (int i = n; i > 0; i--) {
        if (DP[i][j] != DP[i - 1][j]) {
            cout << i << " ";
            j -= w[i - 1];
        }
    }

    cout << endl;
    cout << "Vansh Vaibhav 25/DA/062";

    return 0;
}