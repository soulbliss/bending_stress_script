#include<stdio.h>
#include<conio.h>
#include<Math.h>
#include<iostream>
#include <fstream>
using namespace std;

class hollow
{
private:


public:
    void Dimensions2();
    void no_of_loads2();
    void location_magnitude2();
    void reactions2();
    void moments_finder2(double []);
    void bending_stress2(double [],double []);
    double Inertia2();


    double din,dout,L2,Inertia_of_beam2;
    int no_of_load_var2;

    double ra2,rb2,suma2=0,sumb2=0;

    double load_location2[10][2];
    int max2=0,pos2=0;



};

double hollow::Inertia2()
{
    Inertia_of_beam2= (3.1413*(pow(dout,4)-pow(din,4)))/64;
    return Inertia_of_beam2;
}




void hollow::Dimensions2()
{
    std::cout<<"\n\nPlease Enter the dimensions: \n";
    std::cout<<"Inner Diameter = ";
    std::cin>>din;
    std::cout<<"Outer Diameter = ";
    std::cin>>dout;
    std::cout<<"LENGTH = ";
    std::cin>>L2;

}

void hollow::no_of_loads2()
{
    std::cout<<"\n\nEnter the number of loads [Max 10]\n";
    std::cin>>no_of_load_var2;
}

void hollow::location_magnitude2()
{
    std::cout<<"\n\n\n";
    for(int i=0; i<no_of_load_var2;i++)
    {

        std::cout<<(i+1)<<". Enter the magnitude of load in N and Location in m == ";

        for(int j = 0 ; j<2 ;j++)
        {

        std::cin>>load_location2[i][j];

        }
        std::cout<<"\n";

    }
}

void hollow::reactions2()
{


    for(int i=0; i<no_of_load_var2 ; i++)
    {
         suma2+=(load_location2[i][0]*load_location2[i][1]);
    }
    rb2 = suma2/L2;

    for(int i=0; i<no_of_load_var2 ; i++)
    {
         sumb2+=(load_location2[i][0]*(L2-load_location2[i][1]));
    }
    ra2 = sumb2/L2;

    std::cout<<"\nThe Reaction Force Ra = ";
    std::cout<<ra2;
    std::cout<<"\nThe Reaction Force Rb = ";
    std::cout<<rb2;

    std::cout<<"\n\n";

}


void hollow::moments_finder2(double get2[])
{
    double a2[no_of_load_var2];
    for(int i=0 ; i<no_of_load_var2;i++)
    {
    a2[i]=0;
    get2[i]=0;
    }
    get2[0]=ra2*load_location2[0][1];

      for(int i =1 ; i<no_of_load_var2;i++)
      {
          for(int j =0 ; j<i;j++)
          {

              a2[i]=a2[i]+(load_location2[j][0])*(load_location2[i][1]-load_location2[j][1]);

              get2[i]=(ra2*load_location2[i][1])-a2[i];

          }

     }



    for(int i=0 ; i<no_of_load_var2;i++)
    {
    std::cout<<"\nThe Moment at load"<<i+1<<" = ";
    std::cout<<get2[i];
    }

    std::cout<<"\n\n";

}

void hollow::bending_stress2(double get_stresses2 [],double moments2[])
{
    ofstream file2;
    file2.open ("out.txt");
    file2<<"0"<<","<<"0"<<"\n";
        for(int i = 0; i<no_of_load_var2;i++)
        {
           get_stresses2[i]=(moments2[i]*0.5*dout)/(Inertia2());
           std::cout<<"\nThe Bendning stress at load"<<i+1<<" = "<<get_stresses2[i];
           file2<<get_stresses2[i]<<","<<load_location2[i][1]<<"\n";
        }
        file2<<"0"<<","<<(L2)<<"\n";
        file2.close();

        for(int i =0 ; i<no_of_load_var2;i++)
       {
           if(max2<moments2[i])
           {
               max2 = moments2[i];
               pos2=i;
           }
       }
      // std::cout<<"\n\n\nThe Maximum Moment is = "<<max2<<" at point "<<pos2+1;
       //std::cout<<"\nThe Maximum Bending stress is ="<<get_stresses2[pos2]<<" at point "<<pos2+1;
       //std::cout<<"\n\n";
       ofstream abc2;
       abc2.open("som.txt");
       abc2<<max2<<" "<<Inertia2()<<" "<<dout<<" "<<get_stresses2[pos2]<<" "<<pos2+1;
       abc2.close();
}

