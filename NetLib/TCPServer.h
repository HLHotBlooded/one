#pragma once
#include<WinSock2.h>
#include<thread>
#include<string>
#include<list>
#include"public.h"
#include"Lock.h"
#include<memory>

namespace Net
{
	//������ģ��ö��
	enum SERVER_MODE
	{
		MODE_SELECT,
		MODE_IOCP,
	};

	class CTCPServer;
	typedef void(*ServerFunc)(SOCKET sock, const char* buff,CTCPServer* pServer,LPVOID Param);
	//����������ص��������û��Զ�������ṹ��
	typedef struct  ServerST
	{
		ServerFunc func;
		LPVOID Param;
	};

	class CTCPServer
	{
	public:
	 	CTCPServer();

		//ɾ�����ڹ��캯��
		CTCPServer(const CTCPServer& src) = delete;

		//ɾ�����������
		CTCPServer& operator=(const CTCPServer& src) = delete;
		
		virtual ~CTCPServer();

		/*
		*StartServer(ServerFunc ServerProc, LPVOID Param = NULL, unsigned long port = PORT, SERVER_MODE mode = MODE_SELECT);
		*����������
		*@Param ServerProc:ָ���������߼�����ص�����
		*@Param param���û��Զ������
		*@Param port:�������˿�
		*@Param mode��ָ��������ģ��
		*@return bool:true�����������ɹ���false����ʧ��
		*/
		bool StartServer(ServerFunc ServerProc, LPVOID Param = NULL, unsigned long port = PORT, SERVER_MODE mode = MODE_SELECT);

		/*
		*GetLastError();
		*��ȡ��һ�δ���
		*@return string����������
		*/
		const std::string& GetLastError();

		/*
		*SendMsg(SOCKET dest, const char* buff, unsigned int len);
		*������Ϣ��ָ���Ŀͻ���
		*@Param dest����ϢĿ�Ķ�
		*@Param buff����Ϣ����
		*@Param len����Ϣ����
		*@return bool��true���ͳɹ���false����ʧ��
		*/
		bool SendMsg(SOCKET dest, const char* buff, unsigned int len);

		/*
		*SendMsgAll(const char* buff,unsigned int len);
		*������Ϣ�����������ӵĿͻ���
		*@Param buff����Ϣ����
		*@Param len����Ϣ����
		*@return bool��true���ͳɹ���false����ʧ��
		*/
		bool SendMsgAll(const char* buff,unsigned int len);

		/*
		*GetHostIP()
		*��ȡ����������Ip
		*/
		std::list<std::string> GetHostIPs();

		/*
		*GetMode();
		*��ȡ������ģ��
		*/
		const SERVER_MODE& GetMode();

		/*
		*CloseServer();
		*�رշ�������������Դ
		*/
		void CloseServer();

		/*
		*OnRecv(SOCKET sock, const char* buff)
		*�յ��ͻ�����Ϣ�Ļص�����
		*@Param sock����Ϣ��Դsock
		*@Param buff����Ϣ����
		*@Param len����Ϣ����
		*/
		virtual void OnRecv(SOCKET sock, const char* buff);
	private:
		/*
		*acceptClientProc();
		*���ܿͻ������ӻص�����
		*/
		void acceptClientProc();

		/*
		*StartWorkThread();
		*���������߳�
		*@return bool��true�����ɹ���false����ʧ��
		*/
		bool StartWorkThread();

		/*
		*DoModeSelectMsg();
		*����ѡ��ģ���µĿͻ�����Ϣ
		*/
		void DoModeSelectMsg();

		/*
		*DoIOCPMsg();
		*������ɶ˿��µĿͻ�����Ϣ
		*/
		void DoIOCPMsg();

		//������׽���
		SOCKET m_skServer;

		//��¼��һ�δ������
		std::string m_Error;
		
		//���ܿͻ��������߳�
		std::list<std::thread*> m_ThredList;

		//ָ��������ģ��
		SERVER_MODE m_Mode;

		//����ͻ���socket
		std::list<SOCKET> m_clientList;

		ServerST m_serverProc;

		CLock m_lock;

		HANDLE m_hCompletionPort;

		std::list<OVP_IO_DATA*> m_listData;

		bool m_isClose;
	};
}