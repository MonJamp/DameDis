#include "Cartridge.h"
#include <fstream>

Cartridge::Cartridge()
{
	for (uint32_t i = 0; i < ROM_MAX_SIZE; i++)
	{
		rom[i] = 0x00;
	}
}

Cartridge::~Cartridge()
{

}

// TODO: Check validity of cartridge
void Cartridge::open(const char* filename)
{
	std::ifstream file;
	file.open(filename, std::ios::binary);

	file.seekg(0, file.end);
	size_t fileSize = static_cast<size_t>(file.tellg());
	file.seekg(0, file.beg);

	file.read((char*)(&rom[0]), fileSize);

	file.close();
}

uint8_t Cartridge::read(const uint16_t& address)
{
	return rom[address];
}