/*707. 设计链表
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 

示例：

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
 

提示：

所有val值都在 [1, 1000] 之内。
操作次数将在  [1, 1000] 之内。
请不要使用内置的 LinkedList 库。*/

class MyLinkedList {
public:
    MyLinkedList():count(0),head(nullptr),tail(nullptr){
    }
    // ~MyLinkedList(){
    //     while( head != nullptr ){
    //         ListNode *next= head->next;
    //         delete head;
    //         head = next;
    //     }
    //     count = 0;
    //     tail = nullptr;
    // }
    
    int get(int index) {
        if( index >= count )
            return -1;
        ListNode *ptr = head;
        for( int i = 0; i < index; i++)
            ptr = ptr->next;
        return ptr->val;
    }
    
    void addAtHead(int val) {
        count++;
        ListNode *ptr = new ListNode(val);
        if( head == nullptr ){
            head = ptr;
            tail = ptr;
            return;
        }
        ptr->next = head;
        head = ptr;
    }
    
    void addAtTail(int val) {
        count++;
        ListNode *ptr = new ListNode(val);
        if( head == nullptr ){
            head = ptr;
            tail = ptr;
            return;
        }
        tail->next = ptr;
        tail = tail->next;
    }
    
    void addAtIndex(int index, int val) {
        if(index > count )
            return;
        if( index <= 0 ){//index为负数或者0的时候添加到表头
            addAtHead(val);
            return;
        }
        if( index == count ){//等于的时候添加到表尾
            addAtTail(val);
            return;
        }
        count++;
        ListNode *newNode = new ListNode(val);
        ListNode newHead(0, head);
        ListNode *prev = &newHead;
        for( int i = 0; i < index; i++ )//需寻找第index节点的前一个节点
            prev = prev->next;
        newNode->next = prev->next;//添加
        prev->next = newNode;
        return;
    }
    
    void deleteAtIndex(int index) {
        if( index < 0 || index >= count )//index无效，不删除
            return ;
        ListNode newHead(0, head);
        ListNode *prev = &newHead;
        for( int i = 0; i < index; i++ )//这里是为了寻找被删除节点的的前一个节点
            prev = prev->next;
        ListNode *next = prev->next->next;
        delete prev->next;//删除
        prev->next = next;
        count--;
        if(  prev == &newHead && prev->next == nullptr ){//如果删除后链表为空
            head = nullptr;
            tail = nullptr;
            return;
        }
        if( prev == &newHead ){//如果删除的是头节点
            head = prev->next;
        }
        if( prev->next == nullptr ){//如果删除的是尾节点
            tail = prev;
        }
        return;
    }
private:
    struct ListNode{//定义节点
        int val;
        ListNode *next;
        ListNode(int v):val(v),next(nullptr){}
        ListNode(int v, ListNode* p):val(v),next(p){}
    };
    int count;
    ListNode *head, *tail;
};
