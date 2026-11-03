#include "task.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
enum class OptionForMenu
{
    Exit = 0,
    AddTask = 1,
    PrintAllTask = 2
};

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    const char* FILE_NAME = "tasks.dat";
    const char* fileName = "taski.dat";
    OptionForMenu choice;

    do
    {
        cout << "\n1 - Добавить задачу\n2 - Показать задачи\n 0 - Выход\n";

        int input;
        cin >> input;
        cin.ignore(10000, '\n');
        choice = static_cast<OptionForMenu>(input);
        
        switch (choice) 
        {
        case OptionForMenu::AddTask:
            addTask(fileName);
            break; 
        case OptionForMenu::PrintAllTask:
            printAllTasks(fileName);
            break; 
        case OptionForMenu::Exit:
            break;  
        default:
            cout << "Нет такого пункта меню\n"; 
        }
    } while (choice != OptionForMenu::Exit);
    
    return 0;
}