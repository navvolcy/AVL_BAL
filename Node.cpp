#include "Node.h"

// creating the node
Node::Node(int value, Node* left, Node* right)
{
	this->value = value;
	this->left = left;
	this->right = right;
	this->height = 0;
}
// deletes the  node 
Node::~Node()
{
}
// checking if the leaf (childNode) is empty
bool Node::IsLeaf()
{
	if (left == nullptr && right == nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}

void Node::UpdateHeight()
{  // initialize both heights to 0
	int r_height = -1;
	int l_height = -1;
	// check if the  child node exist
	if (right != nullptr)
	{
		right->UpdateHeight();
		r_height = this->right->height;
	}
	if (left != nullptr)
	{
		left->UpdateHeight();
		l_height = this->left->height;
	}
	// compare the right child node and the leftChild child node
	if (r_height >= l_height)
	{
		height = r_height + 1;
	}
	else {
		height = l_height + 1;
	}

}
