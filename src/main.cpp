#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GeoBRMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto bottomMenu = this->getChildByID("bottom-menu");
        if (!bottomMenu) {
            bottomMenu = this->getChildByID("main-menu");
        }

        auto spr = ButtonSprite::create("GeoBR", "goldFont.fnt", "GJ_button_01.png", .8f);
        auto btn = CCMenuItemSpriteExtra::create(
            spr,
            this,
            menu_selector(GeoBRMenuLayer::onGeoBRBtn)
        );
        btn->setID("geobr-button"_spr);

        if (bottomMenu) {
            bottomMenu->addChild(btn);
            bottomMenu->updateLayout();
        }

        return true;
    }

    void onGeoBRBtn(CCObject*) {
        createQuickPopup(
            "GeoBR GDPS",
            "Bem-vindo ao portal in-game da <cy>GeoBR</c>!",
            "Fechar", "Demon List",
            [](auto, bool btn2) {
                if (btn2) {
                    web::openHTML("https://geobrgdps.github.io/Testes/");
                }
            }
        );
    }
};
