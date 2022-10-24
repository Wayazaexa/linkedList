#include <stdio.h>
#include <stdlib.h>

struct Node{
    int id;
    struct Node *next;
};

int main ()
{
    struct Node *lList = NULL;

    // Add 5 nodes.
    struct Node *newNode = NULL;
    for (int i = 0; i < 5; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->id = i;
        newNode->next = lList;
        printf("Creating node, id: %d\n", newNode->id);
        lList = newNode;
    }

    // Print the linked list.
    for (struct Node *pList = lList; pList != NULL; pList = pList->next)
    {
        printf("List node id: %d\n", pList->id);
    }

    // Free all memory.
    struct Node *old = lList;
    while (old != NULL)
    {
        lList = lList->next;
        printf("Freeing node, id: %d\n", old->id);
        free(old);
        old = lList;
    }
    
    return 0;
}
