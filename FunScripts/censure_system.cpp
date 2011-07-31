// Írd be a káromkodásokat mielõtt forgatsz!
#define Karomkodas1 ""
#define Karomkodas2 ""
#define Karomkodas3 ""
#define Karomkodas4 ""
#define Karomkodas5 ""
#define Karomkodas6 ""
#define Karomkodas7 ""
#define Karomkodas8 ""
#define Karomkodas9 ""
#define Karomkodas10 ""
#define Karomkodas11 ""
#define Karomkodas12 ""
#define Karomkodas13 ""
#define Karomkodas14 ""
#define Karomkodas15 ""
#define Karomkodas16 ""
#define Karomkodas17 ""
#define Karomkodas18 ""
#define Karomkodas19 ""
#define Karomkodas20 ""
class System_Censure : public PlayerScript
{
    public:
        System_Censure() : PlayerScript("System_Censure") {}

void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg)
{
		if (msg == Karomkodas1 || msg == Karomkodas2 || msg == Karomkodas3 || msg == Karomkodas4 || msg == Karomkodas5 || msg == Karomkodas6 || msg == Karomkodas7 || msg == Karomkodas8 || msg == Karomkodas9 || msg == Karomkodas10 || msg == Karomkodas11 || msg == Karomkodas12 || msg == Karomkodas13 || msg == Karomkodas14 || msg == Karomkodas15 || msg == Karomkodas16 || msg == Karomkodas17 || msg == Karomkodas18 || msg == Karomkodas19 || msg == Karomkodas20)
		msg = "****";
}

	void OnChat(Player *player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Player *receiver)
	{
		if (msg == Karomkodas1 || msg == Karomkodas2 || msg == Karomkodas3 || msg == Karomkodas4 || msg == Karomkodas5 || msg == Karomkodas6 || msg == Karomkodas7 || msg == Karomkodas8 || msg == Karomkodas9 || msg == Karomkodas10 || msg == Karomkodas11 || msg == Karomkodas12 || msg == Karomkodas13 || msg == Karomkodas14 || msg == Karomkodas15 || msg == Karomkodas16 || msg == Karomkodas17 || msg == Karomkodas18 || msg == Karomkodas19 || msg == Karomkodas20)
		msg = "****";
	}

	void OnChat(Player *player, uint32 type, uint32 /*lang*/, std::string& msg, Group *group)
	{
		if (msg == Karomkodas1 || msg == Karomkodas2 || msg == Karomkodas3 || msg == Karomkodas4 || msg == Karomkodas5 || msg == Karomkodas6 || msg == Karomkodas7 || msg == Karomkodas8 || msg == Karomkodas9 || msg == Karomkodas10 || msg == Karomkodas11 || msg == Karomkodas12 || msg == Karomkodas13 || msg == Karomkodas14 || msg == Karomkodas15 || msg == Karomkodas16 || msg == Karomkodas17 || msg == Karomkodas18 || msg == Karomkodas19 || msg == Karomkodas20)
		msg = "****";
	}


	void OnChat(Player *player, uint32 type, uint32 lang, std::string& msg, Guild *guild)
	{
		if (msg == Karomkodas1 || msg == Karomkodas2 || msg == Karomkodas3 || msg == Karomkodas4 || msg == Karomkodas5 || msg == Karomkodas6 || msg == Karomkodas7 || msg == Karomkodas8 || msg == Karomkodas9 || msg == Karomkodas10 || msg == Karomkodas11 || msg == Karomkodas12 || msg == Karomkodas13 || msg == Karomkodas14 || msg == Karomkodas15 || msg == Karomkodas16 || msg == Karomkodas17 || msg == Karomkodas18 || msg == Karomkodas19 || msg == Karomkodas20)
		msg = "****";
	}

	void OnChat(Player *player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Channel *channel)
	{
		if (msg == Karomkodas1 || msg == Karomkodas2 || msg == Karomkodas3 || msg == Karomkodas4 || msg == Karomkodas5 || msg == Karomkodas6 || msg == Karomkodas7 || msg == Karomkodas8 || msg == Karomkodas9 || msg == Karomkodas10 || msg == Karomkodas11 || msg == Karomkodas12 || msg == Karomkodas13 || msg == Karomkodas14 || msg == Karomkodas15 || msg == Karomkodas16 || msg == Karomkodas17 || msg == Karomkodas18 || msg == Karomkodas19 || msg == Karomkodas20)
		msg = "****";
		
	}
};
void AddSC_System_Censure()
{
	new System_Censure();
}