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
class ReturnType;

class Type
{
    std::string name_ = "type";

public:
    virtual std::string getName() = 0;
    virtual Type *clone() const = 0;
    int line_number, char_number;
    void swap(Type &);
    virtual std::string toString() = 0;
};

class ReturnType : public Type
{
    std::string name_ = "return_type";

public:
    Type *type_;

    std::string getName()
    {
        return this->name_;
    }
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " ";
        if (type_ == nullptr)
            returnString += this->type_->toString() + "]";
        else
            returnString += "]";
        return returnString;
    }

    ReturnType(const ReturnType &);
    ReturnType &operator=(const ReturnType &);
    ReturnType(Type *p1);
    ~ReturnType();
    void swap(ReturnType &);
    virtual ReturnType *clone() const;
};

class ListType : public Type
{
    std::string name_ = "list";

public:
    std::vector<Type *> types_;

    std::string getName()
    {
        return this->name_;
    }
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " (";
        for (int i = 0; i < this->types_.size(); ++i)
        {
            returnString += (this->types_[i]->toString() + " ");
        }
        returnString += ")]";
        return returnString;
    }
    ListType(const ListType &);
    ListType &operator=(const ListType &);
    ListType(std::vector<Type *> p1);
    ~ListType();
    void swap(ListType &);
    virtual ListType *clone() const { return nullptr; };
};

class TypeFun : public Type
{
    std::string name_ = "fun";

public:
    ListType *listtype_;
    Type *type_;

    std::string getName()
    {
        return this->name_;
    }
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " (";
        for (int i = 0; i < this->listtype_->types_.size(); ++i)
        {
            returnString += (this->listtype_->types_[i]->toString() + " ");
        }
        if (this->type_ != nullptr)
            returnString += (") -> " + this->type_->toString() + "]");
        else
            returnString += (")]");

        return returnString;
    }
    TypeFun(const TypeFun &);
    TypeFun &operator=(const TypeFun &);
    TypeFun(ListType *p1, Type *p2);
    ~TypeFun();
    void swap(TypeFun &);
    virtual TypeFun *clone() const;
};

class TypeRecord : public Type
{
    std::string name_ = "record";

public:
    ListType *listtype_;
    std::vector<std::string> names;

    std::string toString()
    {
        std::string returnString = "[" + this->name_ + " (";
        for (int i = 0; i < this->listtype_->types_.size(); ++i)
        {
            returnString += names[i] + " : ";
            returnString += (this->listtype_->types_[i]->toString() + " ");
        }
        returnString += ")]";
        return returnString;
    }

    std::string getName()
    {
        return this->name_;
    }
    TypeRecord(const TypeRecord &);
    TypeRecord &operator=(const TypeRecord &);
    TypeRecord(ListType *p1, std::vector<std::string> p2);
    ~TypeRecord();
    void swap(TypeRecord &);
    virtual TypeRecord *clone() const;
};

class TypeArray : public Type
{
    std::string name_ = "array";

public:
    Type *type_;

    std::string toString()
    {
        std::string returnString = "[" + this->name_ +
                                   " " + this->type_->toString() + "]";
        return returnString;
    }

    std::string getName()
    {
        return this->name_;
    }
    TypeArray(const TypeArray &);
    TypeArray &operator=(const TypeArray &);
    TypeArray(Type *p1);
    ~TypeArray();
    void swap(TypeArray &);
    virtual TypeArray *clone() const;
};

class TypeInteger : public Type
{
    std::string name_ = "integer";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    std::string getName()
    {
        return this->name_;
    }
    TypeInteger(){};
    void swap(Type &){};
    virtual TypeInteger *clone() const;
};

class TypeReal : public Type
{
    std::string name_ = "real";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    std::string getName()
    {
        return this->name_;
    }
    TypeReal(){};
    void swap(Type &){};
    virtual TypeReal *clone() const;
};

class TypeBool : public Type
{
    std::string name_ = "bool";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    std::string getName()
    {
        return this->name_;
    }

    void swap(Type &){};
    TypeBool(){};
    virtual TypeBool *clone() const { return nullptr; };
};

class TypeChar : public Type
{
    std::string name_ = "char";

public:
    std::string toString()
    {
        std::string returnString = "[" + this->name_ + "]";
        return returnString;
    }
    TypeChar(){};
    std::string getName()
    {
        return this->name_;
    }
    void swap(Type &){};
    virtual TypeChar *clone() const { return nullptr; };
};

#endif