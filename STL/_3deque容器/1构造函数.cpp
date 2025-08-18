/*
	3.3 deque容器

	3.3.1 deque容器基本概念

	功能：

	双端数组，可以对头端进行插入删除操作

	deque与vector区别：

	vector对于头部的插入删除效率低，数据量越大，效率越低
	deque相对而言，对头部的插入删除速度回比vector快
	vector访问元素时的速度会比deque快,这和两者内部实现有关

    ————————————————————————————————————————
    deque（双端队列）容器通过**分段连续存储**和**中控器映射**实现高效的内存管理，其原理可概括为：

1. **分段存储结构**
   - 将数据分散存储在多个固定大小的连续内存块中（如512字节/块），而非单一连续内存（如vector）。
   - 每个内存块称为一个**缓冲区**，通过指针数组（中控器）统一管理。

2. **中控器映射机制**
   - 维护一个指针数组（如`map`），每个指针指向一个独立的内存块。
   - 动态扩展中控器容量（如2倍扩容）以支持更多缓冲区，避免整体数据搬迁。

3. **双端操作优化**
   - 头部/尾部插入删除时，只需分配或释放对应端的缓冲区，时间复杂度为O(1)。
   - 随机访问通过计算`位置 = 中控器索引 + 块内偏移`实现，比vector略慢（多一次间接寻址）。

4. **内存动态管理**
   - 扩容时仅新增缓冲区，无需移动现有数据。
   - 缩容时可释放空闲缓冲区，但通常保留部分缓冲区以提升后续操作效率。

**对比vector**：
- 优势：头插/删效率高（O(1) vs vector的O(n)），无大规模数据搬迁。
- 劣势：随机访问稍慢（需两次寻址），内存局部性较差。

典型实现（如STL的`deque`）通过这种设计平衡了双端操作和动态扩展的需求。
*/
/*
	3.3.2 deque构造函数

	功能描述：

	deque容器构造

	函数原型：

	deque<T> deqT; 默认构造形式
	deque(beg, end); 构造函数将[beg, end]区间中的元素拷贝给本身
	deque(n, elem); 构造函数将n个elem拷贝给本身
	deque(const deque &deq); 拷贝构造函数
*/
#include <deque>
#include <iostream>
using namespace std;

void printDeque(const deque<int>& d)
{
    //防止修改容器元素的值
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//deque构造
void test01() {
    deque<int> d1;
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4 = d3;
    printDeque(d4);
}

int main() {
    test01();
    system("pause");
    return 0;
}