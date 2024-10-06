#include <iostream>
using namespace std;
int main(){

int x;int sum=0;
cout<<"Enter students number:";
cin>>x;
int stu[x];
for(int i=0;i<x;i++){
cout<<"Student marks " <<i+1<<":"<<" ";
cin>>stu[i]; 

sum=sum+stu[i];
}

float avg= (float)sum/x;
cout<<"Total mark:"<<sum<<endl;
cout<<"Average mark:"<<avg<<endl;

int max=stu[0];
for(int i=1;i<x;i++){
if(max<stu[i]){
    max=stu[i];
}

}

int min=stu[0];
for(int i=1;i<x;i++){
if(min>stu[i]){
    min=stu[i];
}

}

cout<<"Maximum mark:"<<max<<endl;
cout<<"Minimum mark:"<<min<<endl;

    return 0;
} 
