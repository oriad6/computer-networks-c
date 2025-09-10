#include "free.h"

void freeEdgeList(EdgeNode* head)
{
    EdgeNode* curr;
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        free(curr);
    }
}

void freeAllEdgeLists(EdgeList* lists, int n)
{
    for (int i = 0; i < n; i++)
        freeEdgeList(lists[i].head);

    free(lists);
}

void freeAll(EdgeList* Netlists, EdgeList* PrimPathlists, int* Prim, int n)
{
    freeAllEdgeLists(Netlists, n);
    freeAllEdgeLists(PrimPathlists, n);
    free(Prim);
}