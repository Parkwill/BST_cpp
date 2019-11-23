#pragma once
#include <iostream>
using namespace std;

class Node
{
	friend class BST; // get, set need x
private:
	int value; // integer value
	Node* left_child;
	Node* right_child;

public:
	Node();
	Node(int v, Node* lc, Node* rc);
};

