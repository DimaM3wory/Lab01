#include "CocaCola.h"
#include "Water.h"
#include "MineralWater.h"
#include "Lemonade.h"

int main(){
    CocaCola a1;
    CocaCola a2 = a1;

    Water b1;
    Water b2 = b1;

    MineralWater c1;
    MineralWater c2 = c1;

    Lemonade d1;
    Lemonade d2 = d1;

    std::cout << d2;
}