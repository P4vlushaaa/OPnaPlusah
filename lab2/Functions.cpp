#include "iostream"
#include "header.hh"

void StreamWriter::OpenFile() {
    file.open(StreamWriter::filename);
}

void StreamWriter::CloseFile(){
    file.close();
}

bool StreamWriter::IsOpen() {
    return file.is_open();
}

void StreamWriter::WriteStr(std::string  f){
    file << f;
}

void StreamWriter::WriteInt(int f){
    file << f;
}

void StreamWriter::WriteDouble(double f){
    file << f;
}

const string &StreamWriter::getFilename() const {

}

void StreamWriter::setFilename(const string &filename) {
    StreamWriter::filename = filename;
}
