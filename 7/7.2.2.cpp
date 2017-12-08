#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Predicate{
private:
  int count=0;
public:
  bool operator()(int data){
    if ( count>=3 ) return false;
    else{
      bool x=(data<=20 && data%3==0);
      count+=x;
     // cout<<x<<" "<<count<<endl;
      return x;
    }
  }
};

int main(){
 Predicate predicate;
 vector<int> vec{2,4,5,6,10,15,3,21,36,72,9,13};
 vector<int> result;
 result.resize (vec.size());
// auto end=copy_if(vec.begin (),vec.end (),result.begin(),predicate);
 int count=0;
 auto end=copy_if(vec.begin (),vec.end (),result.begin()
                  ,[&count](int data)->bool{    
                      if ( count>=3 ) return false;
                      else{
                        bool x=(data<=20 && data%3==0);
                        count+=x;return x;
                      }
                    }
                  );

 result.erase(end,result.end ());
 for_each(result.begin (),result.end (),[](int e){cout<<e<<endl;});
 return 0;
}
