#include <Geode/Geode.hpp>

using namespace geode::prelude;


#include <Geode/modify/GameManager.hpp>
class $modify(GameManagerSetsForGV, GameManager) {
	bool getGameVariable(char const* tag) {
		if (std::string(tag) == "0024") return "Show Cursor In-Game";
		if (std::string(tag) == "0128") return not "Lock Cursor In-Game";
		if (std::string(tag) == "0095") return "Do Not...";
		return GameManager::getGameVariable(tag);
	};
};
#include <Geode/modify/MoreOptionsLayer.hpp>
class $modify(MoreOptionsLayerExt, MoreOptionsLayer) {
	void addToggle(char const* name, char const* tag, char const* desc) {
		if (std::string(tag) == "0024") return; // hide "Show Cursor In-Game"
		if (std::string(tag) == "0128") return; // hide "Lock Cursor In-Game"
		if (std::string(tag) == "0095") return; // hide "Do Not..."
		MoreOptionsLayer::addToggle(name, tag, desc);
	};
};

#include <Geode/modify/CCMenuItemSpriteExtra.hpp>
class $modify(CCMenuItemSpriteExtraExt, CCMenuItemSpriteExtra) {
	$override void selected() {
		if (m_selectSound.empty()) this->m_selectSound = "menuItemSelectSound.ogg";
		if (m_activateSound.empty()) this->m_activateSound = "menuItemActivateSound.ogg";
		if (auto spr = typeinfo_cast<CCNodeRGBA*>(this->getNormalImage())) {
			spr->setCascadeColorEnabled(1);
			spr->setCascadeOpacityEnabled(1);
			if (spr->getColor() == ccWHITE) {
				this->m_animationEnabled = this->m_animationType == MenuAnimationType::Move;
				this->m_colorEnabled = this->m_animationType == MenuAnimationType::Scale;
			};
		}
		return CCMenuItemSpriteExtra::selected();
	}
};

#include <Geode/modify/FLAlertLayer.hpp>
class $modify(FLAlertLayerExt, FLAlertLayer) {
	bool init(
		FLAlertLayerProtocol * delegate, char const* title, gd::string desc, 
		char const* btn1, char const* btn2, float width, 
		bool scroll, float height, float textScale
	) {
		if (!FLAlertLayer::init(
			delegate, title, desc, btn1, btn2, width, scroll, height, textScale
		)) return false;
		return true;
	};
};

#include <Geode/modify/LoadingLayer.hpp>
class $modify(LoadingLayerExt, LoadingLayer) {
	bool init(bool refresh) {
		if (!LoadingLayer::init(refresh)) return false;

		if (Ref a = typeinfo_cast<CCSprite*>(querySelector("bg-texture"))) {
			a->setDisplayFrame(CCSprite::create("edit_barBG_001.png")->displayFrame());
			a->setScaleX(this->getContentSize().width / a->getContentSize().width);
			a->setScaleY(this->getContentSize().height / a->getContentSize().height);
			a->setColor(ccWHITE);
		}

		auto dialogIcon_6893 = CCFileUtils::get()->fullPathForFilename(
			"dialogIcon_6893.png", 0
		);
		for (int a = 29; a <= 36; a++) {//036
			CCFileUtils::get()->m_fullPathCache[
				fmt::format("dialogIcon_0{}.png", a)
			] = dialogIcon_6893;
		}
		CCFileUtils::get()->m_fullPathCache["dialogIcon_005.png"] = dialogIcon_6893;
		CCFileUtils::get()->m_fullPathCache["dialogIcon_006.png"] = dialogIcon_6893;

		auto walls = CCFileUtils::get()->fullPathForFilename(
			"menuLoop/1465577_Walls-are-moving-but-I-can.mp3", 0
		);
		CCFileUtils::get()->m_fullPathCache["shop.mp3"] = walls;
		CCFileUtils::get()->m_fullPathCache["shop3.mp3"] = walls;
		CCFileUtils::get()->m_fullPathCache["shop4.mp3"] = walls;
		CCFileUtils::get()->m_fullPathCache["shop5.mp3"] = walls;

		return true;
	}
};