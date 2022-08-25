#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "string"
#include <cmath>
#include <ctime>
#include <list>
#include <thread>
#include <stdlib.h>

using namespace std;

//Global Variable for Movement.
int movement = 0;

//Day Counter.
int dayCounter = 0;

//Bool for Races
bool Istari = false;

//String for current region for battles.
string CurrentRegion;

//Bool for if first battle has happened already.
bool FirstBattleDone = false;

//Important for determining which party members exist and don't.
int PartyRace;

int KillCount = 0; //A counter for all kills.
int OrcKillCount = 0; //Orc kills.
int UrukKillCount = 0; //Uruk kills.
int TrollKillCount = 0; //Troll kills.

//Current HP, MP and XP.
int Hero1CurrentHP;
int Hero1CurrentXP;
int Hero2CurrentHP;
int Hero2CurrentXP;
int Hero3CurrentHP;
int Hero3CurrentXP;
int Hero4CurrentHP;
int Hero4CurrentXP;

//Unused Vectors.
//vector<Goblin>OrcContainer;
//vector<Warg>OrcContainer;
//vector<Orc>OrcContainer;
//vector<Uruk>OrcContainer;
//vector<Troll>OrcContainer;

class Character {
public:
    string Name;
    string mainClass;
    string race;
    string realm;
    int HP; //Health Points.
    int DP; //Defense Points.
    int AP; //Attack Points.
    int MP; //Magic Points.
    int IP; //Initiative Points.

    //Constructor.
    Character(string name, int Class, int Race, int Realm) {
        Name = name;

        HP = 12; //Health Points.
        DP = 3; //Defense Points.
        AP = 5; //Attack Points.
        MP = 0; //Magic Points.
        IP = 3; //Initiative Points.

        if (Race == 1) {

            race = "Man";
            HP + 4;
            AP + 3;
            DP + 1;
            IP + 1;

            if (Realm == 1) {
                realm = "Gondor";
                DP + 2;
            }

            else if (Realm == 2) {
                realm = "Rohan";
                AP + 2;
            }

            else if (Realm == 3) {
                realm = "Dale";
                IP + 1;
                AP + 1;
            }

            else if (Realm == 4) {
                realm = "Eriador";
                IP + 2;
            }
        }

        else if (Race == 2) {

            race = "Elf";
            HP + 3;
            AP + 2;
            MP + 2;
            DP + 1;
            IP + 2;

            if (Realm == 1) {
                realm = "Noldor";
                MP + 1;
                HP + 1;
            }

            else if (Realm == 2) {
                realm = "Sindar";
                AP + 2;
                IP + 1;
            }
        }

        if (Race == 3) {
            race = "Dwarf";
            HP + 5;
            AP + 3;
            DP + 4;

            if (Realm == 1) {
                realm = "Erebor";
                DP + 1;
                IP + 1;
            }

            else if (Realm == 2) {
                realm = "Ered Luin";
                HP + 1;
                DP + 1;
            }

            else if (Realm == 3) {
                realm = "The Iron Hills";
                AP + 2;
            }
        }

        if (Race == 4) {
            Istari = true;
            HP - 2;
            AP - 1;
            MP + 5;
            mainClass = "Wizard";
            race = "Istari";
        }

        if (Istari != true) {
            if (Class == 1) {
                mainClass = "Guardian";
                DP + 1;
                HP + 1;
            }

            else if (Class == 2) {
                mainClass = "Ranger";
                IP + 1;
                AP + 1;
            }

            else if (Class == 3) {
                mainClass = "Loremaster";
                if (race == "Elf" || race == "Istari") {
                    MP + 2;
                }
                else {
                    IP + 2;
                }
            }
        }

    }

    //Default Constructor - should not be needed.
    Character() {


    }

