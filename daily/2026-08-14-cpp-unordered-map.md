# 2026-08-14｜C++ `unordered_map` 与复杂度

## 今日目标

在掌握 `vector` 和暴力版 Two Sum 的基础上，学习使用 `unordered_map` 优化查找，并理解基础时间复杂度和空间复杂度。

## 今日完成内容

### 1. `unordered_map`

`unordered_map<Key, Value>` 可以理解为“键值字典”：

```text
数字 → 下标
数字 → 出现次数
```

它不需要和 `vector` 绑定，只是在 Two Sum 中用来保存数字和下标的对应关系。

### 2. 重复 key

同一个 key 只能保存一个 value。重复赋值会覆盖旧 value。

Two Sum 中采用：

```text
先查找补数
→ 找到就返回
→ 没找到才保存当前数字
```

因此可以正确处理：

```text
{2, 2}, target = 4 → {0, 1}
```

### 3. `find()`、`end()` 和迭代器

- `find()` 返回指向键值对的迭代器；
- 找不到时返回 `end()`；
- `end()` 是容器结束位置的特殊标记，不是真实元素；
- `it->first` 是 key，`it->second` 是 value；
- `auto` 让编译器自动推断迭代器类型。

还理解了 `it->second` 等价于 `(*it).second`，但不能写成 `it[0]`。

### 4. `map[key]` 的注意事项

如果 key 不存在，访问 `map[key]` 可能会创建一个默认值。

例如，数字 `3` 没有被统计过时，访问 `map[3]` 会创建：

```text
3 → 0
```

因此判断 key 是否存在时，应使用 `find()`。

### 5. 两道实战题

#### Two Sum

使用“数字 → 下标”的 map，把暴力枚举优化为平均 `O(n)`。

已完成：

- [Two Sum submission](../exercises/2026-08-14-two-sum-hashmap/submission.cpp)
- [Two Sum notes](../exercises/2026-08-14-two-sum-hashmap/notes.md)

#### First Unique Index

使用“数字 → 出现次数”的 map：

1. 第一次遍历统计次数；
2. 第二次按照原 `vector` 顺序寻找第一个次数为 `1` 的元素；
3. 返回它的下标，没有答案时返回 `-1`。

测试结果：

```text
{4, 5, 1, 2, 0, 4} → 1
{1, 1, 2, 2}       → -1
{7}                → 0
{2, 3, 2, 4, 3, 5} → 3
```

已完成：

- [First Unique submission](../exercises/2026-08-14-first-unique/submission.cpp)
- [First Unique notes](../exercises/2026-08-14-first-unique/notes.md)

## 复杂度理解

复杂度描述输入规模变大时，工作量或额外内存如何增长，不是精确运行秒数。

- 固定访问：`O(1)`；
- 一次遍历：`O(n)`；
- 两层嵌套遍历：`O(n²)`；
- 两个前后执行的线性循环：`O(n) + O(n) = O(n)`。

Two Sum 和 First Unique 都是两次前后执行的遍历，map 操作平均为 `O(1)`，因此总时间复杂度平均为 `O(n)`，额外空间复杂度为 `O(n)`。

## 今日易错点

- `map[key]` 是按 key 查 value，不是按顺序访问；
- `unordered_map` 不保证按 key 或插入顺序保存；
- `map[3]` 在 key 不存在时可能创建 `3 → 0`；
- `int` 和 `vector::size_type` 不是同一种类型，比较时可能出现警告；
- 两个顺序执行的循环不是递归，也不是 `O(n²)`。

## AI Infra 联系

`unordered_map` 训练了“用合适的数据结构减少重复搜索”的思维。后续在推理调度、缓存管理、请求索引和 KV Cache 管理中，也会不断遇到“key → 状态/位置/缓存块”的映射问题。

## 当前状态

今天的核心内容已完成。仍需巩固：

- `const std::vector<int>&` 的细节；
- `size_type` 与 `int` 的区别；
- 迭代器版本的重构；
- `O(1)`、`O(n)`、`O(n²)` 的识别。

## 下一次学习

先用 5 分钟复习今天的 map 和复杂度，再学习 `const` 引用与索引类型，随后进入 C++ 类、对象和封装。