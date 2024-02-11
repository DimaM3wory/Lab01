#include "SoftDrink.h"

class Lemonade : public SoftDrink{
    private:
        std::string taste_;
        std::string color_;
    public:
        Lemonade(double volume, double price, const std::string& taste, const std::string& color) : SoftDrink(volume, price) {
            taste_ = taste;
            color_ = color;
        }

        ~Lemonade(){};

        std::string getTaste() const{
            return taste_;
        }

        std::string getColor() const{
            return color_;
        }

        void setTaste(const std::string& taste){
            taste_ = taste;
        }

        void setColor(const std::string& color){
            color_ = color;
        }


        void drink(){
            std::cout << "I drink lemonade";
        }
};

std::ostream& operator<<(std::ostream& os, const Lemonade& data_){
    os << "It's a Lemonade" << '\n';
    os << "ID: " << data_.getID() << '\n';
    os << "Volume: " << data_.getVolume() << "L" << '\n';
    os << "Price: " << data_.getPrice() << "$" << '\n';
    os << "Taste: " << data_.getTaste() << '\n';
    os << "Color: " << data_.getColor() << '\n';
    return os;
}