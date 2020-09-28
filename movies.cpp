#include <iostream>
#include <string>
#include <vector>
#include "movies.h"

using namespace std;

MovieBST::MovieBST() : root(0) { } //constructor

MovieBST::~MovieBST(){
  clear(root);
}
void MovieBST::clear(Node* n){
  if(n){
    clear(n->left);
    clear(n->right);
    delete n;
  }
}
bool MovieBST::insert(Movie m1){//needs to take Movie object
  if(!root){ //empty tree
    root = new Node(m1, 0); //
    return true;
  }
  return insert(m1, root, 0);
}
bool MovieBST::insert(Movie m1, MovieBST::Node* n, int depth){
  if(m1.getName() == n->item.getName()){
    return false;
  }
  if(m1.getName()< n->item.getName()){
    if(n->left){
      return insert(m1, n->left, depth+1);
    }
    else{
      n->depth = depth;
      n->left = new Node(m1, depth+1);
      n->left->parent = n;
      return true;
    }
  }
  else{
    if(n->right){
      return insert(m1, n->right, depth+1);
    }
    else{
      n->depth = depth;
      n->right = new Node(m1, depth+1);
      n->right->parent = n;
      return true;
    }
  }
}

void MovieBST::printPreOrder(){
  printPreOrder(root);
}
void MovieBST::printPreOrder(Node* n){
  if(n){
    cout << n->item.getName() << ", " << n->item.getRating() << ", " << n->depth << endl;
    printPreOrder(n->left);
    printPreOrder(n->right);
  }
}
vector<Movie> MovieBST:: searchPrefix(string prefix){
  int prelength = prefix.length();
  Node* n = this->root;
  while(n){ //iterate thru BST
    string s1 = n->item.getName().substr(0, prelength);
    if(prefix < s1){
      n=n->left;
    } else if(prefix > s1){
      n=n->right;
    }
    else{
      break;
    }
  }
    vector<Movie> vv1;
    searchPrefix(n, vv1, prefix);//search for next prefix matches
    if(vv1.size() == 0){
        return vv1;
    }
    return vv1;
}
void MovieBST::searchPrefix(MovieBST::Node* n, vector<Movie>& movielist, string prefix) const{
  int prelength = prefix.length();
  if(!n)
    return;
  if(n->item.getName().substr(0, prelength) == prefix)
    movielist.push_back(n->item);
    searchPrefix(n->left, movielist, prefix);
    searchPrefix(n->right, movielist, prefix);
}
Movie MovieBST::maxRating(vector<Movie> movielist){
  Movie m1 = movielist[0];
  for(int i = 0; i<movielist.size(); i++){
    if(m1.getRating()<movielist[i].getRating()){
      m1=movielist[i];
    }
  }
  return m1;
}
bool MovieBST::contains(Movie m1) const{
  return (getNodeFor(m1, root)!=NULL);
}
MovieBST::Node* MovieBST::getNodeFor(Movie m1, Node* n) const{
  if(n == NULL || n->item.getName() == m1.getName())
    return n;
  if(n->item.getName() < m1.getName())
    return getNodeFor(m1, n->right);
  return getNodeFor(m1, n->left);
}
