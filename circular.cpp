#include<stdio.h>
#include<conio.h>
#include<Math.h>
#include<iostream>
#include <fstream>
using namespace std;

class Circular
{
private:


public:
    void Dimensions1();
    void no_of_loads1();
    void location_magnitude1();
    void reactions1();
    void moments_finder1(double []);
    void bending_stress1(double [],double []);
    double Inertia1();


    double d,L1,Inertia_of_beam1;
    int no_of_load_var1;

    double ra1,rb1,suma1=0,sumb1=0;

    double load_location1[10][2];

    int max1=0,pos1=0;

};

double Circular::Inertia1()
{
    Inertia_of_beam1= (3.1413*d*d*d*d)/64;
    return Inertia_of_beam1;
}




void Circular::Dimensions1()
{
    std::cout<<"\n\nPlease Enter the dimensions: \n";
    std::cout<<"Diameter = ";
    std::cin>>d;
    std::cout<<"LENGTH = ";
    std::cin>>L1;

}

void Circular::no_of_loads1()
{
    std::cout<<"\n\nEnter the number of loads [Max 10]\n";
    std::cin>>no_of_load_var1;
}

void Circular::location_magnitude1()
{
    std::cout<<"\n\n\n";
    for(int i=0; i<no_of_load_var1;i++)
    {

        std::cout<<(i+1)<<". Enter the magnitude of load in N and Location in m == ";

        for(int j = 0 ; j<2 ;j++)
        {

        std::cin>>load_location1[i][j];

        }
        std::cout<<"\n";

    }
}

void Circular::reactions1()
{


    for(int i=0; i<no_of_load_var1 ; i++)
    {
         suma1+=(load_location1[i][0]*load_location1[i][1]);
    }
    rb1 = suma1/L1;

    for(int i=0; i<no_of_load_var1 ; i++)
    {
         sumb1+=(load_location1[i][0]*(L1-load_location1[i][1]));
    }
    ra1 = sumb1/L1;

    std::cout<<"\nThe Reaction Force Ra = ";
    std::cout<<ra1;
    std::cout<<"\nThe Reaction Force Rb = ";
    std::cout<<rb1;

    std::cout<<"\n\n";

}


void Circular::moments_finder1(double get1[])
{
    double a1[no_of_load_var1];
    for(int i=0 ; i<no_of_load_var1;i++)
    {
    a1[i]=0;
    get1[i]=0;
    }
    get1[0]=ra1*load_location1[0][1];

      for(int i =1 ; i<no_of_load_var1;i++)
      {
          for(int j =0 ; j<i;j++)
          {

              a1[i]=a1[i]+(load_location1[j][0])*(load_location1[i][1]-load_location1[j][1]);

              get1[i]=(ra1*load_location1[i][1])-a1[i];

          }

     }



    for(int i=0 ; i<no_of_load_var1;i++)
    {
    std::cout<<"\nThe Moment at load"<<i+1<<" = ";
    std::cout<<get1[i];
    }

    std::cout<<"\n\n";

}

void Circular::bending_stress1(double get_stresses1 [],double moments1[])
{
    ofstream file1;
    file1.open ("out.txt");
        file1<<"0"<<","<<"0"<<"\n";
        for(int i = 0; i<no_of_load_var1;i++)
        {
           get_stresses1[i]=(moments1[i]*0.5*d)/(Inertia1());
           std::cout<<"\nThe Bendning stress at load"<<i+1<<" = "<<get_stresses1[i];
           file1<<get_stresses1[i]<<","<<load_location1[i][1]<<"\n";
        }
        file1<<"0"<<","<<(L1)<<"\n";
        file1.close();

        for(int i =0 ; i<no_of_load_var1;i++)
       {
           if(max1<moments1[i])
           {
               max1 = moments1[i];
               pos1=i;
           }
       }
       //std::cout<<"\n\n\nThe Maximum Moment is = "<<max1<<" at point "<<pos1+1;
       //std::cout<<"\nThe Maximum Bending stress is ="<<get_stresses1[pos1]<<" at point "<<pos1+1;
      // std::cout<<"\n\n";
       ofstream abc1;
       abc1.open("som.txt");
       abc1<<max1<<" "<<Inertia1()<<" "<<d<<" "<<get_stresses1[pos1]<<" "<<pos1+1;
       abc1.close();
}
