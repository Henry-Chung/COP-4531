#include <iostream>

using namespace std;

int reuslt = 0;

// A utility function that returns maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity weight_limit
void KnapSack(unsigned int weights[], unsigned int values[], size_t n, unsigned long weight_limit)
{

	unsigned int i, w;
	int K[n+1][weight_limit+1];

	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= weight_limit; w++)
		{
			if (i == 0 || w == 0)   	 	 // c[i;w] = 0 if i = 0 or w = 0
				K[i][w] = 0;				
			else if (weights[i - 1] <= w)    // c[i;w] = max(vi + c[i .. 1;w .. wi]; c[i .. 1;w]) if i > 0 and w  wi
				K[i][w]
				= max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
			else							 // c[i;w] = c[i .. 1;w] if wi > w
				K[i][w] = K[i - 1][w];
		}
	}

		reuslt = K[n][weight_limit];
}

int main()
{
	/*
	n: the number of items
	weight_limit: maximum weight of the knapsack
	values: values of the item i
	weights: weights of the item i
	*/
	size_t n ;
	long weight_limit;	



	cout << "\n--------" << endl;
	cout << "KnapSack";
	cout << "\n--------" << endl;

	// number of items
	cout << "Enter the number of items: ";
	cin >> n;
	unsigned int values[n], weights[n];
	
	for (unsigned int i = 0; i < n; i++)
	{
		cout << "Enter value for item " << i+1 << ": ";
		cin >> values[i];
		cout << "Enter weight for item " << i+1 << ": ";
		cin >> weights[i];
	}
	
	// capacity
	cout << "Enter the capacity: ";
	cin >> weight_limit;
	
	// call the KnapSack function
	KnapSack(weights, values, n, weight_limit);
	cout << "The result: "<< reuslt;

	cout << "\n--------" << endl;
	system("pause");
	return 0;
}
