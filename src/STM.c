#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Task {
    int id;
    char title[100];
    char desc[256];
    int priority;
    int estTime;
    int completed;
};

struct Task tasks[100];
int count = 0;
int productivityScore = 0;

void chomp(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

void addTask() {
    char line[256];
    struct Task t;
    t.id = count + 1;

    printf("Enter title: ");
    fgets(t.title, sizeof(t.title), stdin);
    chomp(t.title);

    printf("Enter description: ");
    fgets(t.desc, sizeof(t.desc), stdin);
    chomp(t.desc);

    printf("Enter priority (1-10): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &t.priority);
    if (t.priority < 1) t.priority = 1;
    if (t.priority > 10) t.priority = 10;

    printf("Estimated Time (minutes): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &t.estTime);
    if (t.estTime < 0) t.estTime = 0;

    t.completed = 0;

    if (count < 100) {
        tasks[count++] = t;
        printf("Task added successfully!\n");
    } else {
        printf("Task list full.\n");
    }
}

void viewTasks() {
    for (int i = 0; i < count; i++) {
        if (!tasks[i].completed && tasks[i].priority > 1)
            tasks[i].priority--;
    }

    printf("\nID | Title | Priority | Status\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d | %s | %d | %s\n",
               tasks[i].id,
               tasks[i].title,
               tasks[i].priority,
               tasks[i].completed ? "Completed" : "Pending");
    }
}

void completeTask() {
    char line[256];
    int id;

    printf("Enter Task ID to mark complete: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &id);

    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id && tasks[i].completed == 0) {
            tasks[i].completed = 1;
            productivityScore += tasks[i].priority * tasks[i].estTime;
            printf("Task marked complete!\n");
            return;
        }
    }

    printf("Task not found or already completed.\n");
}

void showStats() {
    int done = 0, pending = 0;
    for (int i = 0; i < count; i++) {
        if (tasks[i].completed) done++;
        else pending++;
    }
    printf("\nTotal Tasks: %d\n", count);
    printf("Pending: %d, Completed: %d\n", pending, done);
    printf("Productivity Score: %d\n", productivityScore);
}

int main() {
    char line[256];
    int choice = 0;

    while (1) {
        printf("\n=== SMART TASK MANAGER ===\n");
        printf("1. Add Task\n");
        printf("2. View Tasks (Priority Decay)\n");
        printf("3. Complete Task\n");
        printf("4. Show Productivity Stats\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: completeTask(); break;
            case 4: showStats(); break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
