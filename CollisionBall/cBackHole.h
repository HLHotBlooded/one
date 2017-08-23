#pragma once
#include<cAmination.h>
#define Hole_Radius 45

class cBackHole:public MyEngine::cAmination
{
public:
	cBackHole();
	~cBackHole();

	void SetWorldPos(const POINT& pt);  
	POINT GetWorldPos();

	void DecLifeCycle();  //������������
	void SetLifeCycle(int cycle);
	int GetLifeCycle();

	void SetControlRadius(int controlradius);
	int GetControlRadius();

	void SetPower(int power);
	int GetPower();

	POINT GetCenter();  //��ȡ��Ļ�������ĵ�
private:
	POINT m_worldPos;
	int m_lifecycle;  //��������
	int m_controlRadius; //Ӱ��뾶
	int m_power;
};