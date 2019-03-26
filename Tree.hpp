#include <iostream>

namespace ariel{

	class Node{
	public:
		int key;
		Node* p;
		Node* l;
		Node* r;


		~Node();

		Node(int k, Node* n=NULL);
		Node* search(int i);
		int size();
		void printNode(Node* n);
	};
	class Tree
	{
		Node* Root;

	public:
		Tree();
		~Tree(){
			if(Root!=NULL){
				delete(Root);
			}
		}
		Tree(int k);
		Tree(int k, Tree* n);

		Node* search(int i);
		Tree& insert(int i);
		void remove(int i);
		int size();
		bool contains(int i);
		int root();
		int parent(int i);
		int left(int i);
		int right(int i);
		void print();

	};
}