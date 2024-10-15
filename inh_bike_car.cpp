#include <bits/stdc++.h>
using namespace std;

class car{
  
  private:
  string model;
  
  protected:
  
  int year;
  int speed;
  
  
  public:
  
  car(string m,int s,int y){
      model=m;
      speed=s;
      year=y;
      
  }
  
  void dis(){
       cout<<"Car Model:"<<model<<endl;
  }
  void dis1(){
     
         cout<<"Speed Limited:"<<speed<<"cc"<<endl;
            cout<<"Year:"<<year<<endl;
  }
  

};


class bike:public car{
  
  private:
  string modell;
  string color;
  public:
  
  bike(string mo,string co,int s,int y) : car( mo,s, y){
      modell=mo;
      color=co;
  }
  
   void dis2(){
     
        
      cout<<"Bike Model:"<<modell<<endl;
         
            cout<<"Bike Color:"<<color<<endl;
             dis1();
           
  }
  
    
};

int main (){
    car c("Honda civic",1230,2024);
    c.dis();
    c.dis1();
    
    bike b("R15M","Silver",150,2024);
    b.dis2();
    return 0;
}