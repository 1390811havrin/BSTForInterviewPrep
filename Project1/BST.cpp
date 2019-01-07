#include<cstdlib>
#include<iostream>
#include "BST.h"

using namespace std;

BST::Node * BST::CreateLeaf(int key)
{
	Node* n = new Node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::AddLeaf(int key)
{
	AddLeafPrivate(key, root);

}

void BST::PrintInOrder()
{
	PrintInOrderPrivate(root);
}

BST::Node * BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}

int BST::ReturnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		return -1000;
	}
	
}

void BST::PrintChildren(int key)
{
	Node * ptr = ReturnNode(key);
	if (ptr != NULL)
	{
		cout << "Parent Node = " <<ptr->key << endl;
		ptr->left == NULL ?
			cout << "LEft CHild = null \n" :
			cout << "LEft Child = " << ptr->left->key << endl;
		ptr->right == NULL ?
			cout << "Right CHild = null \n" :
			cout << "Right Child = " << ptr->right->key << endl;
	}
	else
	{
		cout << "not in tree \n";
	}

}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);

}

void BST::AddLeafPrivate(int key, Node * ptr)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < ptr->key)
	{
		if (ptr->left != NULL)
		{
			AddLeafPrivate(key, ptr->left);
		}
		else
		{
			ptr->left = CreateLeaf(key);
		}
	}
	else if (key > ptr->key)
	{
		if (ptr->right != NULL)
		{
			AddLeafPrivate(key, ptr->left);
		}
		else
		{
			ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		cout << "The Key " << key << " is already in the tree" << endl;
	}
}

void BST::PrintInOrderPrivate(Node * ptr)
{
	if (root != NULL)
	{
		if (ptr->left != NULL)
		{
			PrintInOrderPrivate(ptr->left);
		}
		cout << ptr->key << " ";
		if (ptr->right != NULL)
		{
			PrintInOrderPrivate(ptr->right);
		}
	}
	else
	{
		cout << "The Tree is Empty" << endl;
	}
}

BST::Node * BST::ReturnNodePrivate(int key, Node * ptr)
{
	if (ptr != NULL)
	{
		if (ptr->key == key)
		{
			return ptr;
		}
		else
		{
			if (key < ptr->key)
			{
				return ReturnNodePrivate(key, ptr->left);
			}
			else
			{
				return ReturnNodePrivate(key, ptr->right);
			}
		}
	}
	else
	{
		return NULL;
	}

}

int BST::FindSmallestPrivate(Node * ptr)
{
	if (root == NULL)
	{
		cout << "tree is empty\n";
		return -1000;
	}
	else
	{
		if (ptr->left != NULL)
		{
			return FindSmallestPrivate(ptr->left);

		}
		else
		{
			return ptr->key;
		}
	}
	return 0;
}

void BST::RemoveNodePrivate(int key, Node * parent)
{
	if (root != NULL)
	{
		if (root->key == key)
		{
			RemoveRootMatch();
		}
		else
		{
			if(key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else {
				cout << "the key " << key << " not in tree \n";
			}
		}
	}
	else
	{
		cout << "the tree is empty" << endl;
	}
}

void BST::RemoveRootMatch()
{
	if (root != NULL)
	{
		Node* delptr = root;
		int rootkey = root->key;
		int smallestInRightSubtree;
		//0 children
		if (root -> left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delptr;
		}
		//1 child 
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delptr -> right = NULL;
			delete delptr; //root with key deleted, new root contains key
		}
		//1 child
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delptr->left = NULL;
			delete delptr; //root with key deleted, new root contains key
		}
		//2 children
		else
		{
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree; //root key was overwritten by smallest from right tree. Smallest right leaf deleted
		}
	}
	else {
		cout << "tree empty" << endl;
	}

}

void BST::RemoveMatch(Node * parent, Node * match, bool left)
{
	if (root != NULL)
	{
		Node * delptr;
		int mathKey = match -> key;
		int smallestinrt;
		//0 children
		if (match->left == NULL && match->right == NULL)
		{
			delptr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delptr;
		}
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match -> right = NULL;
			delptr = match;
			delete delptr;

		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delptr = match;
			delete delptr;

		}
		else 
		{
			smallestinrt = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestinrt, match);
			match->key = smallestinrt;
		}
	}
	else
	{
		cout << "tree empty" << endl;
	}

}

BST::BST()
{
	root = NULL;

}


BST::~BST()
{
}
