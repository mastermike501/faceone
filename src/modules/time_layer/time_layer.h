#pragma once         // Prevent errors by being included multiple times

#include <pebble.h>  // Pebble SDK symbols

TextLayer* timeLayerInit(GRect bounds);

void timeLayerDeinit();

void setTimeText(struct tm *time);