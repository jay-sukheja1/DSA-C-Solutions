#include<iostream>
using namespace std;
    class Teacher {
    private:
        double salary;

    public:
        Teacher() {
            cout<<"I am constructor"<<endl;
            dept="Computer science";
        }
        string name;
        string dept;
        string subject;


        void changedept(string newdept) {
            dept=newdept;
            cout<<"Change Dept: "<<dept<<endl;
        }

        //setter
        double setsalary(double s) {
            salary=s;
        }

        //getter
        double getsalary() {
            return salary;
        }
    };

int main(){
    Teacher t1;
    t1.name="yash";
    t1.subject="maths";
    // t1.salary=1500.0;  not accessible
    t1.setsalary(1500.0);
    cout<<t1.getsalary()<<endl;
    cout<<t1.name<<" "<<t1.dept<<" "<<t1.subject<<endl;
    t1.changedept("commerce");
    return 0;
}