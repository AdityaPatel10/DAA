#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxValue = dp[n][W];

    int w = W;
    vector<int> selectedItems;

    for (int i = n; i > 0 && maxValue > 0; i--) {
        if (maxValue != dp[i - 1][w]) {
            selectedItems.push_back(i - 1);
            w -= weights[i - 1];
            maxValue -= values[i - 1];
        }
    }

    cout << "\nSelected items (index, weight, value):" << endl;
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        int idx = selectedItems[i];
        cout << "Item " << idx + 1 << ": Weight = " << weights[idx] << ", Value = " << values[idx] << endl;
    }

    return dp[n][W];
}

int main() {
    int W; 
    int n; 

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) cin >> weights[i];

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) cin >> values[i];

    int result = knapsack(W, weights, values, n);
    
    cout << "\nThe maximum value in the knapsack is: " << result << endl;

    return 0;
}
