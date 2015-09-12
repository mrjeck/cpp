#include <vector>
#include <string>
#include <iostream>
 
class Item
{
public:
    Item(const std::string &name, const std::string &own, const std::string &nphone, const std::string &bus) :
        firm_name(name), owner(own), phone(nphone), busines(bus) {
    }
 
    std::string GetFirmName() const {
        return firm_name.c_str();
    }
    
    std::string GetOwnerName() const {
        return owner.c_str();
    }
    
    std::string GetPhone() const {
        return phone.c_str();
    }
    
    std::string GetBusines() const {
        return busines.c_str();
    }
    
private:
    std::string firm_name;
    std::string owner;
    std::string phone;
    std::string busines;
};
 
class Handbook
{
public:
    void AddItem(const Item &i) {
        items.push_back(i);
    }
    
    void PrintAll(std::ostream &os) {
        for(std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it) {
            os << it->GetFirmName() << "\n"
               << it->GetOwnerName() << "\n"
               << it->GetPhone() << "\n"
               << it->GetBusines() << "\n"
               << std::endl;
        }
    }
       
    Handbook FindByFirmName(const std::string &name) {
        Handbook h;
        for(std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it)
            if(it->GetFirmName() == name)
                h.AddItem(*it);
                
        return h;
    }
    
    Handbook FindByOwner(const std::string &owner) {
        Handbook h;
        for(std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it)
            if(it->GetOwnerName() == owner)
                h.AddItem(*it);
                
        return h;
    }
    
    Handbook FindByPhone(const std::string &phone) {
        Handbook h;
        for(std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it)
            if(it->GetPhone() == phone)
                h.AddItem(*it);
                
        return h;
    }
    
    Handbook FindByBusines(const std::string &busines) {
        Handbook h;
        for(std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it)
            if(it->GetBusines() == busines)
                h.AddItem(*it);
                
        return h;
    }
    
private:
    std::vector<Item> items;
};
int main()
{
	return 0;
}