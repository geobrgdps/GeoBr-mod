#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GeoBRMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Procura pelo menu de botões da tela inicial
        auto bottomMenu = this->getChildByID("bottom-menu");
        if (!bottomMenu) {
            bottomMenu = this->getChildByID("main-menu");
        }

        // Criar o botão da GeoBR
        auto spr = CircleButtonSprite::createWithSpriteFrameName(
            "geode.loader/geode-logo.png", // Ícone temporário do Geode
            0.85f,
            CircleBaseColor::Green,
            CircleBaseSize::Medium
        );

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
        // Pop-up ao clicar no botão
        createQuickPopup(
            "GeoBR GDPS",
            "Bem-vindo ao portal in-game da <cy>GeoBR</c>!\nEscolha uma das opcoes abaixo:",
            "Discord", "Demon List",
            [](auto, bool btn2) {
                if (btn2) {
                    // Abre o site da Demon List que criamos
                    web::openHTML("https://luizcxoinavile-hash.github.io/Testes/");
                } else {
                    // Abre o Discord da GeoBR
                    web::openHTML("https://discord.gg/sdYx74wG9");
                }
            }
        );
    }
};