    void CharacterInfo() {
        int Menu;

        cout << "Name: " << Name << "." << endl;
        cout << "Race: " << race << "." << endl;
        if (race == "Elf") {
            cout << "Elven Clan: " << realm << "." << endl;
        }
        else {
            cout << "Realm: " << realm << "." << endl;
        }
        cout << "Class: " << mainClass << "." << endl;
        if (mainClass == "Guardian") {
            cout << "Equipping a melee weapon will give +2 AP";
        }
        if (mainClass == "Ranger") {
            cout << "Equiping a ranged weapon will give +1 AP and +1 DP";
        }
        if (mainClass == "Loremaster") {
            cout << "Equiping a Lore Book will grant +1 MP and either +1 IP or +1 HP";
        }
        if (mainClass == "Wizard") {
            cout << "A wizard needs only their staff which already grants +1 MP and +1 HP." << endl;
        }
        cout << "Health Points: " << HP << "." << endl;
        cout << "Defense Points: " << DP << "." << endl;
        cout << "Attack Points: " << AP << "." << endl;
        cout << "Magic Points: " << MP << "." << endl;
        cout << "Initiative Points: " << IP << "." << endl;

        cout << "\n[1] Return to Menu: ";
        cin >> Menu;
        while (Menu != 1) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nDo not be a conjurer of cheap tricks. Try again: ";
            cin >> Menu;
        }
    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }
};

//Declare Hero Classes.

Character Hero;
Character 

class Enemy {
public:
    int HP;
    int DP;
    int AP;
    int IP;
    int MP;
};

class Orc : public Enemy {
public:
    //EnemyOrc Orc = new EnemyOrc;
    string EnemyName = "Orc";
    Orc() {
        //Base Stats.
        HP = 8;
        DP = 4;
        AP = 5;
        IP = 3;
        MP = 0;

    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }

};

class OrcCaptain : public Enemy {
public:
    //EnemyOrc Orc = new EnemyOrc;
    string EnemyName = "Orc Captain";
    OrcCaptain() {
        //Base Stats.
        HP = 10;
        DP = 5;
        AP = 6;
        IP = 2;
        MP = 0;

    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }

};

class Uruk : public Enemy {
public:
    string EnemyName = "Uruk-Hai";
    Uruk() {
        //Base Stats.
        HP = 6;
        DP = 4;
        AP = 5;
        IP = 2;
        MP = 4;

    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }
};

class UrukCaptain : public Enemy {
public:
    string EnemyName = "Uruk-Hai Captain";
    UrukCaptain() {
        //Base Stats.
        HP = 6;
        DP = 4;
        AP = 5;
        IP = 2;
        MP = 4;

    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }
};

class Troll : public Enemy {
public:
    string EnemyName = "Troll";
    Troll() {
        //Base Stats.
        HP = 12;
        DP = 3;
        AP = 7;
        IP = 1;
        MP = 0;

    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }
};

class Warg : public Enemy {
public:
    Warg() {
        string EnemyName = "Warg";
        //Base Stats.
        HP = 5;
        DP = 0;
        AP = 6;
        IP = 4;
        MP = 0;

    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }
};

class Goblin : public Enemy {
public:

    string EnemyName = "Goblin";

    Goblin() {
        //Base Stats.
        HP = 5;
        DP = 3;
        AP = 4;
        IP = 3;
        MP = 0;

    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }
};

class Nazgul : public Enemy {
public:

    string EnemyName = "Nazgul";

    Nazgul() {

        HP = 15;
        DP = 6;
        AP = 9;
        IP = 6;
        MP = 5;
    }

    int getHP() {
        return HP;
    }
    int getMP() {
        return MP;
    }
    int getAP() {
        return AP;
    }
    int getDP() {
        return DP;
    }
    int getIP() {
        return IP;
    }

};


void FirstBattle(Character Hero1, Character Hero2, Character Hero3, Character Hero4, int PartyRace) {
    //2 Orcs and 1 Goblin.
    //Battle starts with just the player, then they are joined by either the elf, dwarf or man. The other two companions come with the other two regions.Orc Orc1;
    Orc Orc;
    Goblin Goblin;

    int Hero1HP = Hero.getHP();
    int Hero2HP = Hero.getHP();
    int Hero3HP = Hero.getHP();
    int Hero4HP = Hero.getHP();

    //Orc 1.
    int Orc1HP = Orc.getHP();
    int Orc1MP = Orc.getMP();
    int Orc1IP = Orc.getIP();
    int Orc1DP = Orc.getDP();
    int Orc1AP = Orc.getAP();

    //Orc 2.
    int Orc2HP = Orc.getHP();
    int Orc2MP = Orc.getMP();
    int Orc2IP = Orc.getIP();
    int Orc2DP = Orc.getDP();
    int Orc2AP = Orc.getAP();

    //Goblin 1.
    int Goblin1HP = Goblin.getHP();
    int Goblin1MP = Goblin.getMP();
    int Goblin1IP = Goblin.getIP();
    int Goblin1DP = Goblin.getDP();
    int Goblin1AP = Goblin.getAP();

    Hero1CurrentHP = Hero1HP;


    TravelMap();
}

