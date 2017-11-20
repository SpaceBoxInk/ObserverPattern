/**
 * @file Test.cpp
 * @example
 */

#include "Observed.hpp"
#include "Observer.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <exception>

class ExempleObserved : public Observed
{
private:
  bool shown;
public:

  ExempleObserved() :
      shown(false)
  {
  }

  void show()
  {
    shown = true;
    std::cout << "IHM stuff and waiting for input :" << '\n';
    std::string key;
    std::getline(std::cin, key);
    // say that the object state has changed
    setChanged();
    // and then notify observers with the event name : "eventExemple1" and content : key
    notifyObservers(std::string("eventExemple1"), key);

    doOtherIhmStuff();
  }

  /**
   * another test to send an event
   */
  void doOtherIhmStuff()
  {
    std::cout << "Other IHM stuff" << '\n';
    if (isShown())
    {
      setChanged();
    }
    // without content
    notifyObservers("eventExemple2");
  }

  bool isShown()
  {
    return shown;
  }
};

class ExempleObserver : public Observer
{
private:
  ExempleObserved vTest;
public:
  // a function that return a lambda
  /**
   * a function that return a lambda
   * @return the lambda for event "Test"
   */
  auto eventTest()
  {
    return [](std::string const& content, Observed const& observed) -> void
    {
      std::cout <<"Message : " << content << " from object : ";
      std::cout << typeid(observed).name() << " Received !" << '\n';
    };
  }

  ExempleObserver() :
      vTest()
  {
    // add this Observer to the subscribe list of vTest (the Observed)
    vTest.addObserver(this);

    // call the function eventTest that returns the lambda
    // and pass it to addAction
    // <nameEvent Type, content type>
    // ~~~~~~~vvvvvvvvvvvvvv~~~~~~~~~
    addAction<std::string, std::string>(std::string("eventExemple1"), eventTest());

    // or pass directly a lambda function
    // here we do not need content
    addAction("eventExemple2", [](Observed const& observed) -> void
    {
      std::cout <<"Message eventExemple2 without content : " << " from object : ";
      std::cout << typeid(observed).name() << " recieved !" << '\n';
    });

    vTest.show();
  }

};

// launch app
int main()
{
  ExempleObserver();
}
