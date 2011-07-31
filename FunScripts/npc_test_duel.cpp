#define GOSSIP_ITEM "Duel!"


// Define before compile
#define SPELL_1 12345
#define SPELL_2 12345
#define SPELL_3 12345
// Timerz
#define SPELL_ONE_TIMER 1
#define SPELL_TWO_TIMER 2
#define SPELL_THREE_TIMER 3

class npc_duel : public CreatureScript
{
public:
    npc_duel() : CreatureScript("npc_duel") { }


    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_duelAI(creature);
    }

	bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 /*sender*/, uint32 action)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        switch (action)
        {
		
            case GOSSIP_ACTION_INFO_DEF:
				pCreature->setFaction(14);
				pCreature->MonsterWhisper("Duel Starting!", pPlayer->GetGUID(), true);
				break;
		}
	return true;
	}

	bool OnGossipHello(Player *pPlayer, Creature *pCreature)
	{
		if (pPlayer->isAlive())
		{
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
			pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());
		}
		return true;
	}

	struct npc_duelAI : public ScriptedAI
    {
        npc_duelAI(Creature* c) : ScriptedAI(c)
        {
			c->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        }
		uint32 Spell1Timer;
		uint32 Spell2Timer;
		uint32 Spell3Timer;

	void Reset()
	{
		Spell1Timer = SPELL_ONE_TIMER;
		Spell2Timer = SPELL_TWO_TIMER;
		Spell3Timer = SPELL_THREE_TIMER;
	}

	void UpdateAI(const uint32 diff)
	{
		if(!UpdateVictim())
			return;

		if(HealthBelowPct(3))
		{
			me->setFaction(35);
			me->CombatStop(true);
			me->SetHealth(me->GetMaxHealth());
			me->AttackStop();
		}

		if (Spell1Timer <= diff)
		{
			DoCast(SPELL_1);
			Spell1Timer = SPELL_ONE_TIMER;
		} else Spell1Timer -= diff;

		if (Spell2Timer <= diff)
		{
			DoCast(SPELL_2);
			Spell2Timer = SPELL_TWO_TIMER;
		} else Spell2Timer -= diff;

		if (Spell3Timer <= diff)
		{
			DoCast(SPELL_3);
			Spell3Timer = SPELL_THREE_TIMER;
		} else Spell3Timer -= diff;
	}
};
};

void AddSC_npc_duel()
{
	new npc_duel();
}