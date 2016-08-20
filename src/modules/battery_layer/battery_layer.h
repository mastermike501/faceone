#pragma once         // Prevent errors by being included multiple times

#include <pebble.h>  // Pebble SDK symbols

Layer* batteryLayerInit(GRect bounds);

void batteryLayerDeinit();