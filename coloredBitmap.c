#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt', 'ko', 'mo', 'go'
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    float size = (float)(w * h * 3); // Base size in bytes

    if (strcmp(unit, "bt") == 0) {
        size *= 8; // Convert to bits
    } else if (strcmp(unit, "ko") == 0) {
        size /= 1024; // Convert to kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        size /= (1024 * 1024); // Convert to megabytes
    } else if (strcmp(unit, "go") == 0) {
        size /= (1024 * 1024 * 1024); // Convert to gigabytes
    }

    return size;
}
