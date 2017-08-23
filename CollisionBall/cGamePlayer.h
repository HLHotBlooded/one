#pragma once
#include<cSight.h>
#include<cCircle.h>
#include<cText.h>
#include<cRectangle.h>
#include<string>
#define Basic_Speed 5
#define OneExp 10
#define OneFExp 0.3f
#define Basic_Exp 20
#define Basic_Volume 310.0f
#define Basic_Radius 15
#define MAX_RADIUS 250.0f
#define MAX_PHYSICAL 100.0f
#define ONE_PHYSICAL 1.2

class cGamePlayer :
	public MyEngine::cSight
{
public:
	cGamePlayer();
	~cGamePlayer();

	/*
	SetX(const int& x);
	����ui�ؼ�x����
	@Param ��
	int x���µ�x����
	*/
	virtual void SetX(const int& x) override;

	/*
	GetX()
	��ȡui�ؼ�x����
	@return const int&:
	ui�ؼ���ǰx����
	*/
	virtual const int& GetX() const override;

	/*
	SetY(const int& y)
	����ui�ؼ�y����
	@Param ��
	int y:�µ�y����
	*/
	virtual void SetY(const int& y) override; 

	/*
	GetY()
	��ȡui�ؼ���ǰy����
	@return int��
	��ǰy����
	*/
	virtual const int& GetY() const override;

	void DecRadius();  //���ٰ뾶
	void SetRadius(const int& radius);

	/*
	*CalcScreenSite();
	*��������������������Ļ����
	*/
	void CalcScreenSite();

	/*
	*Move();
	*�ƶ���ɫ
	*@return bool��true��λ�÷������ƶ���falseû�з����ƶ�
	*/
	bool Move();

	void SetVx(const int& vx);
	const int& GetVx();
	void SetVy(const int& vy);
	const int& GetVy();

	void SetWorldX(const int& x);
	void SetWorldY(const int& y);
	const int& GetWorldX();
	const int& GetWorldY();

	void AddExp(int value);
	void SetExp(int value);
	const int& GetExp();

	const int& GetBasicSpeed();

	const void SetPhysicalValue(const int& value);
	const int& GetPhysicalValue();
	 
	MyEngine::cCircle* GetBody();

	void AccPhysical(int f=1);  //��������ֵ

	void DecPhysical(); //��������ֵ

	void Accelerate();  //����

	void Decelerate();  //����

	void SetbDel(bool b);

	bool GetbDel();
private:
	int m_vx;  //x�᷽���ϵ��ٶ�
	int m_vy;   //y�᷽���ϵ��ٶ�
	int m_worldx;   //��������ϵ�ϵ�x����
	int m_worldy;   //��������ϵ�ϵ�y����
	int m_exp ;  //����ֵ
	float m_fexp;
	int m_basicSpeed;
	int m_physicalValue; //����ֵ
	MyEngine::cCircle* m_body;
	MyEngine::cRectangle* m_physicalBar;
	bool m_bDel;
public:
	int m_tag = 0;    //��ǩ
};

