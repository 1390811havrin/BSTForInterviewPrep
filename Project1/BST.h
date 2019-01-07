#pragma once
class BST
{
private:

	struct Node {
		int key;
		Node * right;
		Node * left;
	};

	Node * root;

	void AddLeafPrivate(int key, Node* ptr);
	void PrintInOrderPrivate(Node* ptr);
	Node * ReturnNodePrivate(int key, Node * ptr) ;
	int FindSmallestPrivate(Node * ptr);
	void RemoveNodePrivate(int key, Node* parent);
	void RemoveRootMatch();
	void RemoveMatch(Node * parent, Node* match, bool left);
public:
	BST();
	~BST();
	Node* CreateLeaf(int key);
	void AddLeaf(int key);
	void PrintInOrder();
	Node* ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key);

};

