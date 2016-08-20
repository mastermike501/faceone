#include "battery_layer.h"

static Layer *s_layer;
static int s_battery_level;

static void battery_callback(BatteryChargeState state) {
    // Record the new battery level
    s_battery_level = state.charge_percent;

    // Update meter
    layer_mark_dirty(s_layer);
}

static void battery_update_proc(Layer *layer, GContext *ctx) {
    GRect bounds = layer_get_bounds(layer);

    // Find the width of the bar
    int width = (int)(float)(((float)s_battery_level / 100.0F) * 114.0F);

    // Draw the background
    graphics_context_set_fill_color(ctx, GColorBlack);
    graphics_fill_rect(ctx, bounds, 0, GCornerNone);

    // Draw the bar
    graphics_context_set_fill_color(ctx, GColorIslamicGreen);
    graphics_fill_rect(ctx, GRect(0, 0, width, bounds.size.h), 0, GCornerNone);
}

Layer* batteryLayerInit(GRect bounds) {
    battery_state_service_subscribe(battery_callback);
    
    s_layer = layer_create(GRect(0, 25, 115, 2));
    layer_set_update_proc(s_layer, battery_update_proc);

    battery_callback(battery_state_service_peek());

    // Style the text
    // text_layer_set_background_color(s_layer, GColorClear);
    // text_layer_set_text_color(s_layer, GColorWhite);
    // text_layer_set_font(s_layer, fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS));
    // text_layer_set_text_alignment(s_layer, GTextAlignmentCenter);

    return s_layer;
}

void batteryLayerDeinit() {
    layer_destroy(s_layer);
}