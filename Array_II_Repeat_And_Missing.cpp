#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int> hash(n+1,0);
	int miss,repeat;

	for(int i = 0 ; i < n ; i++)
	{
		hash[arr[i]] += 1;
	}

	for(int i = 1 ; i <= n ; i++)
	{
		if(hash[i] == 2)
			repeat = i;
		if(hash[i] == 0)
			miss = i;
	}
	
	return {miss,repeat};
}
