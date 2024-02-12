#include "SoftDrink.h"

class Water : public SoftDrink{
    private:
        double hardness_;
    public:
        Water(double volume, double price, double hardness) : SoftDrink(volume, price) {
            hardness_ = hardness;
        }

        ~Water(){};

        double getHardness() const{
            return hardness_;
        }

        void setHardness(double hardness){
            hardness_ = hardness;
        }


        void drink(){
            std::cout << "I drink water";
        }

        bool operator==(const Water& a){
            return hardness_ == a.hardness_ && SoftDrink::operator==(a);
        }
};

std::ostream& operator<<(std::ostream& os, const Water& data_){
    os << "It's a Water" << '\n';
    os << "ID: " << data_.getID() << '\n';
    os << "Volume: " << data_.getVolume() << "L" << '\n';
    os << "Price: " << data_.getPrice() << "$" << '\n';
    os << "Hardness: " << data_.getHardness() << "mmol/L" << '\n';
    return os;
}