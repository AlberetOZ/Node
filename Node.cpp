#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

struct  Node    {
	Data val;                  //      данные  в       узле	
	struct Node* left;           //      левый   ребен
	struct Node* right;  //      правый  ребенок
};



int ans = 0;



struct Node * tree_add (struct Node * tree, Data x)
{

        if(tree == NULL)
        {
                tree = calloc(1, sizeof(struct Node));
                tree -> val = x;
                return tree;
        }
        if(x == tree -> val)
                return tree;

        if(x > tree -> val)
        {

                tree -> right = tree_add(tree -> right, x);
                return tree;



        }
        else
        {

                tree -> left = tree_add(tree -> left, x);
                return tree;



        }





}

void tree_print(struct Node* tree)
{

        if(((tree -> left) == NULL) && ((tree -> right) == NULL))
        {
                printf("%d ", tree -> val);


        }
        if(tree -> left != NULL)
                tree_print( tree -> left);
        if(tree -> right != NULL)
                tree_print( tree -> right);


}

void tree_destroy(struct Node* tree)
{



	if(tree -> left != NULL)
		tree_destroy( tree -> left);



	if(tree -> right != NULL)
		tree_destroy( tree -> right);
	
	free(tree);


}


int main()
{
	struct Node * tree=NULL;

        int i = 1, u = 0;

        for(; i  != 0; u++)
        {
                scanf("%d", &i);
                if(i != 0)
                        tree = tree_add(tree, i);


        }

        if(u == 1)
        {
                return 0;
        }


	tree_print(tree);
	tree_destroy(tree);

	return 0;
}
