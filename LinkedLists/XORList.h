#ifndef XORLIST_H_GUARD
#define XORLIST_H_GUARD

#include <cstddef>
#include <initializer_list>
#include <utility>
#include <iostream>

template<typename T>
class XORList
{
	struct Node
	{
		T data;
		Node* nodePointerXOR = nullptr;
	};

private:
	Node* begin = nullptr;
	Node* end = nullptr;

	Node* XOR_OfPointers(Node* a, Node* b) const
	{
		return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
	}

	void Copy(const XORList& other)
	{
		Node* currentNode = other.begin;
		Node* lastNode = nullptr;

		while (currentNode != nullptr)
		{
			Append(currentNode->data);

			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}
	}

	void Delete()
	{
		Node* currentNode = begin;
		Node* lastNode = nullptr;

		while (currentNode != nullptr)
		{
			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			
			// delete the current Node
			delete lastNode;

			lastNode = saveCurrentNode;
		}
	}

public:
	Node* GetBegin() const
	{
		return begin;
	}

	Node* GetEnd() const
	{
		return end;
	}

	Node* GetNextNode(const Node* node) const
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		Node* currentNode = begin;
		Node* lastNode = nullptr;

		while (lastNode != node && currentNode != nullptr)
		{
			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}

		return currentNode;
	}

	Node* GetNextNode(Node* fromNode, Node* previousNode) const
	{
		if (fromNode == nullptr)
		{
			return nullptr;
		}

		if (previousNode == nullptr)
		{
			if (begin == fromNode)
			{
				return begin->nodePointerXOR;
			}

			return nullptr;
		}

		return XOR_OfPointers(fromNode->nodePointerXOR, previousNode);
	}

