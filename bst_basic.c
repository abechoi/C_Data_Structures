/*
	BINARY SEARCH TREE:
	1. This is a basic form
	2. pointer of pointers are kind of confusing.
	3. BSTs were hard to learn because everyone seems to do it differently
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int key_value;
  struct node *left;
  struct node *right;
};

void destroy_tree(struct node *leaf)
{
  if( leaf != 0 )
  {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      free( leaf );
  }
}

void insert(int key, struct node **leaf)
{
    if( *leaf == 0 )
    {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->key_value = key;
        /* initialize the children to null */
        (*leaf)->left = 0;    
        (*leaf)->right = 0;  
    }
    else if(key < (*leaf)->key_value)
    {
        insert( key, &(*leaf)->left );
    }
    else if(key > (*leaf)->key_value)
    {
        insert( key, &(*leaf)->right );
    }
}

struct node *search(int key, struct node *leaf)
{
  if( leaf != 0 )
  {
      if(key==leaf->key_value)
      {
          return leaf;
      }
      else if(key<leaf->key_value)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  else return 0;
}

int main(){

	struct node *root = NULL;

	insert( 10, &root);
	insert( 20, &root );
	insert( 5, &root );

	printf("%d\n", search( 10, root)->key_value );
	printf("%d\n", search( 20, root)->key_value );
	printf("%d\n", search( 5, root)->key_value );

	destroy_tree( root );
	return 0;
}





