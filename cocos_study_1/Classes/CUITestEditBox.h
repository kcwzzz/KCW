#pragma once


#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class CUITestEditBox
	:public cocos2d::LayerColor
	, public cocos2d::ui::EditBoxDelegate

{
private:
	cocos2d::ui::EditBox* mpEditName = NULL;
	cocos2d::ui::EditBox* mpEditPassword = NULL;
	cocos2d::ui::EditBox* mpEditEmail = NULL;

protected:
public:

	void OnClickBtnGoSceneTitle(Ref *pSender);

	virtual void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
	virtual void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
	virtual void editBoxTextChanged(cocos2d::ui::EditBox* editBox,const std::string& text);
	virtual void editBoxReturn(cocos2d::ui::EditBox* editBox);

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CUITestEditBox);
};