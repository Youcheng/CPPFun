#include <memory>
#include <utility>
#include <iostream>

enum class Type : char { Unknown, Stock, Bond, RealEstate };

struct Investment {
    Investment(int shares, int price) : units_(shares), price_(price) { std::cout << __FUNCTION__ << std::endl; }
    virtual ~Investment( ) { std::cout << __FUNCTION__ << std::endl; }
    double getTotalValue() { return units_*price_; }
    virtual std::string getType() = 0;
    int units_;
    int price_;
};

struct Stock : public Investment {
    Stock(int shares, int price) : Investment(shares, price) { std::cout << __FUNCTION__ << std::endl; }
    ~Stock( ) { std::cout << __FUNCTION__ << std::endl; }
    std::string getType() override { return std::string("Stock__");}

};

struct Bond : public Investment {
    Bond(int shares, int price) : Investment(shares, price) { std::cout << __FUNCTION__ << std::endl; }
    ~Bond( ) { std::cout << __FUNCTION__ << std::endl; }
    std::string getType() override { return std::string("Bond__");}
};

struct RealEstate : public Investment {
    RealEstate(int shares, int price) : Investment(shares, price) { std::cout << __FUNCTION__ << std::endl; }
    ~RealEstate( ) { std::cout << __FUNCTION__ << std::endl; }
    std::string getType() override { return std::string("RealEstate__");}
};

template<typename... Args>
std::unique_ptr<Investment> makeInvestment(Type it, Args&&... params) {
    std::unique_ptr<Investment> pInv(nullptr);


    // allocate an object on the heap and return a pointer to it
    // caller will be responsible to delete this from the heap
    switch(it) {
        case Type::Bond:
            pInv.reset(new Bond(std::forward<Args>(params)...));
            break;
        case Type::Stock:
            pInv.reset(new Stock(std::forward<Args>(params)...));
            break;
        case Type::RealEstate:
            pInv.reset(new RealEstate(std::forward<Args>(params)...));
            break;
        case Type::Unknown:
        default:
            std::cout << "uknown investment type" << std::endl;
            return pInv;
    }

    // pInv will be moved to the caller
    return pInv;
}


int main() {
    auto pInvestment = makeInvestment(Type::RealEstate, 100, 4);
    if (pInvestment) {
        std::cout << pInvestment->getTotalValue() << std::endl;
        std::cout << pInvestment->getType() << std::endl;
    }
}