/*
	�ɻ���Ʊ����ϵͳ(C++����ʵ�����)
	����Ȩ �����ϵ170717 ѧ��20178859
	ָ����ʦ:�����
	2018��1��12��
*/
#include <string>
#include <fstream>
#include "����.h"
#include"�˿�.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
Passenger customer;
Airline customed_ordered;
Airline plane[16];
int record;
//��������
void gotoxy(int x, int y);
void is_interface();
void recommend(string a);
void BookTickets(int num, Airline air);
void Airline_Query();
void Refund();
void exit();
void change_airplane();
void read();
int main()
{
	//��ӭ����
	cout << "      ///////////////////////////////////////////////////////////////////////////////////////////////////////\n";
	cout << "      ///--------------------��ӭ�����ɶ�����ѧ�ػʵ��������ͨ�Ź���ѧԺ���ʴ����-----------------------///\n";
	cout << "      ///-------------------------------�������:�ɻ���Ʊ����ϵͳ-----------------------------------------///\n";
	cout << "      ///----------------------------------��Ʒ����:�������ʦ--------------------------------------------///\n";
	cout << "      ///-------------------------������Ա:�����ϵ1707������Ȩ ����20178859------------------------------///\n";
	cout << "      ///-------------��ϵͳ���в�ѯ����,�а충Ʊ����Ʊ,�޸ĺ�����Ϣ,�����Ƽ��������ɫ����---------------///\n";
	cout << "      ///////////////////////////////////////////////////////////////////////////////////////////////////////\n";
	 ifstream infile("���뺽����Ϣ.dat"); ofstream  outfile("��¼�û���Ϣ.dat"); getchar();
	cout << "������������ֺ��Ա�:\n";
	customer.basic__info_input();
	system("cls");
	//�ʺ���
	read();
	gotoxy(20, 6);
	cout << "�𾴵�" << customer.Customer_Name[0]<< customer.Customer_Name[1];
	if (customer.gender == "��") { cout << "����"; }
	else { cout << "Ůʿ"; }
	cout << "��ʲô��Ҫ�Ұ�������\n";	is_interface();
	 //loadingʵ��
	int t = 2;
	while (t--)
	{
		system("cls");
		gotoxy(35, 10);
		cout << "//////////////////////////////////////////\n";
		gotoxy(35, 11);
		cout << "///                                    ///\n";
		gotoxy(35, 12);
		cout << "///           ������                   ///\n";
		gotoxy(35, 13);
		cout << "///                                    ///\n";
		gotoxy(35, 14);
		cout << "//////////////////////////////////////////\n";
		gotoxy(55, 12);
		for (int i = 0;i < 7;i++)
		{
			cout << ".";
			Sleep(1000 * 5 / 7);
		}
	}
	system("cls");
	//�ر��ļ�
	outfile.close();
	infile.close();
	 t = 1;
	while (t--)
	{
		system("cls");
		gotoxy(35, 10);
		cout << "//////////////////////////////////////////\n";
		gotoxy(35, 11);
		cout << "///                                    ///\n";
		gotoxy(35, 12);
		cout << "///           �˳���                   ///\n";
		gotoxy(35, 13);
		cout << "///                                    ///\n";
		gotoxy(35, 14);
		cout << "//////////////////////////////////////////\n";
		gotoxy(55, 12);
		for (int i = 0;i < 7;i++)
		{
			cout << ".";
			Sleep(1000 * 5 / 7);
		}
	}
	system("cls");
	getchar();getchar();
	return 0;
}
//ȫ������
void read()
{
	char notation;
	string Initial, Terminal, flight_num;
	int takeoff_time_hour, takeoff_time_minute;
	int landing_time_hour, landing_time_minute;
	string Flight_type;
	int week; int Capacity, price;
	int  First_Class_Ticket, Business_Ticket, economy_Ticket;
	fstream infile("���뺽����Ϣ.dat", ios::in);
	for (int i = 0; i <= 15; i++)
	{
		infile >> Initial >> Terminal >> flight_num >> takeoff_time_hour >> notation >> takeoff_time_minute >> landing_time_hour >> notation >> landing_time_minute;
		infile >> Flight_type >> week >> Capacity >> First_Class_Ticket >> Business_Ticket >> economy_Ticket >> price;
		plane[i].change_var(Initial, Terminal, flight_num, Flight_type, week, takeoff_time_minute, takeoff_time_hour, landing_time_minute, landing_time_hour, Capacity, price, First_Class_Ticket, Business_Ticket, economy_Ticket);
	}
}
void gotoxy(int x, int y) {																								   
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}
void recommend(string a)
{
	int step = 1;
	for (int i=0;i<=15;i++)
	{
		for (int j=0;j<=15;j++)
		{
			if (plane[i].Terminal == plane[j].Initial&&plane[i].display_week() < plane[j].display_week())
			{
				if(step==1)
				cout << "��Ϊ���Ƽ����º���\n";
				cout << "�Ƽ�" << step << ":\n";				
				plane[i].display(); plane[j].display();
					step++;
			}
			if (plane[i].Terminal == plane[j].Initial&&plane[i].display_week() == plane[j].display_week()&&plane[i].display_time("land")<plane[j].display_time("takeoff"))
			{
				if (step == 1)
					cout << "��Ϊ���Ƽ����º���\n"; 
				cout << "��Ϊ���Ƽ����º���\n";
				cout << "�Ƽ�" << step << ":\n";
				plane[i].display(); plane[j].display();
				step++;
			}
		}
	}
	char enter;
	cout << "�밴�س�������ҳ��";
	enter = _getch();
	system("cls");
	is_interface();
}

