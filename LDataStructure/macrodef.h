#ifndef MACRODEF_H
#define MACRODEF_H


#define L_Del(_obj_) do{if(_obj_) {delete (_obj_); (_obj_)=nullptr;}}while(0)

#endif // MACRODEF_H
