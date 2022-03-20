#pragma once
#include <string>
typedef struct
{
	int x;
	int id;//��� �� ������ , ������� ��� ��������� ����� �������
	std::string name;
	double speed;
} DataType;
typedef struct _ELEMENT
{
	DataType value;
	//��������� �� ��������� ������� ������
	struct _ELEMENT* next;
	//��������� �� ���������� ������� ������
	struct _ELEMENT* prev;
}ELEMENT;
typedef struct
{
	ELEMENT* head; //��������� �� ������ �������
	ELEMENT* curr; //��������� �� ������� �������
}LIST;
static int id;
//���������
void create(LIST* list);
//��������� ������ ��� �������
bool add(LIST* list, DataType* value);

bool insert(LIST* list, DataType* value);
bool del(LIST* list);
void destroy(LIST* list);
bool moveHead(LIST* list);
bool moveNext(LIST* list);
bool movePrev(LIST* list);
bool set(LIST* list, DataType* value);
bool get(LIST* list, DataType* value);
void SortIns(LIST* list,int(*cmp)(const DataType*, const DataType*));
void SortBub(LIST* list,int(*cmp)(const DataType*, const DataType*));
void Exchange(LIST* list);
int FindFirst(DataType key, LIST* list,
	int(*cmp)(const DataType*, const DataType*));
int FindNext(DataType key, LIST* list,
	int(*cmp)(const DataType*, const DataType*));
int CompareAscending(const DataType*, const DataType*);
int CompareDescending(const DataType* element1, const DataType* element2);
bool readfile(LIST* mylist);
bool savefile(LIST* mylist);