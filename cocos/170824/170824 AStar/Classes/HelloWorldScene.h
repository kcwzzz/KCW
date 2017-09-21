#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include <list>

using namespace std;


#define MAX_ROW 6
#define MAX_COL 6

typedef stack<int> CIntStack;


class HelloWorld : public cocos2d::Scene
{
//test
private:
    cocos2d::Label *label = NULL;
    

    int mGrid[MAX_ROW][MAX_COL];
    
    CIntStack mIntStack;
    
    
public:
    void OnClickBtnTest(cocos2d::Ref* pSender);
    
    void ClearGrid();
    void DisplayGrid();
    
    
    void DoFloodFillRecursive(int tCol, int tRow);
    void DoFloodFill(int tCol, int tRow);
    
        
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
