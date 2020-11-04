#include <iostream>
#include <string>
#include "treeObj.h"
using namespace std;


int main()
{
	treeObj tree2(77);

	tree2.insertT(33);
	tree2.insertT(88);
	tree2.insertT(22);

	cout << "In Order: " << endl;
	tree2.inOrderDisplay();

	cout << endl << "Pre Order: " << endl;
	tree2.preOrderDisplay();

	cout << endl << "Node Count: " << endl;
	cout << tree2.intCount() << endl;

	system("pause");

}//end main
