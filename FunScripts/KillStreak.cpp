/* 
Author: Blue
*/
#include "ScriptPCH.h"
 
float Version = 2.50f; // Ehhez nem nyúlunk
bool PvPSystemEnabled = true; // Ez legyen False ha ki akarjuk kapcsolni a rendszert.
bool OnlyInBattlegrounds = false;
bool LooseTokenOnPvPDeath = false;
int32 AmountOfItemsYouWantTheVictimToLoose = 1;
bool AddTokenOnPvPKill = true;
int32 ItemReward = 30000; //The ItemID of the reward.
int32 AmountOfRewardsOnKillStreak[5] = { 1, 3, 5, 7, 10 }; //Mennyi jutalom itemet kapjon a killer.
int32 HowManyTimesYouWantTheKillerToGetAwardedForKillingTheSameVictim = 3; // Ezt vágjuk mi.
const int32 KillerStreak1 = 5; // Mennyi legyen a minimum killstreak aminél announcel.
const int32 KillerStreak2 = 10; 
const int32 KillerStreak3 = 15; 
const int32 KillerStreak4 = 20; 
const int32 KillerStreak5 = 30; 
int32 KillStreaks[5] = { KillerStreak1, KillerStreak2, KillerStreak3, KillerStreak4, KillerStreak5 };
 
struct SystemInfo
{
    uint32 KillStreak;
    uint32 LastGUIDKill;
    uint8 KillCount;
};
 
static std::map<uint32, SystemInfo> KillingStreak;
 
class System_OnPvPKill : public PlayerScript
{
    public:
        System_OnPvPKill() : PlayerScript("System_OnPvPKill") {}
 
        
void OnPVPKill(Player *pKiller, Player *pVictim)
{
    if(PvPSystemEnabled == false)
    {
             return;
    }
    else if(PvPSystemEnabled == true)
    {
        uint32 kGUID; 
        uint32 vGUID;
        char msg[500];
        kGUID = pKiller->GetGUID();
        vGUID = pVictim->GetGUID();                 
        if(kGUID == vGUID)
        {
          return;
        }
                
      if(KillingStreak[kGUID].LastGUIDKill == vGUID)
        {
        KillingStreak[kGUID].KillCount++;
        KillingStreak[vGUID].KillCount = 1;
          pKiller->AddItem(ItemReward, 1);
        if(LooseTokenOnPvPDeath == true)
          pVictim->DestroyItemCount(ItemReward, AmountOfItemsYouWantTheVictimToLoose, true, false);
        }
      if(KillingStreak[kGUID].LastGUIDKill != vGUID)
      {
        KillingStreak[kGUID].KillCount = 1;
        KillingStreak[vGUID].KillCount = 1;
      }
 
      if(KillingStreak[kGUID].KillCount == HowManyTimesYouWantTheKillerToGetAwardedForKillingTheSameVictim)
      {
        return;
      }
 
      if(OnlyInBattlegrounds == true)
        {
        if(!pKiller->GetMap()->IsBattleground())
           return;
      }
 
        KillingStreak[kGUID].KillStreak++;
        KillingStreak[vGUID].KillStreak = 0;
        KillingStreak[kGUID].LastGUIDKill = vGUID;
        KillingStreak[vGUID].LastGUIDKill = 0;
      if(AddTokenOnPvPKill == true)
          pKiller->AddItem(ItemReward, 1);
      if(LooseTokenOnPvPDeath == true)
        pVictim->DestroyItemCount(ItemReward, AmountOfItemsYouWantTheVictimToLoose, true, false);
                
        switch(KillingStreak[kGUID].KillStreak)
        {
        case KillerStreak1:
        sprintf(msg, "[PvP System]: %s megölte %s-t és ez volt a %u kill streak. ", pKiller->GetName(), pVictim->GetName(), KillStreaks[1]);
        sWorld.SendWorldText(LANG_SYSTEMMESSAGE, msg);
        pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[1]);
        break;
 
        case KillerStreak2:
        sprintf(msg, "[PvP System]: %s megölte %s-t és ez volt a %u kill streak. ", pKiller->GetName(), pVictim->GetName(), KillStreaks[2]);
        sWorld.SendWorldText(LANG_SYSTEMMESSAGE, msg);
        pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[2]);
        break;
 
        case KillerStreak3:
        sprintf(msg, "[PvP System]: %s megölte %s-t és ez volt a %u kill streak. ", pKiller->GetName(), pVictim->GetName(), KillStreaks[3]);
        sWorld.SendWorldText(LANG_SYSTEMMESSAGE, msg);
        pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[3]);
        break;
 
        case KillerStreak4:
        sprintf(msg, "[PvP System]: %s megölte %s-t és ez volt a %u kill streak. ", pKiller->GetName(), pVictim->GetName(), KillStreaks[4]);
        sWorld.SendWorldText(LANG_SYSTEMMESSAGE, msg);
        pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[4]);
        break;
 
        case KillerStreak5:
        sprintf(msg, "[PvP System]: %s megölte %s-t és ez volt a %u kill streak. ", pKiller->GetName(), pVictim->GetName(), KillStreaks[5]);
        sWorld.SendWorldText(LANG_SYSTEMMESSAGE, msg);
        pKiller->AddItem(ItemReward, AmountOfRewardsOnKillStreak[5]);
        KillingStreak[kGUID].KillStreak = 0;
        break;
     }
    }
}
};
 
void AddSC_System()
{
    new System_OnPvPKill;
}