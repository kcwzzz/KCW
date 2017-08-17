// 170817_LinkedList_Stack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

struct SNode
{
	int mKey;

	SNode *mpNext = NULL;
};


SNode *mpHead = NULL;
SNode *mpTail = NULL;

void init_stack(void)
{
	mpHead = new SNode();
	mpTail = new SNode();

	mpHead->mpNext = mpTail;
	mpTail->mpNext = mpTail;

}

void clear_stack(void)
{
	SNode *t = NULL;
	SNode *s = NULL;

	t = mpHead->mpNext;

	while (t != mpTail)
	{
		s = t;
		t = t->mpNext;

		delete s;
	}

	mpHead->mpNext = mpTail;

}

int push(int k)
{
	SNode *t = NULL;

	t = new SNode();
	if (t == NULL)
	{
		cout << endl << "		Out of memory...";

		return -1;
	}

	t->mKey = k;

	t->mpNext = mpHead->mpNext;
	mpHead->mpNext = t;

	return k;

}

int pop(void)
{
	int i;
	SNode *t = NULL;

	if (mpHead->mpNext == mpTail)
	{
		cout << endl << "	Stack Underflow.";

		return -1;
	}

	t = mpHead->mpNext;
	i = t->mKey;

	mpHead->mpNext = t->mpNext;

	delete t;
	return i;
}


void print_stack(void)
{
	SNode *t = NULL;
	t = mpHead->mpNext;

	cout << endl << "	Stack contents : Top -------------------->Bottem\n";

	while (t != mpTail)
	{
		cout << "		" << t->mKey;

		t = t->mpNext;
	}
}


int main()
{
	int i;
	init_stack();

	cout << endl << "Push 5, 4, 7, 8, 2, 1";

	push(5);
	push(4);
	push(7);
	push(8);
	push(2);
	push(1);
	print_stack();


	cout << endl << "POP";
	i = pop();
	print_stack();
	cout << endl << "		popping value is " << i ;

	cout << endl << "Phsu 3, 2, 5, 7, 2";
	push(3);
	push(2);
	push(5);
	push(7);
	push(2);
	print_stack();

	cout << endl << "Push 3";
	push(3);
	print_stack();

	cout << endl << "Initialize stack";
	clear_stack();
	print_stack();

	cout << endl << "Now stack is empty, pop";
	i = pop();
	print_stack();
	cout << endl << "   popping value is " << i;
	

    return 0;
}

