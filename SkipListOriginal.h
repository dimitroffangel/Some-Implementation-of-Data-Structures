#ifndef SKIPLISTORIGNAL_H_GUARD
#define SKIPLISTORIGNAL_H_GUARD

#include <iostream>
#include <vector>
#include <cassert>
#include <time.h>


template<typename T>
class SkipListOriginal
{
	struct Node
	{
		T data;
		Node** nextNodes = nullptr;
		size_t level = 0;
	};

	static const int MIN_RANDOM_INTERVAL = 0;
	static const int MAX_RANDOM_INTERVAL = 100;

	Node* m_FirstNode = nullptr;
	int m_CurrentNumberOfLevels = -1;
	float m_PropabilityToIncreaseLevel;

public:
	SkipListOriginal(const T& initialValue, const float probabilityToIncreaseLevel)
		:m_PropabilityToIncreaseLevel(probabilityToIncreaseLevel)
	{
		assert(probabilityToIncreaseLevel > MIN_RANDOM_INTERVAL && probabilityToIncreaseLevel < MAX_RANDOM_INTERVAL);

		srand(time(NULL));

		Add(initialValue);
	}

	SkipListOriginal(const float probabilityToIncreaseLevel)
		:m_PropabilityToIncreaseLevel(probabilityToIncreaseLevel)
	{
		assert(probabilityToIncreaseLevel > MIN_RANDOM_INTERVAL && probabilityToIncreaseLevel < MAX_RANDOM_INTERVAL);

		srand(time(NULL));
	}

	~SkipListOriginal()
	{
		if (m_FirstNode == nullptr)
		{
			return;
		}

		Node* currentNode = m_FirstNode->nextNodes[0];
		
		while (currentNode != nullptr)
		{
			Node* previousNode = currentNode;

			currentNode = currentNode->nextNodes[0];

			delete[] previousNode->nextNodes;
			delete previousNode;
		}

		delete[] m_FirstNode->nextNodes;
		delete m_FirstNode;
		m_FirstNode = nullptr;
	}

	bool Add(const T& value)
	{
		if (m_FirstNode == nullptr)
		{
			m_FirstNode = new Node();
			++m_CurrentNumberOfLevels;
			m_FirstNode->nextNodes = new Node*[m_CurrentNumberOfLevels + 1];
			for (size_t i = 0; i <= m_CurrentNumberOfLevels; ++i)
			{
				m_FirstNode->nextNodes[i] = nullptr;
			}
			m_FirstNode->level = 0;
		}

		size_t currentLevel = 0;
		while (rand() % MAX_RANDOM_INTERVAL + MIN_RANDOM_INTERVAL <= m_PropabilityToIncreaseLevel)
		{
			++currentLevel;
		}

		if (currentLevel > m_CurrentNumberOfLevels)
		{
			Node* newNode = new Node();
			newNode->data = m_FirstNode->data;
			newNode->nextNodes = new Node*[currentLevel + 1];
			newNode->level = currentLevel;

			for (size_t i = 0; i <= m_CurrentNumberOfLevels; ++i)
			{
				newNode->nextNodes[i] = m_FirstNode->nextNodes[i];
			}

			for (size_t i = m_CurrentNumberOfLevels + 1; i <= currentLevel; ++i)
			{
				newNode->nextNodes[i] = nullptr;
			}

			delete[] m_FirstNode->nextNodes;
			delete m_FirstNode;
			m_FirstNode = newNode;
		}

		std::vector<Node*> previousNodes;
		TryFindingPreviousElement(value, previousNodes);

		if (currentLevel > m_CurrentNumberOfLevels)
		{
			for (size_t currentIteratedLevel = m_CurrentNumberOfLevels + 1; currentIteratedLevel <= currentLevel; ++currentIteratedLevel)
			{
				previousNodes.push_back(m_FirstNode);
			}

			m_CurrentNumberOfLevels = currentLevel;
		}

		Node* newNode = new Node();
		newNode->data = value;
		newNode->nextNodes = new Node*[currentLevel + 1];
		newNode->level = currentLevel;

		for (size_t currentIteratedLevel = 0; currentIteratedLevel <= currentLevel; ++currentIteratedLevel)
		{
			newNode->nextNodes[currentIteratedLevel] = previousNodes[currentIteratedLevel]->nextNodes[currentIteratedLevel];
			previousNodes[currentIteratedLevel]->nextNodes[currentIteratedLevel] = newNode;
		}

		return true;
	}

