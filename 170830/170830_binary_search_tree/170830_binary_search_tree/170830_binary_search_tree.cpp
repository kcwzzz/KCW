// 170830_binary_search_tree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//typedef struct  treeNode 
// 이건 옛날 문법이야요
struct  treeNode
{
	char key;

	struct treeNode* left = NULL;
	struct treeNode* right = NULL;


};

treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p = NULL;

	p = root;

	while (p != NULL)
	{
		if (x < p->key)
		{
			p = p->left;
		}
		else if (x > p->key)
		{
			p = p->right;
		}
		else if (x == p->key)
		{
			return p;
		}
	}
	cout << endl << "찾는키가 없습니다";
	return p;
}

treeNode* insertNode(treeNode* p, char x)
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
		p->left = insertNode(p->left, x);
	}

	else if (x > p->key)
	{
		p->right = insertNode(p->right, x);
	}
	else
	{
		cout << endl << " 이미 같은 키가 있습니다" << endl;
	}

	return p;

}

void deleteNode(treeNode *root, char key)
{
	treeNode *parent = NULL, *p = NULL, *succ = NULL, *succ_parent = NULL;
	treeNode *child = NULL;

	parent = NULL;
	p = root;

	while (((p != NULL) && (p->key != key)))
	{
		parent = p;

		if (key < p->key)
		{
			p = p->left;

		}
		else
		{
			p = p->right;
		}

	}

	if (p == NULL)
	{
		cout << endl << "찾는 키가 이진 트리에 없슶셊슶";

		return;
	}
	//삭제할 노드가 자식 노드가 없는 경우
	if ((p->left == NULL) && (p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
		}
		else
		{
			root = NULL;
		}
	}
	//삭제할 노드가 자식 노드를 1개 가진 경우
	else if ((p->left == NULL) || (p->right == NULL))
	{
		if (p->left != NULL)
		{
			child = p->left;
		}
		else
		{
			child = p->right;
		}

		if (parent != NULL)
		{
			if (parent->left == p)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
		}
		else
		{
			root = child;
		}
	}

	//삭제할 노드가 자식이 2개를 갖는 경우
	else
	{
		//3가지 경우를 나타낸다.
		succ_parent = p;
		succ = p->left;

		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}

		if (succ_parent->left == succ)
		{
			succ_parent->left = succ->left;

		}
		else
		{
			succ_parent->right = succ->left;

		}

		p->key = succ->key;
		p = succ;

	}
	delete p;
}

void displayInorder(treeNode* root)
{
	if (root)
	{
		displayInorder(root->left);

		cout << root->key << "_";

		displayInorder(root->right);
	}
}


void DisplayMenu()
{
	cout << endl << "*---------------------------*";
	cout << endl << "\t1 : 트리 출력";
	cout << endl << "\t2 : 문자 삽입";
	cout << endl << "\t3 : 문자 삭제";
	cout << endl << "\t4 : 문자 검색";
	cout << endl << "\t5 : 종료";
	cout << endl << "*---------------------------*";
	cout << endl << "메뉴입력 >> ";
}


int main()
{
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;

	char choice, key;

	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');



	while (1)
	{
		DisplayMenu();
		cin >> choice;

		switch (choice - '0')
		{
		case 1:
		{
			cout << "\t[이진 트리 출력]  ";
			displayInorder(root);
			cout << endl;
		}
		break;

		case 2:
		{
			cout << "삽입할 문자를 입력하세요 : ";
			cin >> key;
			insertNode(root, key);

		}
		break;

		case 3:
		{
			cout << "삭제할 문자를 입력하세요 : ";

			cin >> key;
			deleteNode(root, key);
		}
		break;

		case 4:
		{
			cout << "찾을 문자를 입력하세요 : ";
			cin >> key;

			foundedNode = searchBST(root, key);

			if (foundedNode != NULL)
			{
				cout << endl << foundedNode->key << "를 찾았습니다." << endl;

			}
			else
			{
				cout << endl << " 문자를 찾지 못했습" << endl;
			}
		}
		break;

		case 5:
			return 0;

		default:
		{
			cout << "없는 메뉴입니다. 다시 선택 해주셈" << endl;
		}
		break;
		}
	}


	return 0;
}
