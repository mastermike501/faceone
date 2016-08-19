#pragma once         // Prevent errors by being included multiple times

#include <pebble.h>  // Pebble SDK symbols

TextLayer* batteryLayerInit(GRect bounds);

void batteryLayerDeinit();

void setBatteryText(char*);