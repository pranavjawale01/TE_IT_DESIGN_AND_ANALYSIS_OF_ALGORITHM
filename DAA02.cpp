// Write a program to implement Bellman-Ford Algorithm using Dynamic Programming and verify the time complexity 

#include<iostream>
using namespace std;

int v, startv;
int weight[20][20], isavail[20][20];
int d[20];		//dist from starting vertex

void inpt()
{
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"\nEnter 1 if edge exists else 0.\n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			if(i == j)
				isavail[i][j] = 0;
			else
			{
				cout<<i<<" to "<<j<<" : ";
				cin>>isavail[i][j];
			}
		}
	}
	cout<<"Enter weights of edges. \n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			weight[i][j] = 999;
			if(i == j)
				weight[i][j] = 0;
			else if(isavail[i][j] == 1)
			{
				cout<<i<<" to "<<j<<" : ";
				cin>>weight[i][j];
			}
		}
	}
}

void display()
{	
	cout<<"Weights are \n";
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			cout<<weight[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void belFord()
{
	cout<<"\nEnter starting vertex : ";
	cin>>startv;
	for(int i=0; i<v; i++)
	{
		d[i] = weight[startv][i];
	}
	cout<<"\nThe initial distances are.\n";
	for(int i=0; i<v; i++)
	{
		cout<<startv<<" to "<<i<<" = "<<d[i]<<"\n";
	
	}
	for(int itr=0; itr<v-1; itr++)
	{
		for(int i=0; i<v; i++)
		{
			for(int j=0; j<v; j++)
			{
				if(d[j] > d[i] + weight[i][j])
					d[j] = d[i] + weight[i][j];
			}
		}
	}
	cout<<"\nThe final distances are.\n";
	for(int i=0; i<v; i++)
	{
		cout<<startv<<" to "<<i<<" = "<<d[i]<<"\n";
	
	}
}

int main()
{
	inpt();
	display();
	belFord();
	return 0;
}

// OUTPUT >>

// Enter number of vertices : 6

// Enter 1 if edge exists else 0.
// 0 to 1 : 1
// 0 to 2 : 1
// 0 to 3 : 1
// 0 to 4 : 0
// 0 to 5 : 0
// 1 to 0 : 0
// 1 to 2 : 0
// 1 to 3 : 0
// 1 to 4 : 1
// 1 to 5 : 0
// 2 to 0 : 0
// 2 to 1 : 1
// 2 to 3 : 0
// 2 to 4 : 1
// 2 to 5 : 0
// 3 to 0 : 0
// 3 to 1 : 0
// 3 to 2 : 1
// 3 to 4 : 0
// 3 to 5 : 1
// 4 to 0 : 0
// 4 to 1 : 0
// 4 to 2 : 0
// 4 to 3 : 0
// 4 to 5 : 1
// 5 to 0 : 0
// 5 to 1 : 0
// 5 to 2 : 0
// 5 to 3 : 0
// 5 to 4 : 0
// Enter weights of edges.
// 0 to 1 : 6
// 0 to 2 : 4
// 0 to 3 : 5
// 1 to 4 : -1
// 2 to 1 : -2
// 2 to 4 : 3
// 3 to 2 : -2
// 3 to 5 : -1
// 4 to 5 : 3
// Weights are
// 0       6       4       5       999     999
// 999     0       999     999     -1      999
// 999     -2      0       999     3       999
// 999     999     -2      0       999     -1
// 999     999     999     999     0       3
// 999     999     999     999     999     0

// Enter starting vertex : 0

// The initial distances are.
// 0 to 0 = 0
// 0 to 1 = 6
// 0 to 2 = 4
// 0 to 3 = 5
// 0 to 4 = 999
// 0 to 5 = 999

// The final distances are.
// 0 to 0 = 0
// 0 to 1 = 1
// 0 to 2 = 3
// 0 to 3 = 5
// 0 to 4 = 0
// 0 to 5 = 3
// PS P:\VsCode>