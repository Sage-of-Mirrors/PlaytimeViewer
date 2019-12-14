#pragma once
#include <cstdint>

#include <vector>
#include <string>

struct PlaytimeRecord {
	uint32_t TimePlayed;
	uint64_t DatePlayed;
} __attribute__((packed));

struct AppRecord {
	uint64_t ApplicationID;
	std::string AppName;
	std::vector<PlaytimeRecord> PlayRecords;
};

class PlaytimeLogFile {
	std::vector<AppRecord> m_ApplicationRecords;
	
	void ReadLogFile(std::string file_name);
	void WriteLogFile(std::string file_name);
public:
	PlaytimeLogFile(std::string file_name);
	void SaveLogFile(std::string file_name);
	~PlaytimeLogFile();

	void DebugPrint();
};