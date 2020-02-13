#ifndef AVLTREE_H_GUARD
#define AVLTREE_H_GUARD

#include <iostream>

template<typename T>
struct Node
{
	T data;
	char balanceFactor = 0;
	Node<T>* parent = nullptr;
	Node<T>* left   = nullptr;
	Node<T>* right  = nullptr;
};

template<typename T>
class AVLTree
{
private:
	Node<T>* root = nullptr;

	void DeleteTree(Node<T>*& treeRoot) const
	{
		if (treeRoot == nullptr)
		{
			return;
		}

		DeleteTree(treeRoot->left);
		DeleteTree(treeRoot->right);
		delete treeRoot;
		treeRoot = nullptr;
	}

	void Copy(Node<T>*& destination, Node<T>* const& source) const
	{
		destination = nullptr;

		if (source == nullptr)
		{
			return;
		}

		destination = new Node<T>;
		destination->data = source->data;

		Copy(destination->left, source->left);
		Copy(destination->right, source->right);
	}

	void CopyTree(const AVLTree& tree)
	{
		Copy(root, tree.root);
	}

	// LHS -> Root -> Right
	void PrintFromNode(const Node<T>* treeNode) const
	{
		if (treeNode == nullptr)
		{
			return;
		}

		PrintFromNode(treeNode->left);
		std::cout << treeNode->data << " ";
		PrintFromNode(treeNode->right);
	}

	Node<T>* RotateLeft(Node<T>* badlyWeightedParent, Node<T>* savingNode)
	{
		/*
			savingNode will become the parent of its node
			it will have as a right child the child that has had before (which in this case is the child with highest height

			the parent of the savingNode will have its leftChild remain the same 
			and the right child will be the previous left child of the savingNode
		
			------NOTE----- the left child of the parent has height the height of the savingNode->rightChild - 1

			----- NOTE----- the parent of the savingNode will be changed outside the function
		*/

		// savingNode has height with two more than its sibling
		Node<T>* savingNodeLeftChild = savingNode->left;
		
		badlyWeightedParent->right = savingNodeLeftChild;

		if (savingNodeLeftChild != nullptr)
		{
			savingNodeLeftChild->parent = badlyWeightedParent;
		}

		savingNode->left = badlyWeightedParent;
		badlyWeightedParent->parent = savingNode;

		// the left child of the savingNode has height the same as the height of its sibling
		if (savingNode->balanceFactor == 0)
		{
			badlyWeightedParent->balanceFactor = 1;
			savingNode->balanceFactor = -1; // because the its formal left child has height the same as the rightChild of savingNode but one level lower
		}

		else // savingNode->balanceFactor = 1
		{
			badlyWeightedParent->balanceFactor = 0;
			savingNode->balanceFactor = 0;
		}

		return savingNode;
	}

	Node<T>* RotateRight(Node<T>* badlyWeightedParent, Node<T>* savingNode)
	{
		/*
			it is heigher by two than its sibling

			savingNode will become the parent of its node
			it will have as a left child the child that has had before (which in this case is the child with highest height

			the parent of the savingNode will have its rightChild remain the same
			and the left child will be the previous right child of the savingNode

			------NOTE----- the right child of the parent has height the height of the savingNode->leftChild - 1

			----- NOTE----- the parent of the savingNode will be changed outside the function
		*/

		// savingNode has height with two more than its sibling
		Node<T>* savingNodeRightChild = savingNode->right;

		badlyWeightedParent->left = savingNodeRightChild;

		if (savingNodeRightChild != nullptr)
		{
			savingNodeRightChild->parent = badlyWeightedParent;
		}

		savingNode->right = badlyWeightedParent;
		badlyWeightedParent->parent = savingNode;

		// the right child of the savingNode has height the same as the height of its sibling
		if (savingNode->balanceFactor == 0)
		{
			badlyWeightedParent->balanceFactor = -1;
			savingNode->balanceFactor = 1; // because the its formal left child has height the same as the rightChild of savingNode but one level lower
		}

		else // savingNode->balanceFactor = -1
		{
			badlyWeightedParent->balanceFactor = 0;
			savingNode->balanceFactor = 0;
		}

		return savingNode;
	}

