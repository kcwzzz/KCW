#pragma once

#include <stdio.h>
#include <vector>

class CStageInfo;

class CStageMgr
{
private:
	static CStageMgr *mpInstance;

	CStageMgr();
	~CStageMgr();

	std::vector<CStageInfo *> mStageVec;

	unsigned int mCurStageIndex = 0;

public:
	static CStageMgr *GetInstance();

	void CreateActor();
	void DestroyFile();

	void  SetCurStageIndex(unsigned int tStageIndex);

	CStageInfo *GetCurStageInfo();

};