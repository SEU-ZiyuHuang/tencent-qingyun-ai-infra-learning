# 腾讯青云｜AI Infra 学习进度仪表盘

> 最后更新：2026-08-17  
> 目标：一年左右形成 C++ / Linux / PyTorch / Transformer / CUDA / LLM Inference 的 AI Infra 工程能力。

## 状态图例

- ✅ **已掌握**：能够解释核心概念，并独立完成当前阶段的基础练习。
- 🟡 **正在巩固**：已经接触或能够部分使用，但还需要复习、迁移或专项练习。
- ⬜ **尚未学习**：后续课程安排。

## 当前学习卡片

| 维度 | 当前状态 |
| --- | --- |
| 当前阶段 | 阶段 1：C++ 基础与数据结构算法入门 |
| 当前专题 | C++ 类型安全、容器接口与基础算法 |
| 最近产出 | Two Sum 优化、First Unique Index 类型安全重构 |
| 当前可独立完成 | 使用 `vector` 和 `unordered_map` 完成基础数组题，并处理只读参数与无解标记 |
| 正在巩固 | 类型别名、迭代器重构、复杂度识别与边界测试 |
| 下一节课 | 类型别名、边界测试与简洁写法 |
| 下一阶段 | C++ 类、对象、封装与工程工具 |

## 最近学习证据

- [2026-08-14 日总结](daily/2026-08-14-cpp-unordered-map.md)
- [Two Sum 代码](exercises/2026-08-14-two-sum-hashmap/submission.cpp)
- [Two Sum 复盘](exercises/2026-08-14-two-sum-hashmap/notes.md)
- [First Unique 代码](exercises/2026-08-14-first-unique/submission.cpp)
- [First Unique 复盘](exercises/2026-08-14-first-unique/notes.md)
- [2026-08-17 日总结](daily/2026-08-17-cpp-const-size-type.md)
- [每日学习计划](study-plan.md)

---

# 阶段 1｜C++ 基础与数据结构算法

## A. C++ 语言、内存与类型

| 状态 | 知识点 | 当前验收重点 |
| --- | --- | --- |
| ✅ | 变量、基本类型、地址、指针、解引用 | 能解释变量、地址和指针的关系 |
| ✅ | 数组下标与指针偏移 | 能判断下标范围并理解指针移动 |
| ✅ | 引用与引用传参 | 能解释引用为什么会修改原对象 |
| ✅ | `const` 与 `const&` | 能解释只读、避免复制和参数传递 |
| ✅ | `int`、`size_type`、`std::size_t` | 能解释 signed/unsigned 警告 |
| ⬜ | 作用域、生命周期与初始化 | 能判断对象何时创建、销毁和失效 |
| ⬜ | 指针的 `const`、`const` 指针 | 能区分“指向的内容不可改”和“指针本身不可改” |
| ⬜ | 函数声明、定义、参数与返回值 | 能拆分头文件式声明和实现 |
| ⬜ | 类、对象、构造函数、析构函数 | 能设计一个简单资源管理类 |
| ⬜ | 封装、继承与多态 | 能解释接口与实现分离 |
| ⬜ | RAII 与智能指针 | 能使用 `unique_ptr` 并解释所有权 |
| ⬜ | 左值、右值与 `move` | 能理解移动而非复制 |
| ⬜ | 模板基础、异常与命名空间 | 能读懂常见 STL 模板代码 |

## B. STL 容器与常用工具

