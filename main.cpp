#include "CocaCola.h"
#include "Water.h"
#include "MineralWater.h"
#include "Lemonade.h"

int main(){
    std::vector<SoftDrink*> storage;
    std::vector<SoftDrink*> memory(0);
    
    char input;
    bool cycle = true;
    while (cycle) {
        std::cout << "Enter option: ";
        std::cin >> input;
        switch (input){
        case '+':
        {
            int amount;
            std::cout << "How many: ";
            std::cin >> amount;

            int type;
            std::cout << "Enter type: ";
            std::cin >> type;

            double volume;
            std::cout << "Enter volume: ";
            std::cin >> volume;

            double price;
            std::cout << "Enter price: ";
            std::cin >> price;

            switch (type){
                case 0: //CocaCola
                {
                    std::string taste;
                    std::cout << "Enter taste: ";
                    std::cin >> taste;

                    bool isSugarFree;
                    std::cout << "Is sugar free: ";
                    std::cin >> isSugarFree;
                    int mem_size = memory.size();
                    for (int i = mem_size; i < mem_size + amount; i++){
                        memory.push_back(new CocaCola(volume, price, taste, isSugarFree));
                        storage.push_back(memory[i]);
                    }
                    break;
                }
                case 1: //Water
                {
                    double hardness;
                    std::cout << "Enter hardness: ";
                    std::cin >> hardness;
                    int mem_size = memory.size();
                    for (int i = mem_size; i < mem_size + amount; i++){
                        memory.push_back(new Water(volume, price, hardness));
                        storage.push_back(memory[i]);
                    }
                    break;
                }
                case 2: //MineralWater
                {
                    double pH;
                    std::cout << "Enter pH: ";
                    std::cin >> pH;
                    int mem_size = memory.size();
                    for (int i = mem_size; i < mem_size + amount; i++){
                        memory.push_back(new MineralWater(volume, price, pH));
                        storage.push_back(memory[i]);
                    }
                    break;
                }
                case 3: //Lemonade
                {
                    std::string taste;
                    std::cout << "Enter taste: ";
                    std::cin >> taste;

                    std::string color;
                    std::cout << "Enter color: ";
                    std::cin >> color;
                    int mem_size = memory.size();
                    for (int i = mem_size; i < mem_size + amount; i++){
                        memory.push_back(new Lemonade(volume, price, taste, color));
                        storage.push_back(memory[i]);
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
        case 'c':
            //код
            break;
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
                std::istringstream strstream(line);

                int type;
                strstream >> type;

                double volume;
                strstream >> volume;

                double price;
                strstream >> price;

                switch (type){
                    case 0: //CocaCola
                    {
                        std::string taste;
                        strstream >> taste;

                        bool isSugarFree;
                        strstream >> isSugarFree;
                        int mem_size = memory.size();
                        memory.push_back(new CocaCola(volume, price, taste, isSugarFree));
                        storage.push_back(memory[mem_size]);
                        break;
                    }
                    case 1: //Water
                    {
                        double hardness;
                        strstream >> hardness;
                        int mem_size = memory.size();
                        memory.push_back(new Water(volume, price, hardness));
                        storage.push_back(memory[mem_size]);
                        break;
                    }
                    case 2: //MineralWater
                    {
                        double pH;
                        strstream >> pH;
                        int mem_size = memory.size();
                        memory.push_back(new MineralWater(volume, price, pH));
                        storage.push_back(memory[mem_size]);
                    break;
                    }
                    case 3: //Lemonade
                    {
                        std::string taste;
                        strstream >> taste;

                        std::string color;
                        strstream >> color;
                        int mem_size = memory.size();
                        memory.push_back(new Lemonade(volume, price, taste, color));
                        storage.push_back(memory[mem_size]);
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
            for(auto& item : memory){
                delete item;
            }
            memory.clear();
            break;
        default:
            std::cout << "Invalid input \n";
            break;
        }
    }
}