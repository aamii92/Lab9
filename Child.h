#ifndef CHILD_H
#define CHILD_H
#include <string>
#include "Person.h"
using namespace std;
class Child: public Person{
    public:
    string favToy;
    Child(string name, string ssnum, int age, string favToy)
        : Person(name, ssnum, age) {
        this->favToy = favToy;
    }
    string getfavToy(){
            return favToy;
        }
    void setfavToy(char * favToy){
         this->favToy = favToy;
        }


};
#endif