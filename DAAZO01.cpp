// Write a program to implement Fractional knapsack using Greedy algorithm and 0/1 knapsack using dynamic programming. Show that Greedy strategy does not necessarily yield an optimal solution over a dynamic programming approach. 

#include<iostream>
using namespace std;

void input(int totalItem, int bagWeight, int table[][15], int profit[], int weight[]) {
    for (int i = 1; i <= totalItem; i++) {
        cout << "\nEnter the Weight of " << i << " item >> ";
        cin >> weight[i];
        cout << "\nEnter the Profit of " << i << " item >> ";
        cin >> profit[i];
    }
    for (int i = 0; i <= totalItem; i++) {
        for (int j = 0; j<= bagWeight; j++) {
            table[i][j] = 0;
        }
    }
}

void display(int table[][15], int totalItem, int bagWeight) {
    for (int i = 0 ; i <= totalItem; i++) {
        for (int j = 0 ; j <= bagWeight; j++) {
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void calculate(int table[][15], int totalItem, int bagWeight, int profit[], int weight[]) {
    for (int i = 1; i <= totalItem; i++) {
        for (int j = 1; j <= bagWeight; j++) {
            table[i][j] = table[i-1][j];
            if (weight[i] <= j) {
                table[i][j] = max(table[i][j], profit[i] + table[i-1][j-weight[i]]);
            }
        }
    }
}

void selectItem(int totalItem, int bagWeight, int table[][15], int weight[], int profit[]) {
    int i = totalItem;
    int j = bagWeight;
    int totalWeight = 0;
    int totalProfit = 0;
    while (i > 0 && j > 0) {
        if (table[i][j] != table[i-1][j]) {
            cout<<"Item "<<i <<" selected" << endl;
            totalWeight += weight[i];
            totalProfit += profit[i];
            j -= weight[i];
        }
        i--;
    }
    cout << "Total Weight of selected items: " << totalWeight << endl;
    cout << "Total Profit of selected items: " << totalProfit << endl;
}

int main() {
    int bagWeight, totalItem;
    cout << "Enter the Weight of KnapSack Bag >> ";
    cin >> bagWeight;
    cout << "Enter the Total Number of Items >> ";
    cin >> totalItem;
    int table[totalItem + 1][15];
    int profit[totalItem + 1], weight[totalItem + 1];
    input(totalItem, bagWeight, table, profit, weight);
    calculate(table, totalItem, bagWeight, profit, weight);
    cout << "\nDynamic Programming Table:" << endl;
    display(table, totalItem, bagWeight);
    cout << "\nSelected items:" << endl;
    selectItem(totalItem, bagWeight, table, weight, profit);

    return 0;
}

// OUTPUT >>
// Enter the Weight of KnapSack Bag >> 8

// Enter the Total Number of Items >> 4

// Enter the Weight of 1 item >> 2

// Enter the Profit of 1 item >> 1

// Enter the Weight of 2 item >> 3

// Enter the Profit of 2 item >> 2

// Enter the Weight of 3 item >> 4

// Enter the Profit of 3 item >> 5

// Enter the Weight of 4 item >> 5

// Enter the Profit of 4 item >> 6
// Displaying 0/1 KnapSack Table...
// 0       0       0       0       0       0       0       0       0
// 0       0       0       0       0       0       0       0       0
// 0       0       0       0       0       0       0       0       0
// 0       0       0       0       0       0       0       0       0
// 0       0       0       0       0       0       0       0       0

// Table after data allocation
// Displaying 0/1 KnapSack Table...
// 0       0       0       0       0       0       0       0       0
// 0       0       1       1       1       1       1       1       1
// 0       0       1       2       2       3       3       3       3
// 0       0       1       2       5       5       6       7       7
// 0       0       1       2       5       6       6       7       8

// Items selected:
// Item 4 selected
// Item 2 selected

// Total Weight of selected items: 8
// Total Profit of selected items: 8



//.....Using Class.....
/*
#include<iostream>
using namespace std;

class zeroOneKnapSack
{
    private:
        int totalItem, bagWeight;
        int *weight;
        int *profit;
        int **table;

    public:
        void collectData(int totalItem, int bagWeight)
        {
            this->totalItem = totalItem;
            this->bagWeight = bagWeight;
            weight = new int[totalItem];
            profit = new int[totalItem];
            table = new int*[totalItem + 1];
            for (int i = 0; i <= totalItem; i++)
            {
                table[i] = new int[bagWeight + 1];
            }

            weight[0] = 0;
            profit[0] = 0;
            for (int i = 1; i <= totalItem; i++)
            {
                cout << "\nEnter the Weight of " << i << " item >> ";
                cin >> weight[i];
                cout << "\nEnter the Profit of " << i << " item >> ";
                cin >> profit[i];
            }

            for (int i = 0; i <= totalItem; i++)
            {
                for (int j = 0; j <= bagWeight; j++)
                {
                    table[i][j] = 0;
                }
            }
        }

        void displayData()
        {
            cout << "\nDisplaying 0/1 KnapSack Table...\n";
            for(int i=0;i<=totalItem;i++)
            {
                for(int j=0;j<=bagWeight;j++)
                {
                    cout<<table[i][j]<<"\t";
                }
                cout << "\n";
            }
        }

        void calculate()
        {
            for (int i = 1; i <= totalItem; i++)
            {
                for (int j = 1; j <= bagWeight; j++)
                {
                    table[i][j] = table[i - 1][j];
                    if (weight[i] <= j)
                    {
                        table[i][j] = max(table[i][j], profit[i] + table[i - 1][j - weight[i]]);
                    }
                }
            }
        }

        int selectItem()
        {
            int i = totalItem;
            int j = bagWeight;
            int totalWeight = 0;
            int totalProfit = 0; // Initialize total profit to 0

            while (i > 0 && j > 0)
            {
                if (table[i][j] != table[i - 1][j])
                {
                    cout << "Item " << i << " selected\n";
                    totalWeight += weight[i];
                    totalProfit += profit[i]; // Add the profit of the selected item to totalProfit
                    j -= weight[i];
                }
                i--;
            }

            cout << "\nTotal Weight of selected items: " << totalWeight << endl;
            cout << "Total Profit of selected items: " << totalProfit << endl; // Print total profit
            return totalWeight;
        }

};

int main()
{
    int bagWeight, totalItem;
    cout << "\nEnter the Weight of KnapSack Bag >> ";
    cin >> bagWeight;
    cout << "\nEnter the Total Number of Items >> ";
    cin >> totalItem;

    zeroOneKnapSack zok;
    zok.collectData(totalItem , bagWeight );
    zok.displayData();

    cout<<"\nTable after data allocation";
    zok.calculate();
    zok.displayData();
    cout << "\nItems selected:\n";

    zok.selectItem();

    return 0;
}
*/
