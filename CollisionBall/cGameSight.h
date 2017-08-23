#pragma once
#include<cSight.h>
#include<cPicture.h>
#include<cButton.h>
#include<cCircle.h>
#include<cText.h>
#include<TCPClient.h>
#include"cGamePlayer.h"
#include"cFood.h"
#include"cBackHole.h"
#include<vector>
#include<list>

struct NetMsg;

class cGameSight:public MyEngine::cSight,public Net::CTCPClient
{
public:
	cGameSight();
	virtual ~cGameSight();

	/*
	*OnRecv(char* buff);
	*�յ���������Ϣ�Ļص�����
	*@Param buff:��Ϣ����
	*/
	virtual void OnRecv(char* buff);

	/*
	*OnGoBack(void* Param);
	*���˰�ť�ص�����
	*/
	void OnGoBack(void* Param);

	/*
	*int OnTimer(int id, int iParam, string str)
	*��ʱ���ص�����
	*/
	virtual int OnTimer(int id, int iParam, string str) override;
	
	/*
	*initMap();
	*��ʼ����ͼ
	*/
	void initMap();

	/*
	*MovePlayer();
	*�ƶ����
	*/
	void MovePlayer();

	//���̰���
	void OnKeyDown(void *Param);
	//���̵���
	void OnKeyUp(void* Param);

	/*
	*CalcMiniPlayerSite();
	*����С��ͼ�����λ��
	*/
	void CalcMiniPlayerSite();

	/*
	*initSight();
	*��ʼ��������Ұ�ϵ�����
	*/
	void initSight();

	void SendInitMsg();

	void SendPlayMoveMsg();

	void AddPlayer(NetMsg msg);

	void OtherPlayMoveMsg(NetMsg msg);

	void MoveOtherPlayers();

	void CalcFoodScreenPos();

	void AddFood(NetMsg msg);

	//��д���ƺ���
	virtual bool Draw(HDC hDc) override;

	void CheckCollisionFood();

	void SendEatFoodMsg(DWORD id);

	void EatedFood(NetMsg msg);

	void SendUpdateInfoMsg();

	void UpdateInfoMsg(NetMsg msg);

	void CheckCollisionOtherPlayers();

	/*
	*DoCollision(cGamePlayer* pPlayer);
	*�����Լ����������֮����ײ�¼�
	*@Param pPlayer���������
	*@return int��������߶�û�·���0������Լ���������-1���з������Ż�1
	*/
	int DoCollision(cGamePlayer* pPlayer);

	void CheckDeleteOtherPlayers();

	void SendDeletePlayerMsg(DWORD id);

	void DeletePlayerMsg(NetMsg msg);

	void AddBackHole(NetMsg msg);

	void CalcBackHoleScreenPos();

	void CheckAttractByBackHole();

	//void initLeaderList();

	//void UpdateLeadList();  //�������а�
private:
	MyEngine::cPicture* m_Map[MAP_ROW][MAP_RANK]; 
	MyEngine::cButton* m_goBack;
	MyEngine::cButton* m_miniMap;
	MyEngine::cCircle* m_miniPlayer;
	cGamePlayer* m_player;
	std::list<cGamePlayer*> m_otherPlayers;
	std::list<MyEngine::cCircle*> m_otherminiPlayers;
	std::list<cFood*> m_foodList;
	std::list<MyEngine::cCircle*> m_miniFoods;
	std::list<cBackHole*> m_backholeList;
	POINT m_miniMapOrigin;  //С��ͼԭ��
	bool m_KeyIsDown[2] = { false,false };
	//MyEngine::cText* m_leaderboard;  //��ʾ���а�
	//vector<MyEngine::cText*> m_leaderList;  //���а��б�
};