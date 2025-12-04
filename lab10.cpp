#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>   
#include<algorithm>
#include <random> 


using namespace std;

template <typename T>
class LinkedList {
private:
    //  жагсаалтын нэг элемент (Node), 2 гишүүн өгөгдөлтэй
    struct Node {
        T data;         
        Node* next;     // Дараагийн элементийг заах холбоос
    };

    Node* head;      
    int size;       

public:
    LinkedList() : head(nullptr), size(0) {}
    // Деструктор: Жагсаалтыг устгахдаа санах ойг суллана
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
    }

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
    T& get(int index) {
        if (index < 0 || index >= size)                 
        throw out_of_range("Index out of range");   

    // cur заагчийг эхний элемент рүү зааж index хүртэл давтаж гүйнэ
    Node* cur = head;                               
    for (int i = 0; i < index; i++)                 
        cur = cur->next;                            

    return cur->data;
    }
    void deleteNode(int index){
        if (index < 0 || index >= size)                 // Индекс буруу бол юу ч хийхгүй буцах
        return;

    if (index == 0) {                               // Хэрвээ эхний элементийг устгаж байвал
        Node* temp = head;                          // head-г temp-д хадгална
        head = head->next;                          // head-г дараагийн элемент рүү шилжүүлнэ
        delete temp;                                // хуучин эхний Node-ийг устгана
    } else {
        Node* cur = head;                           // cur заагч эхлэлд заана
        for (int i = 0; i < index - 1; i++)         // Устгах Node-оос өмнөх хүртэл давтах
            cur = cur->next;

        Node* temp = cur->next;                     // temp = устгах гэж буй Node
        cur->next = temp->next;                     // өмнөх Node дараагийн Node руу залгана
        delete temp;                                // устгаж байна
    }
    size--;            
    }
    // жагсаалтын уртыг буцаана
    int length(){
        return size;
    }
};

// Үндсэн класс (TwoDShape)
class TwoDShape {
protected:
    string name; 
public:
    TwoDShape(int index, const string& type) {
        // Объектын нэрийг индекс болон төрлөөр автоматаар үүсгэж өгнө.
        name = type + "_" + to_string(index);
    }
    
    virtual ~TwoDShape() = default;

    virtual double Area() const = 0;

    // Нэрийг буцаах функц
    string getName() const { return name; }
};
// --- Circle класс ---
class Circle : public TwoDShape {
private:
    double radius;
public:
    // Зөвхөн index болон radius-ийг авна
    Circle(int index, double r) : TwoDShape(index, "Circle"), radius(r) {}
    // virtual Area() функцийг override хийж байна.
    double Area() const override { return 3.14 * radius * radius; }
};
// --- Square класс ---
class Square : public TwoDShape {
private:
    double side;
public:
    // Зөвхөн index болон side-ийг авна
    Square(int index, double s) : TwoDShape(index, "Square"), side(s) {}
    double Area() const override { return side * side; }

};
// --- Triangle класс---
class Triangle : public TwoDShape {
    private:
    double side;
    public:
    Triangle(int index, double s) : TwoDShape(index, " Triangle"), side(s) {}
    double Area() const override { return (sqrt(3) / 4) * side * side ;}
};
int main(){
    srand(time(0));
    // n-ийг 20-30-ийн хооронд санамсаргүйгээр сонгох
    int n = (rand() % 11) + 20;

    // TwoDShape* заагчуудыг хадгална
    LinkedList<TwoDShape*> shapes;

    // талын уртыг санамсаргүйгээр оноож, элементүүдийг жагсаалтын төгсгөлд нэмж байна
    for(int i=0; i<n; i++){
        double rand_val = (double)(rand() % 50) + 1.0;
        if(i%3==0) {shapes.add(new Circle(i+1, rand_val)); }
        else if (i%3==1) { shapes.add(new Square(i+1, rand_val)); }
        else  { shapes.add(new Triangle(i+1, rand_val)); }

    }
    // объектуудыг талбайгаар нь эрэмбэлэх
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(shapes.get(i)->Area() > shapes.get(j)->Area()) {
                TwoDShape* temp= shapes.get(i);
                shapes.get(i) = shapes.get(j);
                shapes.get(j)= temp;
            }
        }
    }
    cout << "random тооний объект үүсгэж талбайгаар эрэмбэлэн хэвлэе" << endl;
    for( int i=0; i<n; i++){
        const TwoDShape* currentShape = shapes.get(i);
        cout<< "index ["<< i <<"], " << "name: "<< currentShape->getName() << ", area: " <<currentShape->Area()<<endl;
    }

    
}
