/*
Author: Chase(http://wowemuf.org)
*/
class System_Xpforpvp : public PlayerScript
{
    public:
        System_Xpforpvp() : PlayerScript("System_Xpforpvp") {}

	void OnPVPKill(Player* killer, Player* killed)
	{
		uint32 killerlvl = killer->getLevel();
		uint32 killedlvl = killed->getLevel();
		int32 diff = killerlvl-killedlvl;
		uint32 XPLow = (killedlvl*5+45)*(1+0.05*diff);
		uint32 XPHigh = (killedlvl*5+45)*(1+0.05*diff);
		uint32 minusgold = killer->GetMoney()-(diff*10000);
		uint32 plusgold = killed->GetMoney()+(diff*10000);
		uint32 killergold = killer->GetMoney();
		uint32 killedgold = killed->GetMoney();
		uint32 plusgold2= killedgold+killergold;	

		if (killerlvl < killedlvl +1)
		killer->GiveXP(XPHigh , killed);
		else 
		if (diff > 10)
			if (killergold > minusgold)
			{
			killer->SetMoney(minusgold);
			killed->SetMoney(plusgold);
			}
			else 
			{
			killed->SetMoney(plusgold2);
			killer->SetMoney(0);
			}
			else 
			if(0  < diff && diff <10) 
			killer->GiveXP(XPLow , killed);
	}
};
