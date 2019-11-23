#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
	BST t;

	t.BST_insert(11);
	t.BST_insert(5);
	t.BST_insert(3);
	t.BST_insert(15);
	t.BST_insert(13);

	t.print(t.get_root());
	cout << "(Root : " << t.root_value() << ')' << endl;

	t.BST_delete(11);

	t.print(t.get_root());
	cout << "(Root : " << t.root_value() << ')' << endl;

	return 0;
}