| 状态 | 知识点 | 当前验收重点 |
| --- | --- | --- |
| ✅ | `vector` 创建、访问、修改、`size()`、`push_back()` | 能独立完成数组遍历和修改 |
| ✅ | `vector` 下标范围与 `at()` | 能识别基本越界风险 |
| ✅ | `return {}` 与空 `vector` | 能区分空容器和空指针 |
| ✅ | `unordered_map<Key, Value>` 的 key/value | 能把数字映射到下标或出现次数 |
| ✅ | `operator[]` 的插入与更新 | 能解释重复 key 会覆盖 value |
| ✅ | `find()` 与 `end()` | 能判断找到和没找到 |
| 🟡 | 迭代器、`auto`、`->first`、`->second` | 能读懂，待在代码中独立重构 |
| 🟡 | 顺序遍历与迭代器类型 | 能解释 map 无序而 vector 保序 |
| ⬜ | `string` 与字符处理 | 能处理字符串遍历和计数 |
| ⬜ | `pair`、`tuple` 与结构化绑定 | 能组织多个返回值 |
| ⬜ | `map`、`set`、`unordered_set` | 能比较有序和无序容器 |
| ⬜ | `stack`、`queue`、`deque` | 能选择合适的线性容器 |
| ⬜ | `priority_queue` | 能解决 Top K 和优先级问题 |
| ⬜ | STL 算法、迭代器适配器与 lambda | 能使用常见排序、查找和遍历工具 |

## C. 复杂度与数据结构算法

| 状态 | 知识点 | 当前验收重点 |
| --- | --- | --- |
| ✅ | 暴力枚举 Two Sum | 能写出并解释 `O(n²)` |
| ✅ | 哈希表优化 Two Sum | 能解释平均 `O(n)` 和 `O(n)` 空间 |
| ✅ | First Unique Index 两次遍历 | 能理解“统计次数 → 按原顺序寻找” |
| 🟡 | `O(1)`、`O(n)`、`O(n²)` | 能从循环结构判断增长量 |
| 🟡 | 时间复杂度与空间复杂度 | 能说明 map、返回值和输入空间的影响 |
| 🟡 | `unordered_map` 平均复杂度 | 已理解平均 `O(1)`，待学习最坏情况 |
| ⬜ | 摊销复杂度与扩容 | 能解释 `vector` 扩容为什么平均仍较快 |
| ⬜ | 双指针与滑动窗口 | 能识别连续区间和左右边界 |
| ⬜ | 链表、快慢指针与反转 | 能处理指针移动和节点连接 |
| ⬜ | 栈、队列与单调栈 | 能解决括号、下一个更大元素等问题 |
| ⬜ | 二分查找 | 能明确搜索区间和循环不变量 |
| ⬜ | 堆与 Top K | 能分析优先队列的复杂度 |
| ⬜ | 二叉树、DFS 与 BFS | 能递归或迭代遍历树和图 |
| ⬜ | 动态规划基础 | 能定义状态、转移和边界 |

## D. C++ 工程能力

| 状态 | 知识点 | 当前验收重点 |
| --- | --- | --- |
| 🟡 | 编译、运行与基础警告 | 能看懂常见编译器提示 |
| ⬜ | Linux 文件、目录、权限与管道 | 能在 Linux/WSL 中完成基本操作 |
| ⬜ | Git 分支、提交、差异与回退 | 能维护可复现的代码历史 |
| ⬜ | CMake | 能构建多文件 C++ 项目 |
| ⬜ | GDB | 能设置断点、观察变量和定位崩溃 |
| ⬜ | 文件、流与序列化 | 能读写配置和实验结果 |
| ⬜ | 多线程、`mutex`、条件变量 | 能写一个基础线程池 |
| ⬜ | 性能分析与 Benchmark | 能比较延迟、吞吐和内存 |

---

# 阶段 2｜Python、PyTorch 与深度学习基础

当前状态：⬜ 尚未开始

- ⬜ Python 语法、模块、虚拟环境与包管理
- ⬜ NumPy 数组、广播、矩阵运算与内存布局
- ⬜ PyTorch Tensor、设备、dtype 与数据类型
- ⬜ 自动求导与计算图
- ⬜ `nn.Module`、参数、损失函数与优化器
- ⬜ Dataset、DataLoader、训练/验证循环
- ⬜ GPU 训练、checkpoint、混合精度
- ⬜ MLP、CNN 与基本训练实验

