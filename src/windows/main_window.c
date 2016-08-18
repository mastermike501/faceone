#include "main_window.h"

static Window *s_main_window;

static void update_time() {
    // Get a tm structure
    time_t temp = time(NULL);
    struct tm *tick_time = localtime(&temp);
    static char s_time_buffer[6];
    static char s_day_buffer[10];

    // Set hours and mins onto layer
    strftime(s_time_buffer, sizeof(s_time_buffer), clock_is_24h_style() ?
                                            "%H:%M" : "%I:%M", tick_time);
    setTimeText(s_time_buffer);

    // Set day of the week onto later
    strftime(s_day_buffer, sizeof(s_day_buffer), "%A", tick_time);
    setDayText(s_day_buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
    update_time();
}

static void main_window_load(Window *window) {
    // Get information about the Window
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_bounds(window_layer);
    TextLayer *s_time_layer = timeLayerInit(bounds);
    TextLayer *s_day_layer = dayLayerInit(bounds);

    // Add it as a child layer to the Window's root layer
    layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
    layer_add_child(window_layer, text_layer_get_layer(s_day_layer));

    update_time();
    tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void main_window_unload(Window *window) {
    // Destroy time elements
    timeLayerDeinit();

    // Destroy weather elements
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