	bool Contains(const T& value) const
	{
		std::vector<Node*> previousNodes;
		TryFindingPreviousElement(value, previousNodes);

		if (previousNodes.size() == 0)
		{
			return false;
		}

		Node* nearestNode = previousNodes[0]->nextNodes[0];

		if (nearestNode == nullptr)
		{
			return false;
		}

		return nearestNode->data == value;
	}

	bool Delete(const T& value)
	{
		std::vector<Node*> previousNodes;
		TryFindingPreviousElement(value, previousNodes);

		if (previousNodes.size() == 0)
		{
			return false;
		}

		Node* nodeToBeDeleted = previousNodes[0]->nextNodes[0];

		if (nodeToBeDeleted == nullptr || value != nodeToBeDeleted->data)
		{
			return false;
		}

		for (size_t currentIteratedLevel = 0; currentIteratedLevel <= m_CurrentNumberOfLevels; ++currentIteratedLevel)
		{
			if (previousNodes[currentIteratedLevel]->nextNodes == nullptr ||
				previousNodes[currentIteratedLevel]->nextNodes[currentIteratedLevel] != nodeToBeDeleted)
			{
				break;
			}
			
			auto left = nodeToBeDeleted->nextNodes[currentIteratedLevel];
			previousNodes[currentIteratedLevel]->nextNodes[currentIteratedLevel] = 
				nodeToBeDeleted->nextNodes[currentIteratedLevel];

		}

		while (m_CurrentNumberOfLevels > 0 && m_FirstNode->nextNodes[m_CurrentNumberOfLevels] == nodeToBeDeleted)
		{
			--m_CurrentNumberOfLevels;
		}

		delete[] nodeToBeDeleted->nextNodes;
		delete nodeToBeDeleted;

		return true;
	}

	void Print() const
	{
		Node* currentInitialNodeOnLevel = m_FirstNode;

		Node* currentNode = m_FirstNode;
		size_t currentIterationLevel = m_CurrentNumberOfLevels;

		for (int currentIteratedLevel = m_CurrentNumberOfLevels; currentIteratedLevel >= 0; --currentIteratedLevel)
		{
			std::cout << "Level : " << currentIteratedLevel << ": ";
			Node* nextNode = m_FirstNode->nextNodes[currentIteratedLevel];

			while (nextNode != nullptr)
			{
				std::cout << nextNode->data << " ";
				nextNode = nextNode->nextNodes[currentIteratedLevel];
			}
			std::cout << "\n";
		}
	}

private:
	bool TryFindingPreviousElement(const T& valueToSearch, std::vector<Node*>& previousNodes) const
	{
		if (m_FirstNode == nullptr)
		{
			return false;
		}

		previousNodes.resize(m_CurrentNumberOfLevels + 1);

		Node* currentNode = m_FirstNode;
		size_t currentIterationLevel = m_CurrentNumberOfLevels;

		for (int currentIteratedLevel = m_CurrentNumberOfLevels; currentIteratedLevel >= 0; --currentIteratedLevel)
		{
			Node* nextNode = currentNode->nextNodes[currentIteratedLevel];
			while (nextNode != nullptr && nextNode->data < valueToSearch)
			{
				currentNode = nextNode;
				nextNode = currentNode->nextNodes[currentIteratedLevel];
			}

			previousNodes[currentIteratedLevel] = currentNode;
		}

		return true;
	}

};

#endif