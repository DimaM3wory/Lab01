#include "CocaCola.h"
#include "Water.h"
#include "MineralWater.h"
#include "Lemonade.h"
#include "Factories.h"
#include "CompositeSoftDrink.h"

int main(){
    SoftDrinkFactory* waterFactory = new WaterFactory();
    SoftDrinkFactory* mineralWaterFactory = new MineralWaterFactory();
    SoftDrinkFactory* lemonadeFactory = new LemonadeFactory();
    SoftDrinkFactory* cocaColaFactory = new CocaColaFactory();

    std::vector<SoftDrink*> storage;

    std::string input;
    bool cycle = true;
    while (cycle) {
        std::cout << "Enter option (one symbol): ";
        std::getline(std::cin, input);
        switch (input[0]){
        case '+':
        {
            std::cout << "Enter creation request: "; // (How many) (Type) (...) "10 0 2.000000 1.000000 Cherry 1"
            std::string request;
            getline(std::cin, request);
            std::istringstream istr(request);
            
            int amount;
            istr >> amount;

            int type;
            istr >> type;

            std::string str0;
            std::getline(istr, str0);
            switch (type){
                case 0: //CocaCola
                {
                    
                    for (int i = 0; i < amount; i++){
                        std::istringstream copy(str0);
                        storage.push_back(cocaColaFactory->create(copy));
                    }
                    break;
                }
                case 1: //Water
                {
                    for (int i = 0; i < amount; i++){
                        std::istringstream copy(str0);
                        storage.push_back(waterFactory->create(copy));
                    }
                    break;
                }
                case 2: //MineralWater
                {
                    for (int i = 0; i < amount; i++){
                        std::istringstream copy(str0);
                        storage.push_back(mineralWaterFactory->create(copy));
                    }
                    break;
                }
                case 3: //Lemonade
                {
                    for (int i = 0; i < amount; i++){
                        std::istringstream copy(str0);
                        storage.push_back(lemonadeFactory->create(copy));
                    }
                    break;
                }
                default:
                    std::cout << "Invalid input \n";
                    break;

            }
            
            break;
        }
        case '-':
        {
            int id;
            std::cout << "Enter ID: ";
            std::cin >> id;

            storage.erase(std::remove_if(storage.begin(), storage.end(),
                   [id](SoftDrink* item) { return item->getID() == id; }),
                   storage.end());
            break;
        }
        case 's':
            std::cout << "----------------------------------------------STORAGE----------------------------------------------" << '\n';
            for (const auto& item : storage){
                item->printInfo();
                std::cout << "--------------------------------------------------------------------------------------------------" << '\n';
            }
            break;
        case 'S':
        {
            std::ofstream file("db.txt");
            for (int i = 0; i < storage.size(); i++){
                if(i + 1 < storage.size()){
                    file << storage[i]->saveInfo() << '\n';
                }else{
                    file << storage[i]->saveInfo();
                }
            }
            file.close();
            break;
        }
        case 'L':
        {
            std::ifstream file("db.txt");
            while(!file.eof()){
                std::string line;
                std::getline(file, line);
                std::istringstream istr(line);

                int type;
                istr >> type;

                switch (type){
                    case 0: //CocaCola
                    {
                        storage.push_back(cocaColaFactory->create(istr));
                        break;
                    }
                    case 1: //Water
                    {
                        storage.push_back(waterFactory->create(istr));
                        break;
                    }
                    case 2: //MineralWater
                    {
                        storage.push_back(mineralWaterFactory->create(istr));
                        break;
                    break;
                    }
                    case 3: //Lemonade
                    {
                        storage.push_back(lemonadeFactory->create(istr));
                        break;
                    }
                    default:
                        std::cout << "Invalid input \n";
                        break;

            }

            }
            file.close();
            break;
        }
        case 'E':
            cycle = false;
            for(auto& item : storage){
                delete item;
            }
            storage.clear();
            delete waterFactory;
            delete mineralWaterFactory;
            delete lemonadeFactory;
            delete cocaColaFactory;
            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    }

    
}