#include "SoftDrink.h"

class CocaCola : public SoftDrink{
    private:
        std::string taste_;
        bool isSugarFree_;
    public:
        CocaCola(double volume, double price, const std::string& taste, bool isSugarFree) : SoftDrink(volume, price) {
            taste_ = taste;
            isSugarFree_ = isSugarFree;
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

        void drink(){
            std::cout << "I drink coca cola";
        }

        bool operator==(const CocaCola& a){
            return taste_ == a.taste_ && isSugarFree_ == a.isSugarFree_ && SoftDrink::operator==(a);
        }
};

std::ostream& operator<<(std::ostream& os, const CocaCola& data_){
    os << "It's a Coca Cola" << '\n';
    os << "ID: " << data_.getID() << '\n';
    os << "Volume: " << data_.getVolume() << "L" << '\n';
    os << "Price: " << data_.getPrice() << "$" << '\n';
    os << "Taste: " << data_.getTaste() << '\n';
    if(data_.getSugarFree()){
        os << "Sugar Free" << '\n';
    }else{
        os << "Not Sugar Free" << '\n';
    }
    
    return os;
}