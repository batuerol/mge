#pragma once

#include <string>
#include <fstream>

namespace mge
{
	namespace utils
	{
		// TODO(batuhan): Temporary. Until platform layer is implemented.
		static std::string ReadFile(const std::string& fileName)
		{
			std::ifstream is(fileName, std::ios_base::in);
			if (!is.is_open())
			{
				// TODO(batuhan): File not found. Log
				return nullptr;
			}

			std::string line;
			std::string result;
			while(!is.eof())
			{
				std::getline(is, line);
				result.append(line + '\n');
			}

			is.close();

			return result;
		}
	}
}