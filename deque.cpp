#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class Deque {
public:
    Node *front;
    Node *rear;
    int sz;

    Deque() {
        front = NULL;
        rear = NULL;
        sz = 0;
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) { // пустой дек
            front = rear = node;
        } else {
            node->next = front;
            front->prev = node;
            front = node;
        }
        sz++;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (rear == NULL) { // пустой дек
            front = rear = node;
        } else {
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
        sz++;
    }

    void pop_front() {
        if (front == NULL) return; // пусто
        Node *tmp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL; // опустело
        }
        delete tmp;
        sz--;
    }

    void pop_back() {
        if (rear == NULL) return; // пусто
        Node *tmp = rear;
        rear = rear->prev;
        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL; // опустело
        }
        delete tmp;
        sz--;
    }

    int get_front() {
        if (front == NULL) {
            cout << "Deque is empty\n";
            return -1;
        }
        return front->data;
    }

    int get_back() {
        if (rear == NULL) {
            cout << "Deque is empty\n";
            return -1;
        }
        return rear->data;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return (sz == 0);
    }
};

// --- пример использования ---
int main() {
    Deque dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);

    cout << "Front: " << dq.get_front() << "\n"; // 5
    cout << "Back: "  << dq.get_back()  << "\n"; // 20
    cout << "Size: "  << dq.size()      << "\n"; // 3

    dq.pop_front(); // удаляем 5
    cout << "After pop_front, new Front: " << dq.get_front() << "\n"; // 10

    dq.pop_back();  // удаляем 20
    cout << "After pop_back, new Back: " << dq.get_back() << "\n";   // 10

    return 0;
}
