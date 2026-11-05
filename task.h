#pragma once

struct Task
{
    int id;
    int ownerId;
    char title[64];
    char category[32];
    int priority;
    int day,month,year;
    bool done;
};

int getNextId(const char* filename);
void readText(const char* nametask, char* buffer, int buffersize);
void addTask(const char* filename);
void printAllTasks(const char* filename);