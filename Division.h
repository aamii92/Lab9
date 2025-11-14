#ifndef DIVISION_H
#define DIVISION_H
#include <string>
using namespace std;
class Division{
    public:
    string divisionName;
    Division(string name){
        this->divisionName = name;
    }
    string getDivisionName(){
        return divisionName;
    }
    void setDivisionName(string name){
        this->divisionName = name;
    }
};
#endif