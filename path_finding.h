#pragma once

#include "base.h"

void find_and_print_path(EdgeList primpaths[], int n, int first, int last);
void FindPath(int first, int last, EdgeList primpaths[], int* Parent, int* Color);
void PrintPath(int last, int* parent, int first);

