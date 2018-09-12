/*********************************************************************
** Program name: final project (textGame)
** Author: Charles Ledbetter
** Date: 8/13/2017
** Description: A function used as a friend to several classes. It
holds the relevant messages that are displayed by the game.
*********************************************************************/
#include<iostream>
#include<string>

#include "descAbbr.hpp"

using std::cout;
using std::endl;
using std::string;

//return relevant message
string descAbbr(int i)
{
  string tempStr = "";

  if(i == 1)
  {
    tempStr = "\n\n"
    "You are the young captain of an asteroid mining vessel. This is"
    "\n"
    "only your second trip to the asteroid belt. You have sunk all"
    "\n"
    "the money you have into refitting the ship you inherited from"
    "\n"
    "your uncle, but even so, it is still an undersized hunk of junk."
    "\n"
    "You have one crew member, a veteran miner named Vogler. You"
    "\n"
    "would be lost without him. Even now he watches over the ship as"
    "\n"
    "you rest. Your shift behind the main console will come soon"
    "\n"
    "enough, but for now you dream of the riches you will soon pull"
    "\n"
    "from the icy rocks of the belt."
    "\n\n";
  }
  else if(i == 2)
  {
    tempStr = "\n"
    "You wake to a large crash. You tell the AI to turn on the lights,"
    "\n"
    "but they do not come on."
    "\n";
  }
  else if(i == 3)
  {
    tempStr = "\n"
    "AI: Captain there has been a collision. Ship integrity is"
    "\n"
    "compromised. The automated hull sealant has filled the breaches"
    "\n"
    "in the bridge and airlock sections, but the engine room could "
    "\n"
    "not be sealed. It will have to be done manually from outside the"
    "\n"
    "ship. I would suggest that Mr. Vogler undertake the repairs, but"
    "\n"
    "it appears he was injured in the collision. He is in need of"
    "\n"
    "first aid on the bridge."
    "\n\n";
  }
  else if(i == 4)
  {
    int tempRand = (rand() % 4);
    switch(tempRand)
    {
      case 0: tempStr = "\n"
      "The ship quakes violently and you hear the loud grown of"
      "\n"
      "tortured metal."
      "\n\n"
      "AI: Captain, I believ...'buzzzzzz..."
      "\n";
            break;
      case 1: tempStr = "\n"
      "You hear a loud thumping somewhere in the ship."
      "\n\n"
      "AI: Captain, the integrity of the ship will not hold up much"
      "\n"
      "longer. Please hurry."
      "\n";
            break;
      case 2: tempStr = "\n"
      "You smell smoke, but you cannot tell where its coming from."
      "\n";
            break;
    }
  }
  else if(i == 5)
  {
    tempStr = "\n"
    "AI: Captain, the integrity of the ship will not hold up for much"
    "\n"
    "longer."
    "\n";
  }
  else if(i == 6)
  {
    tempStr = "It is very bright.";
  }
  else if(i == 7)
  {
    tempStr = "It has a knife, pliers, and some screwdrivers.";
  }
  else if(i == 8)
  {
    int tempRand = (rand() % 6);
    switch(tempRand){
      case 0: tempStr = "Kelp flavored. Vogler's favorite.";
            break;
      case 1: tempStr = "Algea pie flavored. Just like Momma used to "
                        "make.";
            break;
      case 2: tempStr = "Corn bran and carmel flavored. Mmmmm.";
            break;
      case 3: tempStr = "Marsberry and cream flavored. Your favorite.";
            break;
      case 4: tempStr = "Meaty pasta flavored. Best faux meat this side"
                        " of Jupiter.";
            break;
      case 5: tempStr = "Potatoes and yam flavor. Gotta love root "
                        "veggies.";
            break;
    }
  }
  else if(i == 9)
  {
    tempStr = "A kit of first aid implements.";
  }
  else if(i == 10)
  {
    tempStr = "It is a standard 32 pin mil-spec cable.";
  }
  else if(i == 11)
  {
    tempStr = "There is a gaping hole in the left sleeve.";
  }
  else if(i == 12)
  {
    tempStr = "It sews things together at the nanoscopic level.";
  }
  else if(i == 13)
  {
    tempStr = "Made of heavy duty material from the stateroom's sofa.";
  }
  else if(i == 14)
  {
    tempStr = "This suit should hold for a while, but it may be best to"
    "\n"
    "   avoid prolonged spacewalks.";
  }
  else if(i == 15)
  {
    tempStr = "Light weight and powerful. Has a built on pump to supply"
    "\n"
    "   air. For in-ship use only.";
  }
  else if(i == 16)
  {
    tempStr = "surprisingly portable for such a powerful machine.";
  }
  else if(i == 17)
  {
    tempStr = "An AT87 IUSS standard hull patch with built in temporary"
    "\n"
    "   adhesive. Not cheap, but well worth the money.";
  }
  else if(i == 18)
  {
    tempStr = "\n"
    "You are in the bridge. On the aft bulkhead there are two doors."
    "\n"
    "The portside door leads to the workshop. The starboard"
    "\n"
    "door leads to the stateroom. Forward you can see out of the"
    "\n"
    "port-screen. You see an infinite field of stars broken up by"
    "\n"
    "the nearest asteroids. You see the main console, but where the"
    "\n"
    "overhead controls usually are there is a gaping hole filled "
    "\n"
    "with nano-foam sealant. You see that the overhead indicator panel"
    "\n"
    "has fallen on Vogler. He is pinned to the floor and appears to be"
    "\n"
    "unconscious. The main console is blank, and the command"
    "\n"
    "chair is in pieces around Vogler. It does not look good."
    "\n";
  }
  else if(i == 19)
  {
    tempStr = "\n"
    "You are in the bridge. On the aft bulkhead there are two doors."
    "\n"
    "The portside door leads to the workshop. The starboard"
    "\n"
    "door leads to the stateroom. Forward you can see out of the"
    "\n"
    "port-screen. You see an infinite field of stars broken up by"
    "\n"
    "the nearest asteroids. The overhead indicator panels and control"
    "\n"
    "chair lay in ruins. There is a large hole punched into the "
    "\n"
    "ceiling. It is filled with nano-foam sealant. The main console"
    "\n"
    "is blank. There is meteoroid debris strewn over it. In the"
    "\n"
    "corner there is a bin of junk electronics left over from recent"
    "\n"
    "upgrades Vogler and you have been working on. Vogler is laid out"
    "\n"
    "where you left him. He is unconscious and pale. His leg is still"
    "\n"
    "bleeding. He is in need of first aid."
    "\n";
  }
  else if(i == 20)
  {
    tempStr = "\n"
    "You are in the bridge. On the aft bulkhead there are two doors."
    "\n"
    "The portside door leads to the workshop. The starboard"
    "\n"
    "door leads to the stateroom. Forward you can see out of the"
    "\n"
    "port-screen. You see an infinite field of stars broken up by"
    "\n"
    "the nearest asteroids. The overhead indicator panels and control"
    "\n"
    "chair lay in ruins. There is a large hole punched into the "
    "\n"
    "ceiling. It is filled with nano-foam sealant. The main console"
    "\n"
    "is blank. There is meteoroid debris strewn over it. In the"
    "\n"
    "corner there is a bin of junk electronics left over from recent"
    "\n"
    "upgrades Vogler and you have been working on. Vogler is sitting"
    "\n"
    "against the portside bulkhead. He is conscious, but still very"
    "\n"
    "pale. Perhaps he lost a bit to much blood from that wound on his"
    "\n"
    "leg. He is beckoning you over."
    "\n";
  }
  else if(i == 21)
  {
    tempStr = "\n"
    "You are in the bridge. On the aft bulkhead there are two doors."
    "\n"
    "The portside door leads to the workshop. The starboard"
    "\n"
    "door leads to the stateroom. Forward you can see out of the"
    "\n"
    "port-screen. You see an infinite field of stars broken up by"
    "\n"
    "the nearest asteroids. The overhead indicator panels and control"
    "\n"
    "chair lay in ruins. There is a large hole punched into the "
    "\n"
    "ceiling. It is filled with nano-foam sealant. The main console"
    "\n"
    "is blank. There is meteoroid debris strewn over it. In the"
    "\n"
    "corner there is a bin of junk electronics left over from recent"
    "\n"
    "upgrades Vogler and you have been working on. Vogler has moved"
    "\n"
    "to the main console. He is laying beside it inspecting it. He"
    "\n"
    "sees that you see him, and feebly points to the access panel."
    "\n";
  }
  else if(i == 22)
  {
    tempStr = "\n"
    "You are in the bridge. On the aft bulkhead there are two doors."
    "\n"
    "The portside door leads to the workshop. The starboard"
    "\n"
    "door leads to the stateroom. Forward you can see out of the"
    "\n"
    "port-screen. You see an infinite field of stars broken up by"
    "\n"
    "the nearest asteroids. The overhead indicator panels and control"
    "\n"
    "chair lay in ruins. There is a large hole punched into the "
    "\n"
    "ceiling. It is filled with nano-foam sealant. The main console"
    "\n"
    "is blank. There is meteoroid debris strewn over it. In the"
    "\n"
    "corner there is a bin of junk electronics left over from recent"
    "\n"
    "upgrades Vogler and you have been working on. Vogler has moved"
    "\n"
    "to the main console. He is poking his head into the access panel"
    "\n"
    "you opened. This gives you a good look at his damaged leg. It is"
    "\n"
    "covered in bio-foam, pink with blood. If it does not get more"
    "\n"
    "serious attention soon he may loose it."
    "\n";
  }
  else if(i == 23)
  {
    tempStr = "\n"
    "You are in the bridge. On the aft bulkhead there are two doors."
    "\n"
    "The portside door leads to the workshop. The starboard"
    "\n"
    "door leads to the stateroom. Forward you can see out of the"
    "\n"
    "port-screen. You see an infinite field of stars broken up by"
    "\n"
    "the nearest asteroids. There is a large hole punched into the"
    "\n"
    "ceiling. It is filled with nano-foam sealant. The main console"
    "\n"
    "is blinking oddly. The screen is clear of debris but scratched"
    "\n"
    "and cracked. In the corner there is a bin of junk electronics"
    "\n"
    "left over from recent upgrades Vogler and you have been working"
    "\n"
    "on. You have piled the debris in the corner next to the bin."
    "\n"
    "Vogler has moved back against the portside bulkhead. He looks a"
    "\n"
    "bit better but is still very pale."
    "\n";
  }
  else if(i == 24)
  {
    tempStr = "\n"
    "You are in the bridge. On the aft bulkhead there are two doors."
    "\n"
    "The portside door leads to the workshop. The starboard"
    "\n"
    "door leads to the stateroom. Forward you can see out of the"
    "\n"
    "port-screen. You see an infinite field of stars broken up by"
    "\n"
    "the nearest asteroids. There is a large hole punched into the "
    "\n"
    "ceiling. It is filled with nano-foam sealant. The main console"
    "\n"
    "is blinking oddly. The screen is clear of debris but scratched"
    "\n"
    "and cracked. In the corner there is a bin of junk electronics"
    "\n"
    "left over from recent upgrades Vogler and you have been working"
    "\n"
    "on. You have piled the debris in the corner next to the bin."
    "\n";

  }
  else if(i == 25)
  {
    tempStr = "\n"
    "The bin is overflowing with junk electronics. You spot a patch"
    "\n"
    "cable on top that might come in handy."
    "\n";
  }
  else if(i == 26)
  {
    tempStr = "\n"
    "The bin is overflowing with junk electronics. There is nothing"
    "\n"
    "useful to your situation within."
    "\n";
  }
  else if(i == 27)
  {
    tempStr = "\n"
    "The main console is lifeless. This is what you see:"
    "\n"
    "################################################################"
    "\n"
    "#                                             |  /             #"
    "\n"
    "#                                             | /              #"
    "\n"
    "#                                             /                #"
    "\n"
    "#                                       _ _ _ _ /              #"
    "\n"
    "#                                            \\                 #"
    "\n"
    "#                                             \\                #"
    "\n"
    "#                                                              #"
    "\n"
    "#                                                              #"
    "\n"
    "#                                                              #"
    "\n"
    "#                                                              #"
    "\n"
    "#                                                              #"
    "\n"
    "#                                                              #"
    "\n"
    "#                                            \\                 #"
    "\n"
    "#                                             \\ | /            #"
    "\n"
    "#                                              \\|/             #"
    "\n"
    "#             \\                             _ _ |_ _           #"
    "\n"
    "#              \\ _ _ __                        / \\             #"
    "\n"
    "#               |                                 \\            #"
    "\n"
    "#               |                                              #"
    "\n"
    "################################################################"
    "\n";
  }
  else if(i == 28)
  {
    tempStr = "\n"
    "The main console is malfunctioning. This is what you see:"
    "\n"
    "################################################################"
    "\n"
    "#    ......                                   |  /             #"
    "\n"
    "#    ......                                   | /              #"
    "\n"
    "#    ......                                   /                #"
    "\n"
    "#    system booting from backup...      _ _ _ _ /              #"
    "\n"
    "#    ......                                  \\                 #"
    "\n"
    "#    ......                                   \\                #"
    "\n"
    "#    ......                                                    #"
    "\n"
    "#    00 10 00 00 11 00 00 00                                   #"
    "\n"
    "#    00 00 00 00 00 00 00 01                                   #"
    "\n"
    "#    00 00 00 01 00 10 00 00                                   #"
    "\n"
    "#    0xfffff7ef : 0xfffff02a                                   #"
    "\n"
    "#    0xfffbaf83 : 0xfffff001                                   #"
    "\n"
    "#    0xfffffef6 : 0xffffea5c                 \\                 #"
    "\n"
    "#    ......                                   \\ | /            #"
    "\n"
    "#    ~kernel panic~                            \\|/             #"
    "\n"
    "#    ......   \\                             _ _ |_ _           #"
    "\n"
    "#    ......    \\ _ _ __                        / \\             #"
    "\n"
    "#    ......     |                                 \\            #"
    "\n"
    "#    shutting do|n...                                          #"
    "\n"
    "################################################################"
    "\n";
  }
  else if(i == 29)
  {
    tempStr = "\n"
    "You lift the fallen indicator panel off of Vogler's legs. You "
    "\n"
    "immediately regret it. He begins to bleed profusely from a ragged"
    "\n"
    "wound on his right leg. You faction a makeshift tourniquet from"
    "\n"
    "Vogler's torn pant leg. It slows the bleeding. You need to find"
    "\n"
    "the first aid kit quickly, or he might not make it."
    "\n";
  }
  else if(i == 30)
  {
    tempStr = "\n"
    "You take the bio-foam applicator from the first aid kit and apply"
    "\n"
    "it to Vogler's leg. The white gel foams on contact with Vogler's"
    "\n"
    "bloody leg, immediately stanching the bleeding and filling the"
    "\n"
    "wound. Next you apply a stem-pack to Vogler, rousing him from"
    "\n"
    "unconsciousness. After a few bleary moments he remembers what has"
    "\n"
    "happened."
    "\n\n"
    "VOGLER: Captain, the rocks came out of nowhere. They didn't even"
    "\n"
    "show up on the main screen. By the time I spotted them with my"
    "\n"
    "own eyes it was too late. They were moving so fast..."
    "\n";
  }
  else if(i == 31)
  {
    tempStr = "\n"
    "You have done all you can without a first aid kit."
    "\n";
  }
  else if(i == 32)
  {
    tempStr = "\n"
    "VOGLER: If the main console is offline we cannot reset the life"
    "\n"
    "systems or set the nano-bots repairing the engine. You will have"
    "\n"
    "to go to the engine room and reset the ship's analytical systems"
    "\n"
    "from the emergency reset panel."
    "\n\n"
    "AI: I'm sorry Mr. Vogler but the door to the engine room has been"
    "\n"
    "sealed by the emergency triage system. The damage to the hull on"
    "\n"
    "the stern is more than the ship's auto repair system can handle."
    "\n"
    "As I stated to the captain, before you were conscious, the hole"
    "\n"
    "there will have to be sealed manually."
    "\n\n"
    "VOGLER: What do you mean, the engine room has been sealed? Unseal"
    "\n"
    "it now! We need to reset the life systems and start the engine"
    "\n"
    "repair!"
    "\n\n"
    "AI: I do not have access to interfere with the ship's emergency"
    "\n"
    "triage system. The former owner of this vessel did not fully trust"
    "\n"
    "artificial intelligence systems. If the console was online you"
    "\n"
    "could reset the system from here, but while it is offline the only"
    "\n"
    "way to reset the system is from the emergency reset panel in the"
    "\n"
    "engine room."
    "\n\n"
    "VOGLER: pfff. Kid, your uncle was a piece of work. Well you heard"
    "\n"
    "what it said. We have to fix the main console. Better take the"
    "\n"
    "access panel off, and have a look."
    "\n";
  }
  else if(i == 33)
  {
    tempStr = "\n"
    "VOGLER: What are you waiting for kid help me fix the main console."
    "\n";
  }
  else if(i == 34)
  {
    tempStr = "\n"
    "You use your multitool to unscrew the screws holding the access"
    "\n"
    "panel in place. With in is a rats' nest of cables. Some of them"
    "\n"
    "looked blackened from smoke. One of them is the main power source."
    "\n";
  }
  else if(i == 35)
  {
    tempStr = "\n"
    "You use the patch cable to replace the power source cable. After"
    "\n"
    "a few pops and sparks, you hear the main console hum to life. The"
    "\n"
    "overhead light flicker to life. It seems the ship has power again."
    "\n"
    "Since you can now see, you take a few moments to clear the rubble"
    "\n"
    "from the console and stack the wreckage in the corner next to the"
    "\n"
    "bin."
    "\n";
  }
  else if(i == 36)
  {
    tempStr = "\n"
    "It appears that you need something to replace the main power cable."
    "\n";
  }
  else if(i == 37)
  {
    tempStr = "\n"
    "VOGLER: Captain I think that I could do us more good from the"
    "\n"
    "workshop, perhaps you could help me get there. But before that"
    "\n"
    "I have to eat something. I feel so weak."
    "\n";
  }
  else if(i == 38)
  {
    tempStr = "\n"
    "After Vogler scarfs down the snack bar you lift him to his good"
    "\n"
    "leg, and the two of you hobble to the workshop. You sit Vogler at"
    "\n"
    "the workbench in his favorite swivel chair. He is still pale, but"
    "\n"
    "the snack bar seemed to help, he has more energy now."
    "\n";
  }
  else if(i == 39)
  {
    tempStr = "\n"
    "VOGLER: I'm sorry captain, but I just don't have the energy to"
    "move. I have to eat something first."
    "\n";
  }
  else if(i == 40)
  {
    tempStr = "\n"
    "You reboot the console. This is what you see:"
    "\n"
    "################################################################"
    "\n"
    "#    ......                                   |  /             #"
    "\n"
    "#    ......                                   | /              #"
    "\n"
    "#    ......                                   /                #"
    "\n"
    "#    system booting from backup...      _ _ _ _ /              #"
    "\n"
    "#    ......                                  \\                 #"
    "\n"
    "#    ......                                   \\                #"
    "\n"
    "#    ......                                                    #"
    "\n"
    "#    loading bios...                                           #"
    "\n"
    "#    ......                                                    #"
    "\n"
    "#    getting latest system settings...                         #"
    "\n"
    "#    ......                                                    #"
    "\n"
    "#    populating neural network...                              #"
    "\n"
    "#    ......                                  \\                 #"
    "\n"
    "#    reticulating splines...                  \\ | /            #"
    "\n"
    "#    ......                                    \\|/             #"
    "\n"
    "#    all syste\\s online                     _ _ |_ _           #"
    "\n"
    "#    .         \\ _ _ __                        / \\             #"
    "\n"
    "#    .          |                                 \\            #"
    "\n"
    "#    congratulat|ons you win!                                  #"
    "\n"
    "################################################################"
    "\n";
  }
  else if(i == 41)
  {
    tempStr = "\n"
    "You are in the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. There is a door on the portside bulkhead"
    "\n"
    "that leads to the workshop. There are two beds against the starboard"
    "\n"
    "bulkhead. One for you and one for Vogler. There is a large cabinet"
    "\n"
    "on the forward bulkhead marked with a red cross. There is a lounge"
    "\n"
    "area to the aft with a sturdy couch you picked out yourself. Beyond"
    "\n"
    "the couch is a lavatory booth. On the aft section of the portside"
    "\n"
    "bulkhead there is a kitchenette. The room is the largest in the ship"
    "\n"
    "outside the engine room."
    "\n";
  }
  else if(i == 42)
  {
    tempStr = "\n"
    "You are in the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. There is a door on the portside bulkhead"
    "\n"
    "that leads to the workshop. There are two beds against the starboard"
    "\n"
    "bulkhead. Vogler is in his bed. He is not asleep, only resting"
    "\n"
    "uncomfortably. He probably needs surgery. There is a large cabinet"
    "\n"
    "on the forward bulkhead marked with a red cross. There is a lounge"
    "\n"
    "area to the aft with a sturdy couch you picked out yourself. Beyond"
    "\n"
    "the couch is a lavatory booth. On the aft section of the portside"
    "\n"
    "bulkhead there is a kitchenette. The room is the largest in the ship"
    "\n"
    "outside the engine room."
    "\n";
  }
  else if(i == 43)
  {
    tempStr = "\n"
    "You look inside the cabinet. Inside you find a first aid kit."
    "\n";
  }
  else if(i == 44)
  {
    tempStr = "\n"
    "You look inside the cabinet. There is nothing of use inside."
    "\n";
  }
  else if(i == 45)
  {
     tempStr = "\n"
     "Inside is a toilet and a shower. Just like the rest of the ship,"
     "\n"
     "it is very cramped."
     "\n";
  }
  else if(i == 46)
  {
    tempStr = "\n"
    "The lounge consists of a sofa, a table, and a video player. The"
    "\n"
    "sofa is made of a strong graphene material."
    "\n";
  }
  else if(i == 47)
  {
    tempStr = "\n"
    "The lounge consists of a sofa, a table, and a video player. The"
    "\n"
    "sofa is made of a strong graphene material. You have ruined it by"
    "\n"
    "cutting a large hole in it. Now why'd you go and do that?"
    "\n";
  }
  else if(i == 48)
  {
    tempStr = "\n"
    "The kitchenette consists of a microwave, a sink, a fridge, and a"
    "\n"
    "cabinet. Within the cabinet you find a variety of snack bars."
    "\n";
  }
  else if(i == 49)
  {
    tempStr = "\n"
    "The kitchenette consists of a microwave, a sink, a fridge, and a"
    "\n"
    "cabinet. You don't have time for a snack."
    "\n";
  }
  else if(i == 50)
  {
    tempStr = "\n"
    "VOGLER: Captain... Is the life support system reset yet? What about"
    "\n"
    "the engine?"
    "\n";
  }
  else if(i == 51)
  {
    tempStr = "\n"
    "You are in the workshop. There is a door on the portside aft bulkhead"
    "\n"
    "that leads to the airlock. There is a door on the starboard bulkhead"
    "\n"
    "that leads to the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. Just portside of that door is a corner"
    "\n"
    "workbench. Beside it on the portside bulkhead is a heavy equipment"
    "\n"
    "locker. Beside that is a large toolbox."
    "\n";
  }
  else if(i == 52)
  {
    tempStr = "\n"
    "You are in the workshop. There is a door on the portside aft bulkhead"
    "\n"
    "that leads to the airlock. There is a door on the starboard bulkhead"
    "\n"
    "that leads to the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. Just portside of that door is a corner"
    "\n"
    "workbench. Beside it on the portside bulkhead is a heavy equipment"
    "\n"
    "locker. Beside that is a large toolbox. Vogler is sitting at the"
    "\n"
    "workbench. He looks listless."
    "\n";
  }
  else if(i == 53)
  {
    tempStr = "\n"
    "You are in the workshop. There is a door on the portside aft bulkhead"
    "\n"
    "that leads to the airlock. There is a door on the starboard bulkhead"
    "\n"
    "that leads to the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. Just portside of that door is a corner"
    "\n"
    "workbench. Beside it on the portside bulkhead is a heavy equipment"
    "\n"
    "locker. Beside that is a large toolbox. Vogler is sitting at the"
    "\n"
    "workbench. He is working on something."
    "\n";
  }
  else if(i == 54)
  {
    tempStr = "\n"
    "You are in the workshop. There is a door on the portside aft bulkhead"
    "\n"
    "that leads to the airlock. There is a door on the starboard bulkhead"
    "\n"
    "that leads to the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. Just portside of that door is a corner"
    "\n"
    "workbench. Beside it on the portside bulkhead is a heavy equipment"
    "\n"
    "locker. Beside that is a large toolbox. Vogler is sitting at the"
    "\n"
    "workbench admiring his work. The patched space suit is laid out on"
    "\n"
    "the workbench."
    "\n";
  }
  else if(i == 55)
  {
    tempStr = "\n"
    "You are in the workshop. There is a door on the portside aft bulkhead"
    "\n"
    "that leads to the airlock. There is a door on the starboard bulkhead"
    "\n"
    "that leads to the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. Just portside of that door is a corner"
    "\n"
    "workbench. Beside it on the portside bulkhead is a heavy equipment"
    "\n"
    "locker. Beside that is a large toolbox. Vogler is sitting at the"
    "\n"
    "workbench. He is waving you over."
    "\n";
  }
  else if(i == 56)
  {
    tempStr = "\n"
    "You are in the workshop. There is a door on the portside aft bulkhead"
    "\n"
    "that leads to the airlock. There is a door on the starboard bulkhead"
    "\n"
    "that leads to the stateroom. There is a door on the forward bulkhead"
    "\n"
    "that leads to the bridge. Just portside of that door is a corner"
    "\n"
    "workbench. Beside it on the portside bulkhead is a heavy equipment"
    "\n"
    "locker. Beside that is a large toolbox. You notice that Vogler left"
    "\n"
    "the workbench in disarray."
    "\n";
  }
  else if(i == 57)
  {
    tempStr = "\n"
    "The workbench is lined with static reduction film. It has splotches"
    "\n"
    "and burn marks from many years of use by your uncle. You couldn't"
    "\n"
    "bring yourself to replace it. At least not until you can afford that"
    "\n"
    "extra deluxe model you've been eyeing. There are many tools hanging"
    "\n"
    "on the pegboard above the workbench. Most of them Vogler brought with"
    "\n"
    "him when you hired him. You spot his nano-threader. That could come"
    "\n"
    "in handy."
    "\n";
  }
  else if(i == 58)
  {
    tempStr = "\n"
    "The workbench is lined with static reduction film. It has splotches"
    "\n"
    "and burn marks from many years of use by your uncle. You couldn't"
    "\n"
    "bring yourself to replace it. At least not until you can afford that"
    "\n"
    "extra deluxe model you've been eyeing. There are many tools hanging"
    "\n"
    "on the pegboard above the workbench. Most of them Vogler brought with"
    "\n"
    "him when you hired him."
    "\n";
  }
  else if(i == 59)
  {
    tempStr = "\n"
    "You look inside the heavy equipment locker. Inside is a portable"
    "\n"
    "plasma welder. If you are going to patch the hull you will need it."
    "\n";
  }
  else if(i == 60)
  {
    tempStr = "\n"
    "You look inside the heavy equipment locker. There is nothing but"
    "\n"
    "mining equipment inside."
    "\n";
  }
  else if(i == 61)
  {
    tempStr = "\n"
    "There are many power tools inside the toolbox. You notice the"
    "\n"
    "pneumatic wrench. That could come in handy."
    "\n";
  }
  else if(i == 62)
  {
    tempStr = "\n"
    "There are many power tools inside the toolbox. You don't see"
    "\n"
    "anything you can use right now."
    "\n";
  }
  else if(i == 63)
  {
    tempStr = "\n"
    "You look the patched spacesuit over. It looks good but you are"
    "\n"
    "still nervous about wearing it into space. It is part sofa now"
    "\n"
    "after all."
    "\n";
  }
  else if(i == 64)
  {
    tempStr = "\n"
    "It seems to hold when pressurized. Vogler did a good job."
    "\n";
  }
  else if(i == 65)
  {
    tempStr = "\n"
    "VOGLER: While you were out of the room earlier the AI told me"
    "\n"
    "that your spacesuit is damaged. I can fix it for you if you"
    "\n"
    "bring me what I need. First of all I could use my nano-threader."
    "\n"
    "Its here somewhere but I can't get up."
    "\n";
  }
  else if(i == 66)
  {
    tempStr = "\n"
    "VOGLER: So next I will need something to patch the suit with. Any"
    "\n"
    "ideas? Unfortunately we don't have any standard suit patches lying"
    "\n"
    "around. It might be a good idea to get some if we make it through"
    "\n"
    "this."
    "\n";
  }
  else if(i == 67)
  {
    tempStr = "\n"
    "Now I have what I need. I just need you to hand over the suit and"
    "\n"
    "I can get to work."
    "\n";
  }
  else if(i == 68)
  {
    tempStr = "\n"
    "All done captain. Cross your fingures. ha ha. But in all seriousness"
    "\n"
    "this should hold up. Just get out there and get it done quick, so"
    "\n"
    "you can get back in. I'm feeling tired now I think I need to rest."
    "\n";
  }
  else if(i == 69)
  {
    tempStr = "\n"
    "Captain I have to insist that you help me to my bed. I feel very"
    "\n"
    "ill. I need to lay down."
    "\n";
  }
  else if(i == 70)
  {
    tempStr = "\n"
    "You give Vogler the nano-threader."
    "\n"
    "VOGLER: Just what I needed, thank you captain."
    "\n";
  }
  else if(i == 71)
  {
    tempStr = "\n"
    "VOGLER: I really need that nano-threader, captain."
    "\n";
  }
  else if(i == 72)
  {
    tempStr = "\n"
    "You give Vogler the graphene patch."
    "\n"
    "VOGLER: Is this a piece of the sofa? I always said that thing"
    "\n"
    "was over-engineered. Good thing too. I think this will work."
    "\n"
    "Good thinking, kid."
    "\n";
  }
  else if(i == 73)
  {
    tempStr = "\n"
    "VOGLER: My blood sugar is a little too low to be creative. You"
    "\n"
    "will have to figure something out, kid. You can do it. You're the"
    "\n"
    "captain after all."
    "\n";
  }
  else if(i == 74)
  {
    tempStr = "\n"
    "VOGLER: Alright, I have everything ready. This should only take a"
    "\n"
    "few moments."
    "\n";
  }
  else if(i == 75)
  {
    tempStr = "\n"
    "VOGLER: I need you to bring me your spacesuit, captain."
    "\n";
  }
  else if(i == 76)
  {
    tempStr = "\n"
    "You are in the airlock. There is a door to the engine room on the"
    "\n"
    "aft bulkhead. The airlock door is on the portside. There is a door"
    "\n"
    "to the workshop on the forward bulkhead. The walls are white and"
    "\n"
    "bare except for the spacesuit case and the equipment locker on the"
    "\n"
    "starboard bulkhead. There is a hole in the ceiling just above the"
    "\n"
    "airlock door. Nano-foam sealant has sealed it but the meteoroid"
    "\n"
    "that came through bounced around and did some damage to the airlock"
    "\n"
    "door. It is dented and looks as if it will jam if you try to cycle"
    "\n"
    "it. It needs to be manually loosened before it is cycled. You will"
    "\n"
    "need a heavy duty tool for this. Your pocket multitool won't cut it."
    "\n";
  }
  else if(i == 77)
  {
    tempStr = "\n"
    "You are in the airlock. There is a door to the engine room on the"
    "\n"
    "aft bulkhead. The airlock door is on the portside. There is a door"
    "\n"
    "to the workshop on the forward bulkhead. The walls are white and"
    "\n"
    "bare except for the spacesuit case and the equipment locker on the"
    "\n"
    "starboard bulkhead. There is a hole in the ceiling just above the"
    "\n"
    "airlock door. Nano-foam sealant has sealed it. The airlock door is"
    "\n"
    "still banged up but it should work now."
    "\n";
  }
  else if(i == 78)
  {
    tempStr = "\n"
    "The spacesuit case is smashed. Both of the suits look damaged. Yours"
    "\n"
    "has a big hole ripped in the left sleeve. Vogler's suit does not"
    "\n"
    "look like it has any holes, but the helmet is caved in. If Vogler"
    "\n"
    "was not such a tiny fellow you could squeeze into his suit and use"
    "\n"
    "your own helmet. You will have to find a way to patch your suit if"
    "\n"
    "you are going to use it."
    "\n";
  }
  else if(i == 79)
  {
    tempStr = "\n"
    "The spacesuit case is smashed. You have already taken your suit out."
    "\n"
    "Since Vogler's helmet is ruined his suit can do him no good so you"
    "\n"
    "might as well leave it in the case. It is secured enough that it"
    "\n"
    "should be fine when you cycle the airlock."
    "\n";
  }
  else if(i == 80)
  {
    tempStr = "\n"
    "Within the locker you find the standard hull patch that you need"
    "\n"
    "to patch the hull. You knew these would come in handy one day. You "
    "\n"
    "just didn't know it'd be so soon."
    "\n";
  }
  else if(i == 81)
  {
    tempStr = "\n"
    "There is nothing else of interest in the equipment locker. Only"
    "\n"
    "some more hull patches and a few other odds and ends."
    "\n";
  }
  else if(i == 82)
  {
    tempStr = "\n"
    "AI: The door is sealed captain. I cannot open it because of the"
    "\n"
    "emergency triage system. If you patch the hull the system should"
    "\n"
    "reassess the state of the engine room and unlock the door."
    "\n";
  }
  else if(i == 83)
  {
    tempStr = "\n"
    "You use the pneumatic wrench to engage the airlock's manual override."
    "\n"
    "You turn it just enough to unseized the door without sucking yourself"
    "\n"
    "into space."
    "\n";
  }
  else if(i == 84)
  {
    tempStr = "\n"
    "You need a power tool too engage the airlocks manual override."
    "\n";
  }
  else if(i == 85)
  {
    tempStr = "\n"
    "You are just outside the airlock. The airlock is to your starboard"
    "\n"
    "side. You can see where the damage was done on the stern to your"
    "\n"
    "aft. You can also see the asteroid belt and the trillions of stars"
    "\n"
    "beyond."
    "\n";
  }
  else if(i == 86)
  {
    tempStr = "\n"
    "You can see into the engine room through the hole in the hull. If"
    "\n"
    "only it were a little larger you could try to crawl through, but you"
    "\n"
    "are afraid your patch would rip if you tried. Better just do the"
    "\n"
    "work and get back inside. Beyond the stern you see the sun so far"
    "\n"
    "away, yet still so bright. Your helmet screen tints to protect your"
    "\n"
    "eyes."
    "\n";
  }
  else if(i == 87)
  {
    tempStr = "\n"
    "You have placed the patch over the hole in the hull but it is not"
    "\n"
    "sealed. You need to weld it in place to secure it. Beyond the"
    "\n"
    "stern you see the sun so far away, yet still so bright. Your helmet"
    "\n"
    "screen tints to protect your eyes."
    "\n";
  }
  else if(i == 88)
  {
    tempStr = "\n"
    "You have sealed the hull breach. Good job. You better get back"
    "\n"
    "inside the ship while your spacesuit still holds pressure. This"
    "\n"
    "patch won't last forever. Beyond the stern you see the sun so far"
    "\n"
    "away, yet still so bright. Your helmet screen tints to protect your"
    "\n"
    "eyes."
    "\n";
  }
  else if(i == 89)
  {
    tempStr = "\n"
    "You take a moment to look out into the great vastness. Beyond"
    "\n"
    "the nearby asteroids and meteoroids lay an ocean of ever distant"
    "\n"
    "furnaces. Nearer you see the sun, and the red planet you were born"
    "\n"
    "on. It is but a red speck from here, but you can make it out. Much"
    "\n"
    "closer is your new home, Ceres, but it is impossible to pick out"
    "\n"
    "from the thousands of bodies in the asteroid belt, and much to"
    "\n"
    "small to see from here. You rouse yourself from your reverie. You"
    "\n"
    "have no time for this. Vogler is injured the ship is damaged. You"
    "\n"
    "can look at the stars anytime. Get back to work."
    "\n";
  }
  else if(i == 90)
  {
    tempStr = "\n"
    "You move the standard hull patch into place and activate its"
    "\n"
    "adhesive. It should hold until you can weld it on."
    "\n";
  }
  else if(i == 91)
  {
    tempStr = "\n"
    "You forgot the hull patch. Get your head in the game or you won't"
    "\n"
    "make it through this."
    "\n";
  }
  else if(i == 92)
  {
    tempStr = "\n"
    "You weld on the patch. It takes a while and the welder begins to"
    "\n"
    "overheat. It holds out just long enough to finish. Time to buy a"
    "\n"
    "new welder. You let this one float away."
    "\n";
  }
  else if(i == 93)
  {
    tempStr = "\n"
    "You forgot the welder. Well hurry up and get it before the patch"
    "\n"
    "adhesive gives out."
    "\n";
  }
  else if(i == 94)
  {
    tempStr = "\n"
    "You are in the engine room. There is a door on the forward"
    "\n"
    "bulkhead that leads to the airlock. The engine room is large"
    "\n"
    "in comparison to the rest of the ship. There is a gray cylinder"
    "\n"
    "at the center of the room. You see the emergency reset panel on"
    "\n"
    "the starboard section of the forward wall."
    "\n";
  }
  else if(i == 95)
  {
    tempStr = "\n"
    "You are in the engine room. There is a door on the forward"
    "\n"
    "bulkhead that leads to the airlock. The engine room is large"
    "\n"
    "in comparison to the rest of the ship. The emergency reset"
    "\n"
    "panel has been activated and its many lights are blinking as"
    "\n"
    "it works. Something seems to be happening to the central"
    "\n"
    "cylinder."
    "\n";
  }
  else if(i == 96)
  {
    tempStr = "\n"
    "At the center of the room is the engine. It does not look like"
    "\n"
    "a mechanical device but instead a tank of some sort. When working"
    "\n"
    "correctly trillions of nano-machines operate in congress warping"
    "\n"
    "spacetime and propelling the ship. You can see a huge gash in the"
    "\n"
    "side of the cylinder. Within lightning flashes and liquid metal"
    "\n"
    "shifts."
    "\n";
  }
  else if(i == 97)
  {
    tempStr = "\n"
    "You take a good look at the gash in the engine. Already the"
    "\n"
    "nano-bots are coming out from within the engine to repair the"
    "\n"
    "damage. You see them as a glimmering dust cloud. It might be"
    "\n"
    "best if you left the room. You have always been told that it"
    "\n"
    "will not hurt you to inhale The tiny machines, but you have"
    "\n"
    "never really believed it."
    "\n";
  }
  else if(i == 98)
  {
    tempStr = "\n"
    "You engage the emergency reset panel this is what you see:"
    "\n"
    "################################################################"
    "\n"
    "#     Activate emergency reset?                                #"
    "\n"
    "#     yes                                                      #"
    "\n"
    "#     Are you sure you want to reset ship analytical systems?  #"
    "\n"
    "#     yes                                                      #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     reset initiated                                          #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     resetting ship systems                                   #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     rebooting artificial intelligence                        #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     finished                                                 #"
    "\n"
    "################################################################"
    "\n\n"
    "AI: captain the life support systems are under repair. The ship's"
    "\n"
    "analytical systems have rebooted and are responding correctly to my"
    "\n"
    "quarries. Please use the panel again to start the engine rebuilding"
    "\n"
    "process. Then you will have to reboot the main console to complete"
    "\n"
    "the process."
    "\n";

  }
  else if(i == 99)
  {
    tempStr = "\n"
    "You engage the emergency reset panel this is what you see:"
    "\n"
    "################################################################"
    "\n"
    "#     Activate engine repair procedure?                        #"
    "\n"
    "#     yes                                                      #"
    "\n"
    "#     Are you sure? The engine will be offline until finished  #"
    "\n"
    "#     yes                                                      #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     initializing nano-machine repair sequence                #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     procedure initiated                                      #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     please continue from main console on the bridge          #"
    "\n"
    "#     ...                                                      #"
    "\n"
    "#     waiting...                                               #"
    "\n"
    "################################################################"
    "\n\n"
    "AI: Make your way to the bridge, captain. Once you reboot the main"
    "\n"
    "console and the engines finish the repair procedure. All systems will"
    "\n"
    "be back online."
    "\n";
  }
  else if(i == 100)
  {
    tempStr = "\n"
    "It is too dark to see, use your flashlight!"
    "\n";
  }
  else if(i == 101)
  {
    tempStr = "\n"
    "AI: WARNING!! WARNING!! SHIP INTEGRITY DEGRADING"
    "\n"
    "....'buzzzz...'crackle....."
    "\n\n"
    "You hear a loud explosion somewhere nearby. A rush of air tugs at"
    "\n"
    "you ripping you from where you stand. You twist in the whirlwind"
    "\n"
    "gasping and grabbing at anything nearby, to no avail. You float"
    "\n"
    "into the void of space. You look out into the void, and see"
    "\n"
    "though the field of planetesimals an infinite expanse of stars."
    "\n"
    "You gasp for air to no avail. You cannot breath vacuum. Still"
    "\n"
    "struggling you twist your body and reach for your ship. As your"
    "\n"
    "vision grows dark you see the ship imploding like a crushed can."
    "\n"
    "Vogler is still in there. You could have saved him if only you had"
    "\n"
    "moved quicker. The starry darkness fades to black."
    "\n";
  }
  else if(i == 102)
  {
    tempStr = "\n"
    "AI: WARNING!! WARNING!! SHIP INTEGRITY DEGRADING"
    "\n"
    "....'buzzzz...'crackle....."
    "\n\n"
    "You hear a loud explosion somewhere nearby. A rush of air tugs at"
    "\n"
    "you ripping you from where you stand. You twist in the whirlwind"
    "\n"
    "gasping for anything within reach, to no avail. You float"
    "\n"
    "into the void of space. You look out into the void, and see"
    "\n"
    "though the field of planetesimals an infinite expanse of stars."
    "\n"
    "Still struggling you twist your body and reach for your ship. As"
    "\n"
    "you watch in horror as the ship imploding like a crushed can. Vogler"
    "\n"
    "is still in there. You could have saved him if only you had moved"
    "\n"
    "quicker. You float through the asteroid belt away from the wreckage"
    "\n"
    "of your ship. You float there for what seems like a thousand years."
    "\n"
    "Vogler's patch holds but even so eventually you run low on air. You"
    "\n"
    "begin to hallucinate. You see Vogler and hear the voice of the AI."
    "\n"
    "You float into the blackness speaking to those you have lost. You"
    "\n"
    "are never found."
    "\n";
  }
  else if(i == 103)
  {
    tempStr = "\n"
    "AI: WARNING!! WARNING!! SHIP INTEGRITY DEGRADING"
    "\n"
    "....'buzzzz...'crackle....."
    "\n\n"
    "You hear a loud explosion somewhere nearby. You are launched from"
    "\n"
    "hull. Rubble from the ship surrounds you as you float away. You are"
    "\n"
    "in shock, not sure what to do. You look out into the void, and see"
    "\n"
    "though the field of planetesimals an infinite expanse of stars."
    "\n"
    "Still struggling you twist your body and reach for your ship. As"
    "\n"
    "you watch in horror as the ship imploding like a crushed can. Vogler"
    "\n"
    "is still in there. You could have saved him if only you had moved"
    "\n"
    "quicker. You float through the asteroid belt away from the wreckage"
    "\n"
    "of your ship. You float there for what seems like a thousand years."
    "\n"
    "Vogler's patch holds but even so eventually you run low on air. You"
    "\n"
    "begin to hallucinate. You see Vogler and hear the voice of the AI."
    "\n"
    "You float into the blackness speaking to those you have lost. You"
    "\n"
    "are never found."
    "\n";
  }
  else if(i == 104)
  {
    tempStr = "\n"
    "You were sucked into space without a spacesuit on. You gasp for air"
    "\n"
    "to no avail. As your vision fades you look at your ship. Vogler is"
    "\n"
    "still in there. Perhaps he can find a way to survive, you think as"
    "\n"
    "your vision fades to darkness."
    "\n";
  }
  else if(i == 105)
  {
    tempStr = "\n"
    "AI: Captain your repairs have been successful. The ship will survive."
    "\n"
    "That was a close one. Lets get back to Ceres and get Vogler the help"
    "\n"
    "he needs."
    "\n";
  }
  else if(i == 106)
  {
    tempStr = "\n"
    "To navigate and interact with the ship select from the"
    "\n"
    "menu. You can view your items at any time by selecting the menu"
    "\n"
    "option from the main menu. You can reach this section anytime"
    "\n"
    "from the main menu."
    "\n";
  }

  //return the relevant string
  return tempStr;
}
