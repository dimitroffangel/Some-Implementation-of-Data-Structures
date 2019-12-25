#pragma once

#include <cstddef>

template<typename T>
struct Node
{
	T data;
	Node* nodePointerXOR = nullptr;
};

template<typename T>
class XORLIST
{
private:
	Node<T>* begin = nullptr;
	Node<T>* end = nullptr;

	Node<T>* XOR_OfPointers(Node<T>* a, Node<T>* b)
	{
		return (Node<T>*)((uintptr_t)(a) ^ (uintptr_t)(b));
	}

	void Copy(const XORLIST& other)
	{
		Node<T>* currentNode = other.begin;
		Node<T>* lastNode = nullptr;

		while (currentNode != nullptr)
		{
			Append(currentNode->data);

			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}
	}

	void Delete()
	{
		Node<T>* currentNode = begin;
		Node<T>* lastNode = nullptr;

		while (currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			
			// delete the current Node
			delete lastNode;

			lastNode = saveCurrentNode;
		}
	}

public:
	Node<T>* GetBegin() const
	{
		return begin;
	}

	Node<T>* GetEnd() const
	{
		return end;
	}

	Node<T>* GetNextNode(const Node<T>* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		Node<T>* currentNode = begin;
		Node<T>* lastNode = nullptr;

		while (lastNode != node && currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}

		return currentNode;
	}

public:
	XORLIST()
	{

	}

	XORLIST(const XORLIST& other)
	{
		Copy(other);
	}

	~XORLIST()
	{
		Delete();
	}

	XORLIST(XORLIST&& other)
	{
		begin = other.begin;
		end = other.end;

		other.begin = other.end = nullptr;
	}

	XORLIST(const std::initializer_list<T>& list)
	{
		for (const auto& element : list)
		{
			Append(element);
		}
	}

	XORLIST& operator=(const XORLIST& rhs)
	{
		if (this != &rhs)
		{
			Delete();
			Copy(rhs);
		}

		return *this;
	}

	void PrintFromStart()
	{
		Node<T>* currentNode = begin;
		Node<T>* lastTraversedNode = nullptr;

		while (currentNode != nullptr)
		{
			std::cout << currentNode->data << ", ";

			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversedNode, currentNode->nodePointerXOR);
			lastTraversedNode = saveCurrentNode;
		}

