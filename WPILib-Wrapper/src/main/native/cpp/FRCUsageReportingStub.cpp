#include <stdint.h>
#include "hal/FRCUsageReporting.h"

int64_t HAL_Report(int32_t resource, int32_t instanceNumber,
                   int32_t context, const char* feature) {
    (void) resource;
    (void) instanceNumber;
    (void) context;
    (void) feature;
    return 0;                   
}