#pragma once

#include <switch.h>
#include <string>

NsApplicationControlData* GetAppControlData(uint64_t app_id);
std::string GetAppName(uint64_t app_id);