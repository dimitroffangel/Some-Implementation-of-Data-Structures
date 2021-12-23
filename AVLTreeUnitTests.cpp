#include "AVLTreeUnitTests.h"

#include <chrono>
#include <fstream>
#include <iostream>

AVLTree<int> AVLTreeUnitTests::AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::AddTest: ";
	outputFile << "AVLTreeUnitTests::AddTest: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToAdd)
	{
		linkedList.AddNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

AVLTree<int> AVLTreeUnitTests::RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::RemoveTest: ";
	outputFile << "AVLTreeUnitTests::RemoveTest: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToRemove)
	{
		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		linkedList.DeleteNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

AVLTree<int> AVLTreeUnitTests::GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::GetTest: ";
	outputFile << "AVLTreeUnitTests::GetTest: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToGet)
	{
		linkedList.ContainsNode(elementToAdd);
		//linkedList.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

AVLTree<int> AVLTreeUnitTests::AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::AddRemoveImmediately: ";
	outputFile << "AVLTreeUnitTests::AddRemoveImmediately: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.AddNode(elementToAdd);

		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		linkedList.DeleteNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

AVLTree<int> AVLTreeUnitTests::AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::AddThenRemoveEverythingAdded: ";
	outputFile << "AVLTreeUnitTests::AddThenRemoveEverythingAdded: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.AddNode(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		linkedList.DeleteNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

AVLTree<int> AVLTreeUnitTests::AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::AddGet: ";
	outputFile << "AVLTreeUnitTests::AddGet: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.AddNode(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		if (!linkedList.ContainsNode(elementToAdd))
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

AVLTree<int> AVLTreeUnitTests::AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::AddGetImmediately: ";
	outputFile << "AVLTreeUnitTests::AddGetImmediately: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.AddNode(elementToAdd);

		if (!linkedList.ContainsNode(elementToAdd))
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

AVLTree<int> AVLTreeUnitTests::RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::RemoveGet: ";
	outputFile << "AVLTreeUnitTests::RemoveGet: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		//linkedList.Contains(elementToAdd);

		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		linkedList.DeleteNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;

}

AVLTree<int> AVLTreeUnitTests::RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "AVLTreeUnitTests::RemoveThenAddEverythingRemoved: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		linkedList.DeleteNode(elementToAdd);

		linkedList.AddNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

AVLTree<int> AVLTreeUnitTests::RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "AVLTreeUnitTests::RemoveThenAddEverythingRemoved: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		linkedList.DeleteNode(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		linkedList.AddNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}

AVLTree<int> AVLTreeUnitTests::AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "AVLTreeUnitTests::AddRemoveGet: ";
	outputFile << "AVLTreeUnitTests::AddRemoveGet: ";

	AVLTree<int> linkedList;

	for (const int elementToHave : elementsToHaveInitially)
	{
		linkedList.AddNode(elementToHave);
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		linkedList.AddNode(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{
		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		//linkedList.Contains(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		if (!linkedList.ContainsNode(elementToAdd))
		{
			continue;
		}

		linkedList.DeleteNode(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return linkedList;
}
