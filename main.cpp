#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ptrList.h"
#include "graphviz.h"

FILE* gfile = fopen("graphfile.txt", "w");

int main()
{
    struct list List;
    listCtor (&List);

    struct node* Node1 = newNode(5);
    struct node* Node2 = newNode(15);
    struct node* Node3 = newNode(17);
    struct node* Node4 = newNode(72);
    struct node* Node5 = newNode(23);

    addHead (&List, Node1);
    addHead (&List, Node2);
    addHead (&List, Node3);
    addHead (&List, Node4);
    addNodeBefore (&List, Node3, Node5);
    delNode (&List, Node4);

    struct node* NodeI = List.tail;

    printf("size: %ld\n", List.size);
    
    for (int i = 0; i < List.size; ++i)
    {
        printf("List[%d] = %d\n", i, NodeI->data);
        printf("His address: %p\n", NodeI);
        NodeI = NodeI->next;
    }
    
    listGraph (gfile, &List);

    free (Node1);
    free (Node2);
    free (Node3);
    free (Node5);
    

    return 0;
}