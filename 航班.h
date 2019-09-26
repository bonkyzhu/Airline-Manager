#pragma  once
#include <string>
#include <iostream>
using namespace std;
class Airline
{
public:
	Airline() {};
	Airline(string Initial, string Terminal, string Flight_num, string Flight_type, int Week, int  takeoff_time_minutes, int takeoff_time_hours, int  landing_time_minutes, int landing_time_hours, int Capacity, int price, int First_Class_Ticket, int Business_Ticket, int economy_Ticket)
	{
		this->Initial = Initial;
		this->Terminal = Terminal;
		this->Flight_num = Flight_num;
		this->Flight_type = Flight_type;
		this->Week = Week;
		this->takeoff_time_hours = takeoff_time_hours;
		this->takeoff_time_minutes = takeoff_time_minutes;
		this->landing_time_hours = landing_time_hours;
		this->landing_time_minutes = landing_time_minutes;
		this->Capacity = Capacity;
		this->price = price;
		this->First_Class_Ticket = First_Class_Ticket;
		this->Business_Ticket = Business_Ticket;
		this->economy_Ticket = economy_Ticket;
	}
		void change_var(string Initial, string Terminal, string Flight_num, string Flight_type, int Week, int  takeoff_time_minutes, int takeoff_time_hours, int  landing_time_minutes, int landing_time_hours, int Capacity, int price, int First_Class_Ticket, int Business_Ticket, int economy_Ticket) {
		this->Initial = Initial;
		this->Terminal = Terminal;
		this->Flight_num = Flight_num;
		this->Flight_type = Flight_type;
		this->Week = Week;
		this->takeoff_time_hours=takeoff_time_hours;
		this->takeoff_time_minutes = takeoff_time_minutes;
		this->landing_time_hours=landing_time_hours;
		this->landing_time_minutes=landing_time_minutes;
		this->Capacity=Capacity;
		this->price = price;
		this->First_Class_Ticket=First_Class_Ticket;
		this->Business_Ticket=Business_Ticket;
		this->economy_Ticket = economy_Ticket;
	};//���캯��
	int change(int, string);
	void display();
	int display_week();
	int Airline::display_time(string );
	string Initial, Terminal;//���վ,�յ�վ
protected:
	string Flight_num,Flight_type;//�ɻ��źͷɻ��ͺ�
	int Week;//�º���,����������
	int  takeoff_time_minutes, takeoff_time_hours, landing_time_minutes, landing_time_hours;
	int Capacity;//��Ա
	int price;//�ɻ��۸�
	int First_Class_Ticket,Business_Ticket,economy_Ticket;//ʣ��Ʊ��
};

int  Airline::change(int num,string level)
{
	int flag = 0;
	if (level == "ͷ�Ȳ�")
	{
		if (First_Class_Ticket >=num)
		{
			this->First_Class_Ticket -= num; flag = 1; 
		}
	}
	else if (level=="�����")
	{
		if(Business_Ticket >=num)
		{
			this->Business_Ticket -= num; flag = 1; 
		}
	}
	else if (level=="���ò�")
	{
		if(economy_Ticket >=num)
		{
			this->economy_Ticket -= num; flag = 1; 
		}
	}
	return flag;
}
void Airline::display()
{
	string weeks[7] = { "����һ","���ڶ�" ,"������" ,"������" ,"������" ,"������" ,"������" };
	cout << Initial << "	" << Terminal << "	" << Flight_num << "	  " << takeoff_time_hours << ":" << takeoff_time_minutes << "	  " << landing_time_hours << ":" << landing_time_minutes;
	cout << "	  " << Flight_type << "	  " << weeks[Week-1]<< " " << Capacity << "	" << First_Class_Ticket << "	" << Business_Ticket << "	" << economy_Ticket << "	" << price<<endl;
}
int Airline::display_week()
{
	return Week;
}
int Airline::display_time(string a)
{
	if (a == "takeoff")
		return takeoff_time_hours * 60 + takeoff_time_minutes;
	if (a == "land")
		return landing_time_hours*60+landing_time_minutes;
}