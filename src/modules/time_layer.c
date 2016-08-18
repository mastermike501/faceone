#include "time_layer.h"

static TextLayer *s_time_layer;

TextLayer* timeLayerInit(GRect bounds) {
    s_time_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(58, 52), bounds.size.w, 50));
    
    // Improve the layout to be more like a watchface
    text_layer_set_background_color(s_time_layer, GColorClear);
    text_layer_set_text_color(s_time_layer, GColorBlack);
    text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS));
    text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

    return s_time_layer;
}

void timeLayerDeinit() {
    text_layer_destroy(s_time_layer);
}

void setTimeText(char* s_time_buffer) {
    text_layer_set_text(s_time_layer, s_time_buffer);
}