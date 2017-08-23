#pragma once
#include<WinSock2.h>
#include"public.h"
#include<string>
#include<thread>

namespace Net
{
	class CUDPClient;
	typedef void(*UClientFunc)(char* buff,CUDPClient* pClient,LPVOID Param);
	typedef struct UClientSt
	{
		UClientFunc func;
		LPVOID Param;
	};

	class CUDPClient
	{
	public:
		CUDPClient();
		explicit CUDPClient(UClientFunc proc, LPVOID Param=NULL);
		CUDPClient(const CUDPClient& src) = delete;
		CUDPClient& operator=(const CUDPClient& src) = delete;
		virtual ~CUDPClient();

		/*
		*GetLastError();
		*��ȡ��һ�δ�������
		*@return string����������
		*/
		const std::string& GetLastError();

		/*
		*BindServer(const std::string& serverIp,unsigned long port=PORT);
		*���ӷ�����
		*@Param serverIp��������ip
		*@Param PORT���������˿�
		*/
		bool ConnectServer(const std::string& serverIp,unsigned long port=PORT);

		/*
		*SendMsg(char* buff, unsigned int len);
		*������Ϣ�������
		*@Param buff����Ϣ����
		*@Param len����Ϣ����
		*/
		bool SendMsg(char* buff, unsigned int len);

		/*
		*CloseClient();
		*�رտͻ��˲�������Դ
		*/
		void CloseClient();

		/*
		*OnRecv(char* buff);
		*�յ���������Ϣ�Ļص�����
		*@Param buff����Ϣ����
		*/
		virtual void OnRecv(char* buff);
	private:
		/*
		*DoServerMsg();
		*�������˷�������Ϣ
		*/
		void DoRecvMsg();

		/*
		*SendCloseMsg();
		*���Ϳͻ���������Ϣ��������
		*/
		void SendCloseMsg();

		/*
		*SendConnectMsg();
		*����������Ϣ��������
		*/
		bool SendConnectMsg();

		sockaddr_in m_serverAddr;
		SOCKET m_skClient;
		UClientSt m_cientProc;
		std::string m_error;
		std::thread* m_pRecvThread;
		bool m_isClose;
	};
}