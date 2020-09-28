#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << " arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }

  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2] << endl;
    exit(1);
  }
  MovieBST movieTree;
  vector<Movie> searchVector;
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
      Movie m1(movieName, movieRating);
      movieTree.insert(m1);
      searchVector.push_back(m1);
  }
  Movie m2(movieName, movieRating);
  if(flag == false){
    int w = atoi(argv[3]);
    clock_t t;
    t = clock();
    for(int i = 0; i < searchVector.size(); i++){
      bool b1 = movieTree.contains(searchVector[i]);
    }
    t = clock()-t;
    double r = ((double)t);
    cout<<t<<endl;
    cout<<searchVector.size()<<endl;
  //  double average = (double)t/searchVector.size();
  //  cout<<"Average time: "<<average<<endl;
  }
if(flag == true){
  movieTree.printPreOrder();
  cout<<endl;
  vector<Movie> vv = movieTree.searchPrefix(argv[3]);
  Movie max = movieTree.maxRating(vv);
  cout<<"Best movie is "<<max.getName()<<" with rating "<<max.getRating()<<endl;
  movieFile.close();
  return 0;
  }
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }

  movieRating = stod(tempRating);
  return true;
}
