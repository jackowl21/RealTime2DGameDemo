#pragma once

#include <LoadBalancing-cpp/inc/Client.h>
#include "Application.h"

class MyPhoton : private ExitGames::LoadBalancing::Listener
{

public:
	MyPhoton();
	void run(void);
	void connect(void);
	//void opCreateRoom(void);
	//void opJoinRandomRoom(void);
	//void opJoinOrCreateRoom(void);
	void disconnect(void);

	static MyPhoton& getInstance()
	{
		static MyPhoton instance;
		return instance;
	}


	void sendMyData(float xpos, float ypos, float xvel, float yvel, float xaccel, float yaccel, float angle, float bulletX, float bulletY);
	void sendMyData2(float xpos, float ypos, float xvel, float yvel, float xaccel, float yaccel, float angle, 
		float mXpos, float mYpos, float mXvel, float mYvel, float mXaccel, float mYaccel, float mAngle,
		int opponentHealth, int fireMode,
		int bulletNum,std::list<Bullet*> bulletList);

private:
	// receive and print out debug out here
	virtual void debugReturn(int debugLevel, const ExitGames::Common::JString& string);

	// implement your error-handling here
	virtual void connectionErrorReturn(int errorCode);
	virtual void clientErrorReturn(int errorCode);
	virtual void warningReturn(int warningCode);
	virtual void serverErrorReturn(int errorCode);

	// events, triggered by certain operations of all players in the same room
	virtual void joinRoomEventAction(int playerNr, const ExitGames::Common::JVector<int>& playernrs, const ExitGames::LoadBalancing::Player& player);
	virtual void leaveRoomEventAction(int playerNr, bool isInactive);
	virtual void customEventAction(int playerNr, nByte eventCode, const ExitGames::Common::Object& eventContent);

	virtual void onLobbyStatsResponse(const ExitGames::Common::JVector<ExitGames::LoadBalancing::LobbyStatsResponse>& lobbyStats);
	virtual void onLobbyStatsUpdate(const ExitGames::Common::JVector<ExitGames::LoadBalancing::LobbyStatsResponse>& lobbyStats);
	virtual void onAvailableRegions(const ExitGames::Common::JVector<ExitGames::Common::JString>& availableRegions, const ExitGames::Common::JVector<ExitGames::Common::JString>& availableRegionServers);

	// callbacks for operations on PhotonLoadBalancing server
	virtual void connectReturn(int errorCode, const ExitGames::Common::JString& errorString, const ExitGames::Common::JString& cluster);
	virtual void disconnectReturn(void);
	virtual void createRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
	virtual void joinOrCreateRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
	virtual void joinRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
	virtual void joinRandomRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
	virtual void leaveRoomReturn(int errorCode, const ExitGames::Common::JString& errorString);
	virtual void joinLobbyReturn(void);
	virtual void leaveLobbyReturn(void);

	ExitGames::LoadBalancing::Client mLoadBalancingClient;


};