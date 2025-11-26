//
//  Q2.cpp
//  assignment 3
//
//  Created by Daniel Berg on 19/11/25.
//

#include <iostream>
using namespace std;

class Date{
private:
    int month, day, year;
public:
    Date();
    Date(int, int, int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void input(); //ask for month first
    void output1(); // 12/25/2014
    void output2(); //December 25, 2014
    void output3(); //25 December 2014
    //member function
    void increment();
    void decrement(); //show the previous day
};

Date::Date(){
    month = 1;
    day = 1;
    year = 2000;
};

Date::Date(int a, int b, int c){
    month = a;
    day = b;
    year = c;
};

int Date::getDay() const{
    return day;
};

int Date::getMonth() const{
    return month;
};

int Date::getYear() const{
    return year;
};

void Date::setDay(int x){
    day = x;
};

void Date::setMonth(int x){
    month = x;
};

void Date::setYear(int x){
    year = x;
};

void Date::input(){
    int daysOfMonth;
    cout << "=====" << endl;
    do{
        cout << "Month: ";
        cin >> month;
    } while(month < 1 || month > 12);
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        daysOfMonth = 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        daysOfMonth = 30;
    } else daysOfMonth = 28;
    
    do{
        cout << "Day: ";
        cin >> day;
    } while(day < 1 || day > daysOfMonth);
    
    cout << "Year: ";
    cin >> year;
    cout << "=====" << endl;
};

void Date::output1(){ //12/25/2014
    cout << month << "/" << day << "/" << year << endl;
};

void Date::output2(){ //December 25, 2014
    string tempMonth;
    
    if (month == 1){
        tempMonth = "January";
    } else if (month == 2){
        tempMonth = "February";
    } else if (month == 3){
        tempMonth = "March";
    } else if (month == 4){
        tempMonth = "April";
    } else if (month == 5){
        tempMonth = "May";
    } else if (month == 6){
        tempMonth = "June";
    } else if (month == 7){
        tempMonth = "July";
    } else if (month == 8){
        tempMonth = "August";
    } else if (month == 9){
        tempMonth = "September";
    } else if (month == 10){
        tempMonth = "October";
    } else if (month == 11){
        tempMonth = "November";
    } else if (month == 12){
        tempMonth = "December";
    }
    
    cout << tempMonth << " " << day << ", " << year << endl;
};

void Date::output3(){ //25 December 2014
    string tempMonth;
    
    if (month == 1){
        tempMonth = "January";
    } else if (month == 2){
        tempMonth = "February";
    } else if (month == 3){
        tempMonth = "March";
    } else if (month == 4){
        tempMonth = "April";
    } else if (month == 5){
        tempMonth = "May";
    } else if (month == 6){
        tempMonth = "June";
    } else if (month == 7){
        tempMonth = "July";
    } else if (month == 8){
        tempMonth = "August";
    } else if (month == 9){
        tempMonth = "September";
    } else if (month == 10){
        tempMonth = "October";
    } else if (month == 11){
        tempMonth = "November";
    } else if (month == 12){
        tempMonth = "December";
    }
    
    cout << day << " " << tempMonth << " " << year << endl;
};

void Date::increment(){
    int daysOfMonth;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        daysOfMonth = 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        daysOfMonth = 30;
    } else daysOfMonth = 28;
    
    if(day == daysOfMonth && month != 12){ //last day of the month
        day = 1;
        month++;
    } else if(day == 31 && month == 12){
        day = 1;
        month = 1;
        year++;
    } else {
        day++;
    }
};

void Date::decrement(){
    int daysOfMonth;
    if(day == 1 && month != 1){ //last day of the month
        month--;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            daysOfMonth = 31;
        } else if (month == 4 || month == 6 || month == 9 || month == 11){
            daysOfMonth = 30;
        } else daysOfMonth = 28;
        day = daysOfMonth;
    } else if(day == 1 && month == 1){
        day = 31;
        month = 12;
        year--;
    } else {
        day--;
    }
};

int main(){
    Date a;
    
    a.input();
    cout << "----Outputs before changes----" << endl;
    a.output1();
    a.output2();
    a.output3();

    a.decrement();
    cout << "----After decrement----" << endl;;
    a.output1();
    a.output2();
    a.output3();
    
    a.increment();
    cout << "----After increment----" << endl;;
    a.output1();
    a.output2();
    a.output3();
}
