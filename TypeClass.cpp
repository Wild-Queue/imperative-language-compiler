#include "TypeClass.h"
#include <algorithm>

/********************   ListType    ********************/


ListType* consListType(Type* x, ListType* xs){
  xs->types_.push_back(x);
  return xs;
}

/********************   ReturnType      ********************/

ReturnType::ReturnType(Type *p1){
  type_ = p1;
}

ReturnType::ReturnType(const ReturnType & other){
  type_ = other.type_->clone();

}

ReturnType &ReturnType::operator=(const ReturnType & other){
  ReturnType tmp(other);
  swap(tmp);
  return *this;
}

void ReturnType::swap(ReturnType & other){
  std::swap(type_, other.type_);

}

ReturnType::~ReturnType(){
  delete(type_);

}

ReturnType *ReturnType::clone() const{
  return new ReturnType(*this);
}

/********************   TypeFun    ********************/
TypeFun::TypeFun(ListType *p1, Type *p2){
  listtype_ = p1;
  type_ = p2;

}

TypeFun::TypeFun(const TypeFun & other){
  listtype_ = other.listtype_->clone();
  type_ = other.type_->clone();

}

TypeFun &TypeFun::operator=(const TypeFun & other){
  TypeFun tmp(other);
  swap(tmp);
  return *this;
}

void TypeFun::swap(TypeFun & other){
  std::swap(listtype_, other.listtype_);
  std::swap(type_, other.type_);

}

TypeFun::~TypeFun(){
  delete(listtype_);
  delete(type_);

}

TypeFun *TypeFun::clone() const{
  return new TypeFun(*this);
}

/********************   TypeRecord    ********************/
TypeRecord::TypeRecord(ListType *p1){
  listtype_ = p1;

}

TypeRecord::TypeRecord(const TypeRecord & other){
  listtype_ = other.listtype_->clone();

}

TypeRecord &TypeRecord::operator=(const TypeRecord & other){
  TypeRecord tmp(other);
  swap(tmp);
  return *this;
}

void TypeRecord::swap(TypeRecord & other){
  std::swap(listtype_, other.listtype_);

}

TypeRecord::~TypeRecord(){
  delete(listtype_);

}

TypeRecord *TypeRecord::clone() const{
  return new TypeRecord(*this);
}




/********************   TypeArray    ********************/
TypeArray::TypeArray(Type  *p1){
  type_ = p1;
}

TypeArray::TypeArray(const TypeArray & other){
  type_ = other.type_->clone();

}

TypeArray &TypeArray::operator=(const TypeArray & other){
  TypeArray tmp(other);
  swap(tmp);
  return *this;
}

void TypeArray::swap(TypeArray & other){
  std::swap(type_, other.type_);

}

TypeArray::~TypeArray(){
  delete(type_);

}

TypeArray *TypeArray::clone() const{
  return new TypeArray(*this);
}


/********************   TypeInteger    ********************/


TypeInteger *TypeInteger::clone() const{
  return new TypeInteger(*this);
}



/********************   TypeReal    ********************/


TypeReal *TypeReal::clone() const{
  return new TypeReal(*this);
}