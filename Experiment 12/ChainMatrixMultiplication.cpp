# include <bits/stdc++.h>

using namespace std;

// Vansh Vaibhav 25/DA/062

int main(){
    vector<int> p = {2, 25, 3, 16, 1, 1000};
    int n = p.size() - 1;

    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> K(n + 1, vector<int>(n + 1, 0));
    
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            M[i][j]=INT_MAX;

            for(int k=i;k<j;k++){
                int cost=M[i][j];
                M[i][j]=min(M[i][j],M[i][k]+M[k+1][j]+p[i-1]*p[j]*p[k]);
                if(M[i][j]<cost){
                    K[i][j]=k;
                }
            }
        }
    }

    cout << "Minimum multiplication cost: "
         << M[1][n] << endl << endl;

    cout << "M matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << M[i][j] << "\t";
        cout << endl << endl;
    }

    cout << "K matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << K[i][j] << "\t";
        cout << endl << endl;
    }

    cout<<"Vansh Vaibhav 25/DA/062"<<endl;

    return 0;
}