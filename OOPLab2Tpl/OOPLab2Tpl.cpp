// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"


/// @brief 
/// @return 
int main()
{
    cout << "OOP. Laboratory work #2.\n";

    int task = 0;
    MenuTask();

    cout << "Choose task:" << endl;
    cin >> task;

    if (task == 1)
        task1();
    if (task == 2)
        task2();
    if (task == 3)
        task3();
    if (task == 4)
        cout << "Exited!";

    return 0;
}

