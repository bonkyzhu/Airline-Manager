//#include "����.h"
#include <string>
using namespace std;
class Passenger:public Airline
{
public:
	void basic__info_input();
	Passenger(string name, string sex, int num, string level):Airline( Initial, Terminal, Flight_num, Flight_type,Week, takeoff_time_minutes, takeoff_time_hours, landing_time_minutes, landing_time_hours, Capacity, price, First_Class_Ticket, Business_Ticket, economy_Ticket)
	{
		this->Customer_Name = name;
		this->gender = sex;
		this->Ticket_Number;
		this->Cabin_Level = level;
	}
	Passenger() {};
	void record_info(int, string,string);
	void record_info(int, string);
	void record_info(string);
	string Customer_Name;//�û�����
	string gender;
	int  Ticket_Number;//��Ʊ��
	int numbers;//��¼��������������
	void display();
	string Cabin_Level;//��λ�ȼ�
protected:
	string  state;
};
	void Passenger::basic__info_input()
	{
		std::cin >> this->Customer_Name >> this->gender;
	}
	void Passenger::record_info(int x, string a,string info)//��Ʊ�ɹ�
	{
		this->Ticket_Number = x;
		this->Cabin_Level = a;
		this->state = info;
	}
	void Passenger::record_info(int x, string info)//��Ʊʧ��
	{
		this->Ticket_Number = x;
		this->Cabin_Level = "��";
		this->state = info;
	}
	void Passenger::record_info(string info)//��Ʊ
	{
		this->Ticket_Number = 0;
		this->Cabin_Level = "��";
		this->state = info;
	}
	void Passenger::display()
	{
		std::cout << Customer_Name << " " << Cabin_Level << " " <<" ��Ʊ��: "<<Ticket_Number << " �Ѷ�Ʊ"<<std::endl;
	}
