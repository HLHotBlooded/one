#pragma once

class cTheAgency
{
public:
	cTheAgency(HINSTANCE hInstance);
	~cTheAgency();
	void PreInit();  //��ʼ��ǰ����
	void AfterInit();  //��ʼ������
	void LoadResource();   //������Դ
private:
	HINSTANCE m_hInstance;
};

