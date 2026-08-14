# 2026-08-14｜Two Sum + `unordered_map` 讨论复盘

## 本次目标

在已经理解暴力枚举版 Two Sum 的基础上，学习使用 `unordered_map` 保存“数字 → 下标”，并把查找过程优化到平均 `O(n)`。

## 1. `unordered_map` 是什么

`std::unordered_map<Key, Value>` 是一种键值映射容器，可以先理解为“字典”或“哈希表”。

```cpp
std::unordered_map<int, int> num_map;

num_map[2] = 0;
num_map[7] = 1;
```

含义是：

```text
数字 2 → 下标 0
数字 7 → 下标 1
```

它不必须和 `vector` 配合使用；在 Two Sum 中，只是利用 `vector` 提供数字和下标，再把对应关系保存到 map 中。

## 2. 重复 key

`unordered_map` 中同一个 key 只能对应一个 value：

```cpp
num_map[2] = 0;
num_map[2] = 1;
```

第二次赋值会覆盖第一次的 value。

Two Sum 中之所以仍然可以处理重复数字，是因为算法采用：

```text
先查找补数
→ 找到就返回
→ 没找到才保存当前数字
```

例如：

```text
nums = {2, 2}, target = 4
```

处理过程：

```text
第一次遇到 2：map 中没有 2，保存 2 → 0
第二次遇到 2：找到 2 → 0，返回 {0, 1}
```

这样不会把同一个元素和自己配对。

## 3. `find()` 和 `end()`

```cpp
auto it = num_map.find(need);
```

`find()` 返回一个迭代器。可以把迭代器理解成指向 map 元素的“书签”。

- 找到 key：迭代器指向对应的键值对；
- 找不到 key：返回 `num_map.end()`。

`end()` 不是最后一个元素，而是容器结束位置的特殊标记。

```cpp
if (it != num_map.end()) {
    // 找到了
}
```

```cpp
if (it == num_map.end()) {
    // 没找到
}
```

## 4. `auto` 和迭代器访问

```cpp
auto it = num_map.find(need);
```

`auto` 让编译器自动推断变量类型。这里的实际类型是：

```cpp
std::unordered_map<int, int>::iterator
```

如果 `it` 指向：

```text
7 → 1
```

那么：

```cpp
it->first   // 7，key
it->second  // 1，value
```

以下两种写法等价：

```cpp
it->second
(*it).second
```

`it[0]` 不等价，因为 `it` 是 `unordered_map` 的迭代器，不是数组或 `vector` 的随机访问迭代器。

## 5. 为什么推荐复用迭代器

原来的写法：

```cpp
if (num_map.find(need) != num_map.end())
{
    return {num_map[need], i};
}
```

这里先用 `find(need)` 查找一次，之后 `num_map[need]` 又需要根据 key 查找一次并取出 value。

更推荐：

```cpp
auto it = num_map.find(need);

if (it != num_map.end())
{
    return {it->second, i};
}
```

这样可以直接复用第一次查找得到的迭代器，避免重复查找。

两种写法的整体平均时间复杂度都仍然是 `O(n)`；复用迭代器主要是减少一次哈希查找，降低常数开销，并且让“查找结果”和“取出下标”之间的关系更清楚。

## 6. 当前提交版本

当前 `submission.cpp` 已完成：

- 暴力版 Two Sum 到 `unordered_map` 版的转换；
- 返回两个下标；
- 无解时返回空 `vector`；
- 处理三组基础测试；
- 主函数打印有解和无解情况。

已验证的测试：

```text
{2, 7, 11, 15}, target = 9  → {0, 1}
{3, 2, 4}, target = 6       → {1, 2}
{1, 2, 3}, target = 100      → 无解
```

建议补充：

```text
{2, 2}, target = 4           → {0, 1}
```

## 下一步

在不改变题目功能的前提下，进一步熟悉：

1. `const std::vector<int>&` 的含义；
2. 平均时间复杂度与空间复杂度；
3. 使用迭代器版本重构当前提交。