#include "paths.h"

// Builds an adjacency list (as EdgeList array) from the given Prim tree.
EdgeList* build_paths(int* tree, int n)
{
    EdgeList* PrimPaths;
    int i;

    PrimPaths = (EdgeList*)malloc(sizeof(EdgeList) * n);
    checkAllocation(PrimPaths);

    for (i = 0; i < n; i++)
    {
        PrimPaths[i] = build_list(i, tree, n);
    }

    return PrimPaths;
}

EdgeList build_list(int index, int* tree, int n)
{
    EdgeList neighbors_lst;
    int j;

    MakeEmptyList(&neighbors_lst);

    // if there's a parent, add him to the neighbors list
    if (tree[index] != -1)
        insertDataToSortedList(&neighbors_lst, tree[index], 0);

    // add all children of the current index
    for (j = 0; j < n; j++)
    {
        if (tree[j] == index)
            insertDataToSortedList(&neighbors_lst, j, 0);
    }

    return neighbors_lst;
}

void MakeEmptyList(EdgeList* lst)
{
    lst->head = lst->tail = NULL;
}

bool isEmptyList(EdgeList lst)
{
    return (lst.head == NULL);
}

void insertDataToSortedList(EdgeList* lst, int data, int price)
{
    EdgeNode* newNode;

    newNode = createEdgeNode(data, price);
    insertNodeToSortedList(lst, newNode);
}

void insertNodeToSortedList(EdgeList* lst, EdgeNode* newNode)
{
    int num = newNode->e.neighbor; // The neighbor value to compare and sort by.

    if (isEmptyList(*lst))
        lst->head = lst->tail = newNode;

    else if (num < lst->head->e.neighbor)
    {
        newNode->next = lst->head;
        lst->head = newNode;
    }

    else // Traverse the list to find the correct insertion point.
    {
        EdgeNode* curr = lst->head;

        while (curr->next != NULL && num > curr->next->e.neighbor)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;

        if (newNode->next == NULL)
            lst->tail = newNode;
    }
}