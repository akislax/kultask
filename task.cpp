#include "task.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int getNextId(const char* filename)
{
    ifstream file(filename, ios::binary);
    int maxId = 0;

    Task t;
    //здесь конста нету так как мы копируем из файла и кладем их в t то есть t меняется
    while (file.read(reinterpret_cast<char*>(&t), sizeof(Task)))
    {
        if (t.id > maxId)
        {
            maxId = t.id;
        }
    }
    return maxId + 1;
}
//функция нужна для получения нормального ввода от пользователя
//название подсказки, типо Название,  адрес массива куда кладем, и размер массива
void readText(const char* prompt, char* buffer, int bufferSize)
{
    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (input.empty())
        {
            cout << "Поле не может быть пустым\n";
            continue; //возвращение в начало цикла
        }

        if ((int)input.size() >= bufferSize)
        {
            cout << "Слишком длинный текст\n";
            continue;
        }
        break;
    }
    strcpy(buffer, input.c_str()); //копирование из инпута в наш массива из структуры
}

void addTask(const char* filename) 
{
    Task t{};
        readText("Название: ", t.title, sizeof(t.title));
        readText("Категория: ", t.category, sizeof(t.category));
        cout << "Приоритет (1-3): ";
        cin >> t.priority;
        cout << "Дедлайн (дд мм гггг): ";
        cin >> t.day >> t.month >> t.year;
        cin.ignore(10000, '\n'); 
        t.id = getNextId(filename);
        t.done = false;
        
        ofstream file(filename, ios::binary | ios::app); //создаие файла и команда, что нужно записывать в конец байтами
        file.write(reinterpret_cast<const char*>(&t), sizeof(Task)); //сама запись в файл, принимает  reinterpret_cast как адрес байтов из за работы с write, а сайз оф это размер 124 байта.
//здесь конст стоит так как мы копируем значения и кладем их в файл
}

void printAllTasks(const char* filename) 
{
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Задач пока нет\n";
        return;
    }

    Task t;
    while (file.read(reinterpret_cast<char*>(&t), sizeof(Task))) 
    {
        cout << t.id << ". "<< t.title << " | " << t.category << " | приоритет " << t.priority << " | до " << t.day << "." << t.month << "." << t.year << "\n";
    }
    //а здесь конста нету так как мы перекладываем значения из файла в пустю коробку, которую создали в 32 строчке
}