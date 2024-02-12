#include "SoftDrink.h"

class MineralWater : public SoftDrink{
    private:
        double pH_;
    public:
        MineralWater(double volume, double price, double pH) : SoftDrink(volume, price) {
            pH_ = pH;
        }

        ~MineralWater(){};

        double getPH() const{
            return pH_;
        }

        void setPH(double pH){
            pH_ = pH;
        }


        void drink(){
            std::cout << "I drink mineral water";
        }

        bool operator==(const MineralWater& a){
            return pH_ == a.pH_ && SoftDrink::operator==(a);
        }
};

std::ostream& operator<<(std::ostream& os, const MineralWater& data_){
    os << "It's a Mineral Water" << '\n';
    os << "ID: " << data_.getID() << '\n';
    os << "Volume: " << data_.getVolume() << "L" << '\n';
    os << "Price: " << data_.getPrice() << "$" << '\n';
    os << "PH: " << data_.getPH() << '\n';
    return os;
}