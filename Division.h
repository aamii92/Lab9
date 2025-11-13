#ifndef DIVISION_H
#define DIVISION_H
#include <string>
using namespace std;
class Division{
    public:
    string name;
    Division(string name){
        this->name = name;
    }
    string getDivisionName(){
        return name;
    }
    void setDivisionName(string name){
        this->name = name;
    }
};
#endif