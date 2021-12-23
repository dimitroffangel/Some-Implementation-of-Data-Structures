#include "XORListUnitTests.h"

#include <chrono>
#include <fstream>
#include <iostream>


XORList<int> XORListUnitTests::AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::AddTest: ";
	outputFile << "XORListUnitTests::AddTest: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToAdd)
	{
		linkedList.Append(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::RemoveTest: ";
	outputFile << "XORListUnitTests::RemoveTest: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToRemove)
	{
		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{
			linkedList.DeleteNode(node);
		}

	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::GetTest: ";
	outputFile << "XORListUnitTests::GetTest: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToGet)
	{
		//linkedList.Contains(elementToAdd);
		linkedList.GetNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::AddRemoveImmediately: ";
	outputFile << "XORListUnitTests::AddRemoveImmediately: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.Append(elementToAdd);

		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{
			linkedList.DeleteNode(node);
		}
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::AddThenRemoveEverythingAdded: ";
	outputFile << "XORListUnitTests::AddThenRemoveEverythingAdded: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.Append(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{
			linkedList.DeleteNode(node);
		}
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::AddGet: ";
	outputFile << "XORListUnitTests::AddGet: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.Append(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		auto node = linkedList.GetNode(elementToAdd);


		//linkedList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::AddGetImmediately: ";
	outputFile << "XORListUnitTests::AddGetImmediately: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.Append(elementToAdd);

		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{

		}

		//linkedList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::RemoveGet: ";
	outputFile << "XORListUnitTests::RemoveGet: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		//linkedList.Contains(elementToAdd);

		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{
			linkedList.DeleteNode(node);
		}
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;

}

XORList<int> XORListUnitTests::RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "XORListUnitTests::RemoveThenAddEverythingRemoved: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{
			linkedList.DeleteNode(node);
		}

		linkedList.Append(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "XORListUnitTests::RemoveThenAddEverythingRemoved: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{
			linkedList.DeleteNode(node);
		}
	}

	for (const int elementToAdd : inputContainer)
	{
		linkedList.Append(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

XORList<int> XORListUnitTests::AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "XORListUnitTests::AddRemoveGet: ";
	outputFile << "XORListUnitTests::AddRemoveGet: ";

	XORList<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.Append(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.Append(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{

		}

		//linkedList.Contains(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		auto node = linkedList.GetNode(elementToAdd);
		if (node != nullptr)
		{
			linkedList.DeleteNode(node);
		}
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}
