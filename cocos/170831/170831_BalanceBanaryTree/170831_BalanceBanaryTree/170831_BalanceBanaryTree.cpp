// 170831_BalanceBanaryTree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX(a,b) ((a>b)?a:b)

using namespace std;

struct treeNode
{
	int key;

	treeNode *left = NULL;
	treeNode *right = NULL;


};

treeNode* LL_rotate(treeNode *parent)
{
	treeNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}


treeNode* RR_rotate(treeNode *parent)
{
	treeNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}

treeNode* LR_rotate(treeNode *parent)
{
	treeNode *child = parent->left;
	parent->left = RR_rotate(child);

	return LL_rotate(parent);

}

treeNode* RL_rotate(treeNode *parent)
{
	treeNode *child = parent->right;
	parent->right = LL_rotate(child);

	return RR_rotate(parent);

}

int getHeight(treeNode* p)
{
	int height = 0;
	if (p != NULL)
	{
		height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	}

	return height;
}

int getBF(treeNode *p)

{
	if (p == NULL)
	{
		return 0;
	}

	return getHeight(p->left) - getHeight(p->right);
}

treeNode* rebalance(treeNode **p)
{
	int BF = getBF(*p);
	
	
	if(BF>1)
	{
		if (getBF((*p)->left) > 0)
		{
			*p = LL_rotate(*p);

		}

		else
		{
			*p = LR_rotate(*p);
		}
	}
	else if(BF<-1)
	{
		if (getBF((*p)->right) < 0)
		{
			*p = RR_rotate(*p);
		}
		else
		{
			*p = RL_rotate(*p);
		}
		 
	}
	return *p;
}

treeNode *insert_AVL_Node(treeNode ** root, int x)
{
	if (*root == NULL)
	{
		*root = new treeNode();

		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (x < (*root)->key)
	{
		(*root)->left = insert_AVL_Node(&((*root)->left), x);
		*root = rebalance(root);
	}
	else if (x > (*root)->key)
	{
		(*root)->right = insert_AVL_Node(&((*root)->right), x);
		*root = rebalance(root);
	}
	else
	{
		cout << endl << " 이미 같은 키가 있습니다! " << endl;

		exit(1);
	}

	return *root;
}

treeNode* insert_BST_Node(treeNode *p, int x)
{
	treeNode *newNode = NULL;

	if (p == NULL)
	{
		newNode = new treeNode();

		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;

	}

	else if (x < p->key)
	{
		p->left = insert_BST_Node(p->left, x);
	}
	else if (x > p->key)
	{
		p->right = insert_BST_Node(p->right, x);
	}
	else
	{
		cout << endl << " 이미 같은 키가 있습니다! " << endl;

	}

	return p;
}

treeNode* searchTree(treeNode* root, int x)
{
	treeNode* p = NULL;
	int count = 0;

	p = root;

	while (p != NULL)
	{
		count++;
		if (x < p->key)
		{
			p = p->left;
		}
		else if (x > p->key)
		{
			p = p->right;
		}
		else
		{
			cout << "\t" << count << "번째에 탐색 성공";

			return p;
		}
	}

	count++;

	cout << "\t" << count << "번째에 탐색 실패! 찾는 키가 없습니다!";

	return p;

}
void displayInorder(treeNode *root)
{
	if (root)
	{
		displayInorder(root->left);
		cout << "_" << root->key;
		displayInorder(root->right);
	}
}



int main()
{
	treeNode* root_AVL = NULL;
	treeNode* root_BST = NULL;

	root_AVL = insert_AVL_Node(&root_AVL, 50);
	insert_AVL_Node(&root_AVL, 60);
	insert_AVL_Node(&root_AVL, 70);
	insert_AVL_Node(&root_AVL, 90);
	insert_AVL_Node(&root_AVL, 80);
	insert_AVL_Node(&root_AVL, 75);
	insert_AVL_Node(&root_AVL, 73);
	insert_AVL_Node(&root_AVL, 72);
	insert_AVL_Node(&root_AVL, 78);


	cout << endl << " ******* AVL 트리 출력 ****************** " << endl << endl;
	displayInorder(root_AVL);

	cout << endl << endl << " AVL 트리에서 70 탐색 : ";
	searchTree(root_AVL, 70);

	cout << endl << endl << " AVL 트리에서 72 탐색 : ";
	searchTree(root_AVL, 72);

	cout << endl << endl << " AVL 트리에서 76 탐색 : ";
	searchTree(root_AVL, 76);

	/////////////////////////////////////////////////////////////////////////////
	root_BST = insert_BST_Node(root_BST, 50); //BST 만들기
	insert_BST_Node(root_BST, 60);
	insert_BST_Node(root_BST, 70);
	insert_BST_Node(root_BST, 90);
	insert_BST_Node(root_BST, 80);
	insert_BST_Node(root_BST, 75);
	insert_BST_Node(root_BST, 73);
	insert_BST_Node(root_BST, 72);
	insert_BST_Node(root_BST, 78);

	cout << endl << endl << endl << " ******* BST 출력 ************************ " << endl << endl;
	displayInorder(root_BST);

	cout << endl << endl << " BST에서 70 탐색 : ";
	searchTree(root_BST, 70);

	cout << endl << endl << " BST에서 72 탐색 : ";
	searchTree(root_BST, 72);

	cout << endl << endl << " BST에서 76 탐색 : ";
	searchTree(root_BST, 76);


	cout << endl;

    return 0;
}

