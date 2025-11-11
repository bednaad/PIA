#include <iostream>

class Kruh
{
    public:
        float Plocha;
        float Obvod;

        void setRadius(float radius_in){
            radius = radius_in;
        }
        float getRadius(){
            return radius;
        }
        float spocitejObvod(){
                Obvod = 2*3.14*radius;
                return Obvod;
        }

        float spocitejPlochu(){
                Plocha = 3.14*radius*radius;
                return Plocha;
        }

    void vypisUdaje(){
        std::cout << "radius: " << radius<< std::endl;
        std::cout << "plocha: " << Plocha<< std::endl;
        std::cout << "Obvod: " << Obvod<< std::endl;
    }


    private:
        float radius;

    

};

int main()
{
    float prvniRadius = 2;
    Kruh prvniKruh;
    prvniKruh.setRadius( prvniRadius );
   
    prvniKruh.spocitejObvod();
    prvniKruh.spocitejPlochu();
    prvniKruh.vypisUdaje();
    
/*
    float druhyRaidus = 4;
    Kruh druhyKruh( druhyRaidus );
    druhyKruh.setRadius( druhyRaidus );
    druhyKruh.getRadius( druhyRaidus );
    druhyKruh.spocitejObvod( druhyRaidus );
    druhyKruh.spocitejPlochu(druhyRaidus);


    std::cout << "Plocha kruhu:" << prvniKruh.spocitejPlochu() << std::endl;
    std::cout << "Obvod kruhu:" << prvniKruh.spocitejObvod() << std::endl;

    druhyKruh.vypisUdaje();

    // BONUS: radius kruhu bude sablonovy parametr, a udela pole kruhu a pro kazdy kruh spocita vse
*/
    return 0;
}