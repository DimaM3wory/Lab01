#pragma once
#include "Water.h"
#include "MineralWater.h"
#include "Lemonade.h"
#include "CocaCola.h"

class SoftDrinkFactory{
public:
    virtual SoftDrink* create(std::istringstream& istr) = 0;
};

class WaterFactory : public SoftDrinkFactory {
public:
    SoftDrink* create(std::istringstream& istr) override {
        return new Water(istr);
    }
};

class MineralWaterFactory : public SoftDrinkFactory {
public:
    SoftDrink* create(std::istringstream& istr) override {
        return new MineralWater(istr);
    }
};

class LemonadeFactory : public SoftDrinkFactory {
public:
    SoftDrink* create(std::istringstream& istr) override {
        return new Lemonade(istr);
    }
};

class CocaColaFactory : public SoftDrinkFactory {
public:
    SoftDrink* create(std::istringstream& str) override {
        return new CocaCola(str);
    }
};