#include <iostream>
#include "Tree.hpp"
#include <cmath>
#include <cassert>
#include <string>
using namespace ariel;
using namespace std;
/**
 * Node initiator: 
 * k=key value
 * n=parent node (NULL by default)
*/
Node::Node(int k, Node* n){
	key=k;
	l=NULL;
	r=NULL;
	p=n;
}
/**1
 * Destractor
 */ 
Node::~Node(){
	p=NULL;
	delete l;
	l=NULL;
	delete r;
	r=NULL;

	// delete(p);
}
// /**
//  * node recursive removal
//  */ 
// Node::deleteNode(Node* n, int i){

// }

/**
 * search i value as Recurtion
 * if exists returns node with key=i
 * if doesnt exist returns parent node for i
 * */
Node* Node::search(int i){
	cout<<"search "<<i<<endl;
	Node* tNode = this;
	if (tNode->key==i){
		return tNode;
	}
	else{
		if(tNode->key>i){
			if (tNode->l==NULL){ return tNode; }
			return tNode->l->search(i);
		}
		else{
			if (tNode->r==NULL){ return tNode; }
			return tNode->r->search(i);
		}
	}
}
/**
 * returns number of nodes in tree
 */ 
int Node::size(){
	Node* node = this;
	if (node == NULL)  
		return 0;  
	else
		return(node->l->size() + 1 + node->r->size()); 
}
/**
 * print function for nodes: inc order
 */ 
void Node::printNode(Node* n){
	
	if(n->l!=NULL){
		printNode(n->l);
	} 
	if(n!=NULL){
		std::cout<<"["<<n->key<<"]";
	}
	if(n->r!=NULL){
		printNode(n->r);
	} 
}

/**
 * default init
 */ 
Tree::Tree(){
	Root = NULL;
}

/** this function search for key=i
	if found -> return Tree* for him
	if not found -> return NULL pointer where he should have been.*/
Node* Tree::search(int i){
	if (Root==NULL){
		return Root;
	}
	else{
		return Root->search(i);
	}
}

/* this function inserts int i ass data to BST, if i exists, error will accure */
Tree& Tree::insert(int i){
	cout<<"insert "<<i<<endl;
	if (Root == NULL){

		Root = new Node(i);
		Root->p=Root;
	}
	else{
		Node* tNode = this->search(i);

		if (tNode->key==i){ 
			throw string("ERROR(INSERT):Integer "+to_string(i)+" already exists"); 
		}
		else{
			if (tNode->key>i){
				tNode->l=new Node(i,tNode);
				tNode=tNode->l;
			}
			else{
				tNode->r=new Node(i,tNode);
				tNode=tNode->r;
			}
		}
	}
	return *this;
}
/**
 * removes node with i value
 * if doesnt exits, throws error
 */ 
