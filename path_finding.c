#include "path_finding.h"

void find_and_print_path(EdgeList primpaths[], int n, int first, int last)
{
    int* Parent = (int*)malloc(sizeof(int) * n);
    checkAllocation(Parent);

    int* Color = (int*)malloc(sizeof(int) * n);
    checkAllocation(Color);

    if (first < 0 || first >= n || last < 0 || last >= n)
    {
        printf("Invalid input.");
        exit(1);
    }

    // Initialize all nodes as unvisited and parentless.
    for (int i = 0; i < n; i++)
    {
        Parent[i] = -1;
        Color[i] = WHITE;
    }

    FindPath(first, last, primpaths, Parent, Color);
    if (Parent[last] == -1)
        printf("0"); // If the destination node has no parent, no path was found.
    else
        PrintPath(last, Parent, first);

    free(Parent);
    free(Color);
}

void FindPath(int first, int last, EdgeList primpaths[], int* Parent, int* Color)
{
    Color[first] = GRAY; // Mark current node as being visited

    EdgeNode* curr = primpaths[first].head;

    while (curr != NULL) // Iterate over neighbors of current node.
    {
        int v = curr->e.neighbor;
        if (Color[v] == WHITE)
        {
            Parent[v] = first; // If neighbor is unvisited, mark parent and continue DFS.
            if (v == last)
                return; // Found the target node – stop further recursion.
            else
                FindPath(v, last, primpaths, Parent, Color);
        }

        curr = curr->next;
    }


    Color[first] = BLACK; // Finished exploring all neighbors of this node.
}

void PrintPath(int last, int* parent, int first)
{
    if (last == first)
        printf("%d ", last);
    else
    {
        PrintPath(parent[last], parent, first);
        printf("%d ", last);
    }
}