		std::cout << '\n';
	}

	void Prepend(const T& data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		if (begin == nullptr)
		{
			end = begin = newNode;
			return;
		}

		newNode->nodePointerXOR =  XOR_OfPointers(begin, nullptr);

		begin->nodePointerXOR = XOR_OfPointers(begin->nodePointerXOR, newNode);

		begin = newNode;
	}

	void Append(const T& data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		
		if (end == nullptr)
		{
			end = begin = newNode;
			return;
		}

		newNode->nodePointerXOR = XOR_OfPointers(end, nullptr);

		end->nodePointerXOR = XOR_OfPointers(end->nodePointerXOR, newNode);
		
		end = newNode;
	}

	bool InsertAfter(Node<T>* const afterNode, const T& data)
	{
		if (afterNode == nullptr)
		{
			return false;
		}

		if (afterNode == end)
		{
			Append(data);
			return true;
		}

		Node<T>* currentNode = begin;
		Node<T>* lastTraversed = nullptr;

		// we need to change the xor data of the next as well, because we know we are inserting between two existing elements
		while (lastTraversed != afterNode && currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversed, currentNode->nodePointerXOR);
			lastTraversed = saveCurrentNode;
		}

		if (lastTraversed == afterNode)
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;

			// set the xor of the new node
			newNode->nodePointerXOR = XOR_OfPointers(afterNode, currentNode);

			// set the xor of the node after the newNode
			currentNode->nodePointerXOR = XOR_OfPointers(currentNode->nodePointerXOR, XOR_OfPointers(afterNode, newNode));

			// set the xor of the node before the newNode
			afterNode->nodePointerXOR = XOR_OfPointers(afterNode->nodePointerXOR, XOR_OfPointers(currentNode, newNode));

			return true;
		}

		// afterNode is not in the list
		return false;
	}
	
	bool InsertBefore(Node<T>* const beforeNode, const T& data)
	{
		if (beforeNode == nullptr)
		{
			return false;
		}

		if (beforeNode == begin)
		{
			Prepend(data);
			return true;
		}

		Node<T>* currentNode = begin;
		Node<T>* lastTraversed = nullptr;

		while (currentNode != beforeNode && currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversed, currentNode->nodePointerXOR);
			lastTraversed = saveCurrentNode;
		}

		if (currentNode == beforeNode) // whether it is the end, we don't care
		{
			Node<T>* newNode = new Node<T>;
			newNode->data = data;

			// set the xor link of the new node
			newNode->nodePointerXOR = XOR_OfPointers(lastTraversed, beforeNode);

			//set the xor link of the previous node
			lastTraversed->nodePointerXOR = XOR_OfPointers(lastTraversed->nodePointerXOR,  XOR_OfPointers(beforeNode, newNode));

			// set the xor link of the beforeNode
			beforeNode->nodePointerXOR = XOR_OfPointers(beforeNode->nodePointerXOR, XOR_OfPointers(lastTraversed, newNode));
			return true;
		}


		// beforeNode is not in the list...
		return false;
	}

	void JoinTwoXORLists(const XORLIST& other)
	{
		if (begin == nullptr)
		{
			return;
		}

		if (end == nullptr)
		{
			*this = other;
			return;
		}

		end->nodePointerXOR = XOR_OfPointers(end->nodePointerXOR, other.begin);
		other.begin->nodePointerXOR = XOR_OfPointers(other.begin->nodePointerXOR, end);

		end = other.end;
	}

	void PopBack()
	{
		if (end == nullptr)
		{
			return;
		}

		Node<T>* currentNode = begin;
		Node<T>* lastTraversed = nullptr;

		while (currentNode != end && currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversed, currentNode->nodePointerXOR);
			lastTraversed = saveCurrentNode;
		}

		// get out the lastTraversed xor data the last element
		lastTraversed->nodePointerXOR = XOR_OfPointers(lastTraversed->nodePointerXOR, end);

		// get the last element 
		delete currentNode;

		end = lastTraversed;
	}

	void PopFront()
	{
		if (begin == nullptr)
		{
			return;
		}

		if (begin == end)
		{
			delete begin;

			begin = end = nullptr;
		}

		
		// get the node after the begin
		Node<T>* afterBeginNode = begin->nodePointerXOR;

		afterBeginNode->nodePointerXOR = XOR_OfPointers(afterBeginNode->nodePointerXOR, begin);

		// delete the begin
		delete begin;

		// set the new beginning...
		begin = afterBeginNode;
	}

	void DeleteBefore(Node<T>* beforeNode)
	{
		if (beforeNode == nullptr)
		{
			return;
		}

		if (beforeNode == begin)
		{
			return;
		}

		if (XOR_OfPointers(beforeNode, begin->nodePointerXOR) == nullptr)
		{
			PopFront();
			return;
		}

		Node<T>* currentNode = begin; // node that will be deleted
		Node<T>* aboutToBeDeletedNode = nullptr;
		Node<T>* nodeBeforeDeletedNode = nullptr;

		while (currentNode != beforeNode && currentNode != nullptr)
		{
			nodeBeforeDeletedNode = aboutToBeDeletedNode;
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(aboutToBeDeletedNode, currentNode->nodePointerXOR);
			aboutToBeDeletedNode = saveCurrentNode;
		}

		if (currentNode == nullptr) // beforeNode is not in the list
		{
			return;
		}

		// set the xorData for the node after the deletedNode
		beforeNode->nodePointerXOR = XOR_OfPointers(beforeNode->nodePointerXOR, XOR_OfPointers(aboutToBeDeletedNode, nodeBeforeDeletedNode));

		// set the xorData for the node before the deletedNode
		nodeBeforeDeletedNode->nodePointerXOR = XOR_OfPointers(nodeBeforeDeletedNode->nodePointerXOR, XOR_OfPointers(aboutToBeDeletedNode, beforeNode));

		delete aboutToBeDeletedNode;
	}

	void DeleteAfter(Node<T>* afterNode)
	{
		if (afterNode == nullptr)
		{
			return;
		}

		if (afterNode == end)
		{
			return;
		}

		if (XOR_OfPointers(afterNode, end->nodePointerXOR) == nullptr)
		{
			PopBack();
			return;
		}

		Node<T>* currentNode = begin;
		Node<T>* lastTraversed = nullptr;
		Node<T>* afterDeletedNode = nullptr;

		while (lastTraversed != afterNode && currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversed, currentNode->nodePointerXOR);
			lastTraversed = saveCurrentNode;
		}

		if (currentNode == nullptr)
		{
			return;
		}

		// currentNode is the node to be deleted
		afterDeletedNode = XOR_OfPointers(lastTraversed, currentNode->nodePointerXOR);

		// set the xor data for the element before the about to be deleted node
		afterNode->nodePointerXOR = XOR_OfPointers(afterNode->nodePointerXOR, XOR_OfPointers(currentNode, afterDeletedNode));

		// set the xor data for the element after the deleted node
		afterDeletedNode->nodePointerXOR = XOR_OfPointers(afterDeletedNode->nodePointerXOR, XOR_OfPointers(currentNode, afterNode));

		delete currentNode;
	}

	void DeleteNode(Node<T>* aboutToBeDeletedNode)
	{
		if (aboutToBeDeletedNode == nullptr)
		{
			return;
		}

		if (aboutToBeDeletedNode == begin)
		{
			PopFront();
			return;
		}

		if (aboutToBeDeletedNode == end)
		{
			PopBack();
			return;
		}

		Node<T>* currentNode = begin; // node that will be deleted
		Node<T>* nodeBeforeDeletedNode = nullptr;
		Node<T>* nodeAfterDeletedNode = nullptr;


		while (currentNode != aboutToBeDeletedNode && currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, nodeBeforeDeletedNode);
			nodeBeforeDeletedNode = saveCurrentNode;
		}

		// node is not in the list
		if (currentNode == nullptr)
		{
			return;
		}

		// get the node after the deleted one
		nodeAfterDeletedNode = XOR_OfPointers(currentNode->nodePointerXOR, nodeBeforeDeletedNode);

		// set the xor of the node before the deletedNode
		nodeBeforeDeletedNode->nodePointerXOR = XOR_OfPointers(nodeBeforeDeletedNode->nodePointerXOR, XOR_OfPointers(aboutToBeDeletedNode, nodeAfterDeletedNode));

		// set the xor of the node after the deletedNode
		nodeAfterDeletedNode->nodePointerXOR = XOR_OfPointers(nodeAfterDeletedNode->nodePointerXOR, XOR_OfPointers(aboutToBeDeletedNode, nodeBeforeDeletedNode));

		delete aboutToBeDeletedNode;
	}

	// gets the first node, containing that element
	bool GetNode(const T& element)
	{
		Node<T>* currentNode = begin;
		Node<T>* lastNode = nullptr;

		while (currentNode->data != element && currentNode != nullptr)
		{
			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}

		return currentNode;
	}

	XORLIST GetAllNodes(const T& element)
	{
		Node<T>* currentNode = begin;
		Node<T>* lastNode = nullptr;

		XORLIST result;

		while (currentNode != nullptr)
		{
			if (currentNode->data == element)
			{
				result.Append(currentNode->data);
			}

			Node<T>* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}

		return std::move(result);
	}
};