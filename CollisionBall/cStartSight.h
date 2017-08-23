#pragma once
#include<cSight.h>
#include<cPicture.h>
#include<cButton.h>
#include<cText.h>
#include<cCircle.h>

class cStartSight:public MyEngine::cSight
{
public:
	cStartSight();
	virtual ~cStartSight();

	/*
	*������Ϸ��ť�ص�����
	*/
	void OnEntryGame(void* Param);

	/*
	*�˳���Ϸ��ť�ص�����
	*/
	void OnQuit(void* Param);

	/*
	*��д��ʱ���ص�����
	*/
	virtual int OnTimer(int id, int iParam, string str) override;

	/*
	*MoveCircle();
	*�ƶ�Բ
	*/
	void MoveCircle();
private:
	MyEngine::cPicture* m_Bg;
	MyEngine::cButton* m_EntryBtn;
	MyEngine::cButton* m_QuitBtn;
	MyEngine::cText* m_Title;
	MyEngine::cCircle* m_circle;
	MyEngine::cCircle* m_circle1;
};

