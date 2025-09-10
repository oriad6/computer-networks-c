#pragma once

#include "base.h"

EdgeList* build_net(int n);
void insertionSort(EdgeList* lst, int a, int b, int price);
EdgeNode* createEdgeNode(int neighbor, int price);
