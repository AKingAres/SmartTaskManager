#ifndef TASK_H
#define TASK_H

struct Task {
    int id;
    char title[100];
    char desc[256];
    int priority;
    int estTime;
    int completed;
};

extern struct Task tasks[100];
extern int count;
extern int productivityScore;

void chomp(char *s);
void addTask();
void viewTasks();
void completeTask();
void showStats();

#endif
