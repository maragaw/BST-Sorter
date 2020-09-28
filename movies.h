#include <iostream>
#include <string>
#include <vector>
#include "utility.h"
using namespace std;

class MovieBST{
public:
  MovieBST();
  ~MovieBST();

  bool insert(Movie m1);
  vector<Movie> searchPrefix(string prefix);
  Movie maxRating(vector<Movie> movielist);
  void printPreOrder();
  bool contains(Movie m1) const;
private:
  struct Node{
    Movie item;
    Node* left;
    Node* right;
    Node* parent;
    int depth;
  Node(Movie m1, int d = 0 ) : left(0), right(0), parent(0) {
      item = m1;
      depth = d;
   }
  };
  Node* root; //pointer to root of bst
  void clear(Node* n);
  bool insert(Movie m1, Node* n, int depth);
  void printPreOrder(Node* n);
  void searchPrefix(Node* n, vector<Movie>& movielist, string prefix) const;
  Node* getNodeFor(Movie m1, Node* n) const;//returns node of given movie name

};
