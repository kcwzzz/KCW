//
//  CPlayInfo.hpp
//  cocos_study_1
//
//  Created by YangBruce on 2017. 1. 18..
//
//

#ifndef CPlayInfo_hpp
#define CPlayInfo_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

/*
 created by pokpoongryu
 
 별다른 기능(함수로 표현)은 없고, 데이터만 있는 
 
 데이터클래스.
 */
class CPlayInfo
{
public:
    std::string mName           = "";
    
    unsigned int mScore         = 0;
    
    float mX                    = 0.0f;
    float mY                    = 0.0f;
    
    //생성자,소멸자 명시적으로 안써주면 암묵적으로 컴파일러가 기본 생성자, 소멸자 생성해줌.
};

#endif /* CPlayInfo_hpp */
