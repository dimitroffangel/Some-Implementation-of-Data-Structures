#include "SkipListUnitTests.h"

#include <chrono>
#include <fstream>

SkipList<int> SkipListUnitTests::AddTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::AddTest: ";
	outputFile << "SkipListUnitTests::AddTest: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::RemoveTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::RemoveTest: ";
	outputFile << "SkipListUnitTests::RemoveTest: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::GetTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::GetTest: ";
	outputFile << "SkipListUnitTests::GetTest: ";

	SkipList<int> skipList(probability);

	for (const int elementToHave : elementsToHaveInitially)
	{
		skipList.Add(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToGet)
	{
		skipList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return skipList;
}

SkipList<int> SkipListUnitTests::AddRemoveImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::AddRemoveImmediately: ";
	outputFile << "SkipListUnitTests::AddRemoveImmediately: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::AddThenRemoveEverythingAdded(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::AddThenRemoveEverythingAdded: ";
	outputFile << "SkipListUnitTests::AddThenRemoveEverythingAdded: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::AddGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::AddGet: ";
	outputFile << "SkipListUnitTests::AddGet: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::AddGetImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::AddGetImmediately: ";
	outputFile << "SkipListUnitTests::AddGetImmediately: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::RemoveGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::RemoveGet: ";
	outputFile << "SkipListUnitTests::RemoveGet: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::RemoveAddImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "SkipListUnitTests::RemoveThenAddEverythingRemoved: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::RemoveThenAddEverythingRemoved(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "SkipListUnitTests::RemoveThenAddEverythingRemoved: ";

	SkipList<int> skipList(probability);

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

SkipList<int> SkipListUnitTests::AddRemoveGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "SkipListUnitTests::AddRemoveGet: ";
	outputFile << "SkipListUnitTests::AddRemoveGet: ";

	SkipList<int> skipList(probability);

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
