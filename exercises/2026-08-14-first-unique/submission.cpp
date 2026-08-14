#include<iostream>
#include<vector>
#include<unordered_map>

int firstUniqueIndex(const std::vector<int>& nums);
void printResult(const std::vector<int>& nums, int result);

int main()
{
    std::vector<int> nums1 = {4, 5, 1, 2, 0, 4}, nums2 = {1, 1, 2, 2}, nums3 = {7}, nums4 = {2, 3, 2, 4, 3, 5};
    int result1 = firstUniqueIndex(nums1);
    int result2 = firstUniqueIndex(nums2);
    int result3 = firstUniqueIndex(nums3);
    int result4 = firstUniqueIndex(nums4);
    printResult(nums1, result1);
    printResult(nums2, result2);
    printResult(nums3, result3);
    printResult(nums4, result4);
}

int firstUniqueIndex(const std::vector<int>& nums)
{
    std::unordered_map<int, int> count;
    for(int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }
    for(int j = 0; j < nums.size(); j++)
    {
        if(count[nums[j]] == 1)
        {
            return j;
        }
    }
    return -1;
}

void printResult(const std::vector<int>& nums, int result)
{
    if (nums.size() == 0)
    {
        std::cout << "源数据" << "{}" << std::endl;
    }
    else
    {
        std::cout << "源数据" << "{";
        for(int i = 0; i < nums.size() - 1; i++)
        {
            std::cout << nums[i] << ","; 
        }
        std::cout << nums.back() << "}" << std::endl;
        std::cout << "结果: 唯一元素索引为 " << result << std::endl;
    }
}