	Node<T>* RotateRightLeft(Node<T>* badlyWeightedParent, Node<T>* savingNode)
	{
		/*
			badlyWeightedParent factor is 2 => the savingNode is the right child and its height is longer by two

			basically rotate first right among the left the child of the savingNode
			and than rotate left among the rightNode of the badlyWeitghtedParent

			now the savingNode right child height is as much as the left child of the badlyWeightedParent, due to the induction going from the leaves to the root

			and the left child of the saving node has height at most the height of its sibling and at least with one lower than its sibling

			what is happenning:
			the savingNode becomes a right child of the savingNode left child, savingNodeLeftChild's rightChild becomes left child of the savingNode
			the savingNode left Child, now as a parent of the savingNode, becomes parent of the badlyWeightedParent, who becomes left node of the 
			savingNode left child and also has as a new rightChild the savingNodeLeft child's left child

			got it ? good :D 
		*/

		Node<T>* savingNodeLeftChild = savingNode->left;
		Node<T>* savingNodeLeftChildRightChild = savingNodeLeftChild->right;

		savingNode->left = savingNodeLeftChildRightChild;

		if (savingNodeLeftChildRightChild != nullptr)
		{
			savingNodeLeftChildRightChild->parent = savingNode;
		}

		savingNodeLeftChild->right = savingNode;
		savingNode->parent = savingNodeLeftChild;

		Node<T>* savingNodeLeftChildLeftChild = savingNodeLeftChild->left;
		badlyWeightedParent->right = savingNodeLeftChildLeftChild;

		if (savingNodeLeftChildLeftChild != nullptr)
		{
			savingNodeLeftChildLeftChild->parent = badlyWeightedParent;
		}

		savingNodeLeftChild->left = badlyWeightedParent;
		badlyWeightedParent->parent = savingNodeLeftChild;

		// its right child is longer than the left by one
		if (savingNodeLeftChild->balanceFactor > 0)
		{
			// the right child goes to the savingNode leftChild, and then they have the same height =>
			savingNode->balanceFactor = 0;
			// the badlyWeightedParent has as a right child the left child of the savingNodeLeft
			// which has at least the height of the badlyWeightedParent->leftChild - 1
			badlyWeightedParent->balanceFactor = -1;
		}

		else // savingNodeLeftChild->balanceFactor <= 0
		{
			if (savingNodeLeftChild->balanceFactor == 0)
			{
				/* ------NOTE------ both of the previous children of the savingNode cannot have height the height of the left child of the 
					badlyWeightedParent - 1 because the induction states an invariant that says: 
					the height of the right subtree of X is with two heights bigger than the left subtree
				*/
				// then the left the child and the right child of the savingNodeLeftChild has the same height and the height is the height
				// that the leftChild of the badlyWeightedParent has and the height of the right child of the savingNode (they are unmoved from the rotation)
				savingNode->balanceFactor = 0;
				badlyWeightedParent->balanceFactor = 0;
			}

			else // the other condition, the left child of the savingChildLeft had a height longer than the its previous sibling
			{
				//then the rightChild of the savingNode will have height with one bigger than its new sibling => 
				savingNode->balanceFactor = 1;
				// than the left child of the badlyWeightedParent will have the same height as its new sibling =>
				badlyWeightedParent->balanceFactor = 0;
			}
		}

		savingNodeLeftChild->balanceFactor = 0;
		return savingNodeLeftChild;
		
	}

