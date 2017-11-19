#include "TList.h"
#include "TIterator.h"

template <class T>
TList<T>::TList() {
	first = nullptr;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TList<T>& list) {

	std::shared_ptr<TListItem<T>> item = list.first;
	int i = 1;
	while (item != nullptr)
	{
		std::cout << "[" << i << "]";
		item->GetFigure()->Print();
		item = item->GetNext();
		i++;
	}

	return os;
}

template <class T>
int TList<T>::length() {
	int i = 0;
	std::shared_ptr<TListItem<T>> item = this->first;
	while (item != nullptr)
	{
		item = item->GetNext();
		i++;
	}
	return i;
}

template <class T>
void TList<T>::addFirst(std::shared_ptr<T> &figure) {
	std::shared_ptr<TListItem<T>> other = std::make_shared<TListItem<T>>(figure);

	other->SetNext(first);
	first = other;
}

template <class T>
void TList<T>::insert(int index, std::shared_ptr<T> &figure) {
	std::shared_ptr<TListItem<T>>iter = this->first;
	std::shared_ptr<TListItem<T>> other = std::make_shared<TListItem<T>>(figure);
	//int i = 0;
	if (index == 1) {
		other->SetNext(iter);
		this->first = other;
	}
	else {
		if (index <= this->length()) {
			int i = 1;
			for (i = 1; i < index - 1; ++i) {
				iter = iter->GetNext();
			}
			other->SetNext(iter->GetNext());
			iter->SetNext(other);
		}
		else {
			std::cout << "error" << std::endl;
		}
	}
}

template <class T>
void TList<T>::addLast(std::shared_ptr<T> &figure) {
	std::shared_ptr<TListItem<T>> other = std::make_shared<TListItem<T>>(figure);
	std::shared_ptr<TListItem<T>> iter = this->first;
	if (first != nullptr) {
		while (iter->GetNext() != nullptr) {
			iter = iter->SetNext(iter->GetNext());
		}
		iter->SetNext(other);// little bit strange
		other->SetNext(nullptr);
	}
	else {
		first = other;
	}
}

template <class T>
bool TList<T>::empty() {
	return first == nullptr;
}

template <class T>
void TList<T>::delElement(int &index)
{
	std::shared_ptr<TListItem<T>>iter = this->first;
	//std::shared_ptr<TListItem> other = std::make_shared<TListItem>(figure);
	//int i = 0;
	if (index <= this->length()) {
	if (index == 1) {
		this->first = iter->GetNext();
	}
	else {
		int i = 1;
		for (i = 1; i < index - 1; ++i) {
			iter = iter->GetNext();
		}
		iter->SetNext(iter->GetNext()->GetNext());
	}

	}
	else {
		std::cout << "error" << std::endl;
	}
}

template <class T>
void TList<T>::eraseList() {
	first = nullptr;
}

template <class T>
TList<T>::~TList() {
	std::cout << "List deleted!" << std::endl;
	//delete first;
}
template <class T>
TIterator<TListItem<T>, T> TList<T>::begin()
{
	return TIterator<TListItem<T>, T>(first);
}

template <class T>
TIterator<TListItem<T>, T> TList<T>::end()
{
	return TIterator<TListItem<T>, T>(nullptr);
}
#include "Figure.h"
template class TList<Figure>;
template std::ostream& operator<<(std::ostream &out, const TList<Figure> &figure);