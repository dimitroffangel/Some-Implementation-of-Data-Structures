#include "LinkedListUnitTests.h"

#include <chrono>
#include <fstream>
#include <iostream>

std::list<int> LinkedListUnitTests::AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::AddTest: ";
	outputFile << "LinkedListUnitTests::AddTest: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToAdd)
	{
		linkedList.push_back(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::RemoveTest: ";
	outputFile << "LinkedListUnitTests::RemoveTest: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToRemove)
	{
		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		linkedList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::GetTest: ";
	outputFile << "LinkedListUnitTests::GetTest: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToGet)
	{
		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		//linkedList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::AddRemoveImmediately: ";
	outputFile << "LinkedListUnitTests::AddRemoveImmediately: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.push_back(elementToAdd);

		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		linkedList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::AddThenRemoveEverythingAdded: ";
	outputFile << "LinkedListUnitTests::AddThenRemoveEverythingAdded: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.push_back(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		linkedList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::AddGet: ";
	outputFile << "LinkedListUnitTests::AddGet: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.push_back(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		//linkedList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::AddGetImmediately: ";
	outputFile << "LinkedListUnitTests::AddGetImmediately: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.push_back(elementToAdd);

		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		//linkedList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::RemoveGet: ";
	outputFile << "LinkedListUnitTests::RemoveGet: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		//linkedList.Contains(elementToAdd);

		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);
		it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		linkedList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;

}

std::list<int> LinkedListUnitTests::RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "LinkedListUnitTests::RemoveThenAddEverythingRemoved: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		linkedList.erase(it);

		linkedList.push_back(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "LinkedListUnitTests::RemoveThenAddEverythingRemoved: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		linkedList.erase(it);
	}

	for (const int elementToAdd : inputContainer)
	{
		linkedList.push_back(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

std::list<int> LinkedListUnitTests::AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "LinkedListUnitTests::AddRemoveGet: ";
	outputFile << "LinkedListUnitTests::AddRemoveGet: ";

	std::list<int> linkedList(50);

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.push_back(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.push_back(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		//linkedList.Contains(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		std::list<int>::iterator it = std::find(linkedList.begin(), linkedList.end(), elementToAdd);

		if (it == linkedList.end())
		{
			continue;
		}

		linkedList.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}
