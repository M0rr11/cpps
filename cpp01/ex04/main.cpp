#include <iostream>
#include <fstream>

std::string replaceAll(std::string str, std::string s1, std::string s2)
{
    if (s1.empty()) 
        return str;

    std::string result = "";
    size_t pos = 0;
    size_t found;

    while ((found = str.find(s1, pos)) != std::string::npos)
    {
        result += str.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += str.substr(pos);
    return result;
}

int main(int ac, char **av)
{
    if (ac != 4) 
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) 
    {
        std::cout << "Error: cannot open file " << filename << std::endl;
        return 1;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outfile(outFilename.c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error: cannot create file " << outFilename << std::endl;
        infile.close();
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) 
    {
        std::string replaced = replaceAll(line, s1, s2);
        outfile << replaced << std::endl;
    }
    infile.close();
    outfile.close();
    
    std::cout << "Replacement complete. Output written to " << outFilename << std::endl; 
    return 0;
}