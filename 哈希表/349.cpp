//349. 两个数组的交集
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {

        unordered_set<int> result_set;
        unordered_set<int> nums_set;

        // 等价于unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int i=0;i<nums1.size();i++)
        {
            nums_set.insert(nums1[i]);
        }
        // 将nums1的所有元素存入nums_set（去重）

        // 等价于for (int num : nums2) { ... }
        // 原代码用范围for循环，这里用索引循环，功能相同：遍历nums2的每个元素
        for(int j=0;j<nums2.size();j++)
        {
            int current=nums2[j];
            if(nums_set.find(current)!=nums_set.end())
            {
                result_set.insert(current);
            }
        }
        //从 “[first, last)” 这个范围中复制所有元素，创建一个新的 vector。
        return vector<int>(result_set.begin(),result_set.end());
    }
};

int main() {
    // 测试用例：求两个数组的交集
    vector<int> nums1 = { 4, 9, 5, 4 };
    vector<int> nums2 = { 9, 4, 9, 8, 4 };

    // 创建解决方案实例并计算交集
    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);

    // 输出输入数组
    cout << "nums1: ";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i != nums1.size() - 1) cout << ", ";
    }
    cout << endl;

    cout << "nums2: ";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i != nums2.size() - 1) cout << ", ";
    }
    cout << endl;

    // 输出交集结果
    cout << "交集结果: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
