//
//  main.cpp
//  laba_11_4
//
//  Created by Olga Manikaeva on 18/03/2025.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    int N;

    cout << "Number of elements: " << endl;
    cin >> N;

    if (N <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    // Виділення пам’яті
    int *p = new(nothrow) int[N]; // Використання nothrow, щоб уникнути винятку
    if (!p) {
        cout << "Could not allocate memory" << endl;
        return 1;
    }

    int *p_end = p + N; // Визначаємо кінець масиву

    // Заповнення масиву випадковими числами
    for (int *ptr = p; ptr < p_end; ptr++) {
        *ptr = rand() % 20 - rand() % 20;
    }

    // Виведення масиву
    cout << "Your array: " << endl;
    for (int *ptr = p; ptr < p_end; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    // Звільнення пам’яті
    delete[] p;

    return 0;
}
