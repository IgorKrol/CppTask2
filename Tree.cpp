#include <iostream>
#include "Tree.hpp"
using namespace ariel;

Node::Node(int k, Node* n){
	key=k;
	l=NULL;
	r=NULL;
	p=n;
}

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

int Node::size(){
	Node* node = this;
	if (node == NULL)  
		return 0;  
	else
		return(node->l->size() + 1 + node->r->size()); 
}

void Node::print(){
	if(this->l!=NULL){
		this->l->print();
	} 
	printf("[%d],", this->key);
	if(this->r!=NULL){ 
		this->r->print();
	} 
}

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
	std::cerr<<"Insert"<<i<<std::endl;
	if (Root == NULL){
		Root = new Node(i);
	}
	else{
		Node* tNode = this->search(i);
		try{
			if (tNode->key==i){ throw(i); }
			else{
				if (tNode->key>i){
					tNode->l=new Node(i,tNode);
				}
				else{
					tNode->r=new Node(i,tNode);
				}
			}
		}
		catch(int i){
			std::cerr<<"Integer "<<i<<" already exists"<<std::endl;
		}
		catch(...){
			std::cerr<<"ERROR:INSERT"<<std::endl;
		}
	}
	return *this;
}

void Tree::remove(int i){
	Node* tNode = this->search(i);
	try{
		// didnt find i
		if (tNode == NULL){
			throw(i);
		}
		if (tNode->key!=i){
			throw(i);
		}
		// tNode->key==i
		else{
			if (tNode->l == NULL){
				tNode->p->r=tNode->r;
				delete(tNode);
			}
			else{
				//search to get max value in left tree -> switch and remove
				Node* temp = tNode->l->search(i);
				tNode->key = temp->key;
				delete(temp);
			}
		}
	}
	catch (int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
	catch(...){
		std::cerr<<"ERROR:REMOVE"<<std::endl;
	}
}

int Tree::size(){ 
	if (this->Root==NULL){
		return 0;
	}
	return this->Root->size();
}

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

int Tree::root(){
	if (Root==NULL){
		throw(0);
	}
	try{
		if (this->size() == 0){
			throw(0);
		}
		else{
			return this->Root->key;
		}
	}
	catch(int i){
		std::cerr<<"Root doesnt have value"<<std::endl;
	}
	catch(...){
		std::cerr<<"ERROR:ROOT"<<std::endl;
	}
	return 0;
}

int Tree::parent(int i){
	if (Root==NULL){
		throw(i);
	}
	try{
		Node* tNode = this->search(i);
		if (tNode->key==i){
			if(tNode->p==NULL){
				throw(i);
			}
			else{
				return tNode->p->key;
			}
		}
		else{
			throw(i);
		}
	}
	catch(int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
	catch(...){
		std::cerr<<"ERROR:PARENT"<<std::endl;
	}
	return 0;
}
int Tree::left(int i){
	if (Root==NULL){
		throw(i);
	}
	Node* tNode = this->search(i);
	try{
		if (tNode->key==i){
			return tNode->l->key;
		}
		else{
			throw(i);
		}
	}
	catch(int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
	catch(...){
		std::cerr<<"ERROR:LEFT"<<std::endl;
	}
	return 0;
}
int Tree::right(int i){
	if (Root==NULL){
		throw(i);
	}
	Node* tNode = this->search(i);
	try{
		if (tNode->key==i){
			return tNode->r->key;
		}
		else{
			throw(i);
		}
	}
	catch(int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
	catch(...){
		std::cerr<<"ERROR:RIGHT"<<std::endl;
	}
	return 0;
}

void Tree::print(){
	if(Root != NULL){
		Root->print();
	}
}
