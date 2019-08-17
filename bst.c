#include <stdio.h>
#include <stdlib.h>

struct node{

	int value;
	struct node *left_child;
	struct node *right_child;

};

struct node* search( struct node *root, int val ){

	if( root == NULL || root->value == val ){

		return root;
	}
	else if( val < root->value ){

		return search( root->left_child ,val);
	}
	else{

		return search( root->right_child ,val);
	}
}

struct node* createNode( int val ){

	struct node *newNode = malloc(sizeof( struct node));

	newNode->value = val;
	newNode->left_child = NULL;
	newNode->right_child = NULL;

	return newNode;
}

struct node* insert( struct node *root, int val ){
// create dupefinder function - search function that returns bool

	if( root == NULL ){
		createNode( val );
	}
	else if( val < root->value ){
		root->left_child = insert( root->left_child, val );
	}
	else if( val > root->value ){
		root->right_child = insert( root->right_child, val );
	}

	return root;
}

int main(){

	struct node *root = NULL;
	struct node *temp = NULL;

	root = insert( root, 20 );
	insert( root, 30 );

	temp = search( root, 30 );

	free(search(root, 30));
	free(root);


	return 0;
}