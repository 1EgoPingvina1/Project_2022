#include "list.h"
#include <string>
#include <fstream>
void create(LIST* list)
{
	//������������� ����������
	list->head = nullptr;
	list->curr = nullptr;
	id = 0;
}
bool add(LIST* list, DataType* value)
{
	//��������� ������������ ������ ��� ����� �������
	ELEMENT* tmp = nullptr;
	try
	{
		tmp = new ELEMENT;
	}
	catch (...)
	{
		//���� �������� �� ������� - �����
		return false;
	}
	if (list->head == nullptr)
	{
		//���� ������ ������ (��� ���������)
		//��������� ��������� �� ������ ������� � ������ ��
		list->head = tmp; //����� �������
		//��������� ��������� �� ���������� ������� � ������
		list->head->prev = nullptr; //� ������� ��������
	}
	else
	{
		//����� (���� ������ �� ������)
		//������������� ��������� �� ������� ������� ��
		//��������� ������� � ������
		if (!list->curr) list->curr = list->head;
		while (list->curr->next)
			list->curr = list->curr->next;
		//����-��������� �� ��������� ������� ����������
		//�������� ������������� �� ����� �������
		list->curr->next = tmp;
		//����-��������� �� ���������� ������� ������ ��������
		//������������� �� ��������� ������� � ������
		tmp->prev = list->curr;
	}
	value->id = id;
	tmp->value = *value; //���������� �������� � ����� �������
	//� ����-��������� �� ��������� ������� ����������
	tmp->next = nullptr; //������� ��������
	list->curr = tmp; //������ ����� ������� �������
	id += 1;
	return true; //�������� ����������
}
bool insert(LIST* list, DataType* value)
{
	//���� ������ ������ ��� ������� ������� �� ����������,
	//�� ��������� � ����� ������
	if (!list->head || !list->curr)
		return add(list, value);
	//��������� ������������ ������ ��� ����� �������
	ELEMENT* tmp = nullptr;
	try
	{
		tmp = new ELEMENT;
	}
	catch (...)
	{
		//���� �������� �� ������� - �����
		return false;
	}
	//��������� ����� ������� ������ �:
	tmp->next = list->curr; //����������� ���������
	tmp->prev = list->curr->prev;//���������� ���������
	//���� ���������� ������� � ���c�� ����, �� ��������� ���
	if (tmp->prev)
		tmp->prev->next = tmp; //� ����� ���������
	//��������� ������� ������� ������ � ����� ���������
	list->curr->prev = tmp;
	//���� ������� ������� �������� ������ ���������, ��
	//������������� ��������� �� ������ ������� � ������
	//�� ����� �������
	if (list->curr == list->head)
		list->head = tmp;
	tmp->value = *value; //���������� �������� � ����� �������
	list->curr = tmp; //������ ����� ������� �������
	return true; //�������� ����������
}
void destroy(LIST* list)
{
	while (list->head)
	{
		//���� ������ �� ������
		//������������� ��������� �� ������� ������� ��
		list->curr = list->head; //������ �������
		//������������� ��������� �� ������ ������� ��
		list->head = list->head->next; //��������� �������
		delete list->curr; //������� ������� �������
	}
	//������������� ����������
	list->head = nullptr;
	list->curr = nullptr;
}
bool del(LIST* list)
{
	//���� ������ �� ���������� ��� ������� ������� ��
	//����������, �� �����
	if (!list->head || !list->curr)
		return false;
	ELEMENT* tmp = list->curr; //��������� ����������
	//������������� ��������� �� �������� ������� ��
	list->curr = tmp->next; //��������� �� ������
	//���� ���������� ���������� �������, �� ����-���������
	//�� ��������� ������� �������������� �� ���������
	//������� ����� ����������
	if (tmp->prev)
		tmp->prev->next = list->curr;
	//���� ���������� ��������� �������, �� ����-���������
	//�� ����������� ������� �������������� �� �����������
	//������� ����� ���������
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	//���� ��������� ������ �������, �� ��������� �� ������
	//������� ������������� �� ��������� �� ������
	if (list->head == tmp)
		list->head = tmp->next;
	delete tmp; //����������� ������������ ������
	return true; //�������� ����������
}
bool moveHead(LIST* list)
{
	//���� ������ �����������, �� �����
	if (list->head == nullptr)
		return false;
	//��������� ��������� �� ������� �������
	list->curr = list->head; //�� ������ ������
	return true; //�������� ����������
}
bool moveNext(LIST* list)
{
	//���� ������ ����������� ��� ��������� �� �������
	//������� �� ����������, �� �����
	if (list->head == nullptr || list->curr->next == nullptr)
		return false;
	//��������� ��������� �� ������� ������� ��
	list->curr = list->curr->next; //��������� �������
	return true; //�������� ����������
}
bool movePrev(LIST* list)
{
	//���� ������ ����������� ��� ��������� �� �������
	//������� �� ����������, �� �����
	if (!list->head || !list->curr->prev)
		return false;
	//��������� ��������� �� ������� ������� ��
	list->curr = list->curr->prev; //���������� �������
	return true; //�������� ����������
}
bool set(LIST* list, DataType* value)
{
	//�������� ������� �������� �������� ������
	if (!list->curr)
		return false;
	//��������� ������ �������� �������� ��������
	list->curr->value = *value;
	return true;
}
bool get(LIST* list, DataType* value)
{
	//�������� ������� �������� �������� ������
	if (!list->curr)
		return false;
	//������ �������� �������� �������� � �������� �� ������
	*value = list->curr->value;
	return true;
}
//////////
void SortIns(LIST* list, int(*cmp)(const DataType*, const DataType*))
{
	ELEMENT* tmp, * cur; //��������� ����������
	//��������: ���� � ������ ����� ���� ���������, ��
	//����������� ������������
	if ((list->head == nullptr) || (list->head->next == nullptr))
		return;
	//��������������� ��������� �� ������� ������� �� ������
	list->curr = list->head->next; //������� � ������
	//� �����: ���� �� ����������� ��� ��������
	while (list->curr)
	{
		//��������� tmp - �� ������� ������� � ������
		tmp = list->curr;
		//��������� cur - �� ���������� ������� � ������
		cur = list->curr->prev;
		//��������� �� ������� ������� ��������������� ��
		//��������� ������� � ������
		list->curr = list->curr->next;
		//��������� ��������, �� ������� ���������� ���������
		cur->next = tmp->next; //tmp, �� ������
		if (tmp->next) tmp->next->prev = cur;
		//� ����� ������������ ����� ����� �������
		while (cur && (cmp(&cur->value, &tmp->value) > 0))
			cur = cur->prev;
		//���� ���������� ������� ����� �������� � ���������
		if (cur)
		{
			tmp->next = cur->next;
			tmp->prev = cur;
			cur->next = tmp;
			if (tmp->next) tmp->next->prev = tmp;
		}
		else
		{
			//�����: � ������ ������
			tmp->next = list->head;
			tmp->prev = nullptr;
			list->head->prev = tmp;
			list->head = tmp;
		}
	}
	//��������� ��������� �� ������� ������� ��
	list->curr = list->head; //������ ������
}
void SortBub(LIST* list, int(*cmp)(const DataType*, const DataType*))
{
	//��������: ���� � ������ ��� ���������, ��
	//����������� ������������
	if (!list->head)
		return;
	bool Flag = true; //���� ����������� ����������
	while (Flag)
	{
		//���� ���� ��������������� ��������
		Flag = false; //����� ����� ����������� ����������
		//��������� ��������� �� ������� ������� ��
		list->curr = list->head; //������ ������
		//���� �� ����� ������ �� �������������� ��������
		while (list->curr->next) {
			//�������� ������� ���������������
			if (cmp(&list->curr->value, &list->curr->next->value) > 0) {
				//���� ���������� ������������, ��
				Exchange(list); //������������� ������������
				Flag = 1; //��������� ����� ����������
				//�����: ������� � ���������� �������� �� ������
			}
			else list->curr = list->curr->next;
		}
	}
	//��������� ��������� �� ������� ������� ��
	list->curr = list->head; //������ ������
}
void Exchange(LIST* list)
{
	DataType tmp;
	//����������� �������� �������� �������� � ��������������
	memcpy(&tmp, &list->curr->value, sizeof(DataType));//����������
	//����������� �������� ���������� �������� � �������
	memcpy(&list->curr->value, &list->curr->next->value,
		sizeof(DataType));
	//����������� �������� �� �������������� ����������
	//� ��������� �������
	memcpy(&list->curr->next->value, &tmp, sizeof(DataType));
}
/*void Exchange(LIST *list)
{
	//���������� ���������� ��������� � ��������� ��� ��243
	ELEMENT *tmp = list->curr->next; //��������� �������
	//���������� �������� �������� � ��������� �����
	//���������� �������� � ������
	list->curr->next = tmp->next;
	//���������� ���������� �������� � ��������� �����
	//������� ��������� � ������
	tmp->prev = list->curr->prev;
	//���� ������� ����� �������� �������� ������������, ��
	//���������� ��� � ������� ���������
	if (list->curr->next != nullptr)
		list->curr->next->prev = list->curr;
	//���� ������� ����� ��������� ��������� ������������, ��
	//���������� ��� �� ��������� ���������
	if (tmp->prev != nullptr)
		tmp->prev->next = tmp;
	//���������� ���������� �������� � ������� ���������
	tmp->next = list->curr;
	//���������� �������� �������� �� ��������� ���������
	list->curr->prev = tmp;
	//���� �������������� ������������ ������� � �������
	//���������, �� ��������� ��������� �� ������ ������
	if (list->curr == list->head) list->head = tmp;
}*/
int FindFirst(DataType key, LIST* list,
	int(*cmp)(const DataType*, const DataType*))
{
	//�������� ������� ��������� � ������
	if (!list->head)
		return 0;
	//��������� ��������� �� ������ ������
	list->curr = list->head;
	//� ����� �� ����� ������: �� ���������� ��������
	while (list->curr) {
		//���� �������� �������� �������� ����� ��������
		//�� ���������� ���������� � ������� �������� 1
		if (cmp(&key, &list->curr->value) == 0) return 1;
		//������� � ���������� �������� � ������
		list->curr = list->curr->next;
	}
	return 0; //������� �������� 0
}
int FindNext(DataType key, LIST* list,
	int(*cmp)(const DataType*, const DataType*))
{
	//�������� ������� �������� ��������
	if (!list->curr) return 0;
	//��������� ��������� �� ��������� �������
	list->curr = list->curr->next;
	//� �����: �� ���������� ��������
	while (list->curr) {
		//���� �������� �������� �������� ����� ��������
		//�� ���������� ���������� � ������� �������� 1
		if (cmp(&key, &list->curr->value) == 0)
			return 1;
		//������� � ���������� �������� � ������
		list->curr = list->curr->next;
	}
	return 0; //������� �������� 0
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
