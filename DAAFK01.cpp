// Write a program to implement Fractional knapsack using Greedy algorithm and 0/1 knapsack using dynamic programming. Show that Greedy strategy does not necessarily yield an optimal solution over a dynamic programming approach. 

#include <iostream>

using namespace std;

struct item
{
    int id;
    float weight;
    float profit;
    float density; // profit/weight
};

void BubbleSort(item arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].density < arr[j + 1].density)
            {
                item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void DisplayItems(item arr[], int n)
{
    cout << "ID\tWeight\tProfit\tDensity\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].id << "\t" << arr[i].weight << "\t" << arr[i].profit << "\t" << arr[i].density << endl;
    }
}

void FractionalKnapsack(item arr[], int n, int KnapSackWeight)
{
    BubbleSort(arr, n);

    float totalWeight = 0;
    float totalProfit = 0;

    cout << "Items selected\n";
    cout << "ID\tWeight\tProfit\n";
    for (int i = 0; i < n; i++)
    {
        if (totalWeight + arr[i].weight <= KnapSackWeight)
        {
            totalWeight += arr[i].weight;
            totalProfit += arr[i].profit;
            cout << arr[i].id << "\t" << arr[i].weight << "\t" << arr[i].profit << endl;
        }
        else
        {
            float remainingWeight = KnapSackWeight - totalWeight;
            totalProfit += (arr[i].density * remainingWeight);
            cout << arr[i].id << "\t" << remainingWeight << "\t" << (arr[i].density * remainingWeight);
            totalWeight = KnapSackWeight;
            break;
        }
    }

    cout << "\nTotal Weight in Knapsack >> " << totalWeight;
    cout << "\nTotal Profit >> " << totalProfit;
}

int main()
{
    int KnapSackWeight, totalItem;
    cout << "Enter the Weight of the Knapsack >> ";
    cin >> KnapSackWeight;
    cout << "Enter total No. of items >> ";
    cin >> totalItem;
    item arr[totalItem];
    for (int i = 0; i < totalItem; i++)
    {
        cout << "\nEnter the weight of item " << i + 1 << " >> ";
        cin >> arr[i].weight;
        cout << "Enter the profit of item " << i + 1 << " >> ";
        cin >> arr[i].profit;
        arr[i].id = i + 1;
        arr[i].density = arr[i].profit / arr[i].weight;
    }

    DisplayItems(arr, totalItem);

    FractionalKnapsack(arr, totalItem, KnapSackWeight);

    return 0;
}

// OutPut >>

// Enter the Weight of the Knapsack >> 16
// Enter total No. of items >> 6

// Enter the weight of item 1 >> 6
// Enter the profit of item 1 >> 6

// Enter the weight of item 2 >> 10
// Enter the profit of item 2 >> 2

// Enter the weight of item 3 >> 3
// Enter the profit of item 3 >> 1

// Enter the weight of item 4 >> 5
// Enter the profit of item 4 >> 8

// Enter the weight of item 5 >> 1
// Enter the profit of item 5 >> 3

// Enter the weight of item 6 >> 3
// Enter the profit of item 6 >> 5
// ID      Weight  Profit  Density
// 1       6       	6       1
// 2       10     	2       0.2
// 3       3       	1       0.333333
// 4       5       	8       1.6
// 5       1       	3       3
// 6       3       	5       1.66667
// Items selected
// ID      Weight  Profit
// 5       1      	3
// 6       3       	5
// 4       5       	8
// 1       6       	6
// 3       1       	0.333333
// Total Weight in Knapsack >> 16
// Total Profit >> 22.3333
// PS P:\VsCode>