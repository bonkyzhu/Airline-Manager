/*
	飞机订票管理系统(C++程序实验设计)
	朱子权 计算机系170717 学号20178859
	指导老师:李国瑞
	2018年1月12日
*/
#include <string>
#include <fstream>
#include "航班.h"
#include"乘客.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
Passenger customer;
Airline customed_ordered;
Airline plane[16];
int record;
//函数声明
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
	//欢迎界面
	cout << "      ///////////////////////////////////////////////////////////////////////////////////////////////////////\n";
	cout << "      ///--------------------欢迎来到由东北大学秦皇岛计算机与通信工程学院国际大机场-----------------------///\n";
	cout << "      ///-------------------------------软件名称:飞机订票管理系统-----------------------------------------///\n";
	cout << "      ///----------------------------------产品经理:李国瑞老师--------------------------------------------///\n";
	cout << "      ///-------------------------开发人员:计算机系1707班朱子权 代码20178859------------------------------///\n";
	cout << "      ///-------------本系统具有查询航班,承办订票和退票,修改航班信息,智能推荐航班等特色功能---------------///\n";
	cout << "      ///////////////////////////////////////////////////////////////////////////////////////////////////////\n";
	 ifstream infile("输入航班信息.dat"); ofstream  outfile("记录用户信息.dat"); getchar();
	cout << "请输入你的名字和性别:\n";
	customer.basic__info_input();
	system("cls");
	//问候语
	read();
	gotoxy(20, 6);
	cout << "尊敬的" << customer.Customer_Name[0]<< customer.Customer_Name[1];
	if (customer.gender == "男") { cout << "先生"; }
	else { cout << "女士"; }
	cout << "有什么需要我帮助的吗\n";	is_interface();
	 //loading实现
	int t = 2;
	while (t--)
	{
		system("cls");
		gotoxy(35, 10);
		cout << "//////////////////////////////////////////\n";
		gotoxy(35, 11);
		cout << "///                                    ///\n";
		gotoxy(35, 12);
		cout << "///           加载中                   ///\n";
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
	//关闭文件
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
		cout << "///           退出中                   ///\n";
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
//全部函数
void read()
{
	char notation;
	string Initial, Terminal, flight_num;
	int takeoff_time_hour, takeoff_time_minute;
	int landing_time_hour, landing_time_minute;
	string Flight_type;
	int week; int Capacity, price;
	int  First_Class_Ticket, Business_Ticket, economy_Ticket;
	fstream infile("输入航班信息.dat", ios::in);
	for (int i = 0; i <= 15; i++)
	{
		infile >> Initial >> Terminal >> flight_num >> takeoff_time_hour >> notation >> takeoff_time_minute >> landing_time_hour >> notation >> landing_time_minute;
		infile >> Flight_type >> week >> Capacity >> First_Class_Ticket >> Business_Ticket >> economy_Ticket >> price;
		plane[i].change_var(Initial, Terminal, flight_num, Flight_type, week, takeoff_time_minute, takeoff_time_hour, landing_time_minute, landing_time_hour, Capacity, price, First_Class_Ticket, Business_Ticket, economy_Ticket);
	}
}
void gotoxy(int x, int y) {																								   
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
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
				cout << "以为你推荐以下航班\n";
				cout << "推荐" << step << ":\n";				
				plane[i].display(); plane[j].display();
					step++;
			}
			if (plane[i].Terminal == plane[j].Initial&&plane[i].display_week() == plane[j].display_week()&&plane[i].display_time("land")<plane[j].display_time("takeoff"))
			{
				if (step == 1)
					cout << "以为你推荐以下航班\n"; 
				cout << "以为你推荐以下航班\n";
				cout << "推荐" << step << ":\n";
				plane[i].display(); plane[j].display();
				step++;
			}
		}
	}
	char enter;
	cout << "请按回车返回主页面";
	enter = _getch();
	system("cls");
	is_interface();
}

