#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person{
    public:
    string name, ssnum;
    int age;
   
   Person(string name, string ssnum, int age){
        this->name = name;
        this->ssnum = ssnum;
        this->age = age;
    }
    string getName() const {
        return name;
    }
    string getSSnum() const {
        return ssnum;
    }
    int getAge() const {
        return age;
    }
    void setName(string name){
        this->name = name;
    }
    void setSSnum(string ssnum){
        this->ssnum = ssnum;
    }
    void setAge(int age){
        this->age = age;
    }

};
#endif