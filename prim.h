#pragma once

#include "base.h"

typedef struct {
    int computer;
    int min;
} Candidate;

typedef struct candidate_node {
    Candidate c;
    struct candidate_node* next;
    struct candidate_node* prev;
} CandidateNode;

typedef struct {
    CandidateNode* head;
    CandidateNode* tail;
} CandidateList;

int* build_prim_tree(EdgeList net[], int n);
CandidateNode* createCandidate(int v, int min);
CandidateNode* deleteMin(CandidateList* priority);
void decreaseKey(CandidateNode* location, int newCost);
void addBit(unsigned char inT[], int u);
bool isInTree(unsigned char inT[], int u);

