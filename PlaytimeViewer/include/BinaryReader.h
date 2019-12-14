#pragma once

#include <fstream>

class BinaryReader {
	std::fstream* m_FileStream;
public:
	BinaryReader(std::string file_name);
	~BinaryReader();

	std::string ReadString();

	template<typename T>
	T Read() {
		T temp;
		m_FileStream->read(reinterpret_cast<char*>(&temp), sizeof(temp));

		return temp;
	}
};