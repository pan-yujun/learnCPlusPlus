/*
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

解释:

 

说明:

给定矩阵中的元素总数不会超过 100000 。
*/
//思路：总循环次数m*n中，区分出在矩阵左上角和右下角两大块
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        const int m = matrix.size(); //行数
        const int n = matrix[0].size(); //列数
        int i = 0;
        int j = 0;
        for(int l = 0; l < m*n; l++){
            res.push_back(matrix[i][j]);
            if((i + j) % 2 == 0){ //左往上遍历
                if(j == n - 1){ //列坐标到达右边界
                    i++; //往下移一格准备右往下遍历
                }
                else if(i == 0){ //行坐标到顶部了
                    j++; //往右移一格准备右往下遍历
                }
                else{ //往右上移动一格
                    i--;
                    j++;
                }
            }
            else{ //右往下遍历
                if(i == m - 1){
                    j++;
                }
                else if(j == 0){
                    i++;
                }
                else{
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};