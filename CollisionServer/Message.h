#pragma once

enum Msg_Type
{
	Msg_Init,
	Msg_AddFood,
	Msg_UpdateInfo,
	Msg_UpdatePhysical,
	Msg_EatFood,
	Msg_AllotTag,
	Msg_AddPlayer,
	Msg_DeletePlayer,
	Msg_PlayMove,
	Msg_CreateBackHole,
	Msg_DeleteBackHole,
};

struct NetMsg
{
	Msg_Type Type;   //��Ϣ����
	POINT pt;
	DWORD id;    //���ֱ��
	DWORD id1;  //���ֱ��1
	unsigned int v[4];
};

struct Client
{
	DWORD id;
	POINT pt;
	UINT color;
	UINT radius;
	UINT physical;
	int vx;   
	int vy;
};

struct BackHole
{
	unsigned int lifecycle;   //�ڶ�����������
	POINT pt;      //�ڶ�λ��
	int power;
	int controlRadius;
};

struct _Food
{
	DWORD id;   //ʳ��id
	POINT pt;
	UINT color;
};