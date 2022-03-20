#include "list.h"
#include <string>
#include <fstream>
void create(LIST* list)
{
	//Инициализация указателей
	list->head = nullptr;
	list->curr = nullptr;
	id = 0;
}
bool add(LIST* list, DataType* value)
{
	//Выделение динамической памяти под новый элемент
	ELEMENT* tmp = nullptr;
	try
	{
		tmp = new ELEMENT;
	}
	catch (...)
	{
		//Если выделить не удалось - выход
		return false;
	}
	if (list->head == nullptr)
	{
		//Если список пустой (нет элементов)
		//Установка указателя на первый элемент в списке на
		list->head = tmp; //новый элемент
		//Установка указателя на предыдущий элемент в списке
		list->head->prev = nullptr; //в нулевое значение
	}
	else
	{
		//Иначе (если список не пустой)
		//Устанавливаем указатель на текущий элемент на
		//последний элемент в списке
		if (!list->curr) list->curr = list->head;
		while (list->curr->next)
			list->curr = list->curr->next;
		//Поле-указатель на следуюший элемент последнего
		//элемента устанавливаем на новый элемент
		list->curr->next = tmp;
		//Поле-указатель на предыдущий элемент нового элемента
		//устанавливаем на последний элемент в списке
		tmp->prev = list->curr;
	}
	value->id = id;
	tmp->value = *value; //Записываем значение в новый элемент
	//В поле-указатель на следующий элемент записываем
	tmp->next = nullptr; //нулевое значение
	list->curr = tmp; //Делаем новый элемент текущим
	id += 1;
	return true; //Успешное завершение
}
bool insert(LIST* list, DataType* value)
{
	//Если список пустой или текущий элемент не установлен,
	//то добавляем в конец списка
	if (!list->head || !list->curr)
		return add(list, value);
	//Выделение динамической памяти под новый элемент
	ELEMENT* tmp = nullptr;
	try
	{
		tmp = new ELEMENT;
	}
	catch (...)
	{
		//Если выделить не удалось - выход
		return false;
	}
	//Связываем новый элемент списка с:
	tmp->next = list->curr; //последующим элементом
	tmp->prev = list->curr->prev;//предыдущим элементом
	//Если предыдущий элемент в спиcке есть, то связываем его
	if (tmp->prev)
		tmp->prev->next = tmp; //с новым элементом
	//Связываем текущий элемент списка с новым элементом
	list->curr->prev = tmp;
	//Если текущий элемент является первым элементом, то
	//устанавливаем указатель на первый элемент в списке
	//на новый элемент
	if (list->curr == list->head)
		list->head = tmp;
	tmp->value = *value; //Записываем значение в новый элемент
	list->curr = tmp; //Делаем новый элемент текущим
	return true; //Успешное завершение
}
void destroy(LIST* list)
{
	while (list->head)
	{
		//Пока список не пустой
		//Устанавливаем указатель на текущий элемент на
		list->curr = list->head; //первый элемент
		//Устанавливаем указатель на первый элемент на
		list->head = list->head->next; //следующий элемент
		delete list->curr; //Удаляем текущий элемент
	}
	//Инициализация указателей
	list->head = nullptr;
	list->curr = nullptr;
}
bool del(LIST* list)
{
	//Если список не существует или текущий элемент не
	//установлен, то выход
	if (!list->head || !list->curr)
		return false;
	ELEMENT* tmp = list->curr; //Локальная переменная
	//Устанавливаем указатель на текующий элемент на
	list->curr = tmp->next; //следующий по списку
	//Если существует предыдущий элемент, то поле-указатель
	//на следующий элемент устанаваливаем на следующий
	//элемент после удаляемого
	if (tmp->prev)
		tmp->prev->next = list->curr;
	//Если существует следующий элемент, то поле-указатель
	//на предыдующий элемент устанаваливаем на предыдующий
	//элемент перед удаляемым
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	//Если удаляется первый элемент, то указатель на первый
	//элемент устанавливаем на следующий по списку
	if (list->head == tmp)
		list->head = tmp->next;
	delete tmp; //Освобождаем динамическую память
	return true; //Успешное завершение
}
bool moveHead(LIST* list)
{
	//Если список отсутствует, то выход
	if (list->head == nullptr)
		return false;
	//Установка указателя на текущий элемент
	list->curr = list->head; //на начало списка
	return true; //Успешное завершение
}
bool moveNext(LIST* list)
{
	//Если список отсутствует или указатель на текущий
	//элемент не установлен, то выход
	if (list->head == nullptr || list->curr->next == nullptr)
		return false;
	//Установка указателя на текущий элемент на
	list->curr = list->curr->next; //следующий элемент
	return true; //Успешное завершение
}
bool movePrev(LIST* list)
{
	//Если список отсутствует или указатель на текущий
	//элемент не установлен, то выход
	if (!list->head || !list->curr->prev)
		return false;
	//Установка указателя на текущий элемент на
	list->curr = list->curr->prev; //предыдущий элемент
	return true; //Успешное завершение
}
bool set(LIST* list, DataType* value)
{
	//Проверка наличия текущего элемента списка
	if (!list->curr)
		return false;
	//Установка нового значения текущего элемента
	list->curr->value = *value;
	return true;
}
bool get(LIST* list, DataType* value)
{
	//Проверка наличия текущего элемента списка
	if (!list->curr)
		return false;
	//Запись значения текущего элемента в параметр по ссылке
	*value = list->curr->value;
	return true;
}
//////////
void SortIns(LIST* list, int(*cmp)(const DataType*, const DataType*))
{
	ELEMENT* tmp, * cur; //Локальные переменные
	//Проверка: если в списке менее двух элементов, то
	//сортировать бессмысленно
	if ((list->head == nullptr) || (list->head->next == nullptr))
		return;
	//Устанавливается указатель на текущий элемент на второй
	list->curr = list->head->next; //элемент в списке
	//В цикле: пока не упорядочены все элементы
	while (list->curr)
	{
		//Указатель tmp - на текущий элемент в списке
		tmp = list->curr;
		//Указатель cur - на предыдущий элемент в списке
		cur = list->curr->prev;
		//Указатель на текущий элемент устанавливается на
		//следующий элемент в списке
		list->curr = list->curr->next;
		//Выделение элемента, на который установлен указатель
		cur->next = tmp->next; //tmp, из списка
		if (tmp->next) tmp->next->prev = cur;
		//В цикле производится поиск места вставки
		while (cur && (cmp(&cur->value, &tmp->value) > 0))
			cur = cur->prev;
		//Если выделенный элемент нужно вставить в «середину»
		if (cur)
		{
			tmp->next = cur->next;
			tmp->prev = cur;
			cur->next = tmp;
			if (tmp->next) tmp->next->prev = tmp;
		}
		else
		{
			//Иначе: в начало списка
			tmp->next = list->head;
			tmp->prev = nullptr;
			list->head->prev = tmp;
			list->head = tmp;
		}
	}
	//Установка указателя на текущий элемент на
	list->curr = list->head; //начало списка
}
void SortBub(LIST* list, int(*cmp)(const DataType*, const DataType*))
{
	//Проверка: если в списке нет элементов, то
	//сортировать бессмысленно
	if (!list->head)
		return;
	bool Flag = true; //Флаг продолжения сортировки
	while (Flag)
	{
		//Пока есть неупорядоченные элементы
		Flag = false; //Сброс флага продолжения сортировки
		//Установка указателя на текущий элемент на
		list->curr = list->head; //начало списка
		//Цикл по всему списку до предпоследнего элемента
		while (list->curr->next) {
			//Проверка условия упорядоченности
			if (cmp(&list->curr->value, &list->curr->next->value) > 0) {
				//Если необходима перестановка, то
				Exchange(list); //Осуществление перестановки
				Flag = 1; //Установка флага сортировки
				//Иначе: переход к следующему элементу по списку
			}
			else list->curr = list->curr->next;
		}
	}
	//Установка указателя на текущий элемент на
	list->curr = list->head; //начало списка
}
void Exchange(LIST* list)
{
	DataType tmp;
	//Копирование значения текущего элемента в дополнительную
	memcpy(&tmp, &list->curr->value, sizeof(DataType));//переменную
	//Копирование значения следующего элемента в текущий
	memcpy(&list->curr->value, &list->curr->next->value,
		sizeof(DataType));
	//Копирование значения из дополнительной переменной
	//в следующий элемент
	memcpy(&list->curr->next->value, &tmp, sizeof(DataType));
}
/*void Exchange(LIST *list)
{
	//Объявление локального указателя и установка его на243
	ELEMENT *tmp = list->curr->next; //следующий элемент
	//Связывание текущего элемента с элементом после
	//следующего элемента в списке
	list->curr->next = tmp->next;
	//Связывание следующего элемента с элементом перед
	//текущим элементом в списке
	tmp->prev = list->curr->prev;
	//Если элемент после текущего элемента присутствует, то
	//связывание его с текущим элементом
	if (list->curr->next != nullptr)
		list->curr->next->prev = list->curr;
	//Если элемент перед следующим элементом присутствует, то
	//связывание его со следующим элементом
	if (tmp->prev != nullptr)
		tmp->prev->next = tmp;
	//Связывание следующего элемента с текущим элементом
	tmp->next = list->curr;
	//Связывание текущего элемента со следующим элементом
	list->curr->prev = tmp;
	//Если осуществлялась перестановка первого и второго
	//элементов, то установка указателя на начало списка
	if (list->curr == list->head) list->head = tmp;
}*/
int FindFirst(DataType key, LIST* list,
	int(*cmp)(const DataType*, const DataType*))
{
	//Проверка наличия элементов в списке
	if (!list->head)
		return 0;
	//Установка указателя на начало списка
	list->curr = list->head;
	//В цикле по всему списку: до последнего элемента
	while (list->curr) {
		//Если значение текущего элемента равно искомому
		//то завершение выполнения и возврат значения 1
		if (cmp(&key, &list->curr->value) == 0) return 1;
		//Переход к следующему элементу в списке
		list->curr = list->curr->next;
	}
	return 0; //Возврат значения 0
}
int FindNext(DataType key, LIST* list,
	int(*cmp)(const DataType*, const DataType*))
{
	//Проверка наличия текущего элемента
	if (!list->curr) return 0;
	//Установка указателя на следующий элемент
	list->curr = list->curr->next;
	//В цикле: до последнего элемента
	while (list->curr) {
		//Если значение текущего элемента равно искомому
		//то завершение выполнения и возврат значения 1
		if (cmp(&key, &list->curr->value) == 0)
			return 1;
		//Переход к следующему элементу в списке
		list->curr = list->curr->next;
	}
	return 0; //Возврат значения 0
}
int CompareAscending(const DataType* element1, const DataType* element2)
{
	return element1->name > element2->name;
}
int CompareDescending(const DataType* element1, const DataType* element2)
{
	return element1->name < element2->name;
}
bool readfile(LIST* mylist)
{
	/*destroy(mylist);
	create(mylist);
	std::ifstream in("file_binary.txt", std::ios::binary);
	if (in.is_open() == false)
	{
		return false;
	}
	moveHead(mylist);
	DataType d;
	while (in.read((char*)&d,sizeof(DataType)))
	{
		add(mylist, &d);
	}
	in.close();*/
	return true;
}

bool savefile(LIST* mylist)
{
	/*std::ofstream out_file("file_binary.txt", std::ios::binary);
	if (out_file.is_open() == false)		
	{
		return false;
	}
	moveHead(mylist);
	do
	{
		DataType d;
		get(mylist, &d);
		out_file.write((char*)(&mylist), sizeof(DataType));
	} while (moveNext(mylist) == true);
	out_file.close();*/
	return true;
}
