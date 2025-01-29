#pragma once

#include "stddef.h"

#ifdef __cplusplus

#define scexpr static constexpr
#include <cstdint>

#define HALT asm("csrrw zero, mstatus, zero");
#endif