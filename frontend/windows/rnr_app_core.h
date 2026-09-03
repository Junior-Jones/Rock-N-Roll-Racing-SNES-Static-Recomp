#ifndef RNR_APP_CORE_H
#define RNR_APP_CORE_H

#include "rnr_static_recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

int rnr_recomp_write_diagnostic_log(
    const RockNRollRacingRecomp *instance, const char *path,
    const char *screenshot_path, char *error, size_t error_capacity);
int rnr_recomp_append_diagnostic_log(
    const RockNRollRacingRecomp *instance, const char *path,
    const char *section_title, char *error, size_t error_capacity);

#ifdef __cplusplus
}
#endif
#endif
