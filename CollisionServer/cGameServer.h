#pragma once
#include<TCPServer.h>
#include<list>
#include<vector>
#include<string>
#include"Message.h"
#include"cMyTimer.h"

class cGameServer :public Net::CTCPServer,public cMyTimer
{
public:
	cGameServer();
	virtual  ~cGameServer();

	/*
	*OnRecv(SOCKET sock, const char* buff)
	*�յ��ͻ�����Ϣ�Ļص�����
	*@Param sock����Ϣ��Դsock
	*@Param buff����Ϣ����
	*/
	virtual void OnRecv(SOCKET sock, const char* buff) override;

	/*
	*RemoveClient(DWORD id);
	*�Ƴ�ָ��id�Ŀͻ���
	*@Param id���ͻ���id
	*/
	void RemoveClient(DWORD id);

	/*
    *updateClientInfo(DWORD id, NetMsg msg);
	*����ָ��id�Ŀͻ�����Ϣ
	*@Param id���ͻ���id
	*@Param msg�����������յ���Ϣ
	*/
	void updateClientInfo(DWORD id, NetMsg msg);
	
	/*
	*OnTimer(int id, int iParam, string str) 
	*��ʱ���ص�����
	*/
	int OnTimer(int id, int iParam, string str) override;

	void CreateBackHole();

	void BackHoleStorm();

	void SendAllotTagMsg(DWORD id);

	void SendAddPlayMsg(DWORD id,NetMsg msg);

	void SendPlayMoveMsg(DWORD id,NetMsg msg);

	void SendInitMsg(DWORD id);

	void CreateFood();

	void EatedFood(DWORD who,NetMsg msg);

	void UpdateInfoMsg(DWORD who,NetMsg msg);

	void DeletePlayerMsg(NetMsg msg);
private:
	std::list<Client> m_clientList;  //����ͻ�����Ϣ�б�
	std::list<BackHole> m_backHoleList;
	std::list<_Food> m_foodList;
	int m_onlineNums = 0;
};
