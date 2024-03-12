#pragma once
#include "SoftDrink.h"

class CocaCola : public SoftDrink{
    protected:
        std::string taste_;
        bool isSugarFree_;
    public:
        CocaCola(double volume = 0, double price = 0, const std::string& taste = "Original", bool isSugarFree = 0) : SoftDrink(volume, price) {
            taste_ = taste;
            isSugarFree_ = isSugarFree;
        }

        CocaCola(std::istringstream& istr): SoftDrink(istr){
            istr >> taste_ >> isSugarFree_;
        }

        CocaCola(const CocaCola& a) : SoftDrink(a) {
            taste_ = a.taste_;
            isSugarFree_ = a.isSugarFree_;
        }

        CocaCola(CocaCola&& a): SoftDrink(std::move(a)){
            taste_ = a.taste_;
            isSugarFree_ = a.isSugarFree_;
        }

        ~CocaCola(){};

        std::string getTaste() const{
            return taste_;
        }

        bool getSugarFree() const{
            return isSugarFree_;
        }

        void setTaste(const std::string& taste){
            taste_ = taste;
        }

        void setSugarFree(bool isSugarFree){
            isSugarFree_ = isSugarFree;
        }

        void drink() const{
            std::cout << "I drink coca cola";
        }

        bool operator==(const CocaCola& a){
            return taste_ == a.taste_ && isSugarFree_ == a.isSugarFree_ && SoftDrink::operator==(a);
        }

        CocaCola& operator=(const CocaCola& a){
            taste_ = a.taste_;
            isSugarFree_ = a.isSugarFree_;
            SoftDrink::operator=(a);
            return *this;
        }

        CocaCola& operator=(CocaCola&& a){
            if(this == &a) return *this;

            taste_ = a.taste_;
            isSugarFree_ = a.isSugarFree_;
            SoftDrink::operator=(std::move(a));
            return *this;
        }

        void printInfo() const;

        std::string saveInfo() const{
            std::string result;
            result += "0 ";
            result +=  std::to_string(volume_);
            result += " ";
            result += std::to_string(price_);
            result += " ";
            result += taste_;
            result += " ";
            result += std::to_string(isSugarFree_);
            return result;
        }
};

std::ostream& operator<<(std::ostream& os, const CocaCola& data_){
    os << " " << data_.getID() << " | ";
    os << "Coca Cola | ";
    os << "Volume: " << data_.getVolume() << "L | ";
    os << "Price: " << data_.getPrice() << "$ | ";
    os << "Taste: " << data_.getTaste() << " | ";
    if(data_.getSugarFree()){
        os << "Sugar Free" << " | ";
    }else{
        os << "Not Sugar Free" << " | ";
    }
    
    return os;
}

void CocaCola::printInfo() const{
    std::cout << *this << '\n';
}