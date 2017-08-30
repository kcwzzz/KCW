// 170830_binary_search_tree.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//typedef struct  treeNode 
// �̰� ���� �����̾߿�
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
	cout << endl << "ã��Ű�� �����ϴ�";
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
		cout << endl << " �̹� ���� Ű�� �ֽ��ϴ�" << endl;
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
		cout << endl << "ã�� Ű�� ���� Ʈ���� �����R��";

		return;
	}
	//������ ��尡 �ڽ� ��尡 ���� ���
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
	//������ ��尡 �ڽ� ��带 1�� ���� ���
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

	//������ ��尡 �ڽ��� 2���� ���� ���
	else
	{
		//3���� ��츦 ��Ÿ����.
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
	cout << endl << "\t1 : Ʈ�� ���";
	cout << endl << "\t2 : ���� ����";
	cout << endl << "\t3 : ���� ����";
	cout << endl << "\t4 : ���� �˻�";
	cout << endl << "\t5 : ����";
	cout << endl << "*---------------------------*";
	cout << endl << "�޴��Է� >> ";
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
			cout << "\t[���� Ʈ�� ���]  ";
			displayInorder(root);
			cout << endl;
		}
		break;

		case 2:
		{
			cout << "������ ���ڸ� �Է��ϼ��� : ";
			cin >> key;
			insertNode(root, key);

		}
		break;

		case 3:
		{
			cout << "������ ���ڸ� �Է��ϼ��� : ";

			cin >> key;
			deleteNode(root, key);
		}
		break;

		case 4:
		{
			cout << "ã�� ���ڸ� �Է��ϼ��� : ";
			cin >> key;

			foundedNode = searchBST(root, key);

			if (foundedNode != NULL)
			{
				cout << endl << foundedNode->key << "�� ã�ҽ��ϴ�." << endl;

			}
			else
			{
				cout << endl << " ���ڸ� ã�� ���߽�" << endl;
			}
		}
		break;

		case 5:
			return 0;

		default:
		{
			cout << "���� �޴��Դϴ�. �ٽ� ���� ���ּ�" << endl;
		}
		break;
		}
	}


	return 0;
}
