#include "AVLTree.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree()
{
	this->root = nullptr;
}

AVLTree::~AVLTree()
{
	BtsDestructor(root);
}

void AVLTree::BtsDestructor(Node* cursor)
{

	if (cursor == nullptr) {
		return;
	}

	BtsDestructor(cursor->left);
	BtsDestructor(cursor->right);
	delete cursor;
	return;

}

void AVLTree::Insert(int value)
{
	root = InsertHelper(root, value);
	root->UpdateHeight();
}
Node* AVLTree::InsertHelper(Node* cursor, int value)
{
	//RecursionCounter neededForUnitTest;
	if (cursor == nullptr)
	{
		return new Node(value, nullptr, nullptr);

	}
	else if (cursor->value > value)
	{
		cursor->left = InsertHelper(cursor->left, value);

	}
	else {
		cursor->right = InsertHelper(cursor->right, value);


	}
	cursor->UpdateHeight();
	cursor = re_Balance(cursor);
	return cursor;

}
Node* AVLTree::Search(int value)
{

	return SearchHelper(root, value);
}
Node* AVLTree::SearchHelper(Node* cursor, int value)
{
	//RecursionCounter neededForUnitTest;
	if (cursor == nullptr) {

		return cursor;
	}
	else if (cursor->value == value) {

		return cursor;
	}
	else if (value < cursor->value) {

		return SearchHelper(cursor->left, value);
	}
	else {

		return SearchHelper(cursor->right, value);
	}
}

void AVLTree::Remove(int value)
{
	root = RemoveHelper(root, value);
	if (root != nullptr) {
		root->UpdateHeight();
	}
}
Node* AVLTree::RemoveHelper(Node* cursor, int value)
{
	//RecursionCounter neededForUnitTest;
	if (cursor == nullptr) {
		return cursor;
	}
	if (value < cursor->value) {
		cursor->left = RemoveHelper(cursor->left, value);
	}
	else if (value > cursor->value) {
		cursor->right = RemoveHelper(cursor->right, value);
	}
	else {
		if (cursor->left == nullptr && cursor->right == nullptr) {
			delete cursor;
			return nullptr;
		}
		else if (cursor->left == nullptr) {
			Node* tmp = cursor->right;
			delete cursor;
			return tmp;

		}
		else if (cursor->right == nullptr) {
			Node* tmp = cursor->left;
			delete cursor;
			return tmp;
		}
		else {
			Node* Successor = cursor->right;
			while (Successor->left != nullptr) {
				Successor = Successor->left;
			}
			cursor->value = Successor->value;
			cursor->right = RemoveHelper(cursor->right, cursor->value);

		}

	}

	return cursor;
}
void AVLTree::PreOrderTraversal()
{
	PreorderHelper(root);
	cout << endl;
}
void AVLTree::PreorderHelper(Node* cursor)
{
	//RecursionCounter neededForUnitTest;
	if (cursor == nullptr) {
		return;
	}
	cout << cursor->value << ", ";
	PreorderHelper(cursor->left);
	PreorderHelper(cursor->right);


}
void AVLTree::Print()
{
	string offset = "";
	PrintHelper(offset, root);
	cout << endl << endl;
}

void AVLTree::PrintHelper(string& offset, Node* cursor)
{
	//RecursionCounter neededForUnitTest;
	if (cursor == nullptr) {
		cout << offset << "[Empty]";
		cout << endl;
		return;
	}
	else if (cursor->IsLeaf() == true) {
		cout << offset << cursor->value << " (" << cursor->height << ") " << "[leaf]" << endl;
		return;
	}
	else {
		cout << offset << cursor->value << " (" << cursor->height << ") " << endl;
	}
	string wire = offset + "   ";
	PrintHelper(wire, cursor->left);
	PrintHelper(wire, cursor->right);
}
int AVLTree::Size()
{
	return SizeHelper(root);
}
int AVLTree::SizeHelper(Node* cursor)
{
	//RecursionCounter neededForUnitTest;
	if (cursor == nullptr) {
		return 0;
	}
	return 1 + SizeHelper(cursor->left) + SizeHelper(cursor->right);
}

Node* AVLTree::re_Balance(Node* cursor)
{

	if (Balance_Factor(cursor) < -1)
	{
		// this is a Right-??? proglem
		if (Balance_Factor(cursor->right) < 0)
		{
			// right-right problem
			cursor = Ro_left(cursor);
		}
		else
		{
			// right-left problem
			cursor->right = Ro_right(cursor->right);
			cursor = Ro_left(cursor);
		}


	}

	else if (Balance_Factor(cursor) > 1)
	{
		// this is a Left-??? proglem
		if (Balance_Factor(cursor->left) > 0)
		{
			// left-left problem
			cursor = Ro_right(cursor);
		}
		else
		{
			// left-right problem
			cursor->left = Ro_left(cursor->left);
			cursor = Ro_right(cursor);
		}
	}
	return cursor;
}

int AVLTree::Balance_Factor(Node* cursor)
{
	if (cursor->left != nullptr && cursor->right != nullptr)
		return cursor->left->height - cursor->right->height;
	else if (cursor->left == nullptr && cursor->right == nullptr)
	{
		return 0;
	}
	else if (cursor->left == nullptr)
	{
		return -1 - cursor->right->height;
	}
	else {
		return cursor->left->height + 1;
	}


}

Node* AVLTree::Ro_right(Node* cursor)
{
	Node* tmp;
	tmp = cursor->left;
	cursor->left = tmp->right;
	tmp->right = cursor;
	cursor->UpdateHeight();
	tmp->UpdateHeight();
	return tmp;
}

Node* AVLTree::Ro_left(Node* cursor)
{
	Node* tmp;
	tmp = cursor->right;
	cursor->right = tmp->left;
	tmp->left = cursor;
	cursor->UpdateHeight();
	tmp->UpdateHeight();
	return tmp;

}



