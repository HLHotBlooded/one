#pragma once
#include<WinSock2.h>
#include<thread>
#include<string>
#include<list>
#include"public.h"
#include"Lock.h"

namespace Net
{
	class CUDPServer;
	typedef void(*USeverFunc)(sockaddr_in sai, char* buff, CUDPServer* pSever, LPVOID Param);
	struct UServerST
	{
		USeverFunc func;
		LPVOID Param;
	};

	//������ģ��ö��
	enum USERVER_MODE
	{
		UMODE_ORDINARY,
		UMODE_IOCP,
	};

	class CUDPServer
	{
	public:
		CUDPServer();
		CUDPServer(const CUDPServer& src) = delete;
		CUDPServer& operator=(const CUDPServer& src) = delete;
		virtual ~CUDPServer();

		/*
		*StartServer();
		*����������
		*@Param proc���������ص�����
		*@Param param���û��Զ��壬�ص�����
		*@Param mode��ָ��������ģ��
		*@Param port���������˿�
		*@return bool��true�����ɹ���false����ʧ��
		*/
		bool StartServer(USeverFunc proc,LPVOID Param=NULL,USERVER_MODE mode = UMODE_ORDINARY, unsigned long port = PORT);

		/*
		*GetLastError();
		*��ȡ��һ�εĴ�������
		*@return string��������ϸ����
		*/
		const std::string& GetLastError();

		/*
		*GetMode();
		*��ȡ������ģ��
		*@return USERVER_MODE��������ģ�ͱ�ʶ
		*/
		const USERVER_MODE& GetMode();

		/*
		*GetHostIP()
		*��ȡ����������Ip
		*/
		std::list<std::string> GetHostIPs();

		/*
		*SendMsg(sockaddr_in dest, char* buff, unsigned int len);
		*������Ϣ��ָ���ͻ���
		*@Param dest��Ŀ��ͻ��˵�ַ
		*@Param buff����Ϣ����
		*@Param len����Ϣ����
		*/
		bool SendMsg(sockaddr_in dest, char* buff, unsigned int len);

		/*
		*SendMsgAll(char*buff, unsigned int len);
		*������Ϣ�����пͻ���
		*@Param buff����Ϣ����
		*@len����Ϣ����
		*/
		bool SendMsgAll(char*buff, unsigned int len);

		/*
		*CloseServer();
		*�رշ�����������������Դ
		*/
		void CloseServer();

		/*
		*OnRecv();
		*�յ��ͻ�����Ϣ�Ļص�����
		*@Param buff����Ϣ����
		*/
		virtual void OnRecv(sockaddr_in sai, char* buff);
	private:
		/*
		*InitOridinaryServer(unsigned long port);
		*��ʼ����ͨģ�ͷ�����
		*@Param port���������˿�
		*@return bool��true��ʼ���ɹ���false��ʼ��ʧ��
		*/
		bool InitOridinaryServer(unsigned long port);

		/*
		*InitIOCPServer(unsigned long port);
		*��ʼ����ɶ˿�ģ�ͷ�����
		*@Param port���������˿�
		*@return bool��true��ʼ���ɹ���false��ʼ��ʧ��
		*/
		bool InitIOCPServer(unsigned long port);

		/*
		*DoOridinaryMsg();
		*������ͨģʽ�µĿͻ�����Ϣ
		*/
		void DoOridinaryMsg();

		/*
		*DoIOCPMsg();
		*������ɶ˿�ģʽ�µĿͻ�����Ϣ
		*/
		void DoIOCPMsg();

		/*
		*isHave(sockaddr_in sai);
		*ĳһ�ͻ����Ƿ����
		*@return bool��true���ڣ�false������
		*/
		bool isHave(sockaddr_in sai);

		/*
		*RemoveClientAddr(sockaddr_in sai);
		*�Ƴ�ָ���ͻ���
		*@Param sai��ָ���Ŀͻ��˵�ַ
		@return bool��true�ɹ���falseʧ��
		*/
		bool RemoveClientAddr(sockaddr_in sai);

		/*
		*SendCloseMsg();
		*���ͷ������ر���Ϣ
		*/
		void SendCloseMsg();

		SOCKET m_sockServer;

		std::string m_error;

		USERVER_MODE m_mode;

		std::list<std::thread> m_threadList;

		std::list<sockaddr_in> m_clientaddrList;

		std::list<OVP_IO_UDATA*> m_dataList;

		UServerST m_serverProc;

		HANDLE m_hCompletionPort;

		CLock m_lock;

		bool m_isClose;
	};
}