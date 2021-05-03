#pragma once

#ifndef SOLAR_CORE_H_
#define SOLAR_CORE_H_

#define SOLAR_API __declspec(dllexport)

// Default window width and height
// If no width and height is set by user
#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

// Default window title
// When no title is set by user
#define DEFAULT_TITLE "Solar System"

// Default boolean values for window
#define DEFAULT_RESIZABLE false
#define DEFAULT_FOCUSED true
#define DEFAULT_MAXIMIZED false
#define DEFAULT_VISIBLE true
#define DEFAULT_DECORATED true
#define DEFAULT_FLOATING false
#define DEFAULT_POSITION_X 0
#define DEFAULT_POSITION_Y 0

#endif // !SOLAR_CORE_H_