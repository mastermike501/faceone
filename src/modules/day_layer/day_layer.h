#pragma once         // Prevent errors by being included multiple times

#include <pebble.h>  // Pebble SDK symbols

TextLayer* dayLayerInit(GRect bounds);

void dayLayerDeinit();

void setDayText(struct tm *time);