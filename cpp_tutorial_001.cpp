// pure virtual members can be called
// from the abstract base class
#include <iostream>

using namespace std;

class CPolygon {
 protected:
  int width, height;
 public:
  void set_values (int a, int b) {
   width=a;
   height=b;
  }
  virtual int area (void) = 0;
  void printarea (void) {
	 cout << this->area() << endl;
  }
};

class CRectangle: public CPolygon {
  public:
    int area (void) {
      return (width * height);
    }
};

class CTriangle: public CPolygon {
  public:
    int area (void) {
      return (width * height / 2);
    }
};

template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a > b) ? a:b;
  return (result);
  // return result = (a > b) ? a:b;
}

template <class T>
class mypair {
  T a, b;
  public:
    mypair (T first, T second) {
      a = first;
      b = second;
    }
    T getmax ();
};

template <class T>
T mypair<T>::getmax () {
  T retval;
  retval = (a > b) ? a:b;
  return retval;
}

// ex3 class template:
template <class T>
class mycontainer {
 T element;
 public:
   mycontainer(T arg) {
     element = arg;
   }
   T increase() {
     return ++element;
   }
};

//ex3 class template specialization:
template <>
class mycontainer<char> {
  char element;
  public:
    mycontainer(char arg) {
      element = arg;
    }
    char uppercase() {
      if ((element >= 'a') && (element <= 'z')) {
        element += 'A' - 'a';
      }
      return element;
    }
};

//------------------------------------------
template <class T, int N>
class mysequence {
  T memblock[N];
  public:
    void setmember(int x, T value);
    T getmember(int x);
};

template <class T, int N>
void mysequence<T,N>::setmember(int x, T value) {
  memblock[x] = value;
}

template <class T, int N>
T mysequence<T,N>::getmember(int x) {
  return memblock[x];
}

// example 6
class myexception: public exception {
  virtual const char* what() const throw() {
    return "My exception happened";
  }
}myex;

int main () {
  CPolygon * ppoly1 = new CRectangle;
  CPolygon * ppoly2 = new CTriangle;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly1->printarea();
  ppoly2->printarea();
  delete ppoly1;
  delete ppoly2;

  int i = 5, j = 6, k;
  long l = 10, m = 5, n;
  k = GetMax<int>(i,j);
  n = GetMax<long>(l,m);
  cout << k << endl;
  cout << n << endl;

  // example 3
  mycontainer<int> myint(7);
  mycontainer<char> mychar('j');
  cout << myint.increase() << endl;
  cout << mychar.uppercase() << endl;

  // example 4
  mysequence<int, 5> myints;
  mysequence<double, 5> myfloats;
  myints.setmember(0, 100);
  myfloats.setmember(3, 3.1416);
  cout << myints.getmember(0) << '\n';
  cout << myfloats.getmember(3) << '\n';

  // example 5
  try {
    throw 20;
  } catch(int e) {
    cout << "An exception occurred. ";
    cout << "Exception Nr. " << e << endl;
  }

  //----------------- example 6
  try {
    throw myex;
  } catch(exception& e) {
    cout << e.what() << endl;
  }

  // --------------------
  try {
    int* myarray= new int[1000];
  } catch(exception& e) {
    cout << "Standard exception: " << e.what() << endl;
  }
  // example comment
  return 0;
}
