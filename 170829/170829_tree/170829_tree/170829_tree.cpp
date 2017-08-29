// 170829_tree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stdio.h>
#include <memory>
#include <stdlib.h>

using namespace std;

struct  treeNode
{
	char data;

	treeNode *left = NULL;
	treeNode *right = NULL;
};

typedef queue<treeNode *>CQTreeNode;
CQTreeNode gQ;

treeNode* makeRootNode(char data, treeNode*leftNode, treeNode* rightnode)
{
	treeNode root = new treeNode();
}

int main()
{

    return 0;
}