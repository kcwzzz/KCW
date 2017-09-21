// 170817_DoubleLinkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <stdio.h>

using namespace std;

struct SDNode
{
	int mKey = 0;

	SDNode *mpPrev = NULL;
	SDNode *mpNext = NULL;


};

SDNode *mpHead = NULL;
SDNode *mpTail = NULL;

void init_dlist(void)
{
	mpHead = new SDNode();
	mpTail = new SDNode();

	mpHead->mpNext = mpTail;
	mpHead->mpPrev = mpHead;

	mpTail->mpNext = mpTail;
	mpTail->mpPrev = mpHead;
}

SDNode *find_SDNode(int k)
{
	SDNode *s = NULL;

	s = mpHead->mpNext;
	while (s->mKey != k && s!=mpTail)
	{
		s = s->mpNext;
	}

	return s;
}

int delete_SDNode(int k)
{
	SDNode *s = NULL;
	s = find_SDNode(k);

	if (s != mpTail)
	{
		s->mpPrev->mpNext = s->mpNext;
		s->mpNext->mpPrev = s->mpPrev;

		delete s;

		return 1;
	}

	return 0;
}


SDNode *insert_SDNode(int k, int t)  /* insert k, before t */
{
	SDNode *s = NULL;
	SDNode *i = NULL;

	s = find_SDNode(t);
	if (s != mpTail)   /* if find */
	{
		i = new SDNode();

		i->mKey = k;

		s->mpPrev->mpNext = i;
		i->mpPrev = s->mpPrev;
		s->mpPrev = i;
		i->mpNext = s;
	}

	return i;
}

SDNode *ordered_insert(int k)
{
	SDNode *s = NULL;   //place for insert after
	SDNode *i = NULL;   //'추가할 대상'

	s = mpHead->mpNext;

	while (s->mKey <= k && s != mpTail)
	{
		s = s->mpNext;
	}

	i = new SDNode();

	i->mKey = k;

	s->mpPrev->mpNext = i;
	i->mpPrev = s->mpPrev;
	s->mpPrev = i;
	i->mpNext = s;

	return i;
}

int delete_SDNode_ptr(SDNode *p)
{
	if (p == mpHead || p == mpTail)
	{
		return 0;
	}

	p->mpPrev->mpNext = p->mpNext;
	p->mpNext->mpPrev = p->mpPrev;

	delete p;

	return 1;
}
//노드의 주소를 알려줌
SDNode *insert_SDNode_ptr(int k, SDNode *t)  /* insert k, before t */
{
	SDNode *i = NULL;

	if (t == mpHead)
	{
		return NULL;
	}

	i = new SDNode();

	i->mKey = k;

	t->mpPrev->mpNext = i;
	i->mpPrev = t->mpPrev;
	t->mpPrev = i;
	i->mpNext = t;

	return i;
}

void print_dlist(SDNode *p)
{
	cout << endl;
	while (p != mpTail)
	{
		//printf("%-8d", p->mKey);
		cout << "     " << p->mKey;
		p = p->mpNext;
	}
}

void delete_all(void)
{
	SDNode *p = NULL;
	SDNode *s = NULL;   //'지울 대상'을 담을 곳

						//모든 노드를 순회
	p = mpHead->mpNext;
	while (p != mpTail)
	{
		s = p;
		p = p->mpNext;

		delete s;
	}

	mpHead->mpNext = mpTail;
	mpTail->mpPrev = mpHead;
}



int main(int argc, const char * argv[]) {

	SDNode *t = NULL;
	init_dlist();

	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	cout << endl << "Initial Linked list is ";
	print_dlist(mpHead->mpNext);

	//printf("\nFinding 4 is %ssuccessful", find_SDNode(4) == mpTail ? "un" : "");
	cout << endl << "Finding 4 is " << (find_SDNode(4) == mpTail ? "un" : "") << "ssuccessful";

	t = find_SDNode(5);
	//printf("\nFinding 5 is %ssuccessful", t == mpTail ? "un" : "");
	cout << endl << "Finding 5 is " << (t == mpTail ? "un" : "") << "ssuccessful";

	cout << endl << "Inserting 7 before 5";
	insert_SDNode_ptr(7, t);
	print_dlist(mpHead->mpNext);

	t = find_SDNode(3);
	cout << endl << "Deleting 3 ";
	delete_SDNode_ptr(t);
	print_dlist(mpHead->mpNext);

	cout << endl << "Inserting node 2 before 10";
	insert_SDNode(2, 10);
	print_dlist(mpHead->mpNext);

	cout << endl << "Deleting node 2";
	if (!delete_SDNode(2))
	{
		cout << endl << "  deleting 2 is unsuccessful";
	}

	print_dlist(mpHead->mpNext);


	cout << endl << "Deleting node 1";
	delete_SDNode(1);
	print_dlist(mpHead->mpNext);


	cout << endl << "Inserting 15 at first";
	insert_SDNode_ptr(15, mpHead->mpNext);
	print_dlist(mpHead->mpNext);


	cout << endl << "Deleting all node";
	delete_all();
	print_dlist(mpHead->mpNext);

	return 0;
}
