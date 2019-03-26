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
/**
 * Destractor
 */ 
Node::~Node(){
	delete(l);
	l=NULL;
	delete(r);
	r=NULL;
	p=NULL;
	// delete(p);
}

/**
 * search i value as Recurtion
 * if exists returns node with key=i
 * if doesnt exist returns parent node for i
 * */
Node* Node::search(int i){
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
		std::cout<<"["<<n->key<<"]"<<std::endl;
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
	if (Root == NULL){
		throw string("ERROR(REMOVE):Tree is Empty"); ;
	}
	Node* tNode = this->search(i);
	// didnt find i
	if (tNode->key!=i){
		throw string("ERROR(REMOVE):Integer "+to_string(i)+" doesnt exists"); ;
	}
	// tNode->key==i
	else{
		// if (this->size()==1){
		// 	delete(Root);
		// 	Root=NULL;
		// }
		// if(tNode->l!=NULL){
		// 	Node* temp = tNode->l->search(i);
		// 	Node* pNode = temp->p;
		// 	// std::cout<<i<<": Node.Key="<<temp->key<<" ,tNode-key="<<tNode->key<<std::endl;
		// 	tNode->key = temp->key;
		// 	delete(temp);
		// 	if(pNode->l==temp){
		// 		pNode->l=NULL;
		// 	}
		// 	else{
		// 		pNode->r=NULL;
		// 	}
		// }
		// else{
		// 	if(tNode->r!=NULL){
		// 		Node* temp = tNode->l->search(i);
		// 	Node* pNode = temp->p;
		// 	// std::cout<<i<<": Node.Key="<<temp->key<<" ,tNode-key="<<tNode->key<<std::endl;
		// 	tNode->key = temp->key;
		// 	delete(temp);
		// 	if(pNode->l==temp){
		// 		pNode->l=NULL;
		// 	}
		// 	else{
		// 		pNode->r=NULL;
		// 	}
		// 	}
		// }
	}
}
/**
 * returns tree size
 */ 
int Tree::size(){ 
	if (this->Root==NULL){
		return 0;
	}
	return this->Root->size();
}

/**
 * checks if tree contains value i
 */ 
bool Tree::contains(int i){
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
	if(Root != NULL){
		Root->printNode(Root);
	}

}
