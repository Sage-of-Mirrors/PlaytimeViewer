#include "BinaryFile.h"

BinaryFile::BinaryFile(std::string file_name) {
	m_FileStream = new std::fstream(file_name, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
}

BinaryFile::~BinaryFile() {
	m_FileStream->flush();
	m_FileStream->close();
	delete m_FileStream;
}

std::string BinaryFile::ReadString() {
	return "";
}

void BinaryFile::WriteString(std::string str) {

}