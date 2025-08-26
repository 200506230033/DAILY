#include <vector>
#include<iostream>
using namespace std;

//216. 组合总和 III
//找出所有相加之和为 n 的 k 个数的组合，且满足下条件：
//只使用数字1到9
//每个数字 最多使用一次
//返回所有可能的有效组合的列表。该列表不包含重复的组合。你可以按 任何顺序 返回答案。    

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, k, n, 1); // 从数字1开始
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, vector<int>& path, int k, int n, int start) {
        if (path.size() == k && n == 0) { // 找到一个组合
            res.push_back(path);
            return;
        }
        if (path.size() > k || n < 0) return; // 剪枝

        for (int i = start; i <= 9; ++i) {
            path.push_back(i);
            dfs(res, path, k, n - i, i + 1); // 下一层从 i+1 开始
            path.pop_back(); // 回溯
        }
    }
};


int main(){
    int k = 3 , n = 7;
    Solution s;
    vector<vector<int>> res = s.combinationSum3(k ,n);
    for (const auto& comb : res) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}