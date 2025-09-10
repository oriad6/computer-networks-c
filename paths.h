#pragma once

#include "base.h"

void insertNodeToSortedList(EdgeList* lst, EdgeNode* newNode);
void insertDataToSortedList(EdgeList* lst, int data, int price);
bool isEmptyList(EdgeList lst);
void MakeEmptyList(EdgeList* lst);
EdgeList build_list(int index, int* tree, int n);
EdgeList* build_paths(int* tree, int n);
EdgeNode* createEdgeNode(int neighbor, int price);

