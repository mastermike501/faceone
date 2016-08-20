#include "workweek_layer.h"

static TextLayer *s_layer;
static char s_buffer[7];

TextLayer* workweekLayerInit(GRect bounds) {
    s_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(10, 0), bounds.size.w, 50));
    
    // Improve the layout to be more like a watchface
    text_layer_set_background_color(s_layer, GColorClear);
    text_layer_set_text_color(s_layer, GColorWhite);
    text_layer_set_text_alignment(s_layer, GTextAlignmentRight);
    text_layer_set_font(s_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));

    return s_layer;
}

void workweekLayerDeinit() {
    text_layer_destroy(s_layer);
}

void setWorkweekText(struct tm *time) {
    char buffer[3];
    int ww;
    strftime(s_buffer, sizeof(s_buffer), "ww%U.%u", time);

    //extract ww from string
    strncpy(buffer, s_buffer + 2, 2);
    buffer[2] = '\0';
    ww = atoi(buffer);
    //increment ww
    ww++;
    //place ww back in string
    snprintf(buffer, sizeof(buffer), "%i", ww);
    s_buffer[2] = buffer[0];
    s_buffer[3] = buffer[1];

    text_layer_set_text(s_layer, s_buffer);
}