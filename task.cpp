#include "task.h"
#include <fstream>
#include <iostream>
using namespace std;

void addTask(const char* filename) {
    Task t{};
        cout << "Название: ";
        cin.getline(t.title, sizeof(t.title));
        cout << "Категория: ";
        cin.getline(t.category, sizeof(t.category));
        cout << "Приоритет (1-3): ";
        cin >> t.priority;
        cout << "Дедлайн (дд мм гггг): ";
        cin >> t.day >> t.month >> t.year;
        cin.ignore(10000, '\n'); 
        
        t.done = false;
        
        ofstream file(filename, ios::binary | ios::app); //создаие файла и команда, что нужно записывать в конец байтами
        file.write(reinterpret_cast<const char*>(&t), sizeof(Task)); //сама запись в файл, принимает  reinterpret_cast как адрес байтов из за работы с write, а сайз оф это размер 124 байта.
//здесь конст стоит так как мы копируем значения и кладем их в файл
}

void printAllTasks(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Задач пока нет\n";
        return;
    }

    Task t;
    while (file.read(reinterpret_cast<char*>(&t), sizeof(Task))) 
    {
        cout << t.title << " | " << t.category << " | приоритет " << t.priority << " | до " << t.day << "." << t.month << "." << t.year << "\n";
    }
    //а здесь конста нету так как мы перекладываем значения из файла в пустю коробку, которую создали в 32 строчке
}