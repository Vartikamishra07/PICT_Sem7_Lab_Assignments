//Solve fractional Knapsack using greedy approach

#include <bits/stdc++.h>
using namespace std;

// Structure to represent an item in the knapsack
struct Item {
    int value;
    int weight;

    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;  // Sort in decreasing order of value-to-weight ratio
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item> &items, int n) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // To store the total value of the knapsack

    // Iterate through all items
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            // If the item can be fully taken, take it
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // If the item cannot be fully taken, take a fraction of it
            totalValue += items[i].value * ((double)W / (double)items[i].weight);
            break;  // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int n, W;

    // Input number of items and knapsack capacity
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    vector<Item> items;

    // Input values and weights of the items
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    // Call the function to solve the fractional knapsack problem
    double maxValue = fractionalKnapsack(W, items, n);

    // Output the maximum value that can be carried in the knapsack
    cout << "Maximum value we can obtain = " << maxValue << endl;

    return 0;
}