//For when a saved game is loaded.
void SaveSetter() {

}

void Battle() {

    int encounter = 0;

    encounter = rand() % 100 + 1;

    if (encounter > 0 && encounter < 21) {
        if (CurrentRegion == "Gondor") {
            Orc Orc;

            //Orc 1.
            int Orc1HP = Orc.getHP();
            int Orc1MP = Orc.getMP();
            int Orc1IP = Orc.getIP();
            int Orc1DP = Orc.getDP();
            int Orc1AP = Orc.getAP();

            //Orc 2.
            int Orc2HP = Orc.getHP();
            int Orc2MP = Orc.getMP();
            int Orc2IP = Orc.getIP();
            int Orc2DP = Orc.getDP();
            int Orc2AP = Orc.getAP();

            //Orc 3.
            int Orc3HP = Orc.getHP();
            int Orc3MP = Orc.getMP();
            int Orc3IP = Orc.getIP();
            int Orc3DP = Orc.getDP();
            int Orc3AP = Orc.getAP();

            //Orc 4.
            int Orc4HP = Orc.getHP();
            int Orc4MP = Orc.getMP();
            int Orc4IP = Orc.getIP();
            int Orc4DP = Orc.getDP();
            int Orc4AP = Orc.getAP();


        }
        else if (CurrentRegion == "Rohan") {
            //4 Uruks.
            Uruk Uruk;

        }
        else if (CurrentRegion == "Lothlorien") {
            //1 Goblin and 2 Orcs.
            Orc Orc;
            Goblin Goblin;
        }
    }
    else if (encounter > 20 && encounter < 81) {
        if (CurrentRegion == "Gondor") {
            Orc Orc;

            //Orc 1.
            int Orc1HP = Orc.getHP();
            int Orc1MP = Orc.getMP();
            int Orc1IP = Orc.getIP();
            int Orc1DP = Orc.getDP();
            int Orc1AP = Orc.getAP();

            //Orc 2.
            int Orc2HP = Orc.getHP();
            int Orc2MP = Orc.getMP();
            int Orc2IP = Orc.getIP();
            int Orc2DP = Orc.getDP();
            int Orc2AP = Orc.getAP();

        }
        else if (CurrentRegion == "Rohan") {
            //2 Uruks and 1 Orc.
        }
        else if (CurrentRegion == "Lothlorien") {
            //2 Goblins.
        }
    }
    else if (encounter > 80 && encounter < 100) {
        if (CurrentRegion == "Gondor") {
            //1 Goblin and 1 Orc.
        }
        else if (CurrentRegion == "Rohan") {
            //2 Uruks and 1 Warg.
        }
        else if (CurrentRegion == "Lothlorien") {
            // 3 Goblins.
        }
    }
    encounter = 0;

}

//The first boss battle of the first campaign.
void BattleOfLorien() {
    //Each of the campaigns has a final battle. 
    //The longer it takes the player's party to reach the final location, the more enemies are added to it.
    //The player can choose when they reach the final location to spend more time collecting items or gaining XP from
    //other locations.
}

//The second boss battle of the first campaign.
void BattleUnderTheTrees() {

}

//The final boss battle of the first campaign.
void BattleOfDolGuldur() {

}

//The first boss battle of the second campaign.
void BattleOfWestfold() {

}

//The second boss battle of the second campaign.
void BattleOfHelmsDeep() {

}

//The final boss battle of the second campaign.
void BattleOfIsengard() {

}

//The first boss battle of the third campaign.
void BattleOfCairAndros() {

}

//The second boss battle of the third campaign.
void BattleOfMinasTirith() {

}

//The final battle.
void BattleOfMorannon() {

}


//Bonus battle.
void BattleOfErebor() {

}


//Army.
class Army {
    int Elves;
    int Men;
    int Dwarves;
    int DwarvesWounded;
    int ElvesWounded;
    int MenWounded;
};

class Region {
public:
    string terrain;

};

Region Gondor, Rohan, Isengard, Mordor, Lorien, Mirkwood;

void Location() {

}

void Camp() {

}

