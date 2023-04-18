#include <iostream>
#include "header.hh"



int main() {

    char name[20];
    int x = 19;
    double z = 89.2004;
    std::string a = "Hello world";
    std::cin>>name;
    StreamWriter File(name);
    File.getFilename();
    File.IsOpen();
    File.OpenFile();
    File.IsOpen();
    File.WriteStr(a);
    File.WriteInt(x);
    File.WriteDouble(z);
    File.CloseFile();
    return 0;
}