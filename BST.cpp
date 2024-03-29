#include "BST.h"

BST::BST()
{
	m_root = NULL;
}

BST::BST(int v)
{
	Node* New_node = new Node(v, NULL, NULL);
	m_root = New_node;
}

void BST::clear()
{
	_clear(m_root);
}
BST::~BST()
{
	if (m_root != NULL)
	{
		clear();
		m_root = NULL;
	}
}

bool BST::is_empty()
{
	if (m_root == NULL)
		return true;
	else
		return false;
}

void BST::BST_insert(int v)
{
	Node* New_node = new Node(v, NULL, NULL);
	Node* cur = m_root;

	if (m_root == NULL) // Case tree is empty
		m_root = New_node;
	else // Case tree is not empty
	{
		while (1) // instead of recursive
		{
			if (v < cur->value) // go left
			{
				if (cur->left_child == NULL) // Case NULL -> It is destination
				{
					cur->left_child = New_node;
					break;
				}
				cur = cur->left_child; // or go left
			}
			else // go right
			{
				if (cur->right_child == NULL) // Case NULL -> It is destination
				{
					cur->right_child = New_node;
					break;
				}
				cur = cur->right_child; // or go right
			}
		}//while end
	}//else if(tree is not empty) end

}

void BST::BST_delete(int v)
{
	Node* cur = m_root; //for search
	Node* del = NULL; //delete node
	Node* least = NULL; //find least value, and delete it instead of del when condition satisfied
	int temp = 0; // value of least

	if (is_empty() == true)
	{
		cout << "Tree is empty now." << endl;
		return;
	}

	while (1)
	{
		if (cur->value > v) //go left
		{
			del = cur->left_child;

			if (del == NULL) //cannot find destination
				break;

			if (del->value == v) //if left child of cur is destination
			{
				if (del->left_child == NULL && del->right_child == NULL) //leaf
				{
					cur->left_child = NULL;
					delete del;
				}
				else if (del->left_child != NULL && del->right_child == NULL) //only left child
				{
					cur->left_child = del->left_child;
					delete del;
				}
				else if (del->left_child == NULL && del->right_child != NULL) //only right child
				{
					cur->left_child = del->right_child;
					delete del;
				}
				else //has two children
				{
					least = del->right_child;
					while (least->left_child != NULL)
						least = least->left_child;
					temp = least->value;
					BST_delete(temp);
					del->value = temp;
				}

				break; //break the loop; subroutine executed
			}

			cur = del; // if delete not executed, go left
			continue; //and go back
		} // end if(go left)
		else if (cur->value < v) //go right
		{
			del = cur->right_child;

			if (del == NULL) //cannot find destination
				break;

			if (del->value == v) //if right child of cur is destination
			{
				if (del->left_child == NULL && del->right_child == NULL) //leaf
				{
					cur->right_child = NULL;
					delete del;
				}
				else if (del->left_child != NULL && del->right_child == NULL) //only left child
				{
					cur->right_child = del->left_child;
					delete del;
				}
				else if (del->left_child == NULL && del->right_child != NULL) //only right child
				{
					cur->right_child = del->right_child;
					delete del;
				}
				else //has two children
				{
					least = del->right_child;
					while (least->left_child != NULL)
						least = least->left_child;
					temp = least->value;
					BST_delete(temp);
					del->value = temp;
				}

				break; //break the loop; subroutine executed
			}

			cur = del; // if delete not executed, go right
			continue; // and go back
		} // end else if(go right)
		else // root of tree is destination
		{
			del = cur;

			if (del->left_child == NULL && del->right_child == NULL) //root == leaf
				delete del;
			else if (del->left_child != NULL && del->right_child == NULL) //only left child
			{
				m_root = del->left_child;
				delete del;
			}
			else if (del->left_child == NULL && del->right_child != NULL) //only right child
			{
				m_root = del->right_child;
				delete del;
			}
			else // has two children
			{
				least = del->right_child;
				while (least->left_child != NULL)
					least = least->left_child;
				temp = least->value;
				BST_delete(temp);
				del->value = temp;
			}

			break; // break the loop; subroutine executed
		} // end else(Case root)
	} // end while
}

Node* BST::BST_search(int v)
{
	Node* search = m_root;

	while (1) // search
	{
		if (v < search->value)
			search = search->left_child;
		else if (v > search->value)
			search = search->right_child;
		else
			break;
	}

	return search;
}

void BST::print(Node* r)
{
	if (r == NULL)
		return;
	//print inordered tree
	print(r->left_child);
	cout << r->value << ' ';
	print(r->right_child);
}