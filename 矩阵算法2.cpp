/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
//思路：在循环次数loop中，numi和numj分别-2，以求得当前循环中最大的row和col
#include <iostream>

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty()) {
			return res;
		}
		int numi = matrix.size();
		int numj = matrix[0].size();
		//环数
		int loop = numi > numj ? (numj + 1) / 2 : (numi + 1) / 2;

		for (int i = 0;i < loop;i++, numi -= 2, numj -= 2) {

			for (int col = i;col < i + numj;col++) {
				res.push_back(matrix[i][col]);
			}
			for (int row = i + 1;row < i + numi;row++) {
				res.push_back(matrix[row][i + numj - 1]);
			}
			//最后一环为一行或一列，则在上面两步之后已经全部输出，直接退出即可
			if (numi == 1 || numj == 1)
				break;

			for (int col = i + numj - 2;col >= i;col--) {
				res.push_back(matrix[i + numi - 1][col]);
			}
			for (int row = i + numi - 2;row > i;row--) {
				res.push_back(matrix[row][i]);
			}
		}
		return res;
}

int main() {
	vector<vector<int>> matrit = { {1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6} };
	vector<int> result = spiralOrder(matrit);
	for (vector<int>::iterator ite = result.begin();ite != result.end();ite++) {
		cout << *ite << " ";
	}
	cout << "HelloWorld";
}

