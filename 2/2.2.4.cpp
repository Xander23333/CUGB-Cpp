#include<iostream>
using namespace std;
#include<ctime>

#define rep(i,x) for(int i=0;i<x;++i)

class RandomNum{
public:
  RandomNum(unsigned int seed);
  void setSeed(unsigned int seed);
  int random();
  int random(int max);
  double frandom();
private:
};


RandomNum::RandomNum(unsigned int seed){
  if (seed!=0) srand(seed);
  else srand((unsigned int)time(NULL));
}
void RandomNum::setSeed(unsigned int seed){
  srand(seed);
}
int RandomNum::random(){
  return rand();
}
int RandomNum::random(int max){
  return rand()%max;
}
double RandomNum::frandom(){
  return (double)random(RAND_MAX)/(double)RAND_MAX;
}
int main(){
  RandomNum randomGenerator(100);
  int i;
  rep(i,100){
    cout<<randomGenerator.random(100)<<' ';
  }  cout<<"\n";
  rep(i,100) 
    cout<<randomGenerator.frandom()<<' ';
  cout<<"\n";
  return 0;
}