	Node<T>* RotateLeftRight(Node<T>* badlyWeightedParent, Node<T>* savingNode)
	{
		/*
			badlyWeightedParent factor is -2 => the savingNode is the left child and its height is longer by two

			basically rotate first left among the right the child of the savingNode
			and than rotate right among the leftNode of the badlyWeitghtedParent

			now the savingNode left child height is as much as the right child of the badlyWeightedParent, due to the induction going from the leaves to the root

			and the right child of the saving node has height at most the height of its sibling and at least with one lower than its sibling

			what is happenning:
			the savingNode becomes a left child of the savingNode right child, savingNodeRightChild's leftChild becomes right child of the savingNode
			the savingNode right Child, now as a parent of the savingNode, becomes the parent of the badlyWeightedParent, who becomes a right node of the
			savingNode right child and also has as a new leftChild the savingNodeRight child's right child

			got it ? good :D
		*/

		Node<T>* savingNodeRightChild = savingNode->right;
		Node<T>* savingNodeRightChildLeftChild = savingNodeRightChild->left;

		savingNode->right = savingNodeRightChildLeftChild;

		if (savingNodeRightChildLeftChild != nullptr)
		{
			savingNodeRightChildLeftChild->parent = savingNode;
		}

		savingNodeRightChild->left = savingNode;
		savingNode->parent = savingNodeRightChild;

		Node<T>* savingNodeRightChildRightChild = savingNodeRightChild->right;
		badlyWeightedParent->left = savingNodeRightChildRightChild;

		if (savingNodeRightChildRightChild != nullptr)
		{
			savingNodeRightChildRightChild->parent = badlyWeightedParent;
		}

		savingNodeRightChild->right = badlyWeightedParent;
		badlyWeightedParent->parent = savingNodeRightChild;

		// its left child is longer than the right by one
		if (savingNodeRightChild->balanceFactor < 0)
		{
			// the left child goes to the savingNode RightChild, and then they have the same height =>
			savingNode->balanceFactor = 0;
			// the badlyWeightedParent has as a left child the right child of the savingNodeLeft
			// which has at least the height of the badlyWeightedParent->rightChild - 1
			badlyWeightedParent->balanceFactor = 1;
		}

		else // savingNodeRightChild->balanceFactor >= 0
		{
			if (savingNodeRightChild->balanceFactor == 0)
			{
				/* ------NOTE------ both of the previous children of the savingNode cannot have height the height of the right child of the 
					 badlyWeightedParent-> rightChild - 1 because the induction states an invariant that says: 
					 the height of the left subtree of X is with two heights bigger than the right subtree
				*/
				// then the right the child and the left child of the savingNodeLeftChild has the same height and the height is the height
				// that the rightChild of the badlyWeightedParent has and the height of the left child of the savingNode (they are unmoved from the rotation)
				savingNode->balanceFactor = 0;
				badlyWeightedParent->balanceFactor = 0;
			}

			else // the other condition, the right child of the savingChildRight had a height longer than the its previous sibling
			{
				//then the leftChild of the savingNode will have height with one bigger than its new sibling => 
				savingNode->balanceFactor = -1;
				// than the right child of the badlyWeightedParent will have the same height as its new sibling =>
				badlyWeightedParent->balanceFactor = 0;
			}
		}

		savingNodeRightChild->balanceFactor = 0;
		return savingNodeRightChild;

	}


	Node<T>* Add(Node<T>*& treeNode, Node<T>* comingFromNode, const T& x) const
	{
		if (treeNode == nullptr)
		{
			treeNode = new Node<T>;
			treeNode->data = x;

			if (comingFromNode == nullptr)
			{
				return treeNode;
			}
				
			treeNode->parent = comingFromNode;
			return treeNode;
		}

		if (x < treeNode->data)
		{
			return Add(treeNode->left, treeNode, x);
		}

		return Add(treeNode->right, treeNode, x);
	}

	Node<T>* TryDeletingNodePointer(Node<T>* root, const T& withValue)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (root->data > withValue)
		{
			return TryDeletingNodePointer(root->left, withValue);
		}

		if (root->data < withValue)
		{
			return TryDeletingNodePointer(root->right, withValue);
		}