public:
	XORList()
	{

	}

	XORList(const XORList& other)
	{
		Copy(other);
	}

	~XORList()
	{
		Delete();
	}

	XORList(XORList&& other)
	{
		begin = other.begin;
		end = other.end;

		other.begin = other.end = nullptr;
	}

	XORList(const std::initializer_list<T>& list)
	{
		for (const auto& element : list)
		{
			Append(element);
		}
	}

	XORList& operator=(const XORList& rhs)
	{
		if (this != &rhs)
		{
			Delete();
			Copy(rhs);
		}

		return *this;
	}

	void PrintFromStart() const
	{
		Node* currentNode = begin;
		Node* lastTraversedNode = nullptr;

		while (currentNode != nullptr)
		{
			std::cout << currentNode->data << ", ";

			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversedNode, currentNode->nodePointerXOR);
			lastTraversedNode = saveCurrentNode;
		}

		std::cout << '\n';
	}

	void Prepend(const T& data)
	{
		Node* newNode = new Node;
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
		Node* newNode = new Node;
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

	bool InsertAfter(Node* const insertAfterNode, const T& data)
	{
		if (insertAfterNode == nullptr)
		{
			return false;
		}

		if (insertAfterNode == end)
		{
			Append(data);
			return true;
		}

		Node* currentNode = begin;
		Node* lastTraversed = nullptr;

		// we need to change the xor data of the next as well, because we know we are inserting between two existing elements
		while (lastTraversed != insertAfterNode && currentNode != nullptr)
		{
			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversed, currentNode->nodePointerXOR);
			lastTraversed = saveCurrentNode;
		}

		if (lastTraversed == insertAfterNode)
		{
			Node* newNode = new Node;
			newNode->data = data;

			// set the xor of the new node
			newNode->nodePointerXOR = XOR_OfPointers(insertAfterNode, currentNode);

			// set the xor of the node after the newNode
			currentNode->nodePointerXOR = XOR_OfPointers(currentNode->nodePointerXOR, XOR_OfPointers(insertAfterNode, newNode));

			// set the xor of the node before the newNode
			insertAfterNode->nodePointerXOR = XOR_OfPointers(insertAfterNode->nodePointerXOR, XOR_OfPointers(currentNode, newNode));

			return true;
		}

		// insertAfterNode is not in the list
		return false;
	}
	
	bool InsertBefore(Node* const beforeNode, const T& data)
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

		Node* currentNode = begin;
		Node* lastTraversed = nullptr;

		while (currentNode != beforeNode && currentNode != nullptr)
		{
			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(lastTraversed, currentNode->nodePointerXOR);
			lastTraversed = saveCurrentNode;
		}

		if (currentNode == beforeNode) // whether it is the end, we don't care
		{
			Node* newNode = new Node;
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

	void JoinTwoXORLists(const XORList& other)
	{
		Node* otherCurrentNode = other.begin;
		Node* lastTraversedNode = nullptr;

		while (otherCurrentNode != nullptr)
		{
			Append(otherCurrentNode->data);

			Node* saveCurrentNode = otherCurrentNode;
			otherCurrentNode = XOR_OfPointers(lastTraversedNode, otherCurrentNode->nodePointerXOR);
			lastTraversedNode = saveCurrentNode;
		}
	}

	void JoinTwoXORLists(XORList&& other)
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

		other.end = other.begin = nullptr;
	}

	void PopBack()
	{
		if (end == nullptr)
		{
			return;
		}

		Node* currentNode = begin;
		Node* lastTraversed = nullptr;

		while (currentNode != end && currentNode != nullptr)
		{
			Node* saveCurrentNode = currentNode;
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
		Node* afterBeginNode = begin->nodePointerXOR;

		afterBeginNode->nodePointerXOR = XOR_OfPointers(afterBeginNode->nodePointerXOR, begin);

		// delete the begin
		delete begin;

		// set the new beginning...
		begin = afterBeginNode;
	}

	void DeleteBefore(Node* beforeNode)
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

		Node* currentNode = begin; // node that will be deleted
		Node* aboutToBeDeletedNode = nullptr;
		Node* nodeBeforeDeletedNode = nullptr;

		while (currentNode != beforeNode && currentNode != nullptr)
		{
			nodeBeforeDeletedNode = aboutToBeDeletedNode;
			Node* saveCurrentNode = currentNode;
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

	void DeleteAfter(Node* afterNode)
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

		Node* currentNode = begin;
		Node* lastTraversed = nullptr;
		Node* afterDeletedNode = nullptr;

		while (lastTraversed != afterNode && currentNode != nullptr)
		{
			Node* saveCurrentNode = currentNode;
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

	void DeleteNode(Node* aboutToBeDeletedNode)
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

		Node* currentNode = begin; // node that will be deleted
		Node* nodeBeforeDeletedNode = nullptr;
		Node* nodeAfterDeletedNode = nullptr;


		while (currentNode != aboutToBeDeletedNode && currentNode != nullptr)
		{
			Node* saveCurrentNode = currentNode;
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
	Node* GetNode(const T& element) const
	{
		Node* currentNode = begin;
		Node* lastNode = nullptr;

		while (currentNode != nullptr && currentNode->data != element)
		{
			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}

		return currentNode;
	}

	XORList GetAllNodes(const T& element) const
	{
		Node* currentNode = begin;
		Node* lastNode = nullptr;

		XORList result;

		while (currentNode != nullptr)
		{
			if (currentNode->data == element)
			{
				result.Append(currentNode->data);
			}

			Node* saveCurrentNode = currentNode;
			currentNode = XOR_OfPointers(currentNode->nodePointerXOR, lastNode);
			lastNode = saveCurrentNode;
		}

		return std::move(result);
	}
};

template<typename T>
XORList<T> operator+(const XORList<T>& lhs, const XORList<T>& rhs)
{
	XORList<T> result;
	result.JoinTwoXORLists(lhs);
	result.JoinTwoXORLists(rhs);

	return result;
}

template<typename T>
void operator+=(XORList<T>& lhs, const XORList<T>& rhs)
{
	lhs.JoinTwoXORLists(rhs);

	//return lhs;
}

#endif