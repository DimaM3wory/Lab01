#include "SoftDrink.h"

class MineralWater : public SoftDrink{
    protected:
        double pH_;
    public:
        MineralWater(double volume = 0, double price = 0, double pH = 0) : SoftDrink(volume, price) {
            pH_ = pH;
        }

        MineralWater(const MineralWater& a) : SoftDrink(a) {
            pH_ = a.pH_;
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

        MineralWater& operator=(const MineralWater& a){
            pH_ = a.pH_;
            SoftDrink::operator=(a);
            return *this;
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