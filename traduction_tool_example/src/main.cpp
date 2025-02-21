#include "bn_core.h"

#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_affine_bg_ptr.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "traduction_sprite_language_flags.hpp"
#include "traduction_regular_bg_language_flags_big_regular.hpp"
#include "traduction_affine_bg_language_flags_big_affine.hpp"
#include "traduction_languages.hpp"


void sprite_item_scene(bn::sprite_text_generator& text_generator) {
    constexpr bn::string_view info_text_lines[] = {
        "A: next flag",
        "",
        "START: go to next scene",
    };

    common::info info("Sprite item", info_text_lines, text_generator);

    traduction::languages language = traduction::languages::SPANISH;

    bn::sprite_item sprite_item = traduction::sprite_items::language_flags(language);

    bn::sprite_ptr sprite(sprite_item.create_sprite());

    while (!bn::keypad::start_pressed()) {

        if (bn::keypad::a_pressed()) {
            if (language == traduction::languages::SPANISH) {
                language = traduction::languages::ENGLISH;
            }
            else if (language == traduction::languages::ENGLISH) {
                language = traduction::languages::JAPANESE;
            }
            else if (language == traduction::languages::JAPANESE) {
                language = traduction::languages::SPANISH;
            }
            sprite_item = traduction::sprite_items::language_flags(language);
            sprite.set_item(sprite_item);
        }

        info.update();
        bn::core::update();
    }
}

void regular_bg_scene(bn::sprite_text_generator& text_generator) {
    constexpr bn::string_view info_text_lines[] = {
        "A: next flag",
        "",
        "START: go to next scene",
    };

    common::info info("Regular bg", info_text_lines, text_generator);

    traduction::languages language = traduction::languages::SPANISH;

    bn::regular_bg_item regular_bg_item = traduction::regular_bg_items::language_flags_big_regular(language);

    bn::regular_bg_ptr regular_bg(regular_bg_item.create_bg());

    while (!bn::keypad::start_pressed()) {

        if (bn::keypad::a_pressed()) {
            if (language == traduction::languages::SPANISH) {
                language = traduction::languages::ENGLISH;
            }
            else if (language == traduction::languages::ENGLISH) {
                language = traduction::languages::JAPANESE;
            }
            else if (language == traduction::languages::JAPANESE) {
                language = traduction::languages::SPANISH;
            }
            regular_bg_item = traduction::regular_bg_items::language_flags_big_regular(language);
            regular_bg.set_item(regular_bg_item);
        }

        info.update();
        bn::core::update();
    }
}

void affine_bg_scene(bn::sprite_text_generator& text_generator) {
    constexpr bn::string_view info_text_lines[] = {
        "A: next flag",
        "",
        "START: go to next scene",
    };

    common::info info("affine bg", info_text_lines, text_generator);

    traduction::languages language = traduction::languages::SPANISH;

    bn::affine_bg_item affine_bg_item = traduction::affine_bg_items::language_flags_big_affine(language);

    bn::affine_bg_ptr affine_bg(affine_bg_item.create_bg());
    affine_bg.set_rotation_angle_safe(45);
    affine_bg.set_wrapping_enabled(false);
    
    while (!bn::keypad::start_pressed()) {

        if (bn::keypad::a_pressed()) {
            if (language == traduction::languages::SPANISH) {
                language = traduction::languages::ENGLISH;
            }
            else if (language == traduction::languages::ENGLISH) {
                language = traduction::languages::JAPANESE;
            }
            else if (language == traduction::languages::JAPANESE) {
                language = traduction::languages::SPANISH;
            }
            affine_bg_item = traduction::affine_bg_items::language_flags_big_affine(language);
            affine_bg.set_item(affine_bg_item);
        }

        info.update();
        bn::core::update();
    }
}


int main() {
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);

    while (true) {
        sprite_item_scene(text_generator);
        bn::core::update();

        regular_bg_scene(text_generator);
        bn::core::update();

        affine_bg_scene(text_generator);
        bn::core::update();
    }
}
