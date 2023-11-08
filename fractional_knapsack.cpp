#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio; // value-to-weight ratio
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    
    for (const Item& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += item.ratio * capacity;
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = static_cast<double>(items[i].value) / (items[i].weight);
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
