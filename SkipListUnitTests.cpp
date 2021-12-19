#include "SkipListUnitTests.h"

#include <chrono>

SkipList<int> SkipListUnitTests::AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd)
{
	std::cout << "SkipListUnitTests::AddTest: ";
	
	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove)
{
	std::cout << "SkipListUnitTests::RemoveTest: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet)
{
	std::cout << "SkipListUnitTests::GetTest: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::AddRemoveImmediately: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::AddThenRemoveEverythingAdded: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::AddGet: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::AddGetImmediately: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::RemoveGet: ";

	SkipList<int> skipList(50);

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

	return skipList;

}

SkipList<int> SkipListUnitTests::RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::RemoveThenAddEverythingRemoved: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::RemoveThenAddEverythingRemoved: ";

	SkipList<int> skipList(50);

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

	return skipList;
}

SkipList<int> SkipListUnitTests::AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer)
{
	std::cout << "SkipListUnitTests::AddRemoveGet: ";

	SkipList<int> skipList(50);

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

	return skipList;
}
