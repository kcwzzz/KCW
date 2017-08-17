// 170817_LinkedList_Queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

struct SNode
{
	int mKey = 0;
	SNode *mpPrev = NULL;
	SNode *mpNext = NULL;

};

SNode *mpHead = NULL;
SNode *mpTail = NULL;

void init_queue(void)
{
	mpHead = new SNode();
	mpTail = new SNode();

	mpHead->mpNext = mpTail;
	mpTail->mpNext = mpTail;
	mpHead->mpPrev = mpHead;
	mpTail->mpPrev = mpHead;

}

void clear_queue(void)
{
	SNode *t = NULL;
	SNode *s = NULL;

	t = mpHead->mpNext;

	while (t !=mpTail)
	{
		s = t;
		t = t->mpNext;

		delete s;
	}

	mpHead->mpNext = mpTail;
	mpTail->mpPrev = mpHead;
}

int put(int k)
{
	SNode *t = NULL;

	t = new SNode();
	if (t == NULL)
	{
		cout << endl << "    Out of memory.";

		return -1;
	}

	t->mKey = k;

	mpTail->mpPrev->mpNext = t;
	t->mpPrev = mpTail->mpPrev;
	mpTail->mpPrev = t;
	t->mpNext = mpTail;

	return k;

}


int get(void)
{
	SNode *t = NULL;
	int i = 0;

	t = mpHead->mpNext;

	if (t == mpTail)
	{
		cout << endl << "    Queue underflow.";

		return -1;
	}

	i = t->mKey;

	mpHead->mpNext = t->mpNext;
	t->mpNext->mpPrev = mpHead;

	delete t;

	return i;
}

void print_queue(void)
{
	SNode *t = NULL;

	t = mpHead->mpNext;

	cout << endl << "  Queue contents : Front ----> Rear" << endl;
	while (t != mpTail)
	{
		cout << "     " << t->mKey;

		t = t->mpNext;
	}
}

int main(int argc, const char * argv[]) {

	int i = 0;
	init_queue();

	cout << endl << "Put 5, 4, 7, 8, 2, 1";
	put(5);
	put(4);
	put(7);
	put(8);
	put(2);
	put(1);
	print_queue();

	cout << endl << "Get";
	i = get();
	print_queue();
	cout << endl << "   getting value is " << i;

	cout << endl << "Put 3, 2, 5, 7";
	put(3);
	put(2);
	put(5);
	put(7);
	print_queue();

	cout << endl << "Put 3";
	put(3);
	print_queue();

	cout << endl << "Initialize queue";
	clear_queue();
	print_queue();

	cout << endl << "Now queue is empty, get";
	i = get();
	print_queue();
	cout << endl << "   getting value is " << i;

	return 0;
}

