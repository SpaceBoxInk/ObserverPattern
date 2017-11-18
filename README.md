# ObserverPattern in c++

## Overview
This is an implementation of the observer pattern in c++, it uses c++17 with templates classes only (no #define !)
And handles actions related to each event.

## Installation
just put the 4 files (Observed and Observer) in your project and compile with -std=c++17 (or c++1z)

## Documentation
- [Lambda Functions in c++](http://en.cppreference.com/w/cpp/language/lambda)
- [Lambda explained in video](https://www.youtube.com/watch?v=uk0Ytomv0wY)
- [Quick learn lambda functions](https://www.youtube.com/watch?v=Fg4TNhIQgNM)

## Setup
1. Subclass Observer and Observed where you want
2. In Observer call `addObserver(Observer)` on your Observed
3. Define your action related to an event with `addAction<EventNameType, ContentType>(eventName, eventMethod)`
4. In Observed say you changed `setChanged()`
5. and finally send your event `notifyObservers(eventName, )`

Pay attention to the Type of your eventName, it must be the exact same Type !!

```c++
addAction<std::string, char>("BadExemple", &lamdba); // eventName has type std::string

[...]

notifyObservers("BadExemple", 'c'); // here "BadExemple" has type char* !!!!
// do casting if necessary
```

## Exemple
Includes :

```c++
#include "Observed.hpp"
#include "Observer.hpp"
```
Here an exemple of an Observer class implementation :

```c++
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
    notifyObserver(std::string("eventExemple1"), key);

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
    notifyObserver(std::string("eventExemple2"), "other Ihm input");
  }

  bool isShown()
  {
    return bool();
  }
};
```

This is the function signature for event actions :

```c++
void(Content, Observed const&)

// aliased by
template<class Content>
using actionMethod = std::function<void(Content, Observed const&)>;

// eg:
// a lambda:
auto action = [](Content content, Observed const& observed) -> void 
  {
    // do action [...]
  }
```
Here is the Observed class :

```c++
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
      std::cout << typeid(observed).name() << " recieved !" << '\n';
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
    addAction<std::string, std::string>("eventExemple2",
                              [](std::string const& content, Observed const& observed) -> void
                              {
                                std::cout <<"Message : " << content << " from object : ";
                                std::cout << typeid(observed).name() << " recieved !" << '\n';
                              });

    vTest.show();
  }

};
```
The main :

```c++
// launch app
int main()
{
  ExempleObserver();
}
```
And that's all ;)\
The method/Lambda linked to the event's name is called automatically when Observed send the related event.
(Full exemple in sources)
