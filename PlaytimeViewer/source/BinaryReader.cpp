#include "BinaryReader.h"

BinaryReader::BinaryReader(std::string file_name) {
	m_FileStream = new std::fstream(file_name, std::ios::in | std::ios::binary);
}

BinaryReader::~BinaryReader() {
	m_FileStream->close();
	delete m_FileStream;
}

std::string BinaryReader::ReadString() {
	return "";
}