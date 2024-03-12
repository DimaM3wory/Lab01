#pragma once
#include "other.h"

class SoftDrink{
    protected:
        const uint32_t ID_;
        double volume_;
        double price_;
        static uint32_t ID;
    public:
        SoftDrink(double volume = 0, double price = 0) : ID_(ID++){
            volume_ = volume;
            price_ = price;
        }

        SoftDrink(std::istringstream& istr): ID_(ID++){
            istr >> volume_ >> price_;
        }

        SoftDrink(const SoftDrink& a) : SoftDrink() {
            volume_ = a.volume_;
            price_ = a.price_;
        }

        SoftDrink(SoftDrink&& a): ID_(a.ID_){
            volume_ = a.volume_;
            price_ = a.price_;
        }

        virtual ~SoftDrink(){};

        uint32_t getID() const{
            return ID_;
        }

        double getVolume() const{
            return volume_;
        }

        double getPrice() const{
            return price_;
        }

        void setVolume(double volume){
            volume_ = volume;
        }

        void setPrice(double price){
            price_ = price;
        }

        virtual void drink() const = 0;

        bool operator==(const SoftDrink& a){
            return volume_ == a.volume_ && price_ == a.price_;
        }

        SoftDrink& operator=(const SoftDrink& a){
            volume_ = a.volume_;
            price_ = a.price_;
            return *this;
        }

        SoftDrink& operator=(SoftDrink&& a){
            if(this == &a) return *this;
            *(const_cast<uint32_t*>(&ID_)) = a.ID_;
            volume_ = a.volume_;
            price_ = a.price_;
            return *this;
        }

        virtual void printInfo() const = 0;
        virtual std::string saveInfo() const = 0;
};

uint32_t SoftDrink::ID = 0;