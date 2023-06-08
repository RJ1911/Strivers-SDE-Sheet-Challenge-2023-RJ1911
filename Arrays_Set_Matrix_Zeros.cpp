#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();

	vector<bool> row(n,false) ,col(m,false);

	for(int i = 0 ; i < n;i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(matrix[i][j]== 0)
			{
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for(int i = 0 ; i < n ;i++)
	{
		for(int j = 0 ; j < m;j++)
		{
			if(row[i] == true or col[j] == true)
			matrix[i][j] = 0 ;
		}
	}
}
