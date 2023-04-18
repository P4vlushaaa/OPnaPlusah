#ifndef LAB_4_BASECOBJECT_HH
#define LAB_4_BASECOBJECT_HH

class BaseCObject {
public:
    virtual const char *classname() = 0;

    virtual unsigned int size() = 0;
};

#endif //LAB_4_BASECOBJECT_HH
