#include "time_layer.h"

static TextLayer *s_layer;
static char s_buffer[10];

TextLayer* timeLayerInit(GRect bounds) {
    s_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(38, 32), bounds.size.w, 50));
    
    // Improve the layout to be more like a watchface
    text_layer_set_background_color(s_layer, GColorClear);
    text_layer_set_text_color(s_layer, GColorWhite);
    text_layer_set_font(s_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
    text_layer_set_text_alignment(s_layer, GTextAlignmentCenter);

    return s_layer;
}

void timeLayerDeinit() {
    text_layer_destroy(s_layer);
}

void setTimeText(struct tm *time) {
    strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ?
                                            "%H:%M" : "%I:%M", time);
    text_layer_set_text(s_layer, s_buffer);
}