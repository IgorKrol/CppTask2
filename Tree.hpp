#include <iostream>

namespace ariel{
	class Tree
	{
		int key;
		Tree* p;
		Tree* l;
		Tree* r;

	public:
		Tree();
		~Tree(){
			if (this != NULL) { 
				this->l->print(); 
				this->r->print();
				delete(this);
			}
		}
		Tree(int k);
		Tree(int k, Tree* n);
		int getK(){return key;}
		Tree* getL(){return l;}
		Tree* getR(){return r;}
		Tree* getP(){return p;}
		void setL(Tree* left){l=left;}
		void setR(Tree* right){r=right;}
		void setP(Tree* parent){p=parent;}

		Tree* search(int i);
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