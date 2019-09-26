//#include "航班.h"
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
	string Customer_Name;//用户名字
	string gender;
	int  Ticket_Number;//订票量
	int numbers;//记录航班类数组项数
	void display();
	string Cabin_Level;//舱位等级
protected:
	string  state;
};
	void Passenger::basic__info_input()
	{
		std::cin >> this->Customer_Name >> this->gender;
	}
	void Passenger::record_info(int x, string a,string info)//订票成功
	{
		this->Ticket_Number = x;
		this->Cabin_Level = a;
		this->state = info;
	}
	void Passenger::record_info(int x, string info)//订票失败
	{
		this->Ticket_Number = x;
		this->Cabin_Level = "无";
		this->state = info;
	}
	void Passenger::record_info(string info)//退票
	{
		this->Ticket_Number = 0;
		this->Cabin_Level = "无";
		this->state = info;
	}
	void Passenger::display()
	{
		std::cout << Customer_Name << " " << Cabin_Level << " " <<" 订票量: "<<Ticket_Number << " 已订票"<<std::endl;
	}
