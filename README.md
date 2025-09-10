# 💻 Computer Networks Project   
This project was developed as part of an "Advanced Programming in C" academic course.  
The goal is to model a computer network and implement algorithms that allow a company to purchase the minimum set of communication lines such that all computers in the network remain connected, with minimal total cost.  

---

## ✅ Features
- Graph building from user input
- Minimum Spanning Tree (MST) using Prim's algorithm
- Path reconstruction from root to all nodes
- Path query between any two nodes using DFS
- Full memory cleanup on exit

---

## 🗂️ Project Structure

| File             | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| `base.h`         | Common definitions, constants, structs, and memory check                    |
| `build_net.c/.h` | Network construction and sorted edge insertion                              |
| `prim.c/.h`      | Implementation of Prim's MST algorithm                                      |
| `paths.c/.h`     | Builds PrimPaths (reconstructs path-tree from Prim parent array)            |
| `path_finding.c/.h` | DFS-based path finding on path-trees (used for queries)                  |
| `free.c/.h`      | Memory deallocation for all modules                                         |
| `main.c`         | Entry point: manages input/output and runs steps                            |

---

## ▶️ How It Works  

**Step 1: Network Building**  
- Reads number of computers and connections  
- Builds adjacency lists sorted by neighbor ID  

**Step 2: Prim's Algorithm**  
- Builds MST starting from node 0  
- Uses a candidate list as a priority queue  

**Step 3: Build Paths**  
- For each node, reconstructs path from root (node 0) using parent array  

**Step 4: Query Path**  
- Prompts user for two computers  
- Uses DFS on path trees to find and print the route  

---

## 📖 Sample Run

Enter number of computers: 5  
Enter number of connections: 6  
Connection: 0 1 3  
Connection: 0 2 5  
Connection: 1 2 1  
Connection: 1 3 4  
Connection: 2 3 2  
Connection: 3 4 6  

Enter source and destination: 0 4  
Path: 0 -> 1 -> 2 -> 3 -> 4  

---

## 👤 Author  
Project developed by Ori Adani as part of an academic course in advanced C programming.  

