#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Sol {
public:
    vector<vector<string>> solve(int n){
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));

        // put column index for each row where queen is placed
        int dp[n];

        backtrack(ans, temp, dp, 0, n);
        return ans;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &temp, int dp[], int row, int n) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }

        for (int col=0; col<n; col++) {
            if (valid(dp, row, col, n)) {
                dp[row] = col;
                temp[row][col] = 'Q';
                backtrack(ans, temp, dp, row+1, n);
                temp[row][col] = '.';
            }
        }
    }

    bool valid(int dp[], int row, int col, int n) {
        for (int i=0; i<row; i++) {
            if (dp[i]==col || abs(row-i)==abs(dp[i]-col)) return false;
        }

        return true;
    }
};

int main() {

    Sol obj;
    vector<vector<string>> ans = obj.solve(4);

    for (auto s: ans[0]) {
        cout << s << "\n";
    }

    return 0;
}