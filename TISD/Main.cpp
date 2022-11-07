#include <iostream>
#include <fstream>
#include "List.h"
#include <Windows.h>
#include <cctype>
#include <cstring>



using namespace std;
bool RunMenu = true;


Node* temp;
SingleList* listNeg = new SingleList();
SingleList* listPol = new SingleList();
SingleList* list = new SingleList();
SingleList* result = new SingleList();
string inputfile;
string outputfile;

class menuItem {
private:
	typedef int(*Func)();
	const char* m_item_type{};
	Func m_function{};
public:
	menuItem(const char* item, Func function) :
		m_item_type(item),
		m_function(function) {};
	void print_service() {
		cout << m_item_type;
	}
	int runItem() {
		return m_function();
	}
};

class Menu {
private:
	const char* m_item_name{};
	size_t m_count{};
	menuItem* m_items{};
	int m_select{ -1 };
public:
	Menu(const char* service_name, menuItem* item, size_t count)
		:
		m_item_name(service_name), m_items(item),
		m_count(count) {};
	void menu_print() {
		for (size_t i{}; i < m_count; ++i) {
			cout << i << ". ";
			m_items[i].print_service();
			cout << endl;
		}
	}
	int menuRun() {
		menu_print();
		cout << "\n����-> ";
		cin >> m_select;
		return m_items[m_select].runItem();
	}
};

void FileVVod(const char* input,const char* output)
{
	inputfile = input;
	outputfile = output;
}

//���� ������ �� �����
void InputDataFromText(string filename)
{
	SingleList* list = new SingleList;
	int buff = 0;
	int i = 0;
	ifstream file(filename + ".txt");
	while (!file.eof())
	{
		file >> buff;
		list->AddItem(buff);
	}
	file.close();
	cout << endl;
	cout << endl;
	system("pause");
	system("cls");
}

void proverkafile()
{
	
	SingleList* list = new SingleList;
	ifstream fileOpen(inputfile + ".txt");
	int buff = 0;
	
		// ���� �����
	if (fileOpen.fail())
	{
		cout << endl;
		cout << "����� " << inputfile << ".txt �� ����������, ���������� ����������� ����" << endl;
		ifstream file;
		file.open("DataInput.txt");
		while (!file.eof())
		{
			file >> buff;
			list->AddItem(buff);
		}
		file.close();
	}
	else
	{
		ifstream file(inputfile + ".txt");
		while (!file.eof())
		{
			file >> buff;
			list->AddItem(buff);
		}
		file.close();
		cout << "������ ���������";
	}
	system("cls");
}

// ����� � ����
void OutputToFile(string filename)
{
	SingleList* result = new SingleList();
	ofstream file;
	file.open(filename + ".txt");
	while (!result->IsEmpty())
	{
		auto buf = result->GetTop()->data;
		file << buf << ' ';
		result->DeleteItem(1);
	}
	file.close();
}

void Outputfile()
{
	system("cls");

	// ���� ������
	fstream fileOutput(outputfile + ".txt");
	if (fileOutput.fail())
	{
		cout << endl;
		cout << "����� " << outputfile << " �� ����������, ���������� ����������� ����" << endl;
		cout << endl;
		ofstream file;
		file.open("OutputData.txt");
		while (!result->IsEmpty())
		{
			auto buf = result->GetTop()->data;
			file << buf << ' ';
			result->DeleteItem(1);
		}
		file.close();
		cout << "������ ����������� � �������� ����" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		OutputToFile(outputfile);
		cout << "������ ��������� � ���� " << outputfile << endl;
		system("pause");
		system("cls");
	}
}

// ���� ������ ������ � ������
void DataInput(SingleList* list)
{
	system("cls");
	int kol, item;
	cout << "������� ���������� �����: ";
	cin >> kol;
	cout << endl;
	for (int i = 0; i < kol; i++)
	{
		cout << "������� ����� �" << i + 1 << ":";
		cin >> item;
		list->AddItem(item);


	}
	system("pause");
	system("cls");
}

// �������������� �������
void IndividualQuestions(SingleList* list, SingleList* listNeg, SingleList* listPol, SingleList* result)
{
	system("cls");
	if (list->IsEmpty() == 0) {
		while (!list->IsEmpty()) {
			if (list->GetTop()->data < 0) {
				listNeg->AddItem(list->GetTop()->data);
				list->DeleteItem(1);
			}
			else {
				listPol->AddItem(list->GetTop()->data);
				list->DeleteItem(1);
			}

		}
		while (!listPol->IsEmpty()) {
			result->AddItem(listPol->GetTop()->data);
			listPol->DeleteItem(1);
		}
		while (!listNeg->IsEmpty()) {
			result->AddItem(listNeg->GetTop()->data);
			listNeg->DeleteItem(1);
		}

		result->PrintList();
	}
	else if (list->IsEmpty() == 1)
	{
		cout << "---��� ���������---" << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
}

//����� ������ �� �����
void PrintData(SingleList* list)
{
	system("cls");
	cout << endl;
	cout << "������" << endl;
	list->PrintList();
	cout << endl;
	system("pause");
	system("cls");

}

//����������
int ADDitem()
{
	system("cls");
	int add = 0;
	cout << "---����������---" << endl;
	cout << "����� ������� ������ ������ -> ";
	cin >> add;
	list->AddItem(add);
	system("cls");
	return 1;
}

//����� �� ���������
int exit()
{
	system("cls");
	exit(1);
}

int outputfile1()
{
	Outputfile();
	return 1;
}

int InputDataFromText1()
{
	proverkafile();
	return 1;
}

int DataInput1()
{
	DataInput(list);
	return 1;
}

int PrintData1()
{
	PrintData(list);
	return 1;
}


int IndividualQuestions1()
{
	IndividualQuestions(list, listNeg, listPol, result);
	return 1;
}




//�������� ���������
int main(int argc, const char* argv[])
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FileVVod(argv[1], argv[2]);
	vvoderrorfile(argv[3]);
	const int item_number = 7;;
	menuItem items[item_number]{ menuItem {"�����", exit} ,menuItem {"����� �� �����" ,InputDataFromText1}, menuItem {"������ ������ �������", DataInput1} , menuItem {"����� �� �����" , PrintData1} , menuItem{"����� � ����" , outputfile1}, menuItem {"�������������� �������" , IndividualQuestions1} , menuItem{"���������� ��������" ,ADDitem}};
	Menu menu("���� ������", items, item_number);
	while (menu.menuRun())
	{
	}
	return 0;

}

