#include "battery_layer.h"

static TextLayer *s_layer;

TextLayer* batteryLayerInit(GRect bounds) {
     // Create temperature Layer
    s_layer = text_layer_create(
        GRect(0, PBL_IF_ROUND_ELSE(125, 120), bounds.size.w, 50));

    // Style the text
    text_layer_set_background_color(s_layer, GColorClear);
    text_layer_set_text_color(s_layer, GColorWhite);
    text_layer_set_font(s_layer, fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS));
    text_layer_set_text_alignment(s_layer, GTextAlignmentCenter);

    return s_layer;
}

void batteryLayerDeinit() {
    text_layer_destroy(s_layer);
}

void setBatteryText(char* buffer) {
    text_layer_set_text(s_layer, buffer);
}