void BookTickets(int num, Airline air)
{
	char enter;
	cout << "请选择你所需要的舱位等级:\n";
	cout << "1.头等舱.\n";
	cout << "2.商务舱\n";
	cout << "3.经济舱\n";
	enter = _getch();
	if(enter=='1'){
		if (plane[record].change(num, "头等舱"))
		{
			customer.record_info(num, "头等舱","已订票"); cout << "订票成功" << endl; customer.display();
		}
		else
		{
			cout << "订票失败\n"; customer.record_info(num, "排队中");
		}
	}
	else if (enter == '2') {
		if (plane[record].change(num, "商务舱"))
		{
			customer.record_info(num, "商务舱", "已订票"); cout << "订票成功" << endl; customer.display();
		}
		else
		{
			cout << "订票失败\n"; customer.record_info(num, "排队中");
		}
	}
	else if (enter == '3') {
		if (plane[record].change(num, "经济舱"))
		{
			customer.record_info(num, "经济舱", "已订票"); cout << "订票成功" << endl; customer.display();
		}
		else
		{
			cout << "订票失败\n"; customer.record_info(num, "排队中");
		}
	}
	cout << "三秒后回到主界面\n";
	Sleep(1000 * 1.5);
	system("cls");
	is_interface();
}
	void Airline_Query()
	{
		system("cls");
		cout << "输入你所需要查询的城市" << endl;
		string final;
		cin >> final;
		for (int i = 0; i <= 15; i++)
		{
			if (plane[i].Initial == "秦皇岛"&&plane[i].Terminal == final)
			{
				cout << "帮你找到如下航班\n";
				cout << "起点	终点	航班号	起飞时间 降落时间 机型	起飞日期 容量	头等舱	商务舱	经济舱	价格\n";
				plane[i].display();
				record = i;
				cout << "是否选择购买机票[Y / N]\n";
				char inputs;
				cin >> inputs;
				if (inputs == 'Y')
				{
					int num;
					cout << "输入你所需要的票数:\n";
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
				cout << "没有所找航班" << endl;
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
		cout << "是否确认选择退票?[ Y/N]\n";
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
				cout << "///           退票中                  ///\n";
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
			customer.record_info("已退票");
			cout << "退票成功!"; cout << "三秒后回到主界面\n";
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
		//所有变量
		string start, end; int i;
		char notation;
		string Initial, Terminal, flight_num;
		int takeoff_time_hour, takeoff_time_minute;
		int landing_time_hour, landing_time_minute;
		string Flight_type;
		int week; int Capacity, price;
		int  First_Class_Ticket, Business_Ticket, economy_Ticket;
		gotoxy(35, 14);
		cout << "你需要修改的航班起始点\n";
		cin >> start;
		cout << "接着你需要修改的航班终点\n";
		cin >> end;
		for (i=0;i<=15;i++)
		{
			if (start==plane[i].Initial&&end==plane[i].Terminal)
			{
				break;
			}
		}
		cout << "按照格式修改航班(星期用数字表示)\n";
		plane[i].display();
		cin >> Initial >> Terminal >> flight_num >> takeoff_time_hour >> notation >> takeoff_time_minute >> landing_time_hour >> notation >> landing_time_minute;
		cin >> Flight_type >> week >> Capacity >> First_Class_Ticket >> Business_Ticket >> economy_Ticket >> price;
		plane[i].change_var(Initial, Terminal, flight_num, Flight_type, week, takeoff_time_minute, takeoff_time_hour, landing_time_minute, landing_time_hour, Capacity, price, First_Class_Ticket, Business_Ticket, economy_Ticket);
		cout << "以下是修改后的结果\n";
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
			cout << "              退出中                                \n";
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
		//功能选择界面
		gotoxy(20, 8);
		cout << "////////////////////////////////////\n";
		gotoxy(20, 9);
		cout << "////// 1.查询航线并订阅机票   //////\n";
		gotoxy(20, 10);
		cout << "////// 2.退票服务	          //////\n";
		gotoxy(20, 11);
		cout << "////// 3.修改航班信息         //////\n";
		gotoxy(20, 12);
		cout << "////// 4.退出系统	          //////\n";
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
