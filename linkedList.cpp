#include <iostream>
using namespace std;

// Template LinkedList Class
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;         // Элементийг хадгалах
        Node* next;     // Дараагийн элементийг заах холбоос
    };

    Node* head;      // Жагсаалтын эхний элемент
    int size;        // Жагсаалтын урт

public:
    LinkedList() : head(nullptr), size(0) {}

    // Элементийг сүүлд нь нэмэх
    void add(T t) {
        Node* newNode = new Node{t, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Индекс дээр элементийг оруулах
    void insert(T t, int index) {
        if (index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }
        Node* newNode = new Node{t, nullptr};
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    // Жагсаалтын уртыг авах
    int length() {
        return size;
    }

    // Бүх элементийг хэвлэх
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list; // int төрлийн жагсаалт үүсгэх

    // Элементийг нэмэх
    list.add(5);
    list.add(10);
    list.add(15);
    list.print();  // 5 10 15

    // Индекс дээр элементийг оруулах
    list.insert(20, 1);
    list.print();  // 5 20 10 15

    return 0;
}
