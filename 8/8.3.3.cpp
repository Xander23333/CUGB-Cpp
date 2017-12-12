#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<fstream>
using namespace std;
class Student
{
private:
    string name;
    string specialty;
    long long id;
    double creditPoint;
public:
    Student(string n,string s,long long i,double c):name(n),specialty(s),id(i),creditPoint(c){}
    void setCreditPoint(double c)
    {
        creditPoint=c;
    }
    double getCreditPoint()const
    {
        return creditPoint ;
    }
    string getName()const
    {
        return name;
    }
    long long getId()const
    {
        return id;
    }
    string getSpecialty()const
    {
        return specialty;
    }
    friend ostream& operator<<(ostream& out,const Student& s)
    {
        cout<<"Name:"<<s.name<<endl;
        cout<<"  Id:"<<s.id<<endl;
        cout<<"  Specialty:"<<s.specialty<<endl;
        cout<<"  CreditPoint:"<<s.creditPoint<<endl;
    }
};
class StudentManage
{
public:
    enum SortType{BY_NAME,BY_ID,BY_SPECIALTY,BY_CRDITPOINT};
    StudentManage()=default;
    void addStudent();
    void removeStudent();
    void setSortType(SortType st);
    void findStudent();
    int size()const{return students.size();}
    void loadData(string filename);
    void saveData(string filename);
    friend ostream& operator<<(ostream& out,const StudentManage& sm);
private:
    vector<Student> students;
    SortType sortType=BY_ID;
};
void StudentManage::addStudent()
{
    string n,s;
    long long i;
    double c;
    cout<<"please enter\nname:";
    cin>>n;
    cout<<"specialty:";
    cin>>s;
    cout<<"id:";
    cin>>i;
    cout<<"credit:";
    cin>>c;
    students.push_back(Student(n,s,i,c));
    SortType st=BY_ID;
    setSortType(st);
}
void StudentManage::removeStudent()
{
    long long i;
    cout<<"please enter id:";
    cin>>i;
    for(auto it=students.begin();it!=students.end();++it)
    {
        if((*it).getId()==i)
        {
            students.erase(it);
            return;
        }
    }
}
void StudentManage::setSortType(SortType st)
{
    function<bool(const Student&,const Student&)> f;
    switch(st)
    {
    case BY_ID:
        f=[](const Student &s1,const Student &s2){return s1.getId()<s2.getId();};
        break;
    case BY_NAME:
        f=[](const Student &s1,const Student &s2){return s1.getName()<s2.getName();};
        break;
    case BY_SPECIALTY:
        f=[](const Student &s1,const Student &s2){return s1.getSpecialty()<s2.getSpecialty();};
        break;
    case BY_CRDITPOINT:
        f=[](const Student &s1,const Student &s2){return s1.getCreditPoint()<s2.getCreditPoint();};
        break;
    default:
        break;
    }
    sort(students.begin(),students.end(),f);
}
void StudentManage::findStudent()
{
    long long i;
    cout<<"please enter id:";
    cin>>i;
    for(auto stu:students)
    {
        if(stu.getId()==i)
        {
            cout<<stu;
            return;
        }
    }
}
void StudentManage::loadData(string filename)
{
    ifstream fin;
    fin.open(filename);
    string n;
    string s;
    long long i;
    double c;
    while(fin>>n>>s>>i>>c)
    {
        students.push_back(Student(n,s,i,c));
    }
    fin.close();
}
void StudentManage::saveData(string filename)
{
    ofstream fout;
    fout.open(filename,ios_base::out);
    for(auto stu:students)
    {
        fout<<stu.getName()<<' '<<stu.getSpecialty()<<' '<<stu.getId()<<' '<<stu.getCreditPoint()<<endl;
    }
    fout.close();
}
ostream& operator<<(ostream &out,const StudentManage &sm)
{
    cout<<"Cc"<<endl;
}
int main(){
    StudentManage sm;
    sm.loadData("students.txt" ); //从文件中加载数据
    if(sm.size()==0){
    sm.addStudent();
    sm.addStudent();
    sm.addStudent();
    sm.addStudent();
    }
    cout<<"sort type(0-name,1-id,2-specialty,3-creditpoint):";
    int choice;
    cin>>choice;
    sm.setSortType (static_cast<StudentManage::SortType>(choice));
    cout<<sm;
    sm.findStudent ();
    sm.removeStudent ();
    cout<<sm;
    sm.saveData("students.txt" ); //将数据保存到文件中
    return 0;
}

