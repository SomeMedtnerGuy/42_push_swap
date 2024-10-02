# push_swap
A program which takes n integers on a stack as input and sorts them efficiently given a specific moveset.
### Rules
The program starts with two stacks:
- stack a contains the integers to be sorted.
- stack b is empty.
The allowed moveset is:
- **pa**: pushes the top number of b to a;
- **pb**: pushes the top number of a to b;
- **sa**: swaps the top numbers in a;
- **sb**: swaps the top numbers in b;
- **ss**: **sa** and **sb** combined;
- **ra**: shift up all numbers in a;
- **rb**: shift up all numbers in b;
- **rr**: **ra** and **rb** combined;
- **rra**: shift down all numbers in a;
- **rrb**: shift down all numbers in b;
- **rrr**: **rra** and **rrb** combined;
### The Program
This program sorts the stack with the lowest number of moves it can. It uses the Turk algorithm, an algorithm developed
especially for this project by a 42 student (A. Yigit Ogun - you can read the description I read to develop my implementation 
[here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)). It then prints the moves it found to be the most efficient.
