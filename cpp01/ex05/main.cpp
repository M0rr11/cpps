#include "Harl.hpp"

int main() 
{
    Harl harl;
    
    std::cout << "=== Testing Harl ===" << std::endl << std::endl;
    
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    std::cout << "=== Testing invalid level ===" << std::endl;
    harl.complain("UNKNOWN");
    
    return 0;
}