#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "tests.h"

using namespace std;

int main(int argc, char** argv){

  testInsert();
  testSearchPrefix();
  testmaxRating();


}
void testInsert(){
  Movie m1("a name", 9.9);
  MovieBST testBST;
  testBST.insert(m1);
  if(testBST.contains(m1)){
    cout<<"INSERT FUNCTION TEST: PASSED"<<endl;
  }
  else
    cout<<"INSERT FUNCTION TEST: FAILED"<<endl;
}


void testSearchPrefix(){
  Movie m1("name", 9.9);
  Movie m2("another", 0.0);
  MovieBST testBST;
  testBST.insert(m1);
  testBST.insert(m2);
  string prefix = "ano";
  vector<Movie> vv = testBST.searchPrefix(prefix);
  for(int i = 0; i < vv.size();i++){
    if(vv[i].getName() == m2.getName()){
      cout<<"SEARCH PREFIX TEST: PASSED"<<endl;
      return;
    }
  }
  cout<<"SEARCH PREFIX TEST: FAILED"<<endl;
}

void testmaxRating(){
  Movie m1("name1", 1.0);
  Movie m2("name2", 2.0);
  Movie m3("name3", 3.0);
  MovieBST testBST;
  testBST.insert(m1);
  testBST.insert(m2);
  testBST.insert(m3);
  vector<Movie> vv = testBST.searchPrefix("name");
  Movie max = testBST.maxRating(vv);
  if(max.getName() == m3.getName()){
    cout<<"MAX RATING TEST: PASSED"<<endl;
  }
  else{
    cout<<"MAX RATING TEST: FAILED"<<endl;
  }
}
