#pragma once
#include<iostream>
using namespace std;
class Monster{
  private:
      int mHp;
  public:
     void setHp(int hp){
      mHp = hp;
     };
     int getHp(){
      return mHp;
     } ;
     void display(){
      cout<<"hi";
     }
};