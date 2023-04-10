#include <vector>
#include <string>

#ifndef TYPECLASS
#define TYPECLASS

class Type;
class ListType; // helper type
class TypeFun;
class TypeRecord;
class TypeArray;
class TypeInteger;
class TypeReal;
class TypeBool;
class TypeChar;

class Type{
    std::string name_ = "type";
public:
    
    virtual std::string getName() = 0;
    virtual Type *clone() const = 0;
    int line_number, char_number;
    void swap(Type &);
    virtual Type *clone() const;
};

class ListType : public std::vector<Type *>{
    std::string name_ = "list";
public:
    std::string getName(){
        return this->name_;
    }
    void swap(ListType &);
    virtual ListType *clone() const;
};

class TypeFun : public Type{
    std::string name_ = "fun";
public:
    ListType *listtype_;
    Type *type_;

    std::string getName(){
        return this->name_;
    }
    TypeFun(const TypeFun &);
    TypeFun &operator=(const TypeFun &);
    TypeFun(ListType *p1, Type *p2);
    ~TypeFun();
    void swap(TypeFun &);
    virtual TypeFun *clone() const;
};

class TypeRecord : public Type{
    std::string name_ = "record";
public:
    ListType *listtype_;
    std::vector<std::string> names;
    
    std::string getName(){
        return this->name_;
    }
    TypeRecord(const TypeRecord &);
    TypeRecord &operator=(const TypeRecord &);
    TypeRecord(ListType *p1);
    ~TypeRecord();
    void swap(TypeRecord &);
    virtual TypeRecord *clone() const;
};

class TypeArray : public Type{
    std::string name_ = "array";
public:
    Type *type_;

    std::string getName(){
        return this->name_;
    }
    TypeArray(const TypeArray &);
    TypeArray &operator=(const TypeArray &);
    TypeArray(Type *p1);
    ~TypeArray();
    void swap(TypeArray &);
    virtual TypeArray *clone() const;
};

class TypeInteger : public Type{
    std::string name_ = "integer";
public:

    std::string getName(){
        return this->name_;
    }
    virtual TypeInteger *clone() const;
};

class TypeReal : public Type{
    std::string name_ = "real";
public:

    std::string getName(){
        return this->name_;
    }
    virtual TypeReal *clone() const;
};

class TypeBool : public Type{
    std::string name_ = "bool";
public:

    std::string getName(){
        return this->name_;
    }
    virtual TypeBool *clone() const;
};


class TypeChar : public Type{
    std::string name_ = "char";
public:

    std::string getName(){
        return this->name_;
    }
    virtual TypeChar *clone() const;
};

#endif