//
//  CStageInfo.hpp
//  cocos_study_2
//
//  Created by YangBruce on 2017. 1. 24..
//
//

#ifndef CStageInfo_hpp
#define CStageInfo_hpp

#include <stdio.h>

#include <vector>

class CUnitInfo;

typedef std::vector<CUnitInfo *> CUnitInfoVec;

class CStageInfo
{
public:
    unsigned int mId = 0;
    
    unsigned int mTotalEnemyCount = 0;
    
    CUnitInfoVec mUnitInfoVec;
};


#endif /* CStageInfo_hpp */
