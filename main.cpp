#include <iostream>
using namespace std;

#include "BSTree.h"

int main()
{
	BSTree *miArbol = new BSTree();

	miArbol->insert(15);
	miArbol->insert(20);
	miArbol->insert(10);
	miArbol->insert(8);
	miArbol->insert(12);
	miArbol->insert(24);
	miArbol->insert(22);
	miArbol->insert(14);
	miArbol->insert(1);
	miArbol->insert(4);

	miArbol->print(1);
	miArbol->print(2);
	miArbol->print(3);
	miArbol->print(4);
	cout << miArbol->count() << endl;

	if (miArbol->find(10))
		cout << "Si se encontro el 10" << endl;
	else
		cout << "No encontre el 10" << endl;

	if (miArbol->find(22))
		cout << "Si se encontro el 22" << endl;
	else
		cout << "No encontre el 22" << endl;

	if (miArbol->find(8))
		cout << "Si se encontro el 8" << endl;
	else
		cout << "No encontre el 8" << endl;

	if (miArbol->find(9))
		cout << "Si se encontro el 9" << endl;
	else
		cout << "No encontre el 9" << endl;

	miArbol->erase(15);
	cout << "Borrando el 15" << endl;

	miArbol->print(1);
	miArbol->print(2);
	miArbol->print(3);

	delete miArbol;

	return 0;
}