#include <iostream>
using namespace std;

// 定义链表节点结构体
struct ListNode {
    char val;
    ListNode* next;
    ListNode(char x) : val(x), next(nullptr) {}
};

// 向链表中添加新节点
void appendNode(ListNode*& head, char value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 检查节点是否存在于链表中
bool exists(ListNode* head, char value) {
    while (head != nullptr) {
        if (head->val == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// 计算两个集合的交集
ListNode* intersection(ListNode* headA, ListNode* headB) {
    ListNode* dummyHead = new ListNode(0); // 创建一个哑节点作为结果链表的头节点
    ListNode* tail = dummyHead;
    while (headA != nullptr) {
        if (exists(headB, headA->val)) {
            tail->next = new ListNode(headA->val);
            tail = tail->next;
        }
        headA = headA->next;
    }
    ListNode* result = dummyHead->next;
    delete dummyHead; // 删除哑节点
    return result;
}

// 打印链表
void printList(ListNode* head) {
    while (head != nullptr && head->next != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val;
}

// 清理链表内存
void clearList(ListNode*& head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// 计算字符串长度
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

int main() {
    cout<<"欢迎使用集合交集计算程序"<<endl;
    int caseNum;
    cout << "请输入数字选择功能 (1 for 自定义集合 2 for 向集合添加固定元素): ";
    cin >> caseNum;
    cin.ignore(); // 忽略换行符

    ListNode* headA = nullptr;
    ListNode* headB = nullptr;

    switch (caseNum) {
    case 1: {
        // 自定义集合
        char elementsA[100];
        char elementsB[100];
        cout << "请输入集合A的元素，用空格分隔: ";
        cin.getline(elementsA, 100);
        cout << "请输入集合B的元素，用空格分隔: ";
        cin.getline(elementsB, 100);
        int sizeA = stringLength(elementsA);
        int sizeB = stringLength(elementsB);
        for (int i = 0; i < sizeA; ++i) {
            appendNode(headA, elementsA[i]);
        }
        for (int i = 0; i < sizeB; ++i) {
            appendNode(headB, elementsB[i]);
        }
        break;
    }
    case 2: {
        // 向集合A添加元素
        cout << "集合A={c a e h},集合B={f h b g d a} " << endl;
        appendNode(headA, 'c');
        appendNode(headA, 'a');
        appendNode(headA, 'e');
        appendNode(headA, 'h');

        // 向集合B添加元素
        appendNode(headB, 'f');
        appendNode(headB, 'h');
        appendNode(headB, 'b');
        appendNode(headB, 'g');
        appendNode(headB, 'd');
        appendNode(headB, 'a');
        break;
    }
    default:
        cout << "无效的case编号。" << endl;
        return 1;
    }

    // 计算交集
    ListNode* resultSet = intersection(headA, headB);

    // 打印结果
    cout << "A和B的交集为: {";
    printList(resultSet);
    cout << "}"<<endl;

    // 清理链表内存
    clearList(headA);
    clearList(headB);
    clearList(resultSet);
    system("pause");
    return 0;
}