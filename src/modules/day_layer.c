#include "day_layer.h"

static TextLayer *s_day_layer;
static GFont s_day_font;

TextLayer* dayLayerInit(GRect bounds) {
    // Create temperature Layer
    s_day_layer = text_layer_create(
        GRect(0, PBL_IF_ROUND_ELSE(125, 120), bounds.size.w, 50));

    // Create GFont
    s_day_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_GREATVIBES_28));

    // Style the text
    text_layer_set_background_color(s_day_layer, GColorClear);
    text_layer_set_text_color(s_day_layer, GColorBlack);
    text_layer_set_font(s_day_layer, s_day_font);
    text_layer_set_text_alignment(s_day_layer, GTextAlignmentCenter);

    return s_day_layer;
}

void dayLayerDeinit() {
    text_layer_destroy(s_day_layer);
    fonts_unload_custom_font(s_day_font);
}

void setDayText(char* s_day_buffer) {
    text_layer_set_text(s_day_layer, s_day_buffer);
}