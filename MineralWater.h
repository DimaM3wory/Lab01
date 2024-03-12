#pragma once
#include "SoftDrink.h"

class MineralWater : public SoftDrink{
    protected:
        double pH_;
    public:
        MineralWater(double volume = 0, double price = 0, double pH = 0) : SoftDrink(volume, price) {
            pH_ = pH;
        }

        MineralWater(std::istringstream& istr): SoftDrink(istr){
            istr >> pH_;
        }

        MineralWater(const MineralWater& a) : SoftDrink(a) {
            pH_ = a.pH_;
        }

        MineralWater(MineralWater&& a): SoftDrink(std::move(a)){
            pH_ = a.pH_;
        }


        ~MineralWater(){};

        double getPH() const{
            return pH_;
        }

        void setPH(double pH){
            pH_ = pH;
        }


        void drink() const{
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

        MineralWater& operator=(MineralWater&& a){
            if(this == &a) return *this;

            pH_ = a.pH_;
            SoftDrink::operator=(std::move(a));
            return *this;
        }

        void printInfo() const;

        std::string saveInfo() const{
            std::string result;
            result += "2 ";
            result +=  std::to_string(volume_);
            result += " ";
            result += std::to_string(price_);
            result += " ";
            result += std::to_string(pH_);
            return result;
        }

        
};

std::ostream& operator<<(std::ostream& os, const MineralWater& data_){
    os << " " << data_.getID() << " | ";
    os << "Mineral Water" << " | ";
    os << "Volume: " << data_.getVolume() << "L | ";
    os << "Price: " << data_.getPrice() << "$ | ";
    os << "PH: " << data_.getPH() << " | ";
    return os;
}

void MineralWater::printInfo() const{
    std::cout << *this << '\n';
}