void BookTickets(int num, Airline air)
{
	char enter;
	cout << "��ѡ��������Ҫ�Ĳ�λ�ȼ�:\n";
	cout << "1.ͷ�Ȳ�.\n";
	cout << "2.�����\n";
	cout << "3.���ò�\n";
	enter = _getch();
	if(enter=='1'){
		if (plane[record].change(num, "ͷ�Ȳ�"))
		{
			customer.record_info(num, "ͷ�Ȳ�","�Ѷ�Ʊ"); cout << "��Ʊ�ɹ�" << endl; customer.display();
		}
		else
		{
			cout << "��Ʊʧ��\n"; customer.record_info(num, "�Ŷ���");
		}
	}
	else if (enter == '2') {
		if (plane[record].change(num, "�����"))
		{
			customer.record_info(num, "�����", "�Ѷ�Ʊ"); cout << "��Ʊ�ɹ�" << endl; customer.display();
		}
		else
		{
			cout << "��Ʊʧ��\n"; customer.record_info(num, "�Ŷ���");
		}
	}
	else if (enter == '3') {
		if (plane[record].change(num, "���ò�"))
		{
			customer.record_info(num, "���ò�", "�Ѷ�Ʊ"); cout << "��Ʊ�ɹ�" << endl; customer.display();
		}
		else
		{
			cout << "��Ʊʧ��\n"; customer.record_info(num, "�Ŷ���");
		}
	}
	cout << "�����ص�������\n";
	Sleep(1000 * 1.5);
	system("cls");
	is_interface();
}
	void Airline_Query()
	{
		system("cls");
		cout << "����������Ҫ��ѯ�ĳ���" << endl;
		string final;
		cin >> final;
		for (int i = 0; i <= 15; i++)
		{
			if (plane[i].Initial == "�ػʵ�"&&plane[i].Terminal == final)
			{
				cout << "�����ҵ����º���\n";
				cout << "���	�յ�	�����	���ʱ�� ����ʱ�� ����	������� ����	ͷ�Ȳ�	�����	���ò�	�۸�\n";
				plane[i].display();
				record = i;
				cout << "�Ƿ�ѡ�����Ʊ[Y / N]\n";
				char inputs;
				cin >> inputs;
				if (inputs == 'Y')
				{
					int num;
					cout << "����������Ҫ��Ʊ��:\n";
					cin >> num;
					BookTickets(num, customed_ordered);
					return;
				}
				else
				{
					system("cls");
					is_interface();
					return;
				}
				//Sleep(1000* 5 / 7);
				break;
			}
			if (i == 13)
			{
				cout << "û�����Һ���" << endl;
				recommend(final);
				getchar(); getchar();
				//Sleep(1000 * 3 / 7);
				system("cls");
				is_interface();
			}
		}
		//fclose(stdin);
		is_interface();
		Sleep(1000 * 500 / 7);
	}
	void Refund()
	{
		system("cls");
		char x;
		plane[record].display();
		customer.display();
		int t = 2;
		cout << "�Ƿ�ȷ��ѡ����Ʊ?[ Y/N]\n";
		x = _getch();
		if(x='Y')
		{
			int t = 1;
			while (t--)
			{
				system("cls");
				gotoxy(35, 10);
				cout << "//////////////////////////////////////////\n";
				gotoxy(35, 11);
				cout << "///                                    ///\n";
				gotoxy(35, 12);
				cout << "///           ��Ʊ��                  ///\n";
				gotoxy(35, 13);
				cout << "///                                    ///\n";
				gotoxy(35, 14);
				cout << "//////////////////////////////////////////\n";
				gotoxy(45, 12);
				for (int i = 0; i < 7; i++)
				{
					cout << ".";
					Sleep(1000 * 1 / 7);
				}
			}
			plane[record].change(-customer.Ticket_Number, customer.Cabin_Level);
			customer.record_info("����Ʊ");
			cout << "��Ʊ�ɹ�!"; cout << "�����ص�������\n";
			Sleep(1000 * 1.5);
			system("cls");
			is_interface();
		}
		else
		{
			system("cls");
			is_interface();
		}
	}
	void change_airplane()
	{
		//���б���
		string start, end; int i;
		char notation;
		string Initial, Terminal, flight_num;
		int takeoff_time_hour, takeoff_time_minute;
		int landing_time_hour, landing_time_minute;
		string Flight_type;
		int week; int Capacity, price;
		int  First_Class_Ticket, Business_Ticket, economy_Ticket;
		gotoxy(35, 14);
		cout << "����Ҫ�޸ĵĺ�����ʼ��\n";
		cin >> start;
		cout << "��������Ҫ�޸ĵĺ����յ�\n";
		cin >> end;
		for (i=0;i<=15;i++)
		{
			if (start==plane[i].Initial&&end==plane[i].Terminal)
			{
				break;
			}
		}
		cout << "���ո�ʽ�޸ĺ���(���������ֱ�ʾ)\n";
		plane[i].display();
		cin >> Initial >> Terminal >> flight_num >> takeoff_time_hour >> notation >> takeoff_time_minute >> landing_time_hour >> notation >> landing_time_minute;
		cin >> Flight_type >> week >> Capacity >> First_Class_Ticket >> Business_Ticket >> economy_Ticket >> price;
		plane[i].change_var(Initial, Terminal, flight_num, Flight_type, week, takeoff_time_minute, takeoff_time_hour, landing_time_minute, landing_time_hour, Capacity, price, First_Class_Ticket, Business_Ticket, economy_Ticket);
		cout << "�������޸ĺ�Ľ��\n";
		plane[i].display();
		Sleep(1000 * 3);
		system("cls");
		is_interface();
	}
	void exit()
	{
		int t = 1;
		while (t--)
		{
			system("cls");
			gotoxy(35, 10);
			cout << "//////////////////////////////////////////\n";
			gotoxy(35, 12);
			cout << "              �˳���                                \n";
			gotoxy(35, 14);
			cout << "//////////////////////////////////////////\n";
			gotoxy(55, 12);
			for (int i = 0; i < 7; i++)
			{
				cout << ".";
				Sleep(1000 * 5 / 7);
			}
		}
		system("cls");
		exit(0);
	}
	void is_interface()
	{
		char enter;
		//����ѡ�����
		gotoxy(20, 8);
		cout << "////////////////////////////////////\n";
		gotoxy(20, 9);
		cout << "////// 1.��ѯ���߲����Ļ�Ʊ   //////\n";
		gotoxy(20, 10);
		cout << "////// 2.��Ʊ����	          //////\n";
		gotoxy(20, 11);
		cout << "////// 3.�޸ĺ�����Ϣ         //////\n";
		gotoxy(20, 12);
		cout << "////// 4.�˳�ϵͳ	          //////\n";
		gotoxy(20, 13);
		cout << "////////////////////////////////////\n";
		gotoxy(20, 14);
		enter = _getch();
		switch (enter)
		{
		case '1':Airline_Query(); break;
		case '2':Refund(); break;
		case '3':change_airplane(); break;
		case '4':exit(); break;
		}
	}
