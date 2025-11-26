//
//  Q3.cpp
//  assignment 3
//
//  Created by Daniel Berg on 24/11/25.
//

#include <iostream>
using namespace std;

class Passenger {
private:
    string name;
    double fare;
    int points;
public:
    Passenger();
    Passenger(string, double, int);
    string getName() const;
    double getFare() const;
    int getPoints() const;
    void setName(string);
    void setFare(double);
    void setPoints(int);
    void input();
    void output();
};

Passenger::Passenger(){
    name = "";
    fare = 0.0;
    points = 0;
}

Passenger::Passenger(string a, double b, int c){
    name = a;
    fare = b;
    points = c;
};

string Passenger::getName() const{
    return name;
};

double Passenger::getFare() const{
    return fare;
};

int Passenger::getPoints() const{
    return points;
};

void Passenger::setName(string x){
    name = x;
};

void Passenger::setFare(double x){
    fare = x;
};

void Passenger::setPoints(int x){
    points = x;
};

void Passenger::input(){
    cout << "Passenger's name: ";
    cin >> name;
    cout << "Fare: ";
    cin >> fare;
    cout << "Points: ";
    cin >> points;
};

void Passenger::output(){
    cout << "Name: " << name << endl;
    cout << "Fare: " << fare << endl;
    cout << "Points: " << points << endl;
};

class Flight {
private:
    string flightNumber;
    Passenger *passengers;
    int size;
    int capacity;
public:
    Flight();
    Flight(string);
    string getFlightNumber() const;
    void setFlightNumber(string);
    void insert(const Passenger&);
    void display() const;
    void leave();
};

Flight::Flight(){
    flightNumber = "AA1290";
    capacity = 10;
    size = 0;
    passengers = new Passenger[capacity];
}

Flight::Flight(string x){
    flightNumber = x;
    capacity = 10;
    size = 0;
    passengers = new Passenger[capacity];
};

string Flight::getFlightNumber() const{
    return flightNumber;
};

void Flight::setFlightNumber(string a){
    flightNumber = a;
};

void Flight::insert(const Passenger& p) {

    if (size == capacity) {
        capacity *= 2;
        Passenger* newArray = new Passenger[capacity];

        for (int i = 0; i < size; i++) {
            newArray[i] = passengers[i];
        }

        delete[] passengers;
        passengers = newArray;
    }

    passengers[size] = p;
    size++;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            double priorityA = passengers[j].getFare() * 0.5 + passengers[j].getPoints() * 0.5;
            double priorityB = passengers[j + 1].getFare() * 0.5 + passengers[j + 1].getPoints() * 0.5;

            if (priorityA > priorityB) {
                Passenger temp = passengers[j];
                passengers[j] = passengers[j + 1];
                passengers[j + 1] = temp;
            }
        }
    }
}

void Flight::display() const{
    cout << "Queue is :" << endl;
    cout << "Fare     Points     Name" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < size; i++) {
//        cout << passengers[i].getFare() << "     " << passengers[i].getPoints() << "     " << passengers[i].getName() << endl;
        cout << passengers[i].getFare() << "     " << passengers[i].getPoints() << "     " << passengers[i].getName() << "     " << (passengers[i].getFare() * 0.5 + passengers[i].getPoints() * 0.5) << endl;
    }
};

void Flight::leave(){
    if(size == 0){
        cout << "No passengers in this flight";
        return;
    }
    
    cout << "\nCustomer who leaves is: " << passengers[0].getName() << endl;
    for(int i = 0; i < size-1; i++){
        passengers[i] = passengers[i+1];
    }
    size--;
};

int main(){
    Flight aa;
    Passenger a("Terry", 490.28, 220), b("John", 480.12, 245), c("Alex", 698.95, 100), d("Susan", 577.21, 311), e("Brian", 590.08, 414); //name,fare,points
    aa.insert(a);
    aa.insert(b);
    aa.insert(c);
    aa.insert(d);
    aa.insert(e);
    aa.display();
    aa.leave();
    aa.display();
    aa.leave();
    aa.display();
}
