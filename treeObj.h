#ifndef TREE_OBJ
#define TREE_OBJ

struct nodeType
{
	int item;
	nodeType * left;
	nodeType * right;
};//end node


class treeObj
{
private:
	nodeType * root;
	void inOrder(nodeType * p);
public:
	treeObj();
	treeObj(int itemIn);
	~treeObj();
	bool isEmptyTree();
	bool searchT(int key);
	void inOrderDisplay();
	bool insertT(int itemIn);
	void nodeCount(nodeType * p, int & count);
	int intCount();
	void preOrderDisplay();
	void preOrder(nodeType * p);
};

#endif // !TREE_OBJ
