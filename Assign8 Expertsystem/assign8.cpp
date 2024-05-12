#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    string id;
    string name;
    string department;
    string position;
    int communication;
    int teamwork;
    int quality;
    int punctuality;
    string performance;

public:
    Employee(string id, string name, string department, string position, int communication, int teamwork, int quality, int punctuality)
    {
        this->id = id;
        this->name = name;
        this->department = department;
        this->position = position;
        this->communication = communication;
        this->teamwork = teamwork;
        this->quality = quality;
        this->punctuality = punctuality;
        this->performance = EvaluatePerformance();
    }

    string EvaluatePerformance()
    {
        double rating = (communication + teamwork + quality + punctuality) / 4;
        if (rating >= 4.5)
        {
            return "Excellent";
        }
        else if (rating >= 3.5)
        {
            return "Good";
        }
        else if (rating >= 2.5)
        {
            return "Average";
        }
        else
        {
            return "bad";
        }
    }

    string getID()
    {
        return id;
    }

    void update(int comm, int team, int qua, int punc)
    {
        communication = comm;
        teamwork = team;
        quality = qua;
        punctuality = punc;
        performance = EvaluatePerformance();
    }

    void display()
    {
        cout << "----------------------------------------------------" << endl;
        cout << "EmpID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << " Department : " << department << endl;
        cout << "Position : " << position << endl;
        cout << "Performance" << performance << endl;
        cout << "----------------------------------------------------" << endl;
    }
};

vector<Employee> employees;

void addEmp()
{
    string empid, name, department, position;
    int quality, communication, teamwork, punctuality;

    cout << "Enter the empid : " << endl;
    cin >> empid;
    cout << "Enter the Name : " << endl;
    cin >> name;
    cout << "Enter the department : " << endl;
    cin >> department;
    cout << "Enter the position : " << endl;
    cin >> position;
    cout << "Enter the communication rating(1-5) : " << endl;
    cin >> communication;
    cout << "Enter the quality rating(1-5) : " << endl;
    cin >> quality;
    cout << "Enter the teamwork rating(1-5) : " << endl;
    cin >> teamwork;
    cout << "Enter the punctuality rating(1-5) : " << endl;
    cin >> punctuality;

    Employee emp(empid, name, department, position, communication, quality, teamwork, punctuality);
    employees.push_back(emp);

    cout << "EMPLOYEE ADDED SUCCESSFULLY !!" << endl;
}

void view()
{
    cout << "-----------------------------------EMPLOYEE DATA---------------------------------------" << endl;
    for (Employee emp : employees)
    {
        emp.display();
    }

    cout << endl;
}

void delete_emp()
{
    cout << "Enter the empID of the employee you want to delete : " << endl;
    string empid;
    cin >> empid;

    for (auto it = employees.begin(); it != employees.end(); it++)
    {
        if (it->getID() == empid)
        {
            employees.erase(it);
            return;
        }
    }

    cout << "Employee with EMPID = " << empid << " deleted !!" << endl;
}

void update()
{
    cout << "Enter the Employee id of the employee you want to update";
    string empid;
    cin >> empid;
    int communication, quality, teamwork, punctuality;
    cout << "Enter the new communication rating(1-5) : " << endl;
    cin >> communication;
    cout << "Enter the new quality rating(1-5) : " << endl;
    cin >> quality;
    cout << "Enter the new teamwork rating(1-5) : " << endl;
    cin >> teamwork;
    cout << "Enter the new punctuality rating(1-5) : " << endl;
    cin >> punctuality;

    for (Employee &emp : employees)
    {
        if (emp.getID() == empid)
        {
            emp.update(communication, teamwork, quality, punctuality);
            cout << "Employee Performance Updated !!" << endl;
        }
    }
}

void search()
{
    cout << "Enter Employee ID of the employee you want to search : " << endl;
    string empid;
    cin >> empid;

    for (Employee emp : employees)
    {
        if (emp.getID() == empid)
        {
            cout << "EMPLOYEE FOUND !!" << endl;
            emp.display();
            return;
        }
        else
        {
            cout << "EMPLOYEE NOT FOUND !!" << endl;
        }
    }
}
int main()
{
    char choice;

    do
    {

        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "WELCOME TO THE EMPLOYEE EVALUATION SYSTEM !!" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "1.ADD EMPLOYEE " << endl;
        cout << "2.SEARCH EMPLOYEE" << endl;
        cout << "3.VIEW EMPLOYEE" << endl;
        cout << "4.UPDATE EMPLOYEE" << endl;
        cout << "5.DELETE EMPLOYEE" << endl;
        cin >> choice;

        switch (choice)
        {
        case '1':
            addEmp();
            break;
        case '2':
            search();
            break;
        case '3':
            view();
            break;
        case '4':
            update();
            break;
        case '5':
            delete_emp();
            break;

        default:
            cout << "INVALID CHOICE !! Enter Correct Choice !!" << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}