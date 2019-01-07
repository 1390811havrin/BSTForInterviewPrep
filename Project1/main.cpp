#include<iostream>
#include<cstdlib>
#include"BST.cpp"


using namespace std;

int main() {
	int TreeKeys[16] = { 50, 22, 33, 44, 55, 13, 21, 1 , 2, 3, 99, 77, 6, 345, 15, 16};
	BST myTree;
	myTree.PrintInOrder();
	for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);

	}

	myTree.PrintInOrder();
	cout << endl;
	myTree.PrintChildren(myTree.ReturnRootKey());

	return 0;
}