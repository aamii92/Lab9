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
    string startDate;
    Employee(string name, string ssnum, int age, string companyID, string title, string startDate, Division div)
            :Person(name, ssnum, age), d(div),s(nullptr){
                this->companyID = companyID;
                this->title = title;
                this-> startDate = startDate;
                this->d = div;
            }
    void add_child(const Child& new_child) {
        children.push_back(new_child);
    }
    void add_job_description(JobDescription* job_ptr) {
        if (job_ptr != nullptr) {
            jds.push_back(job_ptr);
        }
    }
    void set_spouse(Spouse *spouse_ptr) {
    // Гаднаас ирсэн Spouse-ийн хаягийг s-д онооно.
    // Энэ нь 0..1 харилцааг (нэгээс илүү Spouse байхгүйг) баталгаажуулна.
        this->s = spouse_ptr; 
    }
    void print_data(){
        
    }

    string getCompanyID(string companyID){
        return companyID;
    }
    string getTitle(){
        return title;
    }
    string getstartDate(){
        return startDate;
    }
    void setCompanyID(string companyID){
       this->companyID = companyID;

    }
    void setTitle(string title){
        this->title =  title;
    }
    void setstartDate(string startDate){
        this->startDate = startDate;
    }

};
#endif