阶段验收：独立完成一个可训练、可保存、可加载、可推理的小模型。

# 阶段 3｜Transformer 与 MiniGPT

当前状态：⬜ 尚未开始

- ⬜ Tokenizer、Embedding 与位置编码
- ⬜ Q、K、V 与 Scaled Dot-Product Attention
- ⬜ Multi-Head Attention
- ⬜ Causal Mask
- ⬜ MLP、残差连接与 LayerNorm
- ⬜ RMSNorm、RoPE、SwiGLU
- ⬜ Transformer Block 与完整 Decoder
- ⬜ 训练、保存、加载与自回归生成
- ⬜ Sampling、temperature、top-k/top-p
- ⬜ KV Cache 的基本原理

阶段验收：用 PyTorch 从底层模块实现一个可生成文本的 MiniGPT。

# 阶段 4｜LLM 推理系统

当前状态：⬜ 尚未开始

- ⬜ Prefill 与 Decode
- ⬜ KV Cache 的内存占用和生命周期
- ⬜ Batch、Dynamic Batching 与 Continuous Batching
- ⬜ TTFT、TPOT、吞吐量与显存占用
- ⬜ FP16、BF16、INT8、INT4 与量化
- ⬜ Paged Attention 的基本思想
- ⬜ Transformers 与 vLLM 的性能对比
- ⬜ TensorRT-LLM / SGLang 的基本架构
- ⬜ 推理服务、并发、限流和监控
- ⬜ Benchmark 设计与结果分析

阶段验收：完成一个 LLM 推理对比实验，并能解释瓶颈。

# 阶段 5｜CUDA、算子与 GPU 性能

当前状态：⬜ 尚未开始

- ⬜ Thread、Block、Grid 与 Kernel
- ⬜ Global Memory、Shared Memory、Register
- ⬜ Warp、线程束执行与分支
- ⬜ Memory Coalescing
- ⬜ Reduction
- ⬜ Softmax、LayerNorm、RMSNorm
- ⬜ GEMM 与矩阵乘法
- ⬜ CUDA Event、Benchmark 与性能分析
- ⬜ PyTorch Extension 与自定义算子
- ⬜ 正确性测试、数值误差与性能回归

阶段验收：完成 CPU/CUDA 算子对比，并记录延迟、带宽和加速比。

# 阶段 6｜项目、开源与求职准备

当前状态：⬜ 尚未开始

- ⬜ MiniGPT 项目整理
- ⬜ Mini LLM Inference Engine
- ⬜ KV Cache / Batching 实验
- ⬜ CUDA 算子优化实验
- ⬜ 阅读 vLLM、SGLang 或 TensorRT-LLM 代码
- ⬜ 从文档、测试、Benchmark 开始贡献开源
- ⬜ 提交并维护真实 Pull Request
- ⬜ 项目 README、架构图和性能报告
- ⬜ AI Infra 简历项目描述
- ⬜ C++、系统、算法和 LLM 推理面试题

---

# 每节课的固定重点

1. 先查看本看板，确认本节课属于哪一个阶段。
2. 对没有学过的概念，先解释“是什么、为什么、最小例子和使用边界”。
3. 一次只推进一个小知识点。
4. 默认采用“解释 → 提问 → 等待回答 → 小练习 → 复盘”。
5. 用户明确要求不提供代码提示时，只提供概念和逐步思考方向。
6. 每节课结束后，把知识、代码、测试、疑问和下一步写入 GitHub。
7. 只有完成实际验收后，才把状态从 🟡 改为 ✅。

## 下一节课重点

**类型别名、边界测试与简洁的索引写法。**

课程目标：

- 理解 `std::size_t` 与 `vector::size_type` 的关系；
- 学会用类型别名减少重复书写；
- 为无解、空输入和重复输入补充测试；
- 根据掌握程度进入范围遍历与迭代器重构。