		//else
		Node<T>* tempPointer = nullptr;

		if (root->left == nullptr)
		{
			tempPointer = root;
			root = root->right;

			if (root != nullptr)
			{
				MakeRotationsAfterDelete(tempPointer->parent, tempPointer);

				//root->parent = tempPointer->parent;

				delete tempPointer;
				return root;
			}

			else
			{
				tempPointer->parent->right = nullptr;
				Node<T>* tempPointerParent = tempPointer->parent;

				MakeRotationsAfterDelete(tempPointer->parent, tempPointer);

				delete tempPointer;
				return tempPointerParent;
			}
		}

		else if (root->right == nullptr)
		{
			tempPointer = root;
			root = root->left;

			if (root != nullptr)
			{
				root->parent = tempPointer->parent;

				MakeRotationsAfterDelete(tempPointer->parent, tempPointer);

				delete tempPointer;
				return root;
			}

			else
			{
				tempPointer->parent->right = nullptr;
				Node<T>* tempPointerParent = tempPointer->parent;
				
				MakeRotationsAfterDelete(tempPointer->parent, tempPointer);

				delete tempPointer;
				return tempPointerParent;
			}
		}

		else
		{
			tempPointer = root->right;
			Node<T>* parentTempPointer = root;

			while (tempPointer->left != nullptr)
			{
				parentTempPointer = tempPointer;
				tempPointer = tempPointer->left;
			}

			root->data = tempPointer->data;

			MakeRotationsAfterDelete(tempPointer->parent, tempPointer);

			// then the right side of the root must only be changed
			if (root == parentTempPointer)
			{
				root->right = tempPointer->right;
				tempPointer->parent = root;
			}

			// there is no left child of the tempPointer, because the while would have gone there
			else
			{
				parentTempPointer->left = tempPointer->right;
			}

			// now nothing points to the tempPointer
			delete tempPointer;

			return parentTempPointer;
		}
	}

	void MakeRotationsAfterDelete(Node<T>* parentOfDeletedNode, Node<T>* deletedNode)
	{
		Node<T>* currentNode = deletedNode;
		Node<T>* grandParent = nullptr;
		Node<T>* movedNode = nullptr;
		char balancingParentChild;

		for (Node<T>* parent = parentOfDeletedNode; parent != nullptr; parent = currentNode->parent)
		{
			grandParent = parent->parent;

			if (currentNode == parent->left) // the left subtree decreases
			{
				if (parent->balanceFactor > 0) // parent is right-heavy => parentRightChild != nullptr
				{
					Node<T>* parentRightChild = parent->right;

					balancingParentChild = parentRightChild->balanceFactor;

					if (parentRightChild->balanceFactor < 0)
					{
						currentNode = RotateRightLeft(parent, parentRightChild);
					}

					else
					{
						currentNode = RotateLeft(parent, parentRightChild);
					}
				}

				else
				{
					if (parent->balanceFactor == 0)
					{
						parent->balanceFactor = 1;
						break;
					}

					currentNode = parent;
					currentNode->balanceFactor = 0;
					continue;
				}
			}

			else // currentNode is a rightChild
			{
				if (parent->balanceFactor < 0) // parent is leaftHeavy
				{
					Node<T>* parentLeftChild = parent->left;
					balancingParentChild = parentLeftChild->balanceFactor;

					if (parentLeftChild->balanceFactor > 0)
					{
						currentNode = RotateLeftRight(parent, parentLeftChild);
					}

					else
					{
						currentNode = RotateRight(parent, parentLeftChild);
					}
				}

				else
				{
					if (parent->balanceFactor == 0)
					{
						parent->balanceFactor = -1;
						break;
					}

					currentNode = parent;
					currentNode->balanceFactor = 0;
					continue;
				}
			}

			currentNode->parent = grandParent;

			if (grandParent != nullptr)
			{
				if (parent == grandParent->left)
				{
					grandParent->left = currentNode;
				}

				else
				{
					grandParent->right = currentNode;
				}

				if (balancingParentChild == 0)
				{
					break; // height does not change
				}
			}

			else
			{
				root = currentNode;
			}
		}
	}

