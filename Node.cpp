#include "Node.h"

Node::Node()
{
	value = NULL;
	left_child = NULL;
	right_child = NULL;
}
Node::Node(int v, Node* lc, Node* rc)
{
	value = v;
	left_child = lc;
	right_child = rc;
}