//#include<iostream>
//using namespace std;
//#include<boost\shared_ptr.hpp>
//
//template<class T>
//struct Singleton_default
//{
//public:
//	typedef T object_type;
//	static shared_ptr<T>& instance()
//	{
//		if (_instance.get() == 0)
//		{
//			cout << "Singleton_default::instance()::if" << endl;
//			_instance.reset(new T());
//			return _instance;
//		}
//		return _instance;
//	}
//
//	static shared_ptr<T> _instance;
//};
//
//
//template<class T>
//shared_ptr<T> Singleton_default<T>::_instance = shared_ptr<T>(new T);// = Singleton_default<T>::instance();
//
//
//class Point
//{
//public:
//	Point(int a = 0,int b = 0,int c = 0)
//	{
//		cout << "Point::Point()" << endl;
//	}
//	~Point()
//	{
//		cout << "Point::~Point()" << endl;
//	}
//	void print()
//	{
//		cout << "Pint::print()" << endl;
//	}
//};
//#pragma warning(disable:4102)
//#pragma warning(disable:4101)
//
//void Func()
//{
//get:
//{
//	cout << "Test " << endl;
//}
//}
//void main()
//{
//	Singleton_default<Point> s1;
//	s1.instance();
//	Func();
//}
////void main()
////{
////	cout << "main() start" << endl;
////	typedef Singleton_default<Point> origin;
////
////	origin::instance();
////	origin::instance();
////	origin::instance();
////	origin::instance();
////
////
////	cout << "main() finish" << endl;
////}
//
//#include"State.h"
//#include"interpreter.h"
//#include"Flyweight.h"
#include"Birdge.h"
void main()
{
	//TestState();
	Client()();
	//TestInterpreter();
}