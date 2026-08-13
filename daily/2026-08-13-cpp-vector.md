# 2026-08-13｜C++ Day 2：`vector` 与两数之和基础

## 今日目标

- 理解 `vector<int>` 是什么。
- 掌握 `size()`、`push_back()` 和下标访问。
- 理解 `vector<int>&` 的引用传参。
- 理解 `return answer` 与 `return {}`。
- 能读懂暴力枚举版两数之和。

## 1. 数组、指针与下标

```cpp
int a[3] = {10, 20, 30};
int* p = a;

*(p + 1) = 21;
```

`p` 指向 `a[0]`，`p + 1` 指向 `a[1]`。指针加一会移动一个 `int` 元素的位置，而不是只移动一个字节。

数组下标从 `0` 开始，因此长度为 `3` 的数组下标是 `0、1、2`。

## 2. `vector` 的常用操作

```cpp
#include <vector>

std::vector<int> nums = {10, 20};

nums.push_back(30);  // 尾部添加元素
nums[0] = 100;       // 修改第一个元素
int x = nums[1];     // 读取第二个元素
int n = nums.size(); // 获取元素数量
```

执行后：

```cpp
nums = {100, 20, 30};
n = 3;
```

`vector` 可以理解为能够自动扩容的动态数组。

## 3. 引用传参

```cpp
void change(std::vector<int>& nums) {
    nums[0] = 100;
    nums.push_back(4);
}
```

参数中的 `&` 表示引用。函数不会复制一份新的 `vector`，而是直接操作原来的对象，因此修改会保留。

如果写成下面这样，函数操作的是副本：

```cpp
void change(std::vector<int> nums) {
    nums[0] = 100;
}
```

## 4. 越界访问

```cpp
std::vector<int> nums = {5, 10, 15};
```

合法下标是 `0、1、2`。访问 `nums[3]` 属于越界访问，使用 `operator[]` 时不会自动检查边界，结果属于未定义行为。

需要检查边界时可以使用：

```cpp
nums.at(3); // 越界时抛出异常
```

## 5. `return {}`

两数之和函数的返回类型是 `vector<int>`：

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    // ...
    return {};
}
```

这里的 `return {};` 表示返回一个空的 `vector<int>`。它不是 `nullptr`；`nullptr` 用于空指针。

## 6. 暴力枚举版两数之和

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }

        return {};
    }
};
```

例如：

```cpp
nums = {2, 7, 11, 15}, target = 9
```

返回：

```cpp
vector<int>{0, 1}
```

返回的是下标，不是元素值。如果没有找到满足条件的两个元素，则返回空 `vector`。

## 今日验收

- 能正确判断数组和 `vector` 的下标范围。
- 能解释 `vector<int>&` 为什么会修改原对象。
- 能区分空 `vector` 与 `nullptr`。
- 能解释两数之和代码返回 `{0, 1}` 的原因。

本次验收：通过。

## 与 AI Infra 的联系

`vector` 通常使用连续内存保存元素。后续学习张量、模型输入和推理缓存时，会经常接触连续内存、指针和数据缓冲区。理解 `vector` 是理解 C++ 推理工程代码的基础。

## 下一次任务

学习 `unordered_map`，把两数之和从暴力枚举的 `O(n²)` 优化到平均 `O(n)`。
