# 实战题 01：用 `unordered_map` 优化两数之和

## 题目目标

你已经完成了暴力枚举版两数之和。现在请独立写出一个可以编译运行的 C++ 模块，使用 `unordered_map` 将平均时间复杂度从 `O(n²)` 降低到 `O(n)`。

## 功能要求

实现函数：

```cpp
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target);
```

要求：

- 返回两个元素的下标；
- 两个下标不能相同；
- 找不到答案时返回空的 `std::vector<int>`；
- 不要求修改输入数组；
- 函数之外写一个 `main()`，至少完成 3 组测试。

## 测试样例

```cpp
nums = {2, 7, 11, 15}, target = 9
期望结果：{0, 1}
```

```cpp
nums = {3, 2, 4}, target = 6
期望结果：{1, 2}
```

```cpp
nums = {1, 2, 3}, target = 100
期望结果：{}
```

## 编译要求

Linux 或 WSL 中可以使用：

```bash
g++ -std=c++17 -Wall -Wextra -pedantic submission.cpp -o two_sum
./two_sum
```

如果你当前还没有配置 Linux，也可以先在 Windows 的 C++ 环境中运行，但请保留完整的 `submission.cpp` 和运行结果。

## 提交前自查

- 你是否理解 `unordered_map` 保存的“键”和“值”分别是什么？
- 你是在查找补数后再保存当前元素，还是反过来？为什么？
- 重复数字，例如 `{3, 3}`，能否正确处理？
- 找不到答案时是否稳定返回空 `vector`？
- 你能否说出该实现的平均时间复杂度和空间复杂度？

## 提交方式

请先独立完成，不要急着看答案。完成后把 `submission.cpp` 的完整内容发给我；我会帮你测试并指出问题。通过验收后，最终版本会归档为：

```text
exercises/2026-08-14-two-sum-hashmap/submission.cpp
```
