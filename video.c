#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt', 'ko', 'mo', 'go'
// Return value
//   video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    float sizeMovie = (float)(w * h * 3 * fps * durationMovie); // Color section
    float sizeCredits = (float)(w * h * fps * durationCredits); // Black/White section
    float totalSize = sizeMovie + sizeCredits; // Total size in bytes

    if (strcmp(unit, "bt") == 0) {
        totalSize *= 8; // Convert to bits
    } else if (strcmp(unit, "ko") == 0) {
        totalSize /= 1024; // Convert to kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        totalSize /= (1024 * 1024); // Convert to megabytes
    } else if (strcmp(unit, "go") == 0) {
        totalSize /= (1024 * 1024 * 1024); // Convert to gigabytes
    }

    return totalSize;
}
