#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<vector>
#include <string>
#include "Person.h"
#include "Spouse.h"
#include "Child.h"
#include "Division.h"
#include "JobDescription.h"
using namespace std;
class Employee: public Person{
    Spouse *s; // 0..1    
    vector<Child> children; // 0..n or child **c;
    Division d; // 1
    vector<JobDescription*> jds; // 1..n
    public:
    string companyID;
    string title;
    int startDate;
    string getCompanyID(string companyID){
        return companyID;
    }
    string getTitle(){
        return title;
    }
    int getstartDate(){
        return startDate;
    }
    void setCompanyID(string companyID){
       this->companyID = companyID;

    }
    void setTitle(string title){
        this->title =  title;
    }
    void setstartDate(int startDate){
        this->startDate = startDate;
    }

};
#endif