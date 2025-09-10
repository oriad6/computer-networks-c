# Computer Networks Project 

## 📌 Project Overview  
This project was developed as part of an Advanced Programming in C academic course.  
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
Each step is implemented in a separate module with .c and .h files:
├── base.h # Common definitions, constants, structs, and memory check
├── build_net.c/h # Network construction and edge insertion
├── path_finding.c/h # DFS-based path finding on Prim’s tree
├── paths.c/.h # Builds PrimPaths (reconstructs path-tree from Prim parent array)
├── prim.c/h # Implementation of Prim's MST algorithm
├── free.c/h # Memory deallocation for all modules
├── main.c # Entry point: manages input/output and runs steps

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

## 📖 Example Input / Output  

**Input format**  
n # number of computers
m # number of edges
a b cost # m lines describing edges
first last # two computers to find path between

**Example:**  
5
6
0 1 10
0 2 5
1 2 2
1 3 8
2 4 7
3 4 3
0 4

**Output:**  
0 2 4

(Meaning: the path from node 0 to 4 is 0 → 2 → 4)

---

## 👤 Author  
Project developed by Ori Adani as part of an academic course in advanced C programming.  

