//
//  main.cpp
//  assignment 3
//
//  Created by Daniel Berg on 19/11/25.
//

#include <iostream>
using namespace std;

template <class T>
T total(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(){
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.5, 2.5, 3.5};
    cout << "Total (int): " << total(intArray, 5) << endl;
    cout << "Total (double): " << total(doubleArray, 3) << endl;
    return 0;
}

