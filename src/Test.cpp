#include "Observed.hpp"
#include "Observer.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TestObserved : public Observed<string, string>
{
public:
  void show()
  {
    cout << "IHM stuff and waiting for input :" << endl;
    string key;
    std::getline(cin, key);
    setChanged();
    notifyObserver("Test", key);
  }
};

class TestObserver : public Observer<string, string>
{
private:
  TestObserved vTest;
  int t;
public:

  TestObserver() :
      vTest(), t(2)
  {
    vTest.addObserver(this);
    addAction("Test",
        [](string const& content, Observed<string, string> const& observed) -> void
    {
          cout << "Message : " << content << " Message from object : "<< typeid(observed).name() << " recieved !" <<endl;
    });
    vTest.show();
  }

};

int main()
{
  TestObserver();
}
