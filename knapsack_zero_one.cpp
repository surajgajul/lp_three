// #include <iostream>
// #include <vector>
// #include <stdc++.h>

// using namespace std;

// int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

//     for (int i = 1; i <= n; ++i) {
//         for (int w = 1; w <= W; ++w) {
//             if (wt[i - 1] <= w) {
//                 dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
//             } else {
//                 dp[i][w] = dp[i - 1][w];
//             }
//         }
//     }

//     return dp[n][W];
// }

// int main() {
//     int n;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<int> val(n);
//     vector<int> wt(n);

//     cout << "Enter the values of the items:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> val[i];
//     }

//     cout << "Enter the weights of the items:" << endl;
//     for (int i = 0; i < n; ++i) {
//         cin >> wt[i];
//     }

//     int W;
//     cout << "Enter the knapsack capacity: ";
//     cin >> W;

//     int maxValue = knapsack(W, wt, val, n);
//     cout << "Maximum value that can be obtained: " << maxValue << endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static compare(Item a, Item b)
    {
        return a.weight < b.weight;
    }

    int knapsack(int capacity, vector<Item>& items)
    {
        int n = items.size();
        sort(items.begin(), items.end(), compare);

        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                if (items[i - 1].weight > w)
                {
                    dp[i][w] = dp[i - 1][w];
                }
                else
                {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
                }
            }
        }

        return dp[n][capacity];
    }
};

int main()
{
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter the value and weight of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
    }

    Solution obj;
    int ans = obj.knapsack(capacity, items);
    cout << "The maximum value is: " << ans << endl;

    return 0;
}