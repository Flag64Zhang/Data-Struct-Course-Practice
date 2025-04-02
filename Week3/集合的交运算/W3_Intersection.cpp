#include <iostream>
using namespace std;

// ��������ڵ�ṹ��
struct ListNode {
    char val;
    ListNode* next;
    ListNode(char x) : val(x), next(nullptr) {}
};

// ������������½ڵ�
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

// ���ڵ��Ƿ������������
bool exists(ListNode* head, char value) {
    while (head != nullptr) {
        if (head->val == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// �����������ϵĽ���
ListNode* intersection(ListNode* headA, ListNode* headB) {
    ListNode* dummyHead = new ListNode(0); // ����һ���ƽڵ���Ϊ��������ͷ�ڵ�
    ListNode* tail = dummyHead;
    while (headA != nullptr) {
        if (exists(headB, headA->val)) {
            tail->next = new ListNode(headA->val);
            tail = tail->next;
        }
        headA = headA->next;
    }
    ListNode* result = dummyHead->next;
    delete dummyHead; // ɾ���ƽڵ�
    return result;
}

// ��ӡ����
void printList(ListNode* head) {
    while (head != nullptr && head->next != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val;
}

// ���������ڴ�
void clearList(ListNode*& head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// �����ַ�������
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

int main() {
    cout<<"��ӭʹ�ü��Ͻ����������"<<endl;
    int caseNum;
    cout << "����������ѡ���� (1 for �Զ��弯�� 2 for �򼯺���ӹ̶�Ԫ��): ";
    cin >> caseNum;
    cin.ignore(); // ���Ի��з�

    ListNode* headA = nullptr;
    ListNode* headB = nullptr;

    switch (caseNum) {
    case 1: {
        // �Զ��弯��
        char elementsA[100];
        char elementsB[100];
        cout << "�����뼯��A��Ԫ�أ��ÿո�ָ�: ";
        cin.getline(elementsA, 100);
        cout << "�����뼯��B��Ԫ�أ��ÿո�ָ�: ";
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
        // �򼯺�A���Ԫ��
        cout << "����A={c a e h},����B={f h b g d a} " << endl;
        appendNode(headA, 'c');
        appendNode(headA, 'a');
        appendNode(headA, 'e');
        appendNode(headA, 'h');

        // �򼯺�B���Ԫ��
        appendNode(headB, 'f');
        appendNode(headB, 'h');
        appendNode(headB, 'b');
        appendNode(headB, 'g');
        appendNode(headB, 'd');
        appendNode(headB, 'a');
        break;
    }
    default:
        cout << "��Ч��case��š�" << endl;
        return 1;
    }

    // ���㽻��
    ListNode* resultSet = intersection(headA, headB);

    // ��ӡ���
    cout << "A��B�Ľ���Ϊ: {";
    printList(resultSet);
    cout << "}"<<endl;

    // ���������ڴ�
    clearList(headA);
    clearList(headB);
    clearList(resultSet);
    system("pause");
    return 0;
}