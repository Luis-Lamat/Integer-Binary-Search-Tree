#include <iostream>
using namespace std;

#include "tnode.h"

class BSTree //integer Binary Search Tree
{
	private:
		tnode *root;
		void preorden(tnode *r);
		void inorden(tnode *r);
		void postorden(tnode *r);
		void print_Leaf(tnode *r); //recursive leaf printing method
		void dest(tnode *r);
		int how_Many_Children_In(tnode *r);
		int predecessor(tnode *r);
		int successor(tnode *r);
		int countRec(tnode *r); //recursive node counting method
	public:
		BSTree();
		~BSTree();
		bool find(int d);
		bool insert(int d);
		bool erase(int d);
		void print(int option);
		int count();
};

void BSTree::dest(tnode *r){
	if (r != NULL){
		dest(r->getLeft());
		dest(r->getRight());
		delete r;
	}
}

BSTree::BSTree(){
	root = NULL;
}

BSTree::~BSTree(){
	dest(root);
}

bool BSTree::find(int d){
	tnode *aux = root;
	while (aux != NULL)
	{
		if (aux->getData() == d)
			return true;
		aux = (d < aux->getData()) ? aux = aux->getLeft() : aux = aux->getRight();
	}
	return false;
}

bool BSTree::insert(int d){
	if (root == NULL)
		root = new tnode(d);
	else {
		tnode *parent = NULL, *aux = root;

		while (aux != NULL){
			if (aux->getData() == d)
				return false;
			parent = aux;
			aux = (d < aux->getData()) ? aux->getLeft() : aux->getRight();
		}

		tnode *added_Node = new tnode(d);
		if (d < parent->getData()) {
			parent->setLeft(added_Node);
		} else {
			parent->setRight(added_Node);
		}
	}
	return true;
}

void BSTree::preorden(tnode *r){
	if (r != NULL) {
		cout << r->getData() << " ";
		preorden(r->getLeft());
		preorden(r->getRight());
	}
}

void BSTree::inorden(tnode *r){
	if (r != NULL) {
		inorden(r->getLeft());
		cout << r->getData() << " ";
		inorden(r->getRight());
	}
}

void BSTree::postorden(tnode *r){
	if (r != NULL) {
		postorden(r->getLeft());
		postorden(r->getRight());
		cout << r->getData() << " ";
	}
}

void BSTree::print_Leaf(tnode *r){ //recursive leaf printing method
	if (r != NULL){
		if (how_Many_Children_In(r) == 0){
			cout << r->getData() << " ";
		} else {
			print_Leaf(r->getLeft());
			print_Leaf(r->getRight());
		}
	}
}

void BSTree::print(int option){
	switch (option){
		case 1: preorden(root);
				break;
		case 2: inorden(root);
				break;
		case 3: postorden(root);
			    break;
		case 4: print_Leaf(root);
				break; 
	}
	cout << endl;
}

int BSTree::how_Many_Children_In(tnode *r){
	int count = 0;
	if (r->getLeft())
		count++;
	if (r->getRight())
		count++;
	return count;
}

int BSTree::predecessor(tnode *r){
	tnode *aux = r->getLeft();
	while (aux->getRight() != NULL){
		aux = aux->getRight();
	}
	return aux->getData();
}

int BSTree::successor(tnode *r){
	tnode *aux = r->getRight();
	while (aux->getLeft() != NULL){
		aux = aux->getLeft();
	}
	return aux->getData();
}

bool BSTree::erase(int d){
	if (root == NULL)
		return false;
	tnode *parent = NULL;
	tnode *aux = root;
	while (aux->getData() != d){
		parent = aux;
		aux = (d < aux->getData()) ? aux->getLeft() : aux->getRight();
		if (aux == NULL)
			return false;
	}
	int number_Of_Children = how_Many_Children_In(aux);

	if (number_Of_Children == 0){
		if (parent == NULL){
			delete root;
			root = NULL;
		} else {
			if (parent->getData() > d)
				parent->setLeft(NULL);
			else
				parent->setRight(NULL);
			delete aux;
		}
	}
	else if (number_Of_Children == 1){
		if (parent == NULL)
			root = (root->getLeft() != NULL) ? root->getLeft() : root->getRight(); 
		else {
			if (parent->getData() > d){
				if (aux->getLeft() != NULL)
					parent->setLeft(aux->getLeft());
				else
					parent->setLeft(aux->getRight());
			}
			else {
				if (aux->getLeft() != NULL)
					parent->setRight(aux->getLeft());
				else
					parent->setRight(aux->getRight());
			}
		}
		delete aux;
	}
	else {
		int p = predecessor(aux);
		erase(p);
		aux->setData(p);
	}
	return true;
}

int BSTree::countRec(tnode *r){ //recursive counting method
	if (r != NULL)
		//returning a count of 1 (root) + any nodes on the left or right from root...
		return 1 + countRec(r->getLeft()) + countRec(r->getRight());
	return 0;
}

int BSTree::count(){
	return countRec(root);
}

