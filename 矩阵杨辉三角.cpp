/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
//思路：初始化一个长度为i+1的全为1的vector，从1-i循环赋值即可
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=0;i<numRows;i++)
        {
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++)
            {
                temp[j]=res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(temp);
        }
        return res;
    }
};