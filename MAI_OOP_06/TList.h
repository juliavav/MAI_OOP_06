#ifndef TLIST_H
#define	TLIST_H

#include "Square.h"
#include "Rectangle.h"
#include "Trapeze.h"
#include "TListItem.h"
#include <memory>
#include "TIterator.h"

template <class T>
class TList {
public:
	TList();
	

	int length();

	void addFirst(std::shared_ptr<T> &figure);
	void insert(int index, std::shared_ptr<T> &figure);
	void addLast(std::shared_ptr<T> &figure);
	bool empty();
	void delElement(int &index);
	void eraseList();
	TIterator<TListItem<T>, T> begin();
	TIterator<TListItem<T>, T> end();
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TList<A>& list);
	virtual ~TList();
private:

	std::shared_ptr<TListItem<T>> first;
};

#endif	/* TLIST_H */