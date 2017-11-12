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
    cin >> key;
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
    addAction("Test", [this](string& content, Observed<string, string>& observed) -> void
    {
      cout << content << ", print t : " << t << " Worked !"<<endl;
      ++t;
      cout<<"t is now : "<<t<<endl;
    });
    vTest.show();
    cout << "t equal : " << t;
  }

};

int main()
{
  TestObserver();
}
