#pragma

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

struct SPathInfo
{
	int mX = 0;
	int mY = 0;

	int mTotalCost = 0;
	int mCostFromStart = 0;
	int mCostToGoal = 0;

	bool mIsOpen = false;
	bool mIsClosed = false;

	SPathInfo *mpParentPathNode = NULL;
};

struct SRyuNode
{
	SPathInfo *mpPathInfo = NULL;
	SRyuNode *mpNext = NULL;
};

typedef std::vector <SPathInfo *> ::iterator PathNodeVecItor;


class CRyuNodeList
{
public : 
	int mTestCount = 0;
	void TestDisplayCount(string tString);

private :
	SRyuNode *mpHead = NULL;
	SRyuNode *mpTail = NULL;

public:
	CRyuNodeList();
	virtual ~CRyuNodeList();

	void Clear();

	void Create();
	void Destroy();

	void Reset();

	bool IsEmpty();

	SPathInfo *IsBe(SPathInfo *node);

	void SetLocation(SPathInfo *node);

	SPathInfo *Pop();

	SPathInfo *FindPathInfoList(SPathInfo *tpPathInfo);

	bool DeletePathInfo(SPathInfo *tpPathInfo);

	SRyuNode *OrderedInsert(SPathInfo *tpPathInfo);


};