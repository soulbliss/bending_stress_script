#include<stdio.h>
#include<conio.h>
#include<Math.h>
#include<iostream>
#include <fstream>
using namespace std;



class Rect
{
private:


public:
    void Dimensions();
    void no_of_loads();
    void location_magnitude();
    void reactions();
    void moments_finder(double []);
    void bending_stress(double [],double []);
    double Inertia();


    double L,b,h,Inertia_of_beam;
    int no_of_load_var;

    double ra,rb;
    double suma=0;
    double sumb=0;

    double load_location[10][2];

    int max=0,pos=0;




};

double Rect::Inertia()
{
    Inertia_of_beam= (b*h*h*h)/12;
    return Inertia_of_beam;
}




void Rect::Dimensions()
{
    std::cout<<"\n\nPlease Enter the dimensions: \n";
    std::cout<<"LENGTH = ";
    std::cin>>L;
    std::cout<<"BREADTH = ";
    std::cin>>b;
    std::cout<<"HEIGHT = ";
    std::cin>>h;
}

void Rect::no_of_loads()
{
    std::cout<<"\n\nEnter the number of loads [Max 10]\n";
    std::cin>>no_of_load_var;
}

void Rect::location_magnitude()
{
    std::cout<<"\n\n\n";
    for(int i=0; i<no_of_load_var;i++)
    {

        std::cout<<(i+1)<<". Enter the magnitude of load in N and Location in m == ";

        for(int j = 0 ; j<2 ;j++)
        {

        std::cin>>load_location[i][j];

        }
        std::cout<<"\n";

    }
}

void Rect::reactions()
{


    for(int i=0; i<no_of_load_var ; i++)
    {
         suma+=(load_location[i][0]*load_location[i][1]);
    }
    rb = suma/L;

    for(int i=0; i<no_of_load_var ; i++)
    {
         sumb+=(load_location[i][0]*(L-load_location[i][1]));
    }
    ra = sumb/L;

    std::cout<<"\nThe Reaction Force Ra = ";
    std::cout<<ra;
    std::cout<<"\nThe Reaction Force Rb = ";
    std::cout<<rb;

    std::cout<<"\n\n";

}


void Rect::moments_finder(double get[])
{
    double a[no_of_load_var];
    for(int i=0 ; i<no_of_load_var;i++)
    {
    a[i]=0;
    get[i]=0;
    }
    get[0]=ra*load_location[0][1];

      for(int i =1 ; i<no_of_load_var;i++)
      {
          for(int j =0 ; j<i;j++)
          {

              a[i]=a[i]+(load_location[j][0])*(load_location[i][1]-load_location[j][1]);

              get[i]=(ra*load_location[i][1])-a[i];

          }



     }



    for(int i=0 ; i<no_of_load_var;i++)
    {
    std::cout<<"\nThe Moment at load"<<i+1<<" = ";
    std::cout<<get[i];
    }

    std::cout<<"\n\n";

}

void Rect::bending_stress(double get_stresses [],double moments[])
{
    ofstream file;
    file.open ("out.txt");
        file<<"0"<<","<<"0"<<"\n";
        for(int i = 0; i<no_of_load_var;i++)
        {
           get_stresses[i]=(moments[i]*0.5*h)/(Inertia());
           std::cout<<"\nThe Bendning stress at load"<<i+1<<" = "<<get_stresses[i];
           file<<get_stresses[i]<<","<<load_location[i][1]<<"\n";
        }
        file<<"0"<<","<<(L)<<"\n";
        file.close();

        for(int i =0 ; i<no_of_load_var;i++)
       {
           if(max<moments[i])
           {
               max = moments[i];
               pos=i;
           }
       }

       ofstream abc;
       abc.open("som.txt");
       abc<<max<<" "<<Inertia()<<" "<<h<<" "<<get_stresses[pos]<<" "<<pos+1;
       abc.close();
}


