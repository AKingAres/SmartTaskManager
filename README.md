# SmartTaskManager
The Smart Task Manager Using C is a menu-driven, command-line application for users to organize and manage their tasks effectively. In contrast to a simple, static list of tasks, this system integrates basic yet intelligent features: priority decay and productivity scoring. It makes the task-handling experience more dynamic and realistic.
It allows the user to create a task with a title, description, priority level, and estimated time of completion. The program stores these tasks in memory and displays all active tasks at any given time the user requests. Each time tasks are displayed to the user, this system automatically implements priority decay, a process where pending tasks gradually lose their priority. This simulates real-world consequences for delaying important work and will encourage users to take timely action.
The system also includes a task completion feature. When a task is marked as completed, its priority and estimated time contribute to a productivity score, giving users a simple measure of their overall efficiency. It also maintains statistics like the total number of tasks, total completed tasks, pending tasks, and total productivity score at any moment.
The project encompasses all the main concepts of C programming, including structures, arrays, conditional logic, loops, user input handling, and modular design, implemented in an easy-to-understand and user-friendly way. It is intentionally designed without file storage to keep the implementation simple and logic-focused, but structured in such a way that any future enhancements can easily be integrated.
Overall, this is a practical example that shows how C can be used to build interactive applications while reinforcing fundamentals.

How to Use
1. Add Task → Enter title, description, priority, and estimated time
2. View Tasks → Shows all tasks and applies automatic priority decay
3. Complete Task → Enter ID to mark a task as completed and update score
4. Show Stats → View total tasks and productivity score
5. Exit → Quit the program
