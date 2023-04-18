#ifndef OP_2_HEADER_HH
#define OP_2_HEADER_HH
#include <fstream>
#include <iostream>
#include "string"

using namespace std;

class StreamWriter {

private:

    ofstream file;
    string filename = "def.txt";

public:

    StreamWriter() {
        this->file = ofstream(filename);
    }
    StreamWriter(char name[20]){
        for (int i = 0; i<20; ++i){
            filename[i] = name[i];
        }
        ofstream file(name);
    }

    void OpenFile ();
    void CloseFile();
    void GetName();
    bool IsOpen();
    void WriteStr(std::string A);
    void WriteInt (int A);
    void WriteDouble (double A);

    const string &getFilename() const;

    void setFilename(const string &filename);
};
#endif //OP_2_HEADER_HH