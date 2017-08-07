#include "CStageMgr.hpp"

#include <iostream>

#include "CUnitInfo.hpp"
#include "CStageInfo.hpp"

#include "cocos2d.h"

using namespace std;

#include "rapidjson\document.h"
#include "rapidjson\reader.h"

using namespace rapidjson;

CStageMgr *CStageMgr::mpInstance = NULL;

CStageMgr::CStageMgr()
{
	mCurStageIndex = 0;

}

CStageMgr::~CStageMgr()
{

}

CStageMgr *CStageMgr::GetInstance()
{
	if (NULL == mpInstance)
	{
		mpInstance = new CStageMgr();
		return mpInstance;
	}
	return mpInstance;
}

/*
void CStageMgr::CreateActor()
{
	CStageInfo *tpStageInfo = NULL;
	CUnitInfo *tpUnitInfo = NULL;

	//0
	tpStageInfo = NULL;
	tpStageInfo = new CStageInfo();

	tpStageInfo->mId = 0;
	tpStageInfo->mTotalEnemyCount = 2;

	
		tpUnitInfo = NULL;
		tpUnitInfo = new CUnitInfo();
		tpUnitInfo->mX = 100;
		tpUnitInfo->mY = 100;

		tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);

		tpUnitInfo = NULL;
		tpUnitInfo = new CUnitInfo();
		tpUnitInfo->mX = 200;
		tpUnitInfo->mY = 100;

		tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);

	mStageVec.push_back(tpStageInfo);

	//1
	tpStageInfo = NULL;
	tpStageInfo = new CStageInfo();

	tpStageInfo->mId = 1;
	tpStageInfo->mTotalEnemyCount = 3;


		tpUnitInfo = NULL;
		tpUnitInfo = new CUnitInfo();
		tpUnitInfo->mX = 100;
		tpUnitInfo->mY = 100;

		tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);

		tpUnitInfo = NULL;
		tpUnitInfo = new CUnitInfo();
		tpUnitInfo->mX = 200;
		tpUnitInfo->mY = 100;

		tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);

		tpUnitInfo = NULL;
		tpUnitInfo = new CUnitInfo();
		tpUnitInfo->mX = 300;
		tpUnitInfo->mY = 100;

		tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);

	mStageVec.push_back(tpStageInfo);

	//2
	tpStageInfo = NULL;
	tpStageInfo = new CStageInfo();

	tpStageInfo->mId = 0;
	tpStageInfo->mTotalEnemyCount = 1;


	tpUnitInfo = NULL;
	tpUnitInfo = new CUnitInfo();
	tpUnitInfo->mX = 100;
	tpUnitInfo->mY = 100;

	tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);

	mStageVec.push_back(tpStageInfo);
}
*/
/*
void CStageMgr::CreateActor()
{
	CStageInfo *tpStageInfo = NULL;
	CUnitInfo *tpUnitInfo = NULL;

	xml_document tXmlDoc;

	std:string tFileName = cocos2d::FileUtils::getInstance()->fullPathForFilename("data/stageinfo.xml");

	xml_parse_result tResult = tXmlDoc.load_file(tFileName.c_str());

	if (tResult)
	{
		xml_node tNodeResult = tXmlDoc.child("response");
		xml_node tNodeStageInfoList = tNodeResult.child("stage_info_list");

		for (xml_node tStageInfo = tNodeStageInfoList.child("stage_info"); tStageInfo; tStageInfo = tStageInfo.next_sibling("stage_info"))
		{
			string tId = tStageInfo.child_value("id");
			string tTotalEnemyCount = tStageInfo.child_value("total_enemy_count");

			tpStageInfo = NULL;
			tpStageInfo = new CStageInfo();

			tpStageInfo->mId = atoi(tId.c_str());
			tpStageInfo->mTotalEnemyCount = atoi(tTotalEnemyCount.c_str());

			xml_node tNodeUnitInfoList = tStageInfo.child("unit_info_list");

			for (xml_node tUnitInfo = tNodeUnitInfoList.child("unit_info"); tUnitInfo; tUnitInfo = tUnitInfo.next_sibling("unit_info"))
			{
				string tX = tUnitInfo.child_value("x");
				string tY = tUnitInfo.child_value("y");

				tpUnitInfo = NULL;
				tpUnitInfo = new CUnitInfo();
				tpUnitInfo->mX = atoi(tX.c_str());
				tpUnitInfo->mY = atoi(tY.c_str());

				tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);
			}
			mStageVec.push_back(tpStageInfo);
		}
	}
}
*/

void CStageMgr::CreateActor()
{
	CStageInfo *tpStageInfo = NULL;
	CUnitInfo *tpUnitInfo = NULL;

	Document tDocument;

	std::string tFileName = cocos2d::FileUtils::getInstance()->fullPathForFilename("data/stageinfo.json");
		std::string clearData = cocos2d::FileUtils::getInstance()->getStringFromFile(tFileName);

	if (tDocument.Parse<0>(clearData.c_str()).HasParseError()) {

		return;
	}

	const rapidjson::Value &tStageInfoList = tDocument["stage_info"];

	for (SizeType i = 0; i < tStageInfoList.Size();i++)
	{
		int tId = tStageInfoList[i].GetObject()["id"].GetInt();
		int tTotalEnemyCount = tStageInfoList[i].GetObject()["total_enemy_count"].GetInt();

		tpStageInfo = NULL;
		tpStageInfo = new CStageInfo();

		tpStageInfo->mId = tId;
		tpStageInfo->mTotalEnemyCount = tTotalEnemyCount;

		const rapidjson::Value& tUnitInfoList = tStageInfoList[i].GetObject()["unit_info"];

		for (SizeType tj = 0; tj < tUnitInfoList.Size(); tj++)
		{
			int tX = tUnitInfoList[tj].GetObject()["x"].GetInt();
			int tY = tUnitInfoList[tj].GetObject()["y"].GetInt();

			tpUnitInfo = NULL;
			tpUnitInfo = new CUnitInfo();

			tpUnitInfo->mX = tX;
			tpUnitInfo->mY = tY;

			tpStageInfo->mUnitInfoVec.push_back(tpUnitInfo);

		}
		mStageVec.push_back(tpStageInfo);
	}
}

void CStageMgr::DestroyFile()
{
	int ti = 0;
	int tCount = 0;

	tCount = mStageVec.size();

	for (ti = 0; ti < tCount; ti++)
	{
		for (int tj = 0; tj < mStageVec[ti]->mUnitInfoVec.size(); tj++)
		{
			delete mStageVec[ti]->mUnitInfoVec[tj];
			mStageVec[ti]->mUnitInfoVec[tj] = NULL;
		}
		mStageVec[ti]->mUnitInfoVec.clear();

		delete mStageVec[ti];
		mStageVec[ti] = NULL;
	}
}

CStageInfo *CStageMgr::GetCurStageInfo()
{
	if (mCurStageIndex < mStageVec.size())
	{
		return mStageVec[mCurStageIndex];

	}
	else
	{
		return NULL;
	}
}

void CStageMgr::SetCurStageIndex(unsigned int tStageIndex)
{
	mCurStageIndex = tStageIndex;
}