void Tree::remove(int i){
	print();
	cout<<"remove "<<i<<endl;
	if (Root == NULL || Root->size()==0){
		throw string("ERROR(REMOVE):Tree is Empty");
		cout<<"Removed"<<endl;
		return;
	}
	Node* tNode = this->search(i);
	// didnt find i
	if (tNode->key!=i){
		throw string("ERROR(REMOVE):Integer "+to_string(i)+" doesnt exists");
		cout<<"Removed"<<endl;
		return;
	}
	// tNode->key==i
	else{
		if (tNode->l==NULL && tNode->r==NULL){//leaf
			Node* pNode = tNode->p;
			if (pNode==tNode){//leaf is Root
				delete(Root);
				Root=NULL;
			}
			else{
				pNode->l==tNode ? pNode->l=NULL : pNode->r=NULL;
				delete(tNode);
			}
			cout<<"Removed"<<endl;
			return;
		}//end_if leaf
		else{//not leaf
			Node* A=NULL;
			Node* B=NULL;
			Node* C=NULL;
			Node* E=NULL;
			Node* F=NULL;
			//A=tNode parent,B=C->p, C=Node to swap with tNode, E=tNode->l,  F= C child if C isnt leaf.
			A = tNode->p;
			// E = tNode->l;
			tNode->r!=NULL ? C=tNode->r->search(i) : C=tNode->l->search(i);
			B = C->p;
			if(C->l==NULL && C->r==NULL){//C is leaf
				B->l==C ? B->l=NULL : B->r=NULL;
				tNode->key=C->key;
				delete(C);
				cout<<"Removed"<<endl;
				return;
			}
			if (A==tNode){//tNode is root and isnt leaf
				if(C->l==NULL){
					C->l=tNode->l;
					tNode->r->p=Root;
					Root=tNode->r;
				}
				else{
					C->r=tNode->r;
					tNode->l->p=Root;
					Root=tNode->l;
				}
				tNode->l=NULL;
				tNode->r=NULL;
				delete(tNode);
				cout<<"Removed"<<endl;
				return;
			}
			else{//C isnt leaf nor root
				if(B==tNode){//tNode is C->p
					A->l==tNode ? A->l=C : A->r=C;
					C->p=A;
					if(C->l==NULL){
						C->l=E;
						E==NULL ? 0 : E->p=C;
					}
					else{
						C->r=E;
						E==NULL ? 0 : E->p=C;
					}
					tNode->l=NULL;
					tNode->r=NULL;
					tNode->p=NULL;
					delete(tNode);
					cout<<"Removed"<<endl;
					return;
				}
				if(C->l==NULL){
					E = tNode->l;
					F = C->r;
					C->l=E;
					C->r=B;
					B->l=F;
				}
				else{
					E = tNode->r;
					F = C->l;
					C->r=E;
					C->l=B;
					B->r=F;
				}
				A->l==tNode ? A->l=C : A->r=C;
				C->p=A;
				E!=NULL? E->p=C : 0 ;
				F->p=B;
				B->p=C;
				cout<<C->key<<endl;
				delete(tNode);
				cout<<"Removed"<<endl;
				return;
			}
		}
	}
}
/**
 * returns tree size
 */ 
int Tree::size(){ 
	cout<<"size"<<endl;
	if (this->Root==NULL){
		return 0;
	}
	return this->Root->size();
}

/**
 * checks if tree contains value i
 */ 
bool Tree::contains(int i){
	cout<<"contains "<<i<<endl;
	if(Root==NULL){
		return false;
	}
	Node* tNode = this->search(i);
	if (tNode->key==i){
		return true;
	}
	else{
		return false;
	}
}
/**
 * returns root value
 */
int Tree::root(){
	cout<<"root "<<endl;
	if (Root==NULL){
		throw string("ERROR(ROOT):Tree is empty"); 
	}

	if (this->size() == 0){
		throw string("ERROR(ROOT):Tree is empty"); 
	}
	else{
		return this->Root->key;
	}
	return 0;
}
/**
 * returns parent value
 */
int Tree::parent(int i){
	cout<<"parent"<<i<<endl;
	if (Root==NULL){
		throw string("ERROR(PARENT):Tree is empty"); 
	}
	Node* tNode = this->search(i);
	if (tNode->key==i){
		if(tNode->p==NULL){
			throw string("ERROR(PARENT):Integer "+to_string(i)+" doesnt exists"); 
		}
		else{
			return tNode->p->key;
		}
	}
	else{
		throw string("ERROR(PARENT):Integer "+to_string(i)+" doesnt exists");
	}
	return 0;
}
/**
 * returns left value
 */
int Tree::left(int i){
	cout<<"left"<<i<<endl;
	if (Root==NULL){
		throw string("ERROR(LEFT):Tree is empty");
	}
	Node* tNode = this->search(i);
	if (tNode->key==i){
		return tNode->l->key;
	}
	else{
		throw string("ERROR(LEFT):Integer "+to_string(i)+" doesnt exists");;
	}
	return 0;
}
/**
 * returns right value
 */
int Tree::right(int i){
	cout<<"right"<<i<<endl;
	if (Root==NULL){
		throw string("ERROR(RIGHT):Tree is empty");
	}
	Node* tNode = this->search(i);

	if (tNode->key==i){
		return tNode->r->key;
	}
	else{
		throw string("ERROR(RIGHT):Integer "+to_string(i)+" doesnt exists");
	}
	return 0;
}
/**
 * print tree
 */
void Tree::print(){
	cout<<"print:"<<endl;
	if(Root != NULL){
		Root->printNode(Root);
		cout<<""<<endl;
	}

}
