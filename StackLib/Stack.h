#ifndef _STACKLIST_
#define _STACKLIST_
#include <iostream>
#include <fstream>
#include "TList.h"

using namespace std;

template <class T>
class TStackList
{
protected:
	TList<T> list;
public:
	TStackList();
	TStackList(TStackList<T>& _v);
	~TStackList();

	TStackList<T>& operator = (TStackList<T>& _v);

	void Push(T d);
	T Get();

	int IsEmpty(void) const;
	int IsFull(void) const;

	//Доп.Задания
	T Min_elem();
	T Max_elem();
	void File();

	template <class T1>
	friend ostream& operator<< (ostream& ostr, const TStackList<T1> &A);
	template <class T1>
	friend istream& operator>> (istream& istr, TStackList<T1> &A);

	int GetCount();
};

template<class T>
inline TStackList<T>::TStackList()
{
	list.count = 0;
	list.end = 0;
	list.root = 0;
}

template<class T>
inline TStackList<T>::TStackList(TStackList<T>& _v)
{
	list = _v.list;
}

template<class T>
inline TStackList<T>::~TStackList()
{

	list.count = 0;
	list.end = 0;
	list.root = 0;

}

template<class T>
inline TStackList<T>& TStackList<T>::operator=(TStackList<T>& _v)
{
	if (this == &_v)
	{
		return *this;
	}
	else
	{
		list = _v.list;
	}
	return *this;
}

template<class T>
inline void TStackList<T>::Push(T d)
{
	list.InsFirst(d);
}

template<class T>
inline T TStackList<T>::Get()
{
	if (list.IsEmpty())
	{
		throw logic_error("Error");
	}

	T tmp = list.GetFirst()->GetData();
	list.DelFirst();

	return tmp;
}

template<class T>
inline int TStackList<T>::IsEmpty(void) const
{
	return list.IsEmpty();
}

template<class T>
inline int TStackList<T>::IsFull(void) const
{
	return list.IsFull();
}

template<class T>
inline T TStackList<T>::Min_elem()
{
	int count = this->GetCount();
	T tmp = 0;
	for (int i = 0; i < count; i++)
	{
		if (tmp == 0)
		{
			tmp = this->Get();
		}
		else
		{
			T tmp_for = this->Get();
			if (tmp_for < tmp)
			{
				tmp = tmp_for;
			}
		}
	}
	return tmp;
}

template<class T>
inline T TStackList<T>::Max_elem()
{
	int count = this->GetCount();
	T tmp = 0;
	for (int i = 0; i < count; i++)
	{
		if (tmp == 0)
		{
			tmp = this->Get();
		}
		else
		{
			T tmp_for = this->Get();
			if (tmp_for > tmp)
			{
				tmp = tmp_for;
			}
		}
	}
	return tmp;
}

template<class T>
inline void TStackList<T>::File()
{
	ofstream outf("file.txt");
	if (!outf)
	{
		throw logic_error("Error file");
	}
	int tmp = this->GetCount();
	for (int i = 0; i < tmp; i++)
	{
		outf << this->Get() << endl;
	}
}

template<class T>
inline int TStackList<T>::GetCount()
{
	return list.GetCount();
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const TStackList<T1>& A)
{
	return ostr << A.list;
}

template<class T1>
inline istream& operator>>(istream& istr, TStackList<T1>& A)
{
	return istr >> A.list;
}

#endif