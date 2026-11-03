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

void addTask(const char* filename);
void printAllTasks(const char* filename);