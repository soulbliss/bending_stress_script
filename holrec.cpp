#include<stdio.h>
#include<conio.h>
#include<Math.h>
#include<iostream>
#include <fstream>
using namespace std;


class holrec
{
private:


public:
    void Dimensions3();
    void no_of_loads3();
    void location_magnitude3();
    void reactions3();
    void moments_finder3(double []);
    void bending_stress3(double [],double []);
    double Inertia3();


    double L3,bin,bout,hin,hout,Inertia_of_beam3;
    int no_of_load_var3;

    double ra3,rb3;
    double suma3=0;
    double sumb3=0;

    double load_location3[10][2];

    int max3=0,pos3=0;

};

double holrec::Inertia3()
{
    Inertia_of_beam3= ((bout*pow(hout,3))/12)-((bin*pow(hin,3))/12);
    return Inertia_of_beam3;
}




void holrec::Dimensions3()
{
    std::cout<<"\n\nPlease Enter the dimensions: \n";
    std::cout<<"LENGTH = ";
    std::cin>>L3;
    std::cout<<"INNER BREADTH = ";
    std::cin>>bin;
    std::cout<<"OUTER BREADTH = ";
    std::cin>>bout;
    std::cout<<"INNER HEIGHT = ";
    std::cin>>hin;
    std::cout<<"OUTER HEIGHT = ";
    std::cin>>hout;
}

void holrec::no_of_loads3()
{
    std::cout<<"\n\nEnter the number of loads [Max 10]\n";
    std::cin>>no_of_load_var3;
}

void holrec::location_magnitude3()
{
    std::cout<<"\n\n\n";
    for(int i=0; i<no_of_load_var3;i++)
    {

        std::cout<<(i+1)<<". Enter the magnitude of load in N and Location in m == ";

        for(int j = 0 ; j<2 ;j++)
        {

        std::cin>>load_location3[i][j];

        }
        std::cout<<"\n";

    }
}

void holrec::reactions3()
{


    for(int i=0; i<no_of_load_var3 ; i++)
    {
         suma3+=(load_location3[i][0]*load_location3[i][1]);
    }
    rb3 = suma3/L3;

    for(int i=0; i<no_of_load_var3 ; i++)
    {
         sumb3+=(load_location3[i][0]*(L3-load_location3[i][1]));
    }
    ra3 = sumb3/L3;

    std::cout<<"\nThe Reaction Force Ra = ";
    std::cout<<ra3;
    std::cout<<"\nThe Reaction Force Rb = ";
    std::cout<<rb3;

    std::cout<<"\n\n";

}


void holrec::moments_finder3(double get3[])
{
    double a3[no_of_load_var3];
    for(int i=0 ; i<no_of_load_var3;i++)
    {
    a3[i]=0;
    get3[i]=0;
    }
    get3[0]=ra3*load_location3[0][1];

      for(int i =1 ; i<no_of_load_var3;i++)
      {
          for(int j =0 ; j<i;j++)
          {

              a3[i]=a3[i]+(load_location3[j][0])*(load_location3[i][1]-load_location3[j][1]);

              get3[i]=(ra3*load_location3[i][1])-a3[i];

          }

     }



    for(int i=0 ; i<no_of_load_var3;i++)
    {
    std::cout<<"\nThe Moment at load"<<i+1<<" = ";
    std::cout<<get3[i];
    }

    std::cout<<"\n\n";

}

void holrec::bending_stress3(double get_stresses3 [],double moments3[])
{
    ofstream file3;
    file3.open ("out.txt");
    file3<<"0"<<","<<"0"<<"\n";
        for(int i = 0; i<no_of_load_var3;i++)
        {
           get_stresses3[i]=(moments3[i]*0.5*hout)/(Inertia3());
           std::cout<<"\nThe Bendning stress at load"<<i+1<<" = "<<get_stresses3[i];
           file3<<get_stresses3[i]<<","<<load_location3[i][1]<<"\n";
        }
        file3<<"0"<<","<<(L3)<<"\n";
        file3.close();

        for(int i =0 ; i<no_of_load_var3;i++)
       {
           if(max3<moments3[i])
           {
               max3 = moments3[i];
               pos3=i;
           }
       }
      // std::cout<<"\n\n\nThe Maximum Moment is = "<<max3<<" at point "<<pos3+1;
       //std::cout<<"\nThe Maximum Bending stress is ="<<get_stresses3[pos3]<<" at point "<<pos3+1;
       //std::cout<<"\n\n";
       ofstream abc3;
       abc3.open("som.txt");
       abc3<<max3<<" "<<Inertia3()<<" "<<hout<<" "<<get_stresses3[pos3]<<" "<<pos3+1;
       abc3.close();
}

