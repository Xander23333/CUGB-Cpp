#include<iostream>
#include<vector>
using namespace std;

vector<int>* getDig(vector<vector<int> > matrix);

int main(){
  vector<vector<int> > data;
  int n;cin>>n;
  for (int i=0;i<n;++i){
    data.push_back(vector<int>());
    for (int j=0;j<n;++j){
      data[i].push_back(i+j);
    }
  }
  vector<int>* diagonal = getDig(data);
  for (auto i:(*diagonal)){
    cout<<i<<" ";
  }cout<<endl;

}

vector<int>* getDig(vector<vector<int> > matrix){
  int n=matrix.size();
  vector<int> arr;
  for (int i=0;i<n;++i){
    arr.push_back(matrix[i][i]);
  }
  return (&arr);
}