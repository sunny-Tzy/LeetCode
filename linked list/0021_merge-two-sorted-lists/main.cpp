//Definition for singly-linked list.

//第一部分：链表节点定义

#include <iostream>    //引入输入输出库，后面`std::cout`打印数字必须要用这个头文件
struct ListNode {    //定义结构体`ListNode`，就是链表的一个节点
    int val;    //节点里面存的数值，int整数类型
    ListNode *next;    //`next`是指针，用来存下一个节点的地址
    ListNode() : val(0), next(nullptr) {}    //无参构造函数。新建节点不给参数时，val 默认 = 0，next是空指针，`nullptr`代表没有下一个节点
    ListNode(int x) : val(x), next(nullptr) {}    //构造函数：只传入数字 x，节点值 = x，下一个节点为空
    ListNode(int x, ListNode *next) : val(x), next(next) {}    //构造函数：传入数值 x + 下一个节点指针，同时赋值
 };    //结构体结束
 
//第二部分：Solution类，合并链表核心函数

class Solution {    //创建 Solution 类，LeetCode 刷题固定写法，把算法函数放里面
public:    //公共成员，外部代码可以调用这个函数
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {    //函数定义：函数名叫 mergeTwoLists，输入：两个链表头指针 list1、list2；返回值：ListNode*，合并完成之后新链表的头指针
        ListNode dumy;    //创建虚拟头节点（哨兵节点）dumy，作用：不用单独处理链表为空的边界情况，简化链表拼接代码
        ListNode* cur=&dumy;    //`cur`是工作指针，`&dumy`取 dumy 的地址，cur一开始指向虚拟头节点，我们用 cur 往后拼接新链表
        while(list1!=nullptr&&list2!=nullptr)    //while 循环。条件：list1不为空并且list2不为空,两个链表都还有节点，才进入循环比较大小
        {
            if(list1->val<=list2->val)    //`->` 指针访问成员,含义：如果 list1 当前节点的值 ≤ list2 当前节点的值,哪个小，就把哪个接到新链表
            {
                cur->next=list1;    //把当前 cur 节点的 next，指向 list1 这个更小的节点，完成拼接
                list1=list1->next;    //list1 指针向后移动，看 list1 的下一个节点
            }
            else    //否则（list2 的值更小）
            {
                cur->next=list2;    //cur 的下一个节点接 list2
                list2=list2->next;    //list2 指针向后移动一格
            }
            cur=cur->next;    //cur指针向后走一步，移动到刚接上的这个新节点，准备下一轮拼接
        }    //循环结束代表:list1或者list2其中一条链表已经走完了
        if(list1!=nullptr)    //判断：如果 list1还有剩下节点没处理完
        {
            cur->next=list1;    //直接把剩余所有节点接到 cur 后面（剩下的链表本身有序，不用一个个比较）
        }
        else    //如果 list1 已经空了
        {
            cur->next=list2;    //那就接上 list2 剩下的全部节点
        }
        return dumy.next;    //返回虚拟头节点的下一个节点，这就是合并后链表真正的起点。虚拟头本身是占位节点，不算有效数据
    }    //函数结束
};    //Solution 类结束

//第三部分 main 函数，本地测试代码（LeetCode 提交不需要 main）

int main() {    //程序入口，所有程序从 main 开始运行
    ListNode a1(1), a2(2), a3(4);    //创建 3 个节点，a1 值 = 1，a2=2，a3=4。用来构造链表 list1：`1→2→4`
    ListNode b1(1), b2(3), b3(4);    //创建 3 个节点，b1=1,b2=3,b3=4，构造链表 list2：`1→3→4`

    a1.next = &a2;    //a1的next存a2的地址，a1的下一个节点是a2
    a2.next = &a3;    //a2的下一个节点是a3

    b1.next = &b2;    //b1 下一个节点是 b2
    b2.next = &b3;    //b2 下一个节点是 b3

    Solution solution;    //创建 Solution 类的实例，名字叫 solution，用来调用合并函数

    ListNode* result = solution.mergeTwoLists(&a1, &b1);    //调用合并函数，传入 a1、b1 地址（两个链表头），把合并后的链表头指针存入 result

    while (result != nullptr) {    //循环：result 不是空指针，就持续遍历链表
        std::cout << result->val << " ";    //打印当前节点的值，后面加空格。std::cout 就是控制台输出
        result = result->next;    //result 指针移动到下一个节点
    }

    return 0;    //main 函数正常结束，返回 0
}