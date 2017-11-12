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
  std::vector<Observer<MessageName, Content> const*> observers;
  bool changed;
//=======================>Constructors<=======================
public:
  Observed();
  // TODO: rule of five ? copyandswap
  virtual ~Observed() = default;

private:

//=========================>Methods<==========================
public:
  void addObserver(Observer<MessageName, Content>* observer);
  void deleteObserver(Observer<MessageName, Content>* observer);
  void deleteObservers();

  int countObservers() const;
protected:
  void notifyObserver(MessageName messageName, Content content);
private:

//=====================>Getters&Setters<======================
public:
  bool hasChanged() const;

protected:
  void setChanged();
  void clearChanged();
private:

};

#include "Observed.cpp"

#endif
