#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Queue {
public:
    Node *front;
    Node *rear;
    int sz;

    Queue() {
        front = NULL;
        rear = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        if (rear == NULL) {       // если очередь пустая
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        sz++;
    }

    void pop() {
        if (front == NULL) return; // пустая очередь
        Node *tmp = front;
        front = front->next;
        if (front == NULL) rear = NULL; // если опустела
        delete tmp;
        sz--;
    }

    int peek() { // возвращает первый элемент
        if (front == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
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
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << "\n"; // 10
    cout << "Size: " << q.size() << "\n";  // 3

    q.pop();
    cout << "After pop, new Front: " << q.peek() << "\n"; // 20
    cout << "Size: " << q.size() << "\n";  // 2

    return 0;
}
