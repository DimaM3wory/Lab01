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

        SoftDrink(const SoftDrink& a) : SoftDrink() {
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

        virtual void drink() = 0;

        bool operator==(const SoftDrink& a){
            return volume_ == a.volume_ && price_ == a.price_;
        }

        SoftDrink& operator=(const SoftDrink& a){
            volume_ = a.volume_;
            price_ = a.price_;
            return *this;
        }
};

uint32_t SoftDrink::ID = 0;