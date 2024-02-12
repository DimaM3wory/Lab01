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

        CocaCola(const CocaCola& a) : SoftDrink(a) {
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

        void drink(){
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