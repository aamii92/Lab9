#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>   
#include<algorithm>
#include <random> // Random тоо үүсгэхэд илүү найдвартай
 // std::min, std::swap

using namespace std;




// Үндсэн класс (TwoDShape)
class TwoDShape {
protected:
    string name; // Нэрийг private/protected болгож автоматаар онооно
public:
    TwoDShape(int index, const string& type) {
        // Объектын нэрийг индекс болон төрлөөр автоматаар үүсгэх
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
class Triangle : public TwoDShape {
    private:
    double side;
    public:
    Triangle(int index, double s) : TwoDShape(index, " Triangle"), side(s) {}
    double Area() const override { return (sqrt(3) / 4) * side * side ;}
};
int main(){
    srand(time(0));
    Mylist<TwoDShape*> shapes;
    int n = shapes.getCapacity();
    const double MAX_RADIUS = 50.0;
    for(int i=0; i<n; i++){
        double rand_val = (double)(rand() % 50) + 1.0;
        if(i%3==0) {shapes.add(new Circle(i+1, rand_val)); }
        else if (i%3==1) { shapes.add(new Square(i+1, rand_val)); }
        else  { shapes.add(new Triangle(i+1, rand_val)); }

    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(shapes.get(i)->Area() > shapes.get(j)->Area()) {
                TwoDShape* temp= shapes.get(i);
                shapes.get(i) = shapes.get(j);
                shapes.get(j)= temp;
            }
        }
    }
    cout<<"random тооний объект үүсгэж талбайгаар эрэмбэлэн хэвлэе";
    for(int i=0; i<n; i++){
        const TwoDShape* currentShape = shapes.get(i);
        cout<< "index ["<< i <<"]" << "name: "<< currentShape->getName() << "area: " <<currentShape->Area()<<endl;
    }

    
}
