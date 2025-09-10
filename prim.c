#include "prim.h"

int* build_prim_tree(EdgeList net[], int n)
{
    int i;
    int* prim = (int*)malloc(sizeof(int) * n);
    checkAllocation(prim);

    int* min = (int*)malloc(sizeof(int) * n);
    checkAllocation(min);

    unsigned char inT[(n + 7) / 8];
    CandidateList priority;
    priority.head = NULL;
    priority.tail = NULL;
    CandidateNode** location = (CandidateNode**)malloc(sizeof(CandidateNode*) * n);
    checkAllocation(location);

    //Initialization
    for (i = 0;i < n;i++)
    {
        prim[i] = -1;
        min[i] = INT_MAX;
        if (priority.head == NULL)
            priority.head = priority.tail = createCandidate(i, min[i]);
        else
        {
            priority.tail->next = createCandidate(i, min[i]);
            priority.tail->next->prev = priority.tail;
            priority.tail = priority.tail->next;
        }
        location[i] = priority.tail;
    }
    for (i = 0;i < (n + 7) / 8;i++)
        inT[i] = 0;
    //first computer
    min[0] = 0;
    location[0]->c.min = 0;

    EdgeNode* cur;
    CandidateNode* node_u = NULL;
    int u, v;
    while (priority.head != NULL)
    {
        node_u = deleteMin(&priority);
        u = node_u->c.computer;

        if (min[u] == INT_MAX)
        {
            printf("No spanning tree available.");
            exit(1);
        }
        addBit(inT, u);
        cur = net[u].head;
        while (cur != NULL)
        {
            v = cur->e.neighbor;

            if (!isInTree(inT, v) && cur->e.cost < min[v])
            {
                min[v] = cur->e.cost;
                prim[v] = u;
                decreaseKey(location[v], cur->e.cost);
            }
            cur = cur->next;
        }
        free(node_u);
    }
    free(location);
    free(min);
    return prim;
}

CandidateNode* createCandidate(int v, int min)
{
    CandidateNode* res = (CandidateNode*)malloc(sizeof(CandidateNode));
    checkAllocation(res);

    res->c.computer = v;
    res->c.min = min;
    res->prev = NULL;
    res->next = NULL;
    return res;
}

CandidateNode* deleteMin(CandidateList* priority)
{
    if (priority->head == NULL)
        return NULL;
    CandidateNode* cur = priority->head->next;
    CandidateNode* min = priority->head;

    while (cur != NULL)
    {
        if (cur->c.min < min->c.min)
        {
            min = cur;
        }
        cur = cur->next;
    }

    //Edge cases
    if (min == priority->tail && min == priority->head)
        priority->head = priority->tail = NULL;
    else if (min == priority->tail)
    {
        priority->tail = min->prev;
        priority->tail->next = NULL;
    }
    else if (min == priority->head)
    {
        priority->head = min->next;
        priority->head->prev = NULL;
    }

    else
    {
        min->prev->next = min->next;
        min->next->prev = min->prev;
    }
    return min;
}

void decreaseKey(CandidateNode* location, int newCost)
{
    location->c.min = newCost;
}

void addBit(unsigned char inT[], int u)
{
    inT[u / 8] |= (1 << (u % 8));
}

bool isInTree(unsigned char inT[], int u)
{
    return (inT[u / 8] >> (u % 8)) & 1;
}