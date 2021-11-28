#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_subset_available(vector<int>& A, int m);

int main()
{
	int t, m, n;
	
	cout << "Enter the number of test cases: ";
	cin >> t;
	
	while(t--)
	{
		cout << "Enter the value of n(length of array) and m(required length): ";
		cin >> n >> m;
	
		int val;	
		vector<int> A;

		cout << "Enter the array elements:\n ";
		while (n--)
		{
			cin >> val;
			A.push_back(val);
		}

		cout << is_subset_available(A, m) << endl;
		
		A.clear();
	}

	return 0;
}

bool is_subset_available(vector<int>& A, int m)
{
	int size = (int) A.size();

	vector<vector<bool>> subset(size + 1, vector<bool> (m + 1, false));

	for(int i = 0; i < size+1; i++)
		subset[i][0] = true;

	for (int i = 1; i < size+1; i++)
		for (int j = 1; j < m+1; j++)
		{
			if (j < A[i-1])
				subset[i][j] = subset[i-1][j];
			else
				subset[i][j] = subset[i-1][j] || subset[i-1][j - A[i-1]];
		}
	
	for (int i = 0; i < size+1; i++)
	{
		for (int j = 0; j < m+1; j++)
			cout << subset[i][j] << " ";
		cout << endl;
	}

	return subset[size][m];
}
