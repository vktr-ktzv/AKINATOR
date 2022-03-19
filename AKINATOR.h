//#define TX_USE_SPEAK

//#include "C:\прога\TX\TXLib.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

struct Node
{
   const char* data;
   Node* left;
   Node* right;
};

enum {
    ADD_RIGHT = 999,
    ADD_LEFT  = 888
};

int TreeCtor (Node* root);
Node* find (Node* root, int value);
Node* make_a_node_auto (Node* dad_node, int branch, int value);
Node* make_a_node (const char* str);
int Print_node (Node* node, FILE* fp);
int Reading_function (Node* node, FILE* fp);
