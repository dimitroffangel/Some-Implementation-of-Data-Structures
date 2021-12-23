#include "SkipListOriginalUnitTests.h"

#include <chrono>
#include <fstream>
#include <iostream>

SkipListOriginal<int> SkipListOriginalUnitTests::AddTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::AddTest: ";
	outputFile << "SkipListOriginalUnitTests::AddTest: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToAdd)
	{
		skipList.Add(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::RemoveTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::RemoveTest: ";
	outputFile << "SkipListOriginalUnitTests::RemoveTest: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToRemove)
	{
		skipList.Delete(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::GetTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::GetTest: ";
	outputFile << "SkipListOriginalUnitTests::GetTest: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToGet)
	{
		bool res = skipList.Contains(elementToAdd);
		int a = 42;
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::AddRemoveImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::AddRemoveImmediately: ";
	outputFile << "SkipListOriginalUnitTests::AddRemoveImmediately: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Add(elementToAdd);
		skipList.Delete(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::AddThenRemoveEverythingAdded(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::AddThenRemoveEverythingAdded: ";
	outputFile << "SkipListOriginalUnitTests::AddThenRemoveEverythingAdded: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Add(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		skipList.Delete(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::AddGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::AddGet: ";
	outputFile << "SkipListOriginalUnitTests::AddGet: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Add(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		skipList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::AddGetImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::AddGetImmediately: ";
	outputFile << "SkipListOriginalUnitTests::AddGetImmediately: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Add(elementToAdd);
		skipList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::RemoveGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::RemoveGet: ";
	outputFile << "SkipListOriginalUnitTests::RemoveGet: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Contains(elementToAdd);
		skipList.Delete(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;

}

SkipListOriginal<int> SkipListOriginalUnitTests::RemoveAddImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "SkipListOriginalUnitTests::RemoveThenAddEverythingRemoved: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Delete(elementToAdd);
		skipList.Add(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::RemoveThenAddEverythingRemoved(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "SkipListOriginalUnitTests::RemoveThenAddEverythingRemoved: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Delete(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		skipList.Add(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipListOriginal<int> SkipListOriginalUnitTests::AddRemoveGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListOriginalUnitTests::AddRemoveGet: ";
	outputFile << "SkipListOriginalUnitTests::AddRemoveGet: ";

	SkipListOriginal<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		skipList.Add(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		skipList.Contains(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		skipList.Delete(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}
