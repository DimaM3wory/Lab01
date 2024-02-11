#pragma once
#include "other.h"

class SoftDrink{
    private:
        const uint32_t ID_;
        double volume_;
        double price_;
    protected:
        static uint32_t ID;
    public:
        SoftDrink(double volume, double price) : ID_(ID++){
            volume_ = volume;
            price_ = price;
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
};

uint32_t SoftDrink::ID = 0;