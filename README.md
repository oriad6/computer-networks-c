# Computer Networks Project
A modular C project developed as part of a first-year Computer Science course: Advanced Programming in C.
Implementation of computer network communication,  including construction of a Minimum Spanning Tree (MST) using Prim's algorithm,  network path building, and path search between computers using Depth-First Search (DFS).  The project demonstrates data structures, graph traversal,  and efficient network cost minimization.

✅ Features
⚖️ Graph building from user input
📊 Minimum Spanning Tree (MST) using Prim's algorithm
🧩 Path reconstruction from root to all nodes
⏩ Path query between any two nodes using DFS
♻️ Full memory cleanup on exit

📁 Project Structure
Each task is implemented in a separate module with .c and .h files:

File	Purpose
main.c	Main driver: runs all 4 tasks step-by-step
network.c/h	Task 1: Build graph from input
prim.c/h	Task 2: Calculate MST using Prim
paths.c/h	Task 3: Build paths from root
routing.c/h	Task 4: Find and print path between nodes
free.c/h	Frees all memory
base.h	Shared structs and typedefs
