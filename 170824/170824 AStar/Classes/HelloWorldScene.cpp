#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(240.0f,
                            160.0f));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    //this->addChild(sprite, 0);
    
    
    
    
    srand(time(NULL));
    
    
    
    auto tBtnTest = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::OnClickBtnTest, this));
    
    tBtnTest->setPosition(Vec2(240.0f, 50.0f));
    
    auto tMenuTest = Menu::create(tBtnTest, NULL);
    tMenuTest->setPosition(Vec2::ZERO);
    this->addChild(tMenuTest, 100);
    
    
    
    
    
    
    
    //flood_fill
    ClearGrid();
    
    
    
    return true;
}


void HelloWorld::ClearGrid()
{
    int tRow = 0;
    int tCol = 0;
    for( tRow = 0; tRow <MAX_ROW; tRow++ )
    {
        for( tCol = 0; tCol <MAX_COL; tCol++ )
        {
            mGrid[tRow][tCol] = 0;
        }
    }
    
    
    
    for(int ti = 0; ti<MAX_COL; ti++)
    {
        mGrid[0][ti] = 2;
        
        mGrid[MAX_ROW - 1][ti] = 2;
    }
    
    for(int ti = 0; ti<MAX_ROW; ti++)
    {
        mGrid[ti][0] = 2;
        
        mGrid[ti][MAX_COL - 1] = 2;
    }
    
    
    
    /*
    for(int ti = 0; ti<MAX_COL; ti++)
    {
        mGrid[2][ti] = 2;
        
        mGrid[MAX_ROW - 1][ti] = 2;
    }
     */
}





//flood_fill
//FLOOD FILL 알고리즘을 사용하여 모든 격자를 채움.
void HelloWorld::DoFloodFillRecursive(int tCol, int tRow)
{

    if( 1 == mGrid[tRow][tCol] || 2 == mGrid[tRow][tCol] )
    {
        return;
    }
    else
    {
        mGrid[tRow][tCol] = 1;
        
        DoFloodFillRecursive( tCol - 1, tRow);
        DoFloodFillRecursive( tCol + 1, tRow);
        DoFloodFillRecursive( tCol, tRow - 1);
        DoFloodFillRecursive( tCol, tRow + 1);
    }
}


//여기서 스택 자료구조를 이용하는 이유는 무엇인가?
//
/*
    재귀호출 구조에서
    
    함수를 재귀적으로 호출하여 형성되는 반복구조는
    제어구조의 반복구조로
    
    함수의 매개변수들은
    스택에 담기는 데이터들로
 
    교체한 것이다.
    
    재귀호출 형태로 만들어진 것은
    '제어의 흐름'을 파악하는데 어려움이 크고
    또한 같은 맥락으로
    제어구조의 '형태를 변형'하는데 어려움이 크다.
*/

void HelloWorld::DoFloodFill(int tCol, int tRow)
{
    //clear stack
    while( false == mIntStack.empty() )
    {
        mIntStack.pop();
    }
    
    
    mIntStack.push(tCol);
    mIntStack.push(tRow);
    
    
    while( false == mIntStack.empty() )
    {
        //1개를 꺼낸다.
        tRow = mIntStack.top();
        mIntStack.pop();
        
        tCol = mIntStack.top();
        mIntStack.pop();
        
        //이미 다녀간 곳이거나 경계라면 아무것도 하지 않고 다음 것으로 넘어간다.
        if( 1 == mGrid[tRow][tCol] || 2 == mGrid[tRow][tCol] )
        {
            continue;
        }
        
        mGrid[tRow][tCol] = 1;
        
        
        
        
        //4개를 넣는다.
        mIntStack.push(tCol - 1 );
        mIntStack.push(tRow );
        
        mIntStack.push(tCol + 1 );
        mIntStack.push(tRow );
        
        mIntStack.push(tCol );
        mIntStack.push(tRow - 1 );
        
        mIntStack.push(tCol );
        mIntStack.push(tRow + 1 );
        
    }
}







void HelloWorld::DisplayGrid()
{
    int tRow = 0;
    int tCol = 0;
    
    //display grid
    log("=====");
    string tString = "";
    char tszTemp[1024];
    memset( tszTemp, 0, 1024 );
    
    for( tRow = 0; tRow<MAX_ROW; tRow++ )
    {
        for( tCol = 0; tCol<MAX_COL; tCol++ )
        {
            sprintf(tszTemp, "%d", mGrid[tRow][tCol]);
            
            tString = tString + tszTemp;
        }
        
        tString = tString + "\n";
    }
    
    label->setString(tString);
    
    
    
    int *tpPtr = &mGrid[0][0];
    for(int ti = 0; ti<MAX_ROW*MAX_COL; ti++)
    {
        log("%d", *(tpPtr + ti));
    }
}





//test
void HelloWorld::OnClickBtnTest(cocos2d::Ref* pSender)
{
    ClearGrid();
    
    //DoFloodFillRecursive(1, 1);
    DoFloodFill(1, 1);
    
    
    DisplayGrid();
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
}
