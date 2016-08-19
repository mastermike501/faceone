#include "main_window.h"

static Window *s_main_window;

static void update_time() {
    // Get a tm structure
    time_t temp = time(NULL);
    struct tm *tick_time = localtime(&temp);

    setDateText(tick_time);
    setWorkweekText(tick_time);
    setTimeText(tick_time);
    setDayText(tick_time);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
    update_time();
}

static void main_window_load(Window *window) {
    window_set_background_color(window, GColorBlack);

    // Get information about the Window
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_bounds(window_layer);

    TextLayer *s_date_layer = dateLayerInit(bounds);
    TextLayer *s_workweek_layer = workweekLayerInit(bounds);
    TextLayer *s_time_layer = timeLayerInit(bounds);
    TextLayer *s_day_layer = dayLayerInit(bounds);

    // Add it as a child layer to the Window's root layer
    layer_add_child(window_layer, text_layer_get_layer(s_date_layer));
    layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
    layer_add_child(window_layer, text_layer_get_layer(s_workweek_layer));
    layer_add_child(window_layer, text_layer_get_layer(s_day_layer));

    update_time();
    tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void main_window_unload(Window *window) {
    // Destroy time elements
    dateLayerDeinit();
    workweekLayerDeinit();
    timeLayerDeinit();
    dayLayerDeinit();

    window_destroy(s_main_window);
}


void main_window_push() {
    if(!s_main_window) {
        s_main_window = window_create();
        window_set_window_handlers(s_main_window, (WindowHandlers) {
            .load = main_window_load,
            .unload = main_window_unload,
        });
    }
    window_stack_push(s_main_window, true);
}
