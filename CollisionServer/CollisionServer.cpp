// CollisionServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include"cGameServer.h"
#include<string>
using namespace std;

int main()
{
	cGameServer* pServer = new cGameServer;
	if (pServer->StartServer(NULL, NULL, 6036, Net::MODE_IOCP) == true)
	{
		cout << "�����������ɹ�!" << endl;
	}
	
	string input;
	while (true)
	{
		cin >> input;
		if (input == "exit")
		{
			break;
		}
	}
	delete pServer;
    return 0;
}

