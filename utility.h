#include <iostream>
using namespace std;

class Movie{
private:
  string name;
  double rating;
public:
  Movie(string n = " ", double r = 0.0){
    name = n;
    rating = r;
  }
  Movie(const Movie& m2){
    name = m2.name;
    rating = m2.rating;
  }
  string getName() const {
    return name;
  }
  void setName(string n){
    name = n;
  }
  double getRating() const{
    return rating;
  }
  void setRating(double r){
    rating = r;
  }
  void print(){
    cout<<"Name: "<<name<<", Rating: "<<rating<<endl;
  }
};
