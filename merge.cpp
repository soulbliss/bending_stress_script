#include "rect.cpp"
#include "circular.cpp"
#include "hollowcircle.cpp"
#include "holrec.cpp"

#include<stdio.h>
#include<conio.h>
#include<Math.h>
#include<iostream>

static int first_choice;

int main()
{

    std::cout<<"The units used in calculations adn the result are : -\nForce - N\nLength - m\n";
    std::cout<<"==============================";


    std::cout<<"\n\n\nEnter the Beam type \n\n";
    std::cout<<"1 == Solid rectangular beam\n";
    std::cout<<"2 == Circular beam\n";
    std::cout<<"3 == Hollow Circular beam\n";
    std::cout<<"4 == Hollow Rectangular beam\n";

    std::cout<<"Enter your choice: ";
    std::cin>>first_choice;





    switch(first_choice)
    {
        case 1:
            {
            Rect a;
            std::cout<<"\n\n\n\ You have chosen A solid rectangualar beam\n";
            a.Dimensions();
            a.no_of_loads();
            a.location_magnitude();
            a.reactions();
            a.Inertia();

            double moments[a.no_of_load_var];
            a.moments_finder(moments);

            double bending_stress_array[a.no_of_load_var];
            a.bending_stress(bending_stress_array,moments);


            break;
            }


        case 2:
            {
            Circular b;
            std::cout<<"\n\n\n\ You have chosen A Circular beam\n";
            b.Dimensions1();
            b.no_of_loads1();
            b.location_magnitude1();
            b.reactions1();
            b.Inertia1();

            double moments1[b.no_of_load_var1];
            b.moments_finder1(moments1);

            double bending_stress_array1[b.no_of_load_var1];
            b.bending_stress1(bending_stress_array1,moments1);
            break;
            }



        case 3:
            {
            hollow c;
            std::cout<<"\n\n\n\ You have chosen A  Hollow Circular beam\n";
            c.Dimensions2();
            c.no_of_loads2();
            c.location_magnitude2();
            c.reactions2();
            c.Inertia2();

            double moments2[c.no_of_load_var2];
            c.moments_finder2(moments2);

            double bending_stress_array2[c.no_of_load_var2];
            c.bending_stress2(bending_stress_array2,moments2);
            break;
            }

        case 4:
            {
            holrec d;
            std::cout<<"\n\n\n\ You have chosen A Hollow rectangualar beam\n";
            d.Dimensions3();
            d.no_of_loads3();
            d.location_magnitude3();
            d.reactions3();
            d.Inertia3();

            double moments3[d.no_of_load_var3];
            d.moments_finder3(moments3);

            double bending_stress_array3[d.no_of_load_var3];
            d.bending_stress3(bending_stress_array3,moments3);
            break;
            }




        default:
            {
                std::cout<<"\n\nSorry Wrong Input entered";
            }





    }


 return 1;
}


