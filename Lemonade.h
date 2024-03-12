#pragma once
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

        Lemonade(std::istringstream& istr): SoftDrink(istr){
            istr >> taste_ >> color_;
        }

        Lemonade(const Lemonade& a) : SoftDrink(a) {
            taste_ = a.taste_;
            color_ = a.color_;
        }

        Lemonade(Lemonade&& a): SoftDrink(std::move(a)){
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

        void drink() const{
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

        Lemonade& operator=(Lemonade&& a){
            if(this == &a) return *this;

            taste_ = a.taste_;
            color_ = a.color_;
            SoftDrink::operator=(std::move(a));
            return *this;
        }

        void printInfo() const;

        std::string saveInfo() const{
            std::string result;
            result += "3 ";
            result +=  std::to_string(volume_);
            result += " ";
            result += std::to_string(price_);
            result += " ";
            result += taste_;
            result += " ";
            result += color_;
            return result;
        }
};

std::ostream& operator<<(std::ostream& os, const Lemonade& data_){
    os << " " << data_.getID() << " | ";
    os << "Lemonade" << " | ";
    os << "Volume: " << data_.getVolume() << "L | ";
    os << "Price: " << data_.getPrice() << "$ | ";
    os << "Taste: " << data_.getTaste() << " | ";
    os << "Color: " << data_.getColor() << " | ";
    return os;
}

void Lemonade::printInfo() const{
    std::cout << *this << '\n';
}