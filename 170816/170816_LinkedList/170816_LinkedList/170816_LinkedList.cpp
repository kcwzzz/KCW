// 170816_LinkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct  SNode
{

	int mKey = 0;

	SNode *mpNext = NULL;


};

SNode *mpHead = NULL;
SNode *mpTail = NULL;

void init_list(void)
{
	mpHead = new SNode();
	mpTail = new SNode();

	mpHead->mpNext = mpTail;
	mpTail->mpNext = mpTail;
}

int delete_mpNext(SNode *t)
{

	SNode *tpNode = NULL;

	if (t->mpNext == mpTail)
	{

		return 0;
	}

	tpNode = t->mpNext;
	t->mpNext = t->mpNext->mpNext;

	delete tpNode;

	return 1;
}


SNode *insert_after(int k, SNode *t)
{

	SNode *tpNode = NULL;
	tpNode = new SNode();

	tpNode->mKey = k;
	tpNode->mpNext = t->mpNext;
	t->mpNext = tpNode;
	
	return tpNode;
	}

SNode *find_SNode(int k)
{

	SNode *tpNode = NULL;
	tpNode = mpHead->mpNext;
	while (tpNode->mKey != k && tpNode !=mpTail)
	{
		tpNode = tpNode->mpNext;
	}
	return tpNode;
}

int delete_SNode(int k)

{

	SNode *s = NULL;
	SNode *p = NULL;

	p = mpHead;
	s = p->mpNext;

	while (s->mKey != k && s !=mpTail)
	{

		p = p->mpNext;
		s = p->mpNext;

	}

	if (s != mpTail)
	{
		p->mpNext = s->mpNext;
		delete s;
		return 1;
	}
	else
	{
		return 0;
	}
}

SNode *insert_SNode(int t, int k)
{
	SNode *p = NULL;
	SNode *s = NULL;

	SNode *r = NULL;

	p = mpHead;
	s = p->mpNext;

	while (s->mKey != k && s!=mpTail)
	{
		p = p->mpNext;
		s = p->mpNext;
	}

	if (s != mpTail)
	{
		r = new SNode();
		r->mKey = t;
		p->mpNext = r;
		r->mpNext = s;

	}

	return p->mpNext;

}

SNode *ordered_insert(int k)
{
	SNode *p = NULL;
	SNode *s = NULL;
	SNode *r = NULL;

	p = mpHead; 
	s = p->mpNext;

	while (s->mKey <=k && s!= mpTail)
	{
		p = p->mpNext;
		s = p->mpNext;
	}

	r = new SNode();

	r->mKey = k;
	p->mpNext = r;
	r->mpNext = s;

	return r;

}

void DisplayList(SNode *t)
{
	cout << endl;

	while (t != mpTail)
	{
		cout << "     " << t->mKey;
		t = t->mpNext;
	}
}

SNode *delete_all(void)
{

	SNode *s = NULL;
	SNode *t = NULL;

	t = mpHead->mpNext;
	while (t != mpTail)
	{
		s = t;
		t = t->mpNext;

		delete s;
	}

	mpHead->mpNext = mpTail;

	return mpHead;
}

int main()
{
	SNode *t = NULL;

	init_list();

	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	cout << endl << "Initial Lnked list if ";
	DisplayList(mpHead->mpNext);
	//Head의 다음 링크를 디스플레이

	cout << endl << "Finding 4 is" << (find_SNode(4) == mpTail ? "un" : "") << "successful";

	t = find_SNode(5);
	cout << endl << "Finding 5 is" << (find_SNode(5) == mpTail ? "un" : "") << "successful";

	cout << endl << "Insert 9 after 5";
	insert_after(9, t);
	DisplayList(mpHead->mpNext);
	
	t = find_SNode(10);
	cout << endl << "Deleting mpNext last SNode";
	delete_mpNext(t);
	DisplayList(mpHead->mpNext);

	t = find_SNode(3);
	cout << endl << "Deleting mpNext 3";
	delete_mpNext(t);
	DisplayList(mpHead->mpNext);

	cout << endl << "Insert SNode 2 before 3";
	insert_SNode(2, 3);
	DisplayList(mpHead->mpNext);

	cout << endl << "Deleting Snode 2";
	if (!delete_SNode(2))
	{
		cout << endl << "  deleting 2 is unsuccessful";
	}

	DisplayList(mpHead->mpNext);

	cout << endl << "Deleting SNode 1";
	delete_SNode(1);
	DisplayList(mpHead->mpNext);

	cout << endl << "Deleting all SNode";
	delete_all();
	DisplayList(mpHead->mpNext);


	return 0;
}