void TravelMap() {

    int Option;

    if (dayCounter == 12) {
        //+2 Enemies to final battle.
        
    }

    else if (dayCounter == 19) {
        //+2 Enemies to final battle.
    }

    else if (dayCounter == 31) {
        //+2 Enemies to final battle.
    }

    cout << "** TRAVEL **\n\nDay: " << dayCounter << "\n\n[1] Travel\n[2] Make Camp\n[3] Level Up\n[4] Save Game\n[5] Leave Game.\n\nMake your choice: ";
    cin >> Option;

    while (Option < 0 || Option > 5) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nDo not abandon reason for madness. Try again: ";
        cin >> Option;
    }

    switch (Option) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }


}

void Movement() {

    if (movement >= 20) {

    }

    else if (movement < 20) {
        int encounter = 0;
        encounter = rand() % 100 + 1;

        if (encounter > 0 && encounter < 21) {
            movement++;
            Battle();
        }
        else if (encounter > 20 && encounter < 81) {
            movement++;
            cout << "You have moved into " << Gondor.terrain << "terrain";
        }
        else if (encounter > 80 && encounter < 100) {
            Location();
            movement++;
        }
        //Reset encounter.
        encounter = 0;
    }

}

int main()
{
    srand(time(0));
    string name;
    int RaceChoice;
    int ClassChoice;
    int FirstMenu;
    int Continue;
    int realm;

    cout << "------* THE FIRES OF MIDDLE EARTH *-------\n\n";
    cout << "[1] New Game\n[2] Continue\n[3] Exit\n\nChoice: ";
    cin >> FirstMenu;
    while (FirstMenu < 0 || FirstMenu > 3) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nDo not abandon reason for madness. Try again: ";
        cin >> FirstMenu;
    }

    switch (FirstMenu) {
    case 1:
        break;
    case 2:
        //Something something fstream.
        break;
    case 3:
        system("CLS");
        cout << "Farewell for now.";
        return 0;
        break;
    }

    system("CLS");

    cout << "Enter the name of your character: ";
    cin >> name;

    system("CLS");

    cout << "[1] Man\n[2] Elf\n[3] Dwarf\n[4] Istari\n\nChoose your race: ";
    cin >> RaceChoice;

    while (RaceChoice < 0 || RaceChoice > 4) {
        cout << "\nDo not abandon reason for madness. Try again: ";
        cin >> RaceChoice;
    }

    system("CLS");

    switch (RaceChoice) {
    case 1:
        cout << "Ah yes, one of the Men of the West. Yet, of which realm do you belong?\n\n[1] Gondor\n[2] Rohan\n[3] Dale\n[4] Eriador\n\nYou must choose: ";
        cin >> realm;
        while (realm < 0 || realm > 4) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nDo not abandon reason for madness. Try again: ";
            cin >> realm;
        }

        switch (realm) {
        case 1:
            cout << "One of the descendants of Numenor, a Gondorian of stern strength and protective of their family.";
            break;
        case 2:
            cout << "You are of the realm of Rohan, a descendant of Eorl and one who is determined to make things right in the lands of the horse-lords.";
            break;
        case 3:
            cout << "From the city of Dale, you are a proud child of smiths, bowmen, fisherfolk and artisans. You are known to dwarves.";
            break;
        case 4:
            cout << "From the ashes of Arnor, you are one of the few remaining of the Dunedain, the descendants of the kings of old.";
            break;
        }
        break;
    case 2:
        cout << "Ah yes, one of Iluvatar's Firstborn. Yet of which of the Elven lines do you belong to?\n\n[1] Noldor\n[2] Sindar\n\nYou must choose: ";
        cin >> realm;
        while (realm < 0 || realm > 2) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nDo not abandon reason for madness. Try again: ";
            cin >> realm;
        }

        switch (realm) {
        case 1:
            cout << "Even before Beleriand was settled, you had seen the light of Valinor which was created by its two legendary trees. You are a child of high elves. Your doom in this world is near.";
            break;
        case 2:
            cout << "You descend from the Silvan Elves, those who chose not to cross the sea to reach Valinor. Yet the sea calls to you still. Your doom in this world is near.";
            break;
        }
        break;
    case 3:
        cout << "Ah yes, one of Aule's descendants. Yet of which mighty hall of the sturdy folk do you belong?\n\n[1] Erebor\n[2] Ered Luin\n[3] The Iron Hills\n\nYou must choose: ";
        cin >> realm;
        while (realm < 0 || realm > 3) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nDo not abandon reason for madness. Try again: ";
            cin >> realm;
        }

        switch (realm) {
        case 1:
            cout << "Your father is one of the Longbeards, a descendant and member of Durin's Folk. You grew up and came of age in the splendour of Erebor's riches.";
            break;
        case 2:
            cout << "When your people were exiled by Smaug long ago and even after Thorin and his company returned, your family remained to reside in the mountains of Ered Luin.";
            break;
        case 3:
            cout << "Your folk descend from the line of Durin's Folk, yet you are among those who remained in the halls of the Iron Hills even when Erebor was retaken.";
            break;
        }
        break;
    case 4:
        break;
    }

    if (RaceChoice == 4) {
        cout << "You are among the wise of the veiled West and thus in Westron language, are relegated to the style of Wizard. A high honour of mighty Eru.";
        cout << "\n\nSpeak '1' and continue: ";
        realm = 0;
        ClassChoice = 0;
        cin >> Continue;
    }

    else {
        cout << "[1] Guardian\n[2] Ranger\n[3] Loremaster\n\nPlease select your style: ";
        cin >> ClassChoice;
        while (ClassChoice < 0 || ClassChoice > 3) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nDo not abandon reason for madness. Try again: ";
            cin >> ClassChoice;
        }
        switch (ClassChoice) {
        case 1:
            cout << "A guardian, a true warrior at heart and one who would protect their friends above all.";
            break;
        case 2:
            cout << "A ranger with skill at stealth, speed and wit.";
            break;
        case 3:
            cout << "A Loremaster, one who wields great knowledge of this world and in the arts.";
            break;
        }
    }
    PartyRace = RaceChoice;

    Character Hero(name, ClassChoice, RaceChoice, realm);
    //Creates three other party members based on your input (erasing one of the race that you are playing as):
    if (PartyRace == 1) {
        Character Gilad(name = "Gilad", ClassChoice = 0, RaceChoice = 4, realm = 0);
        Character Azhaghai(name = "Azhaghai", ClassChoice = 1, RaceChoice = 3, realm = 2);
        Character Vardil(name = "Vardil", ClassChoice = 3, RaceChoice = 2, realm = 2);
    }
    else if (PartyRace == 2) {
        Character Azhaghai(name = "Azhaghai", ClassChoice = 1, RaceChoice = 3, realm = 2);
        Character Hardan(name = "Hardan", ClassChoice = 2, RaceChoice = 1, realm = 1);
        Character Gilad(name = "Gilad", ClassChoice = 0, RaceChoice = 4, realm = 0);
    }
    else if (PartyRace == 3) {
        Character Vardil(name = "Vardil", ClassChoice = 3, RaceChoice = 2, realm = 2);
        Character Hardan(name = "Hardan", ClassChoice = 2, RaceChoice = 1, realm = 1);
        Character Gilad(name = "Gilad", ClassChoice = 0, RaceChoice = 4, realm = 0);
    }
    else if (PartyRace == 4) {
        Character Vardil(name = "Vardil", ClassChoice = 3, RaceChoice = 2, realm = 2);
        Character Azhaghai(name = "Azhaghai", ClassChoice = 1, RaceChoice = 3, realm = 2);
        Character Hardan(name = "Hardan", ClassChoice = 2, RaceChoice = 1, realm = 1);
    }

    Character Vardil = Vardil;
    Character Azhaghai = Azhaghai;
    Character Hardan = Hardan;
    Character Gilad = Gilad;

    system("CLS");

    cout << "Sauron's Ring of Power has been discovered at long last. The War of the Ring is about to begin and you as an adventuring herald are called to fight in the defense of Middle Earth!\n\nThe enchanted forests of Lothlorien are under attack and you must venture there at once!\n\n";
    this_thread::sleep_for(10s);
    system("CLS");
    cout << "You stumble upon a band of orcs harassing a trio of traveling adventurers.";
    this_thread::sleep_for(5s);
    system("CLS");
    cout << "\n\n.......";
    this_thread::sleep_for(2s);
    cout << " Battle commencing.";

    if (PartyRace == 1) {
        FirstBattle(Hero, Vardil, Azhaghai, Gilad, PartyRace);
    }

    if (PartyRace == 2) {
        FirstBattle(Hero, Azhaghai, Hardan, Gilad, PartyRace);
    }

    if (PartyRace == 3) {
        FirstBattle(Hero, Vardil, Hardan, Gilad, PartyRace);
    }

    if (PartyRace == 4) {
        FirstBattle(Hero, Vardil, Azhaghai, Hardan, PartyRace);
    }

}