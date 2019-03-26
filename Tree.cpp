#include <iostream>
#include "Tree.hpp"
using namespace ariel;
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
	if(l!=NULL){
		delete(l);
	} 
	if(r!=NULL){ 
		delete(r);
	}
	p=NULL;	
	free(this);
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
	printf("[%d]", n->key);
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
			throw;
		}
		catch(...){
			std::cerr<<"ERROR:INSERT"<<std::endl;
			throw;
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
		throw(i);
	}
	Node* tNode = this->search(i);
	try{
		// didnt find i
		if (tNode->key!=i){
			throw(i);
		}
		// tNode->key==i
		else{
			if(tNode->l==NULL && tNode->r==NULL){

			}
			else{
				if(tNode->l!=NULL){
					Node* temp = tNode->l->search(i);
					std::cout<<i<<": Node.Key="<<temp->key<<" ,tNode-key="<<tNode->key<<std::endl;
					tNode->key = temp->key;
					delete(temp);
				}
				else{
					Node* temp = tNode->r->search(i);
					std::cout<<i<<": Node.Key="<<temp->key<<" ,tNode-key="<<tNode->key<<std::endl;
					tNode->key = temp->key;
					delete(temp);
				}
			}
		}
	}
	catch (int i){
		std::cerr<<"Integer "<<i<<" doesnt exists"<<std::endl;
		throw;
	}
	catch(...){
		std::cerr<<"ERROR:REMOVE"<<std::endl;
		throw;
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
		throw;
	}
	catch(...){
		std::cerr<<"ERROR:ROOT"<<std::endl;
		throw;
	}
	return 0;
}
/**
 * returns parent value
 */
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
		throw;
	}
	catch(...){
		std::cerr<<"ERROR:PARENT"<<std::endl;
		throw;
	}
	return 0;
}
/**
 * returns left value
 */
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
		throw;
	}
	catch(...){
		std::cerr<<"ERROR:LEFT"<<std::endl;
		throw;
	}
	return 0;
}
/**
 * returns right value
 */
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
		throw;
	}
	catch(...){
		std::cerr<<"ERROR:RIGHT"<<std::endl;
		throw;
	}
	return 0;
}
/**
 * print tree
 */
void Tree::print(){
	if(Root != NULL){
		Root->printNode(Root);
		printf("\n");
	}

}
