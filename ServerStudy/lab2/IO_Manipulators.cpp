#include "IO_Manipulators.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <cassert>
#include <numeric>
#include <iomanip>

namespace lab2
{
	void Test()
	{
		{
			std::ifstream in("C:\\Users\\user\\source\\repos\\ServerStudy\\ServerStudy\\lab2\\test.txt");
			if (in.is_open())
			{
				std::cout << "PrintIntegers\n";

				lab2::PrintIntegers(in, std::cout);
				// lab2::PrintIntegersTeacher(in, std::cout);

				std::cout << '\n';
			}
			else
			{
				std::cout << "파일을 찾을 수 없습니다!!" << std::endl;
			}
		}

		{
			std::ifstream in("C:\\Users\\user\\source\\repos\\ServerStudy\\ServerStudy\\lab2\\test2.txt");
			if (in.is_open())
			{
				std::cout << "PrintMaxFloat\n";

				PrintMaxFloat(in, std::cout);
			}
			else
			{
				std::cout << "파일을 찾을 수 없습니다!" << std::endl;
			}
		}
	}

	namespace internal
	{
		void parseFloat(const int value,
			bool& isStart,
			bool& hasDot,
			std::string& numberBuffer,
			std::vector<float>& numberList)
		{
			const bool isDigit = (0 != std::isdigit(value));
			if ('-' == value)
			{
				if (true == isStart)
				{
					assert(0 && "비정상적인 형식입니다.");
				}
				else
				{
					isStart = true;
					numberBuffer.push_back(value);
				}
			}
			else if ('.' == value)
			{
				if (false == isStart)
				{
					assert(0 && "비정상적인 형식입니다.");
				}
				else
				{
					if (true == hasDot)
					{
						assert(0 && "비정상적인 형식입니다.");
					}
					else
					{
						hasDot = true;
						numberBuffer.push_back(value);
					}
				}
			}
			else if (true == isDigit)
			{
				assert((static_cast<int>(std::numeric_limits<char>::min()) <= value)
					&& (static_cast<int>(std::numeric_limits<char>::max()) >= value));

				isStart = true;
				numberBuffer.push_back(static_cast<char>(value));
			}
			else
			{
				if (true == isStart)
				{
					const float number = std::stof(numberBuffer);
					numberList.push_back(number);

					isStart = false;
					hasDot = false;
					numberBuffer.clear();
				}
			}
		}

		void printFloat(std::ostream& out, const std::string& prefix, const float number)
		{
			out << std::setw(5) << std::setfill(' ') << std::left
				<< prefix

				<< ((number >= 0.0f) ? '+' : '-')

				<< std::setw(14) << std::setfill(' ') << std::right
				<< std::fixed << std::setprecision(3)
				<< std::abs(number) << '\n';
		};
	} // namespace internal

	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		std::string numberBuffer;
		std::vector<int> numberList;

		while (false == in.eof())
		{
			const int	value = in.get();
			const bool	isStartNumber = (false == numberBuffer.empty());
			const bool	isDigit = (0 != std::isdigit(value));
			if (true == isDigit)
			{
				assert((static_cast<int>(std::numeric_limits<char>::min()) <= value)
					&& (static_cast<int>(std::numeric_limits<char>::max()) >= value));

				numberBuffer.push_back(static_cast<char>(value));
			}
			else
			{
				if (true == isStartNumber)
				{
					const int number = std::stoi(numberBuffer);
					numberList.push_back(number);
					numberBuffer.clear();
				}
			}
		}

		const int octWidth = 9;
		const int decWidth = 8;
		const int hexWidth = 7;

		out << std::setw(octWidth) << std::setfill(' ') << "oct "
			<< std::setw(decWidth) << std::setfill(' ') << "dec "
			<< std::setw(hexWidth - 1) << std::setfill(' ') << "hex"
			<< '\n'

			<< std::setw(octWidth) << std::setfill('-') << ' '
			<< std::setw(decWidth) << std::setfill('-') << ' '
			<< std::setw(hexWidth) << std::setfill('-') << ' '
			<< '\n';

		for (int number : numberList)
		{
			out << std::setw(octWidth - 1) << std::setfill(' ') << std::oct << number << ' '
				<< std::setw(decWidth - 1) << std::setfill(' ') << std::dec << number << ' '
				<< std::setw(hexWidth - 1) << std::setfill(' ') << std::hex << number << '\n';
		}
	}

	void PrintIntegersTeacher(std::istream& in, std::ostream& out)
	{
		int number = 0;
		std::string trash;
		while (false == in.eof())
		{
			in >> number;
			if (true == in.fail())
			{
				in.clear();
				in >> trash;
			}

			// TODO: 구현해보세요
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		bool isStart = false;
		bool hasDot = false;

		std::string numberBuffer;
		std::vector<float> numberList;

		while (false == in.eof())
		{
			const int value = in.get();
			internal::parseFloat(value, isStart, hasDot, numberBuffer, numberList);
		}

		float max = std::numeric_limits<float>::min();
		for (float number : numberList)
		{
			if (max <= number)
			{
				max = number;
			}
		}

		for (float number : numberList)
		{
			internal::printFloat(out, " ", number);
		}

		internal::printFloat(out, "max:", max);
	}
} // namespace lab2