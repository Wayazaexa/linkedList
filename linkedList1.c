#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    struct Node *next;
} node;

int main ()
{
    node *lList = NULL;

    // Add 5 nodes.
    node *newNode = NULL;
    for (int i = 0; i < 5; i++)
    {
        newNode = (node *)malloc(sizeof(node));
        newNode->id = i;
        newNode->next = lList;
        printf("Creating node, id: %d\n", newNode->id);
        lList = newNode;
    }

    // Print the linked list.
    for (node *pList = lList; pList != NULL; pList = pList->next)
    {
        printf("List node id: %d\n", pList->id);
    }

    // Free all memory.
    node *old = lList;
    while (old != NULL)
    {
        lList = lList->next;
        printf("Freeing node, id: %d\n", old->id);
        free(old);
        old = lList;
    }
    
    return 0;
}
