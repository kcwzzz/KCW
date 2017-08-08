#include "CUITestEditBox.h"

USING_NS_CC;


Scene* CUITestEditBox::createScene()
{
	auto scene = Scene::create();

	auto layer = CUITestEditBox::create();

	scene->addChild(layer);

	return scene;
}


bool CUITestEditBox::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto tBtnGoSceneTitle = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CUITestEditBox::OnClickBtnGoSceneTitle, this));

	tBtnGoSceneTitle->setPosition(Vec2(origin.x + visibleSize.width - tBtnGoSceneTitle->getContentSize().width / 2,
		origin.y + tBtnGoSceneTitle->getContentSize().height / 2));


	auto menu = Menu::create(tBtnGoSceneTitle,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	Size tSize = Size(300, 60);

	std::string tString = "extensions/Green_edit.png";
	mpEditName = ui::EditBox::create(tSize, ui::Scale9Sprite::create(tString));

	mpEditName->setPosition(Vec2(240, 250));
	mpEditName->setFontName("Paint Boy");
	mpEditName->setFontSize(25);
	mpEditName->setFontColor(Color3B::RED);
	mpEditName->setPlaceHolder("NAME");
	mpEditName->setPlaceholderFontColor(Color3B::WHITE);
	mpEditName->setMaxLength(8);

	mpEditName->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
	mpEditName->setDelegate(this);

	this->addChild(mpEditName);

	mpEditPassword = ui::EditBox::create(tSize, "extensions/orange_edit.png");

	mpEditPassword->setPosition(Vec2(240, 150));

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	mpEditPassword->setFont("American Typewriter", 30);
#else
	mpEditPassword->setFont("American Typewriter", 30);
	mpEditPassword->setPlaceholderFont("American Typewriter", 30);
#endif
	mpEditPassword->setFontColor(Color3B::GREEN);
	mpEditPassword->setPlaceHolder("Password:");
	mpEditPassword->setMaxLength(6);

	mpEditPassword->setInputFlag(ui::EditBox::InputFlag::PASSWORD);
	mpEditPassword->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);

	mpEditPassword->setDelegate(this);

	this->addChild(mpEditPassword);




	// bottom
	mpEditEmail = ui::EditBox::create(Size(tSize.width, tSize.height), "extensions/yellow_edit.png");

	mpEditEmail->setPosition(Vec2(240, 50));

	mpEditEmail->setPlaceHolder("Email:");

	mpEditEmail->setInputMode(ui::EditBox::InputMode::EMAIL_ADDRESS);

	mpEditEmail->setDelegate(this);

	this->addChild(mpEditEmail);


	return true;
}

void CUITestEditBox::editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)
{
	log("editBox %p DidBegin !", editBox);
}

void CUITestEditBox::editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)
{
	log("editBox %p DidEnd !", editBox);
}

void CUITestEditBox::editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text)
{
	log("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

void CUITestEditBox::editBoxReturn(ui::EditBox* editBox)
{
	log("editBox %p was returned !", editBox);
}

void CUITestEditBox::OnClickBtnGoSceneTitle(Ref *pSender)
{
	Director::getInstance()->popScene();
}
