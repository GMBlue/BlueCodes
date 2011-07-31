/*
* Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/


#include "ScriptPCH.h"
#include "culling_of_stratholme.h"


enum Spells
{
    SPELL_CORRUPTING_BLIGHT                     = 60588,
    SPELL_VOID_STRIKE                           = 60590
};


enum Yells
{
    SAY_AGGRO                                   = -1595045,
    SAY_FAIL                                    = -1595046,
    SAY_DEATH                                   = -1595047
};

class boss_infinite : public CreatureScript
{
	public:
		boss_infinite() : CreatureScript ("boss_infinite") {}
                
        CreatureAI* GetAI(Creature* pCreature) const
        {
			return new boss_infiniteAI (pCreature);
        }
        struct boss_infiniteAI : public ScriptedAI
        {
			boss_infiniteAI (Creature *c) : ScriptedAI (c) {}


    InstanceScript* pInstance;
    uint32 uiCorruptingBlight;
    uint32 uiVoidStrike;


    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_INFINITE_EVENT, NOT_STARTED);


        uiCorruptingBlight = 7000;
        uiVoidStrike = 5000;
    }


    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_INFINITE_EVENT, IN_PROGRESS);
		DoScriptText(SAY_AGGRO, me);
    }
	
	void KilledUnit(Unit * /*killed*/)
	{
		DoScriptText(SAY_FAIL, me);
	}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;


        if (uiCorruptingBlight <= diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM,0))
                DoCast(pTarget, SPELL_CORRUPTING_BLIGHT);
            uiCorruptingBlight = 17000;
        } else uiCorruptingBlight -= diff;


        if (uiVoidStrike <= diff)
        {
            DoCast(me->getVictim(), SPELL_VOID_STRIKE);
            uiVoidStrike = 5000;
        } else uiVoidStrike -= diff;


        DoMeleeAttackIfReady();
    }


    void JustDied(Unit* killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_INFINITE_EVENT, DONE);
		DoScriptText(SAY_DEATH, me);
    }
};
};