#include <.hpp>

#include <Geode/modify/CreatorLayer.hpp>
class $modify(CreatorLayerExt, CreatorLayer) {
    void later() {
		FMODAudioEngine::get()->playEffect(
            "grunt02.ogg", 0.5 + CCRANDOM_0_1(), CCRANDOM_0_1(), 1.0 + CCRANDOM_0_1()
        );
        if (CCRANDOM_0_1() > 0.5) onBack(this);
		if (CCRANDOM_0_1() > 0.5) Notification::create("hi its mirra!")->show();
		if (CCRANDOM_0_1() > 0.5) Notification::create("later.")->show();
		if (CCRANDOM_0_1() > 0.5) Notification::create("im not here yet")->show();
		if (CCRANDOM_0_1() > 0.5) Notification::create("please")->show();
		if (CCRANDOM_0_1() > 0.5) Notification::create("i come later")->show();
    }
    void onAdventureMap(cocos2d::CCObject * sender) {
        later();
    }
    void onMultiplayer(cocos2d::CCObject* sender) {
        later();
    }
};