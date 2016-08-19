#include "date_layer.h"

static TextLayer *s_layer;
static char s_buffer[13];

TextLayer* dateLayerInit(GRect bounds) {
     // Create temperature Layer
    s_layer = text_layer_create(
        GRect(0, PBL_IF_ROUND_ELSE(15, 10), bounds.size.w / 2, 50));

    // Style the text
    text_layer_set_background_color(s_layer, GColorClear);
    text_layer_set_text_color(s_layer, GColorWhite);
    text_layer_set_text_alignment(s_layer, GTextAlignmentLeft);
    // text_layer_set_font(s_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));

    return s_layer;
}

void dateLayerDeinit() {
    text_layer_destroy(s_layer);
}

void setDateText(struct tm *time) {
    strftime(s_buffer, sizeof(s_buffer), "%d %b, %Y", time);
    text_layer_set_text(s_layer, s_buffer);
}