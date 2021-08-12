/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制：
最多会对 addNum、findMedian 进行 50000 次调用。
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        /*
        在加入元素时，先判断大顶堆和小顶堆的元素数量是否相同，
        若相同则优先往小顶堆中加入元素，反之优先往大顶堆中加；
        加入元素的方法为，先将元素加入到相反的堆内，再将相反
        堆的顶元素加入到该堆中，然后将该顶元素pop
        */
        if(min_heap.size() == max_heap.size()) {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop(); 
        } else {
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    }
    
    double findMedian() {
        int size_min_heap = min_heap.size();
        int size_max_heap = max_heap.size();
        /*
        由加入元素的原理可知，当两堆元素数量相同时，取两堆顶的元素平均值即位中位数，
        否则，取小顶堆的堆顶元素即可
        */
        if (size_min_heap == size_max_heap) {
            return (min_heap.top() + max_heap.top())*1.0/2;
        } else {
            return min_heap.top();
        }

    }
private:
    // 定义小顶堆，堆顶元素为最小值，用来存放较大的一半数字
    std::priority_queue<int, std::vector<int>, greater<int>> min_heap;
    // 定义大顶堆，堆顶元素为最大值，用来存放较小的一半数字
    std::priority_queue<int, std::vector<int>, less<int>> max_heap;
    

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

最多会对 addNum、findMedian 进行 50000 次调用。
*/


