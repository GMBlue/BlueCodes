#define GOSSIP_ITEM_VIP "VIP Menu"
#define GOSSIP_ITEM "Repair"
#define GOSSIP_ITEM_1 "Whisp On/Off"
#define GOSSIP_ITEM_2 "Customize"
#define GOSSIP_ITEM_3 "Faction change"
#define GOSSIP_ITEM_4 "Race change"
#define GOSSIP_ITEM_5 "Rename"
#define GOSSIP_ITEM_6 "Teleports"
#define GOSSIP_ITEM_7 "Character Save"
#define GOSSIP_ITEM_8 "Mailbox"

class npc_vip : public CreatureScript
{
    public:
        npc_vip() : CreatureScript("npc_vip") { }


	bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 /*sender*/, uint32 action )
	{
		pPlayer->PlayerTalkClass->ClearMenus();

		switch(action)
		{

			case 1001:
				pPlayer->DurabilityRepairAll(false, 0, false);
				break;
				
			case 2000:
				if(pPlayer->isAcceptWhispers())
				{
					pPlayer->SetAcceptWhispers(false);
					pCreature->MonsterWhisper("Whispers off!", pPlayer->GetGUID(), false);
				} 

				else 
				{
					pPlayer->SetAcceptWhispers(true);
					pCreature->MonsterWhisper("Whispers on!", pPlayer->GetGUID(), false);
				}
				break;
			case 3000:
				pPlayer->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
				pCreature->MonsterWhisper("Customize Done!", pPlayer->GetGUID(), false);
				break;

			case 4000:
				pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
				pCreature->MonsterWhisper("Faction Change Done!", pPlayer->GetGUID(), false);
				break;

			case 5000:
				pPlayer->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
				pCreature->MonsterWhisper("Race Change Done!", pPlayer->GetGUID(), false);
				break;

			case 9000:
				pPlayer->SetAtLoginFlag(AT_LOGIN_RENAME);
				pCreature->MonsterWhisper("Rename Done!", pPlayer->GetGUID(), false);
				break;

			case 7000:
				pPlayer->CastCustomSpell(pPlayer, 67833, 0, 0, 0, false, 0, 0, 0);
				break;

			case 8000:
				pPlayer->SaveToDB();
				pCreature->MonsterWhisper("Saved!", pPlayer->GetGUID(), false);
				break;

			case 10000:
				pCreature->SummonGameObject(191605, pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(), 0, 0, 0, 0, 0, 100000);
				break;


		}
		return true;
	}

	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{
		if (pPlayer->isAlive())
		{
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, 1001);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, 2000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, 3000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_3, GOSSIP_SENDER_MAIN, 4000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_4, GOSSIP_SENDER_MAIN, 5000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_5, GOSSIP_SENDER_MAIN, 9000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_6, GOSSIP_SENDER_MAIN, 7000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_7, GOSSIP_SENDER_MAIN, 8000);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_8, GOSSIP_SENDER_MAIN, 10000);
			pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
		}
			return true;
	}
};

void AddSC_npc_vip()
{
	new npc_vip();
}