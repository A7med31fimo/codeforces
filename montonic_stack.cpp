/*
  montonic stack 
  author : Ahmed Fahim

*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <vector>
using namespace std;
int maximalRectangle(vector<vector<char>> &matrix)
{
    int ans = 0;
    int size = matrix[0].size();//size of row in matrix
    for (int u = 0; u < matrix.size(); u++) // iterate on each row
    {
        /*array that accumlate each column until 
        find 0 and the base is row u*/
        int heights[size];
        //init array with zeros
        for (int h = 0; h < size; h++)
        {
            heights[h] = 0;
        }

         //iterate on each column 
        for (int j = 0; j < size; j++) // columns
        {
            //iterate on each row from u to end of matrix
            for (int k = u; k < matrix.size(); k++) // rows
            {
               
               //0 1 0
               //1 1 1
               //1 1 1
            //heights will accumlate in u =0
            //0 3 0
            //heights will accumlate in u =1
            //2 2 2
            //heights will accumlate in u =2
            //1 1 1
    //and for each array heghts we will find max area or rectangle
    //by the code of problem maxArea of reactangle 
                if (matrix[k][j] - '0' == 0)
                    break;
                heights[j] += 1;
            }
        }
        // for (int  m = 0; m < size; m++)
        // {
        //     cout<<heights[m]<<" ";
        // }
        // cout<<"\n";

        stack<int> s1;
        int a[size];
        memset(a, 0, sizeof(a));
        s1.push(-1);
        for (int i = 0; i < size; i++)
        {
            while (s1.top() >= 0 && heights[s1.top()] >= heights[i])
            {
                s1.pop();
            }

            a[i] = i - s1.top() - 1;
            s1.push(i);
        }
        stack<int> s2;
        int a2[size];
        memset(a2, 0, sizeof(a2));

        s2.push(size);
        for (int i = size - 1; i >= 0; i--)
        {
            while (s2.top() < size && heights[s2.top()] >= heights[i])
            {
                s2.pop();
            }

            a2[i] = abs(i - s2.top()) - 1;
            s2.push(i);
        }

        for (int i = 0; i < size; i++)
        {
                ans = max(ans, (a[i] + a2[i] + 1) * heights[i]);
        }
    }
    return ans;
}
int main()
{

    vector<vector<char>> matrix = {
        {'1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1'}};
    cout << maximalRectangle(matrix);

    return 0;
}
