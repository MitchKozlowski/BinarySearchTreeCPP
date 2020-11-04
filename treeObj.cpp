#include <iostream>
#include <string>
#include "treeObj.h"
using namespace std;

treeObj::treeObj()
{

}//end default constructor
treeObj::treeObj(int itemIn)
{
	insertT(itemIn);
}//end second constructor
treeObj::~treeObj()
{
	// deubugginh
	cout << "\n in the destructor...\n";
	// visit each node and delete it
}//end destructor

bool treeObj::insertT(int itemIn)
{// get a new node
	nodeType * newNode;
	//1. get a new node
	newNode = new nodeType;
	if (newNode == NULL)
		return false;
	//2. put in data
	newNode->item = itemIn;
	//3. set pointers
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
	{//the new item is the root
		root = newNode;
		return true;
	}

	nodeType * prev = NULL;
	nodeType * pres = root;
	//search for the proper location in the tree
	//previous will be needed to put new node in location
	bool found = false;
	while ((pres != NULL) && (!found))
	{//keep looking
		if (itemIn == pres->item) //found
			found = true;
		else if (itemIn < pres->item)
		{//go to the left
			prev = pres;
			pres = pres->left;
		}
		else //go to the right
		{
			prev = pres;
			pres = prev->right;
		}

	}//end while

	if (found) //duplicate
	{
		return false;
	}
	else
	{
		//general case, with at least 1 node.
		//left or right?
		if (itemIn < prev->item) //left
			prev->left = newNode;
		else
			prev->right = newNode;
		return true;
	}//end not null.
}
bool treeObj::isEmptyTree()
{
	return root == NULL;
}//end is empty
bool treeObj::searchT(int key)
{
	return false;
}//end search
void treeObj::inOrderDisplay()
{
	inOrder(root);
}//end inorder display
void treeObj::inOrder(nodeType * p)
{
	if (p)
	{// go left
		inOrder(p->left);
		// visit the node
		cout << p->item << endl;
		// go right
		inOrder(p->right);
	}// valid node
}


void treeObj::nodeCount(nodeType * p, int & count)
{
	if (p) {
		count++;
		nodeCount(p->left, count);
		nodeCount(p->right, count);
	}
}//end node count

int treeObj::intCount()
{
	int count = 0;
	nodeCount(root, count);
	return count;
}
void treeObj::preOrderDisplay()
{
	preOrder(root);
}

void treeObj::preOrder(nodeType * p)
{
	if (p)
	{
		cout << p->item << endl;
		inOrder(p->left);
		inOrder(p->right);
	}
}
