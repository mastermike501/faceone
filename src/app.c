#include <pebble.h>

#include "windows/main_window.h"

static void init() {
    main_window_push();
    
    // Make sure the time is displayed from the start
    // update_time();
    
    // Register with TickTimerService
    // tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void deinit() {

}

int main(void) {
    init();
    app_event_loop();
    deinit();
}