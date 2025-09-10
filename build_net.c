#include "build_net.h"


EdgeList* build_net(int n)
{
    int m, a, b, price, i;
    EdgeList* Net;
    Net = (EdgeList*)malloc(sizeof(EdgeList) * n);
    checkAllocation(Net);

    for (i = 0;i < n;i++)
    {
        Net[i].head = NULL;
        Net[i].tail = NULL;
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &price);

        if (a >= n || b >= n || a < 0 || b < 0 || price < 0)
        {
            printf("Invalid input.");
            exit(1);
        }

        insertionSort(&Net[a], a, b, price);
        insertionSort(&Net[b], b, a, price);
    }
    return Net;
}

void insertionSort(EdgeList* lst, int a, int b, int price)
{
    EdgeNode* res = createEdgeNode(b, price);
    EdgeNode* cur = lst->head;
    EdgeNode* prev = NULL;
    if (cur == NULL)
    {
        lst->head = lst->tail = res;
        res->next = NULL;
        return;
    }
    if (b < cur->e.neighbor)
    {
        lst->head = res;
        res->next = cur;
        return;
    }
    while (cur != NULL && cur->e.neighbor < b)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = res;
    res->next = cur;
    if (cur == NULL)
        lst->tail = res;
}

EdgeNode* createEdgeNode(int neighbor, int price)
{
    EdgeNode* res = (EdgeNode*)malloc(sizeof(EdgeNode));
    checkAllocation(res);

    res->e.neighbor = neighbor;
    res->e.cost = price;
    res->next = NULL;
    return res;
}

void checkAllocation(void* ptr)
{
    if (ptr == NULL)
    {
        printf("Invalid input.\n");
        exit(-1);
    }
}