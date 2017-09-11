#include "DataDriven.h"
#include <iostream>
#include "cocos2d.h"
#include "CActorStatus.h"
#include "CActorInfoList.h"
#include "CActorImage.h"
#include "CAttackImage.h"

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
	CActorImage *tpActorImage = NULL;
	CAttackImage *tpAttackImage = NULL;
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
		
		tpActorInfoList = NULL;
		tpActorInfoList = new CActorInfoList();
		tpActorInfoList->mId = tId;
		
		const rapidjson::Value &tActorStatus	= tActorInfoList[i].GetObject()["ActorStatus"];
		const rapidjson::Value &tActorImage		= tActorInfoList[i].GetObject()["ActorImage"];
		const rapidjson::Value &tAttackImage	= tActorInfoList[i].GetObject()["AttackImage"];
		
		for (SizeType j = 0; j < tActorStatus.Size(); j++)
		{
			int tLevel = tActorStatus[j].GetObject()["Level"].GetInt();
			int tExp = tActorStatus[j].GetObject()["EXP"].GetInt();
			int tMaxHP = tActorStatus[j].GetObject()["MaxHP"].GetInt();
			int tMaxSP = tActorStatus[j].GetObject()["MaxSP"].GetInt();
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
			tpActorStatus->mMaxSP = tMaxSP;

			tpActorInfoList->mActorStatusVec.push_back(tpActorStatus);
		}
		
		
		for (SizeType j = 0; j < tActorImage.Size(); j++)
		{
			
			string tImageFileName = tActorImage[j].GetObject()["ImageFileName"].GetString();
			int tImageSize_x = tActorImage[j].GetObject()["ImageSize_x"].GetInt();
			int tImageSize_y = tActorImage[j].GetObject()["ImageSize_y"].GetInt();
			float tSetDelay = tActorImage[j].GetObject()["SetDelay"].GetFloat();

			tpActorImage = NULL;
			tpActorImage =  new CActorImage();

			tpActorImage->mImageFileName = tImageFileName;
			tpActorImage->mImageSize_x = tImageSize_x;
			tpActorImage->mImageSize_y = tImageSize_y;
			tpActorImage->mSetDelay = tSetDelay;			

			tpActorInfoList->mActorImageVec.push_back(tpActorImage);
		}
		
		
		for (SizeType j = 0; j < tAttackImage.Size(); j++)
		{
			string tImageFileName = tAttackImage[j].GetObject()["ImageFileName"].GetString();
			int tImageSize_x = tAttackImage[j].GetObject()["ImageSize_x"].GetInt();
			int tImageSize_y = tAttackImage[j].GetObject()["ImageSize_y"].GetInt();
			float tSetDelay = tAttackImage[j].GetObject()["SetDelay"].GetFloat();
			int tSetImageCount = tAttackImage[j].GetObject()["SetImageCount"].GetInt();

			tpAttackImage = NULL;
			tpAttackImage = new CAttackImage();
			tpAttackImage->mImageFileName = tImageFileName;
			tpAttackImage->mImageSize_x = tImageSize_x;
			tpAttackImage->mImageSize_y = tImageSize_y;
			tpAttackImage->mSetDelay = tSetDelay;
			tpAttackImage->mSetImageCount = tSetImageCount;

			tpActorInfoList->mAttackImageVec.push_back(tpAttackImage);
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

