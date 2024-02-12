#include "SoftDrink.h"

class Lemonade : public SoftDrink{
    protected:
        std::string taste_;
        std::string color_;
    public:
        Lemonade(double volume = 0, double price = 0, const std::string& taste = "Original", const std::string& color = "Transparent") : SoftDrink(volume, price) {
            taste_ = taste;
            color_ = color;
        }

        Lemonade(const Lemonade& a) : SoftDrink(a) {
            taste_ = a.taste_;
            color_ = a.color_;
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

        bool operator==(const Lemonade& a){
            return taste_ == a.taste_ && color_ == a.color_ && SoftDrink::operator==(a);
        }

        Lemonade& operator=(const Lemonade& a){
            taste_ = a.taste_;
            color_ = a.color_;
            SoftDrink::operator=(a);
            return *this;
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