#include <vector>
#include <iostream>
using namespace std;

//215   . 数组中的第K个最大元素
//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。       


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 桶数组大小: [-10000, 10000] → 20001
        vector<int> bucket(20005, 0);

        // 统计每个数出现的次数
        for (int n : nums) {
            bucket[n + 10000]++;
        }

        // 从大到小累加
        int sum = 0;
        for (int i = 20004; i >= 0; --i) {
            sum += bucket[i];
            if (sum >= k) {
                return i - 10000; // 恢复原值
            }
        }

        return 0; // 理论上不会走到这里
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << sol.findKthLargest(nums, k) << endl; // 输出 5
    return 0;
}
