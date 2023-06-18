// LeetCode -> Rotate image
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0 ; i  < n ;i++)
        {
            for(int j = i + 1 ; j < n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
      
        
        for(int i = 0 ; i  < n  ;i++)
        {
            int start = 0;
            int end = n-1;
            while(start < end)
            {
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
         
    }

// Coding Ninjas -> Rotate Matrix Elements => Matrix spiral traversal.
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &matrix, int n, int m)
{
        if(n == 1 or m == 1) return;
        int top =0 , bottom = n -1 ;
        int left = 0 , right = m - 1;
        
        while(top<bottom and left<right)
        {
            int curr = matrix[top+1][left];
            // top/left -> top/right
            for(int i = top ,j =left ; j<=right;j++ )
                swap(matrix[i][j],curr);
            top++;
            if(top>bottom) break;
            
            //top/right -> bottom/right
            for(int i = top , j =right ; i<=bottom ; i++)
                swap(matrix[i][j],curr);
            right--;
            
            if(right<left) break;
            //bottom/right -> bottom/left
            for(int i = bottom , j = right ; j >=left;j--)
                swap(matrix[i][j],curr);
            bottom--;
            
            if(bottom<top) break;
            //bottom/left -> top/left
            for(int i = bottom , j = left ; i >=top ; i--)
                swap(matrix[i][j],curr);
            left++;
            
            if(left>right) break;
        }

}
