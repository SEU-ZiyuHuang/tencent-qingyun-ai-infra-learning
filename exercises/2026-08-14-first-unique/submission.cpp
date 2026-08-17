#include<iostream>
#include<vector>
#include<unordered_map>

std::vector<int>::size_type firstUniqueIndex(const std::vector<int>& nums);
void printResult(const std::vector<int>& nums, std::vector<int>::size_type result);

int main()
{
    std::vector<int> nums1 = {4, 5, 1, 2, 0, 4}, nums2 = {1, 1, 2, 2}, nums3 = {7}, nums4 = {2, 3, 2, 4, 3, 5};
    std::vector<int>::size_type result1 = firstUniqueIndex(nums1);
    std::vector<int>::size_type result2 = firstUniqueIndex(nums2);
    std::vector<int>::size_type result3 = firstUniqueIndex(nums3);
    std::vector<int>::size_type result4 = firstUniqueIndex(nums4);
    printResult(nums1, result1);
    printResult(nums2, result2);
    printResult(nums3, result3);
    printResult(nums4, result4);
}

std::vector<int>::size_type firstUniqueIndex(const std::vector<int>& nums)
{
    std::unordered_map<int, int> count;
    for(std::vector<int>::size_type i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }
    for(std::vector<int>::size_type j = 0; j < nums.size(); j++)
    {
        if(count[nums[j]] == 1)
        {
            return j;
        }
    }
    return nums.size();
}

void printResult(const std::vector<int>& nums, std::vector<int>::size_type result)
{
    if (nums.size() == 0)
    {
        std::cout << "源数据" << "{}" << std::endl;
        std::cout << "结果: 没有唯一元素" << std::endl;
    }
    else
    {
        std::cout << "源数据" << "{";
        for(std::vector<int>::size_type i = 0; i < nums.size() - 1; i++)
        {
            std::cout << nums[i] << ",";
        }
        std::cout << nums.back() << "}" << std::endl;
        if (result == nums.size())
        {
            std::cout << "结果: 没有唯一元素" << std::endl;
        }
        else
        {
            std::cout << "结果: 唯一元素索引为 " << result << std::endl;
        }
    }
}
