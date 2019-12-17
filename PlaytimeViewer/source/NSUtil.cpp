#include <iostream>
#include "NSUtil.h"

NsApplicationControlData* GetAppControlData(u64 app_id) {
	NsApplicationControlData* ctrl = new NsApplicationControlData();
	size_t ctrl_size = 0;

	Result rc = nsGetApplicationControlData(NsApplicationControlSource_Storage, app_id, ctrl, sizeof(NsApplicationControlData), &ctrl_size);

	if (R_FAILED(rc)) {
		delete ctrl;
		return nullptr;
	}

	return ctrl;
}

std::string GetAppName(u64 app_id) {
	NsApplicationControlData* appCtrl = GetAppControlData(app_id);
	NacpLanguageEntry* lang = nullptr;

	if (!appCtrl) {
		return "[Game control data not found.]";
	}

	Result rc = nacpGetLanguageEntry(&appCtrl->nacp, &lang);
	delete appCtrl;

	if (R_FAILED(rc) || !lang) {
		return "[Failed to get language data for game.]";
	}

	return lang->name;
}