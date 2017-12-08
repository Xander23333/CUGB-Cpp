#include<iostream>
using std::cout;using std::endl;using std::cin;using std::ostream;
template <typename T>
class Array1D{
public:
  Array1D(int newSize);
  Array1D(T *p,int newSize);
  Array1D(const Array1D <T>& a);
  ~Array1D();
  int getSize() const;
  T max()const;
  void reverse();
  const T& operator[](int index) const;
  T& operator[](int index);
  Array1D<T>& operator = (const Array1D<T>& a);
  friend ostream& operator<< (ostream& out,Array1D<T>& t){
    for(int i=0;i<t.size;++i) out<<t[i]<<" ";
    return out<<endl;
  }
private:
  T *pData;
  int size;
};
template <typename T>
Array1D<T>::Array1D(int newSize):size(newSize){
  pData=new T[size];
}
template <typename T>
Array1D<T>::Array1D(T *p,int newSize):pData(p),size(newSize){}
template <typename T>
Array1D<T>::Array1D(const Array1D <T> &a):size(a.size){
  pData=new T[size]; 
  for(int i=0;i<size;++i) pData[i]=a[i];
}
template <typename T>
Array1D<T>::~Array1D(){
  delete[] pData;
}
template <typename T>
int Array1D<T>::getSize() const{
  return size;
}
template <typename T>
T Array1D<T>::max() const {
  if (size==0) {
    cout<<"No elem!\n";
    exit(0);
  }
  T Max=pData[0];
  for(int i=1;i<size;++i){
    if(pData[i] > Max) Max=pData[i];
  }
  return Max;
}
template <typename T>
void Array1D<T>::reverse(){
  for(int i=0;i<size/2;++i){
    swap(pData[i],pData[size-1-i]);
  }
}
template <typename T>
const T& Array1D<T>::operator[](int index) const{
  return pData[index];
}
template <typename T>
T& Array1D<T>::operator[](int index){
  return pData[index];
}
template <typename T>
Array1D<T>& Array1D<T>::operator=(const Array1D<T>& a){
  delete[] pData;
  size=a.size;
  pData=new T[size];
  for(int i=0;i<size;++i) pData[i]=a[i];
}
int main(){
  Array1D <int> array(5);
  for(int i=0;i<array.getSize();++i)
    array[i]=i+1;
  cout<<"Max:"<<array.max()<<endl;
  for(int i=0;i<array.getSize();++i)
    cout<<array[i]<<" ";
  cout<<endl;
  cout<<array;
  return 0;
}