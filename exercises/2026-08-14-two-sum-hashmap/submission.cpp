#include<iostream>
#include<vector>
#include<unordered_map>
std::vector<int> twoSum(const std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> num_map;
    for (int i = 0 ; i < nums.size(); i++)
    {
        int need = target - nums[i];
        if(num_map.find(need) != num_map.end())
        {
            return {num_map[need], i};
        }
        else
        {
            num_map[nums[i]] = i;
        }
    }
    return {};
}

int main()
{
    std::vector<int> nums1 = {2 ,7, 11, 15}, nums2 = {3, 2, 4}, nums3 = {1, 2, 3};
    int target1 = 9, target2 = 6, target3 = 100;  
    std::vector<int> result1 = twoSum(nums1, target1);
    std::vector<int> result2 = twoSum(nums2, target2);
    std::vector<int> result3 = twoSum(nums3, target3);
    if (result1.size() == 0)
    {
        std::cout<< "结果" << "{" << "无解" << "}" << std::endl;
    }
    else
        std::cout<< "结果"<< "{" << result1[0] << ","<< result1[1] << "}" << std::endl;
    if (result2.size() == 0)
    {
        std::cout<< "结果" << "{" << "无解" << "}" << std::endl;
    }
    else
        std::cout<< "结果"<< "{" << result2[0] << ","<< result2[1] << "}" << std::endl;
    if (result3.size() == 0)
    {
        std::cout<< "结果" << "{" << "无解" << "}" << std::endl;
    }
    else
        std::cout<< "结果"<< "{" << result3[0] << ","<< result3[1] << "}" << std::endl;
}