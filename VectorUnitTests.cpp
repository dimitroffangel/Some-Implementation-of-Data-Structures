#include "VectorUnitTests.h"

#include <chrono>
#include <fstream>
#include <iostream>

std::vector<int> VectorUnitTests::AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::AddTest: ";
	outputFile << "VectorUnitTests::AddTest: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToAdd)
	{
		vectorList.push_back(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::RemoveTest: ";
	outputFile << "VectorUnitTests::RemoveTest: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToRemove)
	{
		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		vectorList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::GetTest: ";
	outputFile << "VectorUnitTests::GetTest: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToGet)
	{
		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		//vectorList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::AddRemoveImmediately: ";
	outputFile << "VectorUnitTests::AddRemoveImmediately: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		vectorList.push_back(elementToAdd);

		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		vectorList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::AddThenRemoveEverythingAdded: ";
	outputFile << "VectorUnitTests::AddThenRemoveEverythingAdded: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		vectorList.push_back(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		vectorList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::AddGet: ";
	outputFile << "VectorUnitTests::AddGet: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		vectorList.push_back(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		//vectorList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::AddGetImmediately: ";
	outputFile << "VectorUnitTests::AddGetImmediately: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		vectorList.push_back(elementToAdd);

		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		//vectorList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::RemoveGet: ";
	outputFile << "VectorUnitTests::RemoveGet: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		//vectorList.Contains(elementToAdd);

		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);
		it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		vectorList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;

}

std::vector<int> VectorUnitTests::RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "VectorUnitTests::RemoveThenAddEverythingRemoved: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		vectorList.erase(it);

		vectorList.push_back(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "VectorUnitTests::RemoveThenAddEverythingRemoved: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		vectorList.erase(it);
	}

	for (const int elementToAdd : inputContainer)
	{
		vectorList.push_back(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}

std::vector<int> VectorUnitTests::AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "VectorUnitTests::AddRemoveGet: ";
	outputFile << "VectorUnitTests::AddRemoveGet: ";

	std::vector<int> vectorList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		vectorList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		vectorList.push_back(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		//vectorList.Contains(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		std::vector<int>::iterator it = std::find(vectorList.begin(), vectorList.end(), elementToAdd);

		if (it == vectorList.end())
		{
			continue;
		}

		vectorList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return vectorList;
}
