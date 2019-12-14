#include "PlaytimeRecords.h"
#include "BinaryReader.h"

PlaytimeLogFile::PlaytimeLogFile(std::string file_name) {
	ReadLogFile(file_name);
	DebugPrint();
}

void PlaytimeLogFile::SaveLogFile(std::string file_name) {
	WriteLogFile(file_name);
}

void PlaytimeLogFile::ReadLogFile(std::string file_name) {
	BinaryReader reader(file_name);

	uint32_t num_apps = reader.Read<uint32_t>();

	for (uint32_t i = 0; i < num_apps; i++) {
		AppRecord app_rec{ reader.Read<uint64_t>() }; // Grab the appID from the log file

		uint32_t num_records = reader.Read<uint32_t>();
		for (uint32_t j = 0; j < num_records; j++) {
			PlaytimeRecord rec = reader.Read<PlaytimeRecord>(); // Read in a log

			app_rec.PlayRecords.push_back(rec);
		}

		m_ApplicationRecords.push_back(app_rec);
	}
}

void PlaytimeLogFile::WriteLogFile(std::string file_name) {
	std::fstream log(file_name, std::ios::out | std::ios::binary);



	log.close();
}

void PlaytimeLogFile::DebugPrint() {
	size_t num_apps = m_ApplicationRecords.size();

	printf("Debug printing log file...\n");
	printf("Number of apps logged: %ld\n", num_apps);

	for (size_t i = 0; i < num_apps; i++) {
		size_t num_logs = m_ApplicationRecords[i].PlayRecords.size();

		printf("Recursing app #%ld (ID %lX):\n", i, m_ApplicationRecords[i].ApplicationID);
		printf("\tNumber of logs for app: %ld\n", num_logs);

		for (size_t j = 0; j < num_logs; j++) {
			printf("\tLog #%ld:\n", j);
			printf("\t\tPlaytime: %u\n", m_ApplicationRecords[i].PlayRecords[j].TimePlayed);
			printf("\t\tDate played: %lu\n", m_ApplicationRecords[i].PlayRecords[j].DatePlayed);
		}
	}
}

PlaytimeLogFile::~PlaytimeLogFile() {
	m_ApplicationRecords.clear();
}