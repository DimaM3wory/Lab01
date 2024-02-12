#include "SoftDrink.h"

class Water : public SoftDrink{
    protected:
        double hardness_;
    public:
        Water(double volume = 0, double price = 0, double hardness = 0) : SoftDrink(volume, price) {
            hardness_ = hardness;
        }

        Water(const Water& a) : SoftDrink(a) {
            hardness_ = a.hardness_;
        }

        ~Water(){};

        double getHardness() const{
            return hardness_;
        }

        void setHardness(double hardness){
            hardness_ = hardness;
        }


        void drink() const{
            std::cout << "I drink water";
        }

        bool operator==(const Water& a){
            return hardness_ == a.hardness_ && SoftDrink::operator==(a);
        }

        Water& operator=(const Water& a){
            hardness_ = a.hardness_;
            SoftDrink::operator=(a);
            return *this;
        }

        void printInfo() const;

        std::string saveInfo() const{
            std::string result;
            result += "1 ";
            result +=  std::to_string(volume_);
            result += " ";
            result += std::to_string(price_);
            result += " ";
            result += std::to_string(hardness_);
            return result;
        }
};

std::ostream& operator<<(std::ostream& os, const Water& data_){
    os << " " << data_.getID() << " | ";
    os << "Water" << " | ";
    os << "Volume: " << data_.getVolume() << "L | ";
    os << "Price: " << data_.getPrice() << "$ | ";
    os << "Hardness: " << data_.getHardness() << "mmol/L | ";
    return os;
}

void Water::printInfo() const{
    std::cout << *this << '\n';
}