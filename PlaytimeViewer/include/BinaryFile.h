#pragma once
#include <fstream>

class BinaryFile {
	std::fstream* m_FileStream;
public:
	BinaryFile(std::string file_name);
	~BinaryFile();

	std::string ReadString();
	void WriteString(std::string str);

	template<typename T>
	T Read() {
		T temp;
		m_FileStream->read(reinterpret_cast<char*>(&temp), sizeof(temp));

		return temp;
	}

	template<typename T>
	void Write(T data) {
		m_FileStream->write(reinterpret_cast<char*>(&data), sizeof(data));
	}
};