/*
    LINKED LISTS:
    1. Basic Linked List
    2. Not optimized
    
    Ima hustla baybeh.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
// Creating typedefs makes it so you don't always have to type struct before node.

  int x;
  struct node *next;

}node;

void printList( node *root ){
// Best way to print for a singly linked list.
// Traverse towards the end from the root.
    struct node *current = root;

    while( current != NULL ){
        printf("%s%d\n", "Printing: ", current->x );
        current = current->next;
    }
}

void cleanUp( node *root ){

    node *freeMe = root;
    node *holdMe = NULL;

    while( freeMe != NULL ){
        holdMe = freeMe->next;
        printf("%s", "freeing...\n");
        free(freeMe);
        freeMe = holdMe;
    }
}
 
int main()
{
    /* This won't change, or we would lose the list in memory */
    node *root;       
    /* This will point to each node as it traverses the list */
    node *conductor;  
 
    root = malloc( sizeof(node) );
    root->next = NULL;   
    root->x = 12;
    conductor = root;

    if ( conductor != NULL ) {
        while ( conductor->next != NULL)
        {
            conductor = conductor->next;
        }
    }
    /* Creates a node at the end of the list */
    conductor->next = malloc( sizeof(struct node) );  
 
    conductor = conductor->next; 
 
    if ( conductor == NULL )
    {
        printf( "Out of memory" );
        return 0;
    }
    /* initialize the new memory */
    conductor->next = 0;         
    conductor->x = 42;

    printList(root);
 
    cleanUp(root);
    return 0;
}