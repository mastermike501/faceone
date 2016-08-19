#pragma once         // Prevent errors by being included multiple times

#include <pebble.h>  // Pebble SDK symbols

TextLayer* dateLayerInit(GRect bounds);

void dateLayerDeinit();

void setDateText(struct tm *time);