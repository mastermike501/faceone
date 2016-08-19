#pragma once         // Prevent errors by being included multiple times

#include <pebble.h>  // Pebble SDK symbols
#include <string.h>

TextLayer* workweekLayerInit(GRect bounds);

void workweekLayerDeinit();

void setWorkweekText(struct tm *time);