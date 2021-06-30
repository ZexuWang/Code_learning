/*用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 
appendTail 和 deleteHead ，分别完成在队列尾部插入整
数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 
操作返回 -1 )*/

/*
示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
*/

class CQueue {
    stack<int> stack1, stack2;
public:
    CQueue() {
        while(!stack1.empty()) {
            stack1.pop();//清空可能存在的元素，保证stack初始为空
        }
        while (!stack2.empty()){
            stack2.pop();//清空可能存在的元素，保证stack初始为空
        }
         
    }
    
    void appendTail(int value) {
        stack1.push(value);//将插入值压入stack1中，进入队列尾部
    }
    
    int deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }//若stack2已经为空，将stack1的栈顶弹出压入stack2；因此，stack2的栈顶即为stack1的栈底
        }
        if (stack2.empty()) {
            return -1;
        } else {
            int temp = stack2.top();
            stack2.pop();//此时弹出stack2的栈顶就等同于弹出stack1的栈底。从整体上看，相当于弹出CQueue的头部元素
            return temp; 
        }
    }
};

