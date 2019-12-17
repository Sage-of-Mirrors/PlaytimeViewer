#include <time.h>

#include "TimeUtil.h"

std::string GetHoursMinutes(uint32_t length) {
	uint32_t minutes = length / 60;
	uint32_t hours = minutes / 60;

	char buf[64];
	sprintf(buf, "%02i:%02i", hours, minutes % 60);

	std::string str(buf);

	return str;
}

std::string GetDate(uint64_t unix) {
	struct tm* timeStruct = gmtime((const time_t*)&unix);

	char buf[100];
	sprintf(buf, "%i/%i/%i", timeStruct->tm_mon, timeStruct->tm_mday, timeStruct->tm_year + 1900);

	std::string str(buf);
	return str;
}