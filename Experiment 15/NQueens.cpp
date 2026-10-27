# include <bits/stdc++.h>

using namespace std;

// Vansh Vaibhav 25/DA/062

bool isSafe(int row, int col,int n,vector<string>&Board){
    for(int i=0;i<row;i++){
        if(Board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--){
        if(Board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1, j=col+1;i>=0 && j<n;i--,j++){
        if(Board[i][j]=='Q'){
            return false;
        }
    }
    return true;

}

void Solve(int row, int n,vector<vector<string>>&ans,vector<string>&Board){
    if(row==n){
        ans.push_back(Board);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col,n,Board)){
            Board[row][col]='Q';
            Solve(row+1,n,ans,Board);
            Board[row][col]='.';
        }
    }
}


int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl;
    vector<string>Board(n,string(n,'.'));
    vector<vector<string>> ans;
    Solve(0,n,ans,Board);
    for (const auto& row : ans) {
        for (const auto& str : row) {
            cout << str << "\n";
        }
        cout << "\n\n";
    }

    cout<< "Vansh Vaibhav 25/DA/062"<<endl;
    return 0;
}
