#include "day_layer.h"

static TextLayer *s_layer;
static GFont s_font;
static char s_buffer[10];

TextLayer* dayLayerInit(GRect bounds) {
    // Create temperature Layer
    s_layer = text_layer_create(
        GRect(0, PBL_IF_ROUND_ELSE(85, 80), bounds.size.w, 50));

    // Create GFont
    s_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_GREATVIBES_28));

    // Style the text
    text_layer_set_background_color(s_layer, GColorClear);
    text_layer_set_text_color(s_layer, GColorWhite);
    text_layer_set_font(s_layer, s_font);
    text_layer_set_text_alignment(s_layer, GTextAlignmentCenter);

    return s_layer;
}

void dayLayerDeinit() {
    text_layer_destroy(s_layer);
    fonts_unload_custom_font(s_font);
}

void setDayText(struct tm *time) {
    strftime(s_buffer, sizeof(s_buffer), "%A", time);
    text_layer_set_text(s_layer, s_buffer);
}