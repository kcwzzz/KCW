#include "DataDriven.h"
#include <iostream>
#include "cocos2d.h"
#include "CActorStatus.h"
#include "CActorInfoList.h"

#include "rapidjson\document.h"
#include "rapidjson\reader.h"


using namespace std;
using namespace rapidjson;

DataDriven *DataDriven::mpInstance = NULL;

DataDriven *DataDriven::GetInstance()
{
	if (NULL == mpInstance)
	{
		mpInstance = new DataDriven();
		return mpInstance;
	}

	return mpInstance;
}

void DataDriven::CreateActor()
{
	CActorInfoList *tpActorInfoList = NULL;
	CActorStatus *tpActorStatus = NULL;
	Document tDocument;

	string tFileName = cocos2d::FileUtils::getInstance()->fullPathForFilename("data/ActorInfo.json");
	string clearData = cocos2d::FileUtils::getInstance()->getStringFromFile(tFileName);

	if (tDocument.Parse<0>(clearData.c_str()).HasParseError())
	{
		return;
	}

	const rapidjson::Value &tActorInfoList = tDocument["Actor_info"];

	for (SizeType i = 0; i < tActorInfoList.Size(); i++)
	{
		int tId = tActorInfoList[i].GetObject()["id"].GetInt();
		string tImageFileName = tActorInfoList[i].GetObject()["ImageFileName"].GetString();

		tpActorInfoList = NULL;
		tpActorInfoList = new CActorInfoList();
		tpActorInfoList->mId = tId;
		tpActorInfoList->mImageFileName = tImageFileName;

		const rapidjson::Value &tActorStatus = tActorInfoList[i].GetObject()["ActorStatus"];

		for (SizeType j = 0; j < tActorStatus.Size(); j++)
		{
			int tLevel = tActorStatus[j].GetObject()["Level"].GetInt();
			int tExp = tActorStatus[j].GetObject()["EXP"].GetInt();
			int tMaxHP = tActorStatus[j].GetObject()["MaxHP"].GetInt();
			int tAP = tActorStatus[j].GetObject()["Ap"].GetInt();
			int tSpeed = tActorStatus[j].GetObject()["Speed"].GetInt();
			int tSpeedRatio = tActorStatus[j].GetObject()["SpeedRatio"].GetInt();
	
			tpActorStatus = NULL;
			tpActorStatus = new CActorStatus();

			tpActorStatus->mLevel = tLevel;
			tpActorStatus->mExp = tExp;
			tpActorStatus->mMaxHP = tMaxHP;
			tpActorStatus->mAP = tAP;
			tpActorStatus->mSpeed = tSpeed;
			tpActorStatus->mSpeedRatio = tSpeedRatio;

			tpActorInfoList->mActorStatusVec.push_back(tpActorStatus);
		}
		mActorInfoListVec.push_back(tpActorInfoList);
	}
}

CActorInfoList* DataDriven::GetCurActorInfo()
{
	if (mCurActorIndex < mActorInfoListVec.size())
	{
		return mActorInfoListVec[mCurActorIndex];
	}
	else
	{
		return NULL;
	}
}

void DataDriven::SetCurActorInfo(unsigned int tActorInfo)
{
	mCurActorIndex = tActorInfo;
}