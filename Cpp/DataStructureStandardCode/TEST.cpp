#include "DAST.h"
//------------------ functions

//------------------ main
int main(){
	Tree tree;
	tree.insert(tree.root, 50);
	tree.insert(tree.root, 70);
	tree.insert(tree.root, 25);
	tree.insert(tree.root, 30);
	tree.insert(tree.root, 10);
	tree.insert(tree.root, 80);
	tree.insert(tree.root, 17);
	tree.insert(tree.root, 5);
	tree.root=tree.remove(tree.root, 5);
	tree.showPreorder(tree.root);
}