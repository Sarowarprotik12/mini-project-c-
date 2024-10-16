#include <bits/stdc++.h>
using namespace std;
class car{
  private:
  string model;
  
  public:
  int year;
  float speed;
  string color;
  
  car(string m,string c,float s,int y){
      model=m;
      color=c;
      speed=s;
      year=y;
  }
    
     void setModel(string m) {
        model = m;
    }

    void model1(){
        cout<<"Car Model:"<<model<<endl;
        
    }
    
    void display(){
         cout<<"Color:"<<color<<endl;
         cout<<"Speed:"<<speed<<"cc"<<endl;
         cout<<"Year:"<<year<<endl;
        
        
    }
    
    
};


class bike:public car{
  private:
  string modell;
  
  public:
  float price;
  
  bike(string mo,string c,float s,int y,float p): car(mo,c,s,y), price(p){
      modell=mo;
     
  }
  
  void dis(){
      cout<<"Bike Model:"<<modell<<endl;
      display();
      cout<<"Bike price:"<<price<<"Tk"<<endl;
  }
    
};




int main()
{
    car c("Rolls Royace","Red",1560,2024);
    c.model1();
    c.display();
    
    bike b("R15m Indonesia","Silver",150,2024,710000);
    b.dis();

    return 0;
}
