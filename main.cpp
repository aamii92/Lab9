#include<iostream>
#include "Employee.h"
#include<string>
using namespace std;
int main(){
    Division techDivision("techDivision");
    Division hrDivision("hrDivision");
    Division financeDivision("financeDivision");
    JobDescription Ceo(Ceo);
    JobDescription manager(manager);
    JobDescription assistant(assistant);
    Employee emp1("John", "SSN123", 40, "E1001", "HR", "2020-05-10", hrDivision);
    Employee emp2("Anny", "SSN124", 30, "E1002", "Te", "2021-04-10", techDivision);
    Employee emp3("Katy", "SSN125", 34, "E1003", "Fin", "2023-11-09", financeDivision);
    emp1.add_job_description(&manager);
    emp2.add_job_description(&Ceo);
    emp1.add_job_description(&assistant);
    Child child_a("Olivia", "C1001", 5, "Teddy Bear");
    Child child_b("Noah", "C1002", 8, "Lego Set");
    Child child_c("Emma", "C1003", 12, "Gaming Console");
    Spouse spouse_a("Elizabeth", "S5001", 38, "2010-06-15");
    Spouse spouse_b("David", "S5002", 45, "2005-11-01");
    Spouse spouse_c("janny", "S5003", 32, "2018-06-15");
    emp1.add_child(child_a);
    emp1.add_child(child_b);
    emp3.add_child(child_c);
    emp1.set_spouse(&spouse_a);
    emp2.set_spouse(&spouse_b);
    emp3.set_spouse(&spouse_c);
    
}
