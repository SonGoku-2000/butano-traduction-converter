#include "bn_core.h"

#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "traduction_sprite_language_flags.hpp"
#include "traduction_languages.hpp"


void sprite_item_scene(bn::sprite_text_generator& text_generator) {
    constexpr bn::string_view info_text_lines[] = {
        "A: next language",
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

int main() {
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);

    while (true) {
        sprite_item_scene(text_generator);
        bn::core::update();
    }
}
