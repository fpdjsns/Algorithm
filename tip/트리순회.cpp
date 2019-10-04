#include<stdio.h>
#include<stdlib.h>
#define node_num 7

//node struct
typedef struct node
{
	char alphabet;  //alphabet
	struct node* left; //left child node
	struct node* right; //right child node
}node;

//set up information of node
void set_node(node* n, char alphabet, node* left, node* right)
{
	n->alphabet = alphabet;
	n->left = left;
	n->right = right;
}

//preorder
void preorder(node* root)
{
	printf("%c ", root->alphabet); //print node
	if(root->left) preorder(root->left); //left child
	if (root->right) preorder(root->right); //right child
}

//inorder
void inorder(node* root)
{
	if (root->left) inorder(root->left); //left child
	printf("%c ", root->alphabet); //print node
	if (root->right) inorder(root->right); //right child
}

//postorder
void postorder(node* root)
{
	if (root->left) postorder(root->left); //left child
	if (root->right) postorder(root->right); //right child
	printf("%c ", root->alphabet); //print node
}

int main()
{
	int i;
	node* arr_node[node_num];
	for(i=0;i<node_num;i++)
		arr_node[i] = (node*)malloc(sizeof(node));

	set_node(arr_node[0], 'A', NULL, NULL);
	set_node(arr_node[1], 'B', arr_node['A' - 'A'], NULL);
	set_node(arr_node[2], 'C', arr_node['B' - 'A'], arr_node['E' - 'A']);
	set_node(arr_node[3], 'D', NULL, NULL);
	set_node(arr_node[4], 'E', arr_node['D' - 'A'], arr_node['F' - 'A']);
	set_node(arr_node[5], 'F', NULL, arr_node['G' - 'A']);
	set_node(arr_node[6], 'G', NULL, NULL);

	printf("preorder : ");  preorder(arr_node['C' - 'A']);
	printf("\ninorder : "); inorder(arr_node['C' - 'A']);
	printf("\npostorder : "); postorder(arr_node['C' - 'A']);

	return 0;
}