public:
	AVLTree()
	{

	}

	~AVLTree()
	{
		DeleteTree(root);
	}

	AVLTree(const AVLTree& tree)
	{
		CopyTree(tree);
	}

	AVLTree& operator=(const AVLTree& rhs)
	{
		if (this != rhs)
		{
			DeleteTree(root);
			CopyTree(rhs);
		}

		return *this;
	}

	T GetRootData() const
	{
		return root->data;
	}

	Node<T>* GetRootPointer() const
	{
		return root;
	}

	AVLTree&& GetLeftTree() const
	{
		AVLTree leftTree;
		Copy(leftTree.root, root->left);
		return std::move(leftTree);
	}

	AVLTree&& GetRightTree() const
	{
		AVLTree leftTree;
		Copy(leftTree.root, root->left);
		return std::move(leftTree);
	}

	void Print() const
	{
		PrintFromNode(root);
	}

	void AddNode(const T& value)
	{
		Node<T>* currentNode = Add(root, nullptr, value);

		Node<T>* movedNode= nullptr;
		Node<T>* grandfather = nullptr;
		// now the rebalancing stuff
		for (Node<T>* parent = currentNode->parent; parent != nullptr; parent = currentNode->parent)
		{
			// the balanceFactor of the currentParent has to be updated
			if (currentNode == parent->right)
			{
				// the right subtree increases
				if (parent->balanceFactor > 0) // parent is right-heavy
				{
					// parent->balanceFactor will be equal to 2 (because of the newly added node

					// get the parent of the currentNode parent
					grandfather = parent->parent;

					if (currentNode->balanceFactor < 0) // right-left case
					{ 
						// double rotation: Right(currentNode) and then Left(parent)
						movedNode= RotateRightLeft(parent, currentNode);
					}

					else // >= 0
					{
						// rotation on the Left(X)
						movedNode= RotateLeft(parent, currentNode);
					}
				}

				else // parent->balanceFactor <= 0
				{
					// nothing to rotate, since it is balanced among its height
					if (parent->balanceFactor < 0)
					{
						parent->balanceFactor = 0;
						break;
					}

					// else parent->balanceFactor = 0
					// but there is no certainty that the tree will remain balanced among its lower heights
					parent->balanceFactor = 1;
					currentNode = parent;
					continue;
				}
			}

			else // => currentNode is a leftChild of the parent
			{
				if (parent->balanceFactor < 0) // x is left-heavy
				{
					grandfather = parent->parent;

					if (currentNode->balanceFactor > 0)
					{
						// left-right case, rotate Left(currentNode), Right(parent)
						movedNode = RotateLeftRight(parent, currentNode);
					}

					else
					{
						// left-left case
						//rotate Right(parent)
						movedNode = RotateRight(parent, currentNode);
					}
				}

				else // parent->balanceFactor >= 0
				{
					// because currentNode is a leftChild
					if (parent->balanceFactor > 0)
					{
						parent->balanceFactor = 0;
						break;
					}

					// again no certainty that the nodes on lower height will remain balanced
					parent->balanceFactor = -1;
					currentNode = parent;
					continue;
				}
			}

			// Now link the moved nodes, that are not linked after the rotation
			movedNode->parent = grandfather;

			// so that node has a parent
			if (grandfather != nullptr)
			{
				// do the linking for the grandfather
				if (parent == grandfather->left)
				{
					grandfather->left = movedNode;
				}

				else
				{
					grandfather->right = movedNode;
				}

				break;
			}

			// that node does not have a parent
			else
			{
				root = movedNode;
				break;
			}
		}
	}

	void DeleteNode(const T& value)
	{
		if (root == nullptr)
		{
			return;
		}

		TryDeletingNodePointer(root, value);
	}
};
#endif