#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct
{
    int neighbor;
    int cost;
} Edge;

typedef struct edge_node {
    Edge e;
    struct edge_node* next;
} EdgeNode;

typedef struct {
    EdgeNode* head;
    EdgeNode* tail;
} EdgeList;

void checkAllocation(void* ptr);

