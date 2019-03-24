#include <iostream>
#include "Tree.hpp"
using namespace ariel;

Tree::Tree(){}
Tree::Tree(int k){
	key=k;
	l=NULL;
	r=NULL; 
	p=NULL;
}
Tree::Tree(int k, Tree* n){
	key=k;
	l=NULL;
	r=NULL; 
	p=n;
}
/** this function search for key=i
	if found -> return Tree* for him
	if not found -> return NULL pointer where he should have been.*/
Tree* Tree::search(int i){
	// if (this==NULL){
	// 	return this;
	// }
	Tree* node = this;
	if (node->key==i){
		return node;
	}
	else{
		if(node->key>i){
			if (node->l==NULL){ return node; }
			return node->l->search(i);
		}
		else{
			if (node->r==NULL){ return node; }
			return node->r->search(i);
		}
	}
}

/* this function inserts int i as data to BST, if i exists, error will accure */
Tree& Tree::insert(int i){
	Tree* node = this->search(i);
	try{
		if (node == NULL){
			node = new Tree(i);
		}
		else{
			if (node->key==i){ throw(i); }
			else{
				if (node->key>i){
					node->l=new Tree(i,node);
				}
				else{
					node->l=new Tree(i,node);
				}
			}
		}
	}
	catch(int i){
		std::cerr<<"Integer "<<i<<" already exists"<<std::endl;
	}
	return *this;
}

void Tree::remove(int i){
	Tree* node = this->search(i);
	try{
		// didnt find i
		if (node == NULL){
			throw(i);
		}
		if (node->key!=i){
			throw(i);
		}
		// node->key==i
		else{
			if (node->l == NULL){
				node->p->r=node->r;
				delete(node);
			}
			else{
				//search to get max value in left tree -> switch and remove
				Tree* temp = node->l->search(i);
				node->key = temp->key;
				delete(temp);
			}
		}
	}
	catch (int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
}

int Tree::size(){ 
	Tree* node = this;
	if (node == NULL)  
		return 0;  
	else
		return(node->l->size() + 1 + node->r->size());  
}

bool Tree::contains(int i){
	Tree* temp = this;
	Tree* node = temp->search(i);
	if (node->key==i){
		return true;
	}
	else{
		return false;
	}
}

int Tree::root(){
	try{
		if (this->size() == 0){
			throw(0);
		}
		else{
			return this->key;
		}
	}
	catch(int i){
		std::cerr<<"Root doesnt have value"<<std::endl;
	}
	return 0;
}

int Tree::parent(int i){
	Tree* temp = this;
	Tree* node = temp->search(i);
	try{
		if (node->key==i){
			return node->p->key;
		}
		else{
			throw(i);
		}
	}
	catch(int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
	return 0;
}
int Tree::left(int i){
	Tree* temp = this;
	Tree* node = temp->search(i);
	try{
		if (node->key==i){
			return node->l->key;
		}
		else{
			throw(i);
		}
	}
	catch(int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
	return 0;
}
int Tree::right(int i){
	Tree* temp = this;
	Tree* node = temp->search(i);
	try{
		if (node->key==i){
			return node->r->key;
		}
		else{
			throw(i);
		}
	}
	catch(int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
	}
	return 0;
}

void Tree::print(){
	if (this != NULL) { 
        this->l->print(); 
        printf("[%d],", this->key); 
        this->r->print(); 
    }
}
