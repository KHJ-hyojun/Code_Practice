#include <iostream>

using namespace std;

// 💡 1. 데이터와 다음 주소를 품은 노드 설계도
struct Node {
    int data;
    Node* next;
    
    // 생성자: 방을 처음 만들 때 데이터는 넣고, 다음 주소는 '없음(nullptr)'으로 초기화
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// 💡 2. 기차 전체를 통제하는 관리자
class LinkedList {
private:
    Node* head; // 기차의 맨 앞칸 주소
    Node* tail; // 기차의 맨 뒷칸 주소

public:
    // 처음 생성될 때는 기차가 텅 비어있음
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // 맨 뒤에 새로운 칸을 추가하는 엔진
    void push_back(int val) {
        // 여기에 로직을 구축해야 합니다!
        Node *New_Node = new Node(val);
        if (head == nullptr)
        {
            head = New_Node;
            tail = New_Node;
        }
        else
        {
            tail->next = New_Node;

            tail = New_Node;
        }
    }

    void print() {
        Node* curr = head;

        while (curr != nullptr) 
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void pop_front() {

        if (head == nullptr) return;

        Node* temp = head;

        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }

    void pop_back() {

        if (head == nullptr) 
            return;
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *curr = head;

            while (curr->next->next != nullptr)
            {
                curr = curr->next;
            }
        
            delete tail;
                tail = curr;
                tail->next = nullptr;
            
        }



    }
};