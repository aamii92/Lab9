#include <iostream>
using namespace std;

template <typename T>
class MyList {
private:
    T* data;         // Элементийг хадгалах массив
    int capacity;    // Массивын багтаамж
    int size;        // Жагсаалтын хэмжээ

public:
    // Конструктор
    MyList() {
        capacity = 10;  // Эхлээд багтаамж 10 гэж тохируулна
        size = 0;
        data = new T[capacity];  // Массив үүсгэх
    }

    // Destructor
    ~MyList() {
        delete[] data;  // Массивыг устгах
    }

    // Жагсаалтын сүүлд элемент нэмэх
    void add(T t) {
        if (size == capacity) {
            // Хэрэв массив дүүрч байсан бол шинэ массив үүсгэнэ
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];  // Х旧 массивын өгөгдлийг шинэ массив руу хуулна
            }
            delete[] data;  // Х旧 массивыг устгана
            data = newData;  // Шинэ массив руу шилжүүлнэ
        }
        data[size] = t;  // Элементийг сүүлд нь оруулна
        ++size;  // Жагсаалтын хэмжээ 1-ээр нэмэгдэнэ
    }

    // Индекс дээр элементийг оруулах
    void insert(T t, int index) {
        if (index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }
        if (size == capacity) {
            // Массив дүүрч байсан тохиолдолд багтаамжийг нэмнэ
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < index; ++i) {
                newData[i] = data[i];  // Элементийг хуулна
            }
            newData[index] = t;  // Тухайн индекст оруулна
            for (int i = index; i < size; ++i) {
                newData[i + 1] = data[i];  // Үлдсэн элементийг шилжүүлнэ
            }
            delete[] data;
            data = newData;
        } else {
            for (int i = size; i > index; --i) {
                data[i] = data[i - 1];  // Элементийг шилжүүлнэ
            }
            data[index] = t;  // Индекст оруулна
        }
        ++size;
    }

    // Жагсаалтын уртыг авах
    int length() {
        return size;
    }

    // Жагсаалтын бүх элементийг хэвлэх
    void print() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyList<int> list; // int төрлийн жагсаалт үүсгэх

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
