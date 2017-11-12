/**
 * Observed.hpp
 *
 * Early optimization is the root of all evil
 *
 *  Created on: 11 nov. 2017
 *      Author: nihil
 */

#ifndef OBSERVED_HPP
#define OBSERVED_HPP


#include "Observer.hpp"

#include <vector>

template<class MessageName, class Content>
class Observed
{
//========================>Attributes<========================
private:
  std::vector<Observer<MessageName, Content>*> observers;
//=======================>Constructors<=======================
public:
  Observed();
  // TODO: rule of five ? copyandswap
  virtual ~Observed();

private:

//=========================>Methods<==========================
public:
  void addObserver(Observer<MessageName, Content>* observer);

protected:
  void notifyObserver(MessageName messageName, Content content);
private:

  //=====================>Getters&Setters<======================
public:

private:

};

#include "Observed.cpp"

#endif
