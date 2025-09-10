#pragma once

#include "base.h"

void freeEdgeList(EdgeNode* head);
void freeAllEdgeLists(EdgeList* lists, int n);
void freeAll(EdgeList* Netlists, EdgeList* PrimPathlists, int* Prim, int n);

