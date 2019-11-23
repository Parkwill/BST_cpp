#pragma once
#include "Node.h"
using namespace std;

class BST
{
private:
	Node* m_root;

	void _clear(Node* parent_node)
	{
		if (parent_node->left_child != NULL)
		{
			_clear(parent_node->left_child);
			parent_node->left_child = NULL;
		}

		if (parent_node->right_child != NULL)
		{
			_clear(parent_node->right_child);
			parent_node->right_child = NULL;
		}

		delete parent_node;
	}

public:
	//constructor
	BST();
	BST(int v);

	//destructor
	void clear();
	~BST();

	//m_function
	void BST_insert(int v); //clear
	void BST_delete(int v);
	Node* BST_search(int v);
	bool is_empty();
	void print(Node* r);

	Node* get_root()
	{
		return m_root;
	}
	int root_value()
	{
		return m_root->value;
	}
};

