#ifndef XORLIST_H_GUARD
#define XORLIST_H_GUARD

#include <iostream>
#include <vector>
#include <cassert>
#include <time.h>


template<typename T>
class SkipList
{
	struct Node
	{
		T data;
		Node* leftPointer = nullptr;
		Node* rightPointer = nullptr;
		Node* downPointer = nullptr;
		Node* upPointer = nullptr;
	};

	static const int MIN_RANDOM_INTERVAL = 0;
	static const int MAX_RANDOM_INTERVAL = 100;

	Node* m_FirstNode = nullptr;
	size_t m_CurrentNumberOfLevels = 1;
	float m_PropabilityToIncreaseLevel;

public:
	SkipList(const T& initialValue, const float probabilityToIncreaseLevel)
		:m_PropabilityToIncreaseLevel(probabilityToIncreaseLevel)
	{
		assert(probabilityToIncreaseLevel > MIN_RANDOM_INTERVAL && probabilityToIncreaseLevel < MAX_RANDOM_INTERVAL);

		srand(time(NULL));

		m_FirstNode = new Node();

		Node* newNode = new Node();
		newNode->data = initialValue;
		newNode->leftPointer = m_FirstNode;
		m_FirstNode->rightPointer = newNode;
	}

	SkipList(const float probabilityToIncreaseLevel)
		:m_PropabilityToIncreaseLevel(probabilityToIncreaseLevel)
	{
		assert(probabilityToIncreaseLevel > MIN_RANDOM_INTERVAL && probabilityToIncreaseLevel < MAX_RANDOM_INTERVAL);

		srand(time(NULL));
	}

	bool Add(const T& value)
	{
		Node* adjacentLeftNode = TryFindingPreviousElement(value);

		if (adjacentLeftNode == nullptr && m_FirstNode == nullptr)
		{
			m_FirstNode = new Node();
			adjacentLeftNode = m_FirstNode;
		}

		else if (adjacentLeftNode == nullptr)
		{
			return false;
		}

		Node* adjacentRightNode = adjacentLeftNode->rightPointer;

		Node* newNode = new Node();
		newNode->data = value;
		newNode->leftPointer = adjacentLeftNode;
		newNode->rightPointer = adjacentRightNode;

		adjacentLeftNode->rightPointer = newNode;

		if (adjacentRightNode != nullptr)
		{
			adjacentRightNode->leftPointer = newNode;
		}

		size_t currentLevel = 1;
		while (rand() % MAX_RANDOM_INTERVAL + MIN_RANDOM_INTERVAL <= m_PropabilityToIncreaseLevel)
		{
			++currentLevel;

			if (currentLevel > m_CurrentNumberOfLevels)
			{
				Node* newInitialNode = new Node();
				newInitialNode->downPointer = m_FirstNode;

				m_FirstNode->upPointer = newInitialNode;
				m_FirstNode = newInitialNode;

				Node* newLevelNode = new Node();
				newLevelNode->data = newNode->data;
				newLevelNode->leftPointer = m_FirstNode;

				newLevelNode->downPointer = newNode;
				newNode->upPointer = newLevelNode;

				m_FirstNode->rightPointer = newLevelNode;
				
				m_CurrentNumberOfLevels = currentLevel;
				newNode = newLevelNode;

				continue;
			}

			while (adjacentLeftNode->upPointer == nullptr)
			{
				adjacentLeftNode = adjacentLeftNode->leftPointer;
			}
			
			adjacentLeftNode = adjacentLeftNode->upPointer;
			Node* adjacentUpperRightNode = adjacentLeftNode->rightPointer;

			Node* upperLevelNode = new Node();
			upperLevelNode->data = value;
			upperLevelNode->leftPointer = adjacentLeftNode;
			upperLevelNode->rightPointer = adjacentUpperRightNode;
			upperLevelNode->downPointer = newNode;
			newNode->upPointer = upperLevelNode;
			
			newNode = upperLevelNode;

			adjacentLeftNode->rightPointer = upperLevelNode;

			if (adjacentUpperRightNode != nullptr)
			{
				adjacentUpperRightNode->leftPointer = upperLevelNode;
			}
		}

		return true;
	}

	bool Contains(const T& value) const
	{
		Node* nearestElement = TryFindingPreviousElement(value);
		
		return nearestElement->data == value;
	}

	bool Delete(const T& value)
	{
		Node* nearestNode = TryFindingPreviousElement(value);

		if (nearestNode == nullptr)
		{
			return false;
		}

		nearestNode = nearestNode->rightPointer;

		if (nearestNode->data == value)
		{
			while (nearestNode != nullptr)
			{
				nearestNode->leftPointer->rightPointer = nearestNode->rightPointer;

				if (nearestNode->rightPointer != nullptr)
				{
					nearestNode->rightPointer->leftPointer = nearestNode->leftPointer;
				}

				Node* previousNode = nearestNode;
				nearestNode = nearestNode->upPointer;

				if (nearestNode != nullptr)
				{
					nearestNode->downPointer = nullptr;
				}

				delete previousNode;
			}

			return true;
		}

		return false;
	}

	void Print() const
	{
		Node* currentInitialNodeOnLevel = m_FirstNode;

		while (currentInitialNodeOnLevel != nullptr)
		{
			Node* currentNodeOnLevel = currentInitialNodeOnLevel->rightPointer;

			while (currentNodeOnLevel != nullptr)
			{
				std::cout << currentNodeOnLevel->data << "-> ";
				currentNodeOnLevel = currentNodeOnLevel->rightPointer;
			}

			currentInitialNodeOnLevel = currentInitialNodeOnLevel->downPointer;
			std::cout << '\n';
		}
	}

private:
	Node* TryFindingPreviousElement(const T& valueToSearch) const
	{
		if (m_FirstNode == nullptr)
		{
			return nullptr;
		}
	
		if (m_FirstNode->leftPointer == nullptr && m_FirstNode->rightPointer == nullptr && m_FirstNode->downPointer == nullptr)
		{
			return m_FirstNode;
		}
	
		Node* previousNode = nullptr;
		Node* currentNode = m_FirstNode;
		size_t currentIterationLevel = m_CurrentNumberOfLevels;
	
		while (currentNode != nullptr)
		{
			previousNode = currentNode;
			currentNode = currentNode->rightPointer;
	
			while (currentNode != nullptr && currentNode->data < valueToSearch)
			{
				previousNode = currentNode;
				currentNode = currentNode->rightPointer;
			}
	
			if (currentNode == nullptr || currentNode->data >= valueToSearch)
			{
				assert(previousNode != nullptr);
	
				if (currentIterationLevel == 1)
				{
					return previousNode;
				}
	
				currentNode = previousNode->downPointer;
				previousNode = currentNode;
				--currentIterationLevel;
	
				continue;
			}
	
			//if (currentNode->data == valueToSearch)
			//{
			//	while (currentNode->downPointer != nullptr)
			//	{
			//		currentNode = currentNode->downPointer;
			//	}
	
			//	return currentNode;
			//}
		}
	
		assert(currentNode == nullptr);
	
		return nullptr;
	}

};

#endif