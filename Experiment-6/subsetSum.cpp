#include <iostream>
#include <vector>
using namespace std;

// Function to determine if there's a subset with sum equal to target
bool isSubsetSum(const vector<int>& set, int target, vector<int>& subset) {
    int n = set.size();
    
    // Create a 2D DP table
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    
    // A sum of 0 can always be formed with an empty subset
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    // If there is no subset with the target sum
    if (!dp[n][target]) {
        return false;
    }
    
    // Backtrack to find the subset
    int w = target;
    for (int i = n; i > 0 && w > 0; --i) {
        if (!dp[i - 1][w]) {
            subset.push_back(set[i - 1]);
            w -= set[i - 1];
        }
    }
    
    return true;
}

int main() {
    int n, target;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> set(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }
    
    cout << "Enter the target sum: ";
    cin >> target;
    
    vector<int> subset;
    if (isSubsetSum(set, target, subset)) {
        cout << "There is a subset with the given sum: ";
        cout<<"{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }
    
    return 0;
}
