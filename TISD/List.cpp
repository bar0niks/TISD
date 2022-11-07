#include "List.h"
#include <fstream>
#include <iostream>
using namespace std;
string errorfile;

void vvoderrorfile(const char* fileror)
{
	errorfile = fileror;
}

void WriteErrorsIntoFile1() {
	fstream file2(errorfile);
	if (file2.fail())
	{
		fstream file;
		file.open("Errors.txt");
		file << "WARNING: ERROR! " << "Empty list - 0";
		file.close();
	}
	else
	{
		fstream file;
		file.open(errorfile);
		file << "WARNING: ERROR! " << "Empty list - 0";
		file.close();
	}
}

void WriteErrorsIntoFile2() {
	fstream file2(errorfile);
	if (file2.fail())
	{
		fstream file;
		file.open("Errors.txt");
		file << "WARNING: ERROR! " << "Out of index - 1";
		file.close();
	}
	else
	{
		fstream file;
		file.open(errorfile);
		file << "WARNING: ERROR! " << "Out of index - 1";
		file.close();
	}
}

void SingleList::AddItem(int _data)
{
	Node* temp;
	temp = new Node;
	temp->data = _data;
	temp->next = top;
	top = temp;
	size++;

}

void SingleList::PrintList()
{
	cout << "\nThe size is " << size << endl;

	Node* temp = top;
	if (!size)
	{
		WriteErrorsIntoFile1();
		throw SLException(SLException::EMPTY_LIST, (char*)"empty list!");
	}

	while (temp != NULL)
	{
		cout << "-> " << temp->data << "\t: " <<
			temp->next << endl;
		temp = temp->next;
	}
	cout << endl << endl;
}

void SingleList::PrintListRecurrently(Node* _top) {
	if (!size)
	{
		WriteErrorsIntoFile1();
		throw SLException(SLException::EMPTY_LIST, (char*)"empty list!");
	}
	if (_top != NULL)
	{
		cout << _top->data << "\t";
		PrintListRecurrently(_top->next);
	}
}

void SingleList::DeleteItem(int index)
{
	if ((index < 0) || (index > size))
	{
		WriteErrorsIntoFile2();
		throw SLException(SLException::OUT_OF_INDEX, (char*)"out of index!");
	}
	if (!size)
	{
		WriteErrorsIntoFile1();
		throw SLException(SLException::EMPTY_LIST,(char*)"empty list!");
	}

	Node* temp, * prev;
	if (index == 1)
	{
		temp = top;
		top = top->next;
		delete temp;
		size--;
	}
	else if (index == size)
	{
		prev = top;
		while (prev->next->next != NULL)
		{
			prev = prev->next;
		}
		temp = prev->next;
		prev->next = NULL;
		delete temp;
		size--;
	}
	else
	{
		prev = top;
		int i = 1;
		while (i < (index - 1))
		{
			prev = prev->next;
			i++;
		}
		temp = prev->next;
		prev->next = prev->next->next;
		delete temp;
		size--;
	}
}

bool SingleList::IsItem(int source)
{
	Node* temp = top;
	while (temp != NULL)
	{
		if (temp->data == source)
		{
			break;
		}
		temp = temp->next;
	}
	return (temp != NULL) ? 1 : 0;
}

bool SingleList::IsEmpty()
{
	return (top == NULL) ? 1 : 0;
}

void SingleList::DeleteList(Node* _top)
{
	cout << "inside deleting:\t";
	if (_top->next != NULL) {
		cout << "-> " << _top->data << "\t: " <<
			top->next << endl;
		DeleteList(_top->next);
	}
	cout << "\t\t" << _top->data << "\t: " <<
		_top->next << endl;
	_top->next = NULL;
	size--;
	delete _top;
}
