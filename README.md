# TF2 Weapon Pick Rates
MySQL Database for Weapon Pick Rates

## Features:

 - Automatically logs the number of times specific weapons were played with by players.
 - Automatically logs the number of teams each class was chosen. (Saved as ItemDefinitionIndex -1)
 - Natives to retrieve the numbers from a cache.
 - Natives to turn off the automatic logging, and to allow you to log weapon/class pick rates manually.
   (Useful for integration into plugins like Custom Weapons 3 or anything that spawns any kind of custom weapons).
 - Ignores bosses from Versus Saxton Hale during automatic logging.
 
## Convars:
Autoexec Config: tf/cfg/sourcemod/ch.wpr.cfg

**cv_wprdata_errorlog** Default: "0" - 1 = log SQL errors | 0 = don't log SQL errors

**cv_wprdata_tablename** Default: "wprdata" - Name of the table to use for this server.
*You might consider changing this if you run more than one server, and want them tracked separately.*
 
## Does not feature:
 - There's nothing made to display the weapon pick rates. If someone submits something, I'll update this.
   Otherwise you'd have to consider making your own, or looking at it through something like phpmyadmin.
   
   I was going to integrate it into my custom weapons plugin and make a menu that only tells me the rates for custom weapons.

## Database Format

    Format for the database is as follows:

    COL: id, slot, name, picks/class

    `id`          is the ItemDefinitionIndex of a weapon
    `slot`        is the weapon slot of the weapon
    `p1`          is the number of times it was chosen for Scout
    `p2`          is the number of times it was chosen for Sniper
    `p3`          is the number of times it was chosen for Soldier
    `p4`          is the number of times it was chosen for Demoman
    `p5`          is the number of times it was chosen for Medic
    `p6`          is the number of times it was chosen for Heavy
    `p7`          is the number of times it was chosen for Pyro
    `p8`          is the number of times it was chosen for Spy
    `p9`          is the number of times it was chosen for Engineer

    if (`id` == -1) then `p` is the number of times that `class` was chosen.

    Stats are only updated when a player dies or the round ends (in which case you chose the weapon, but didn't necessarily die), because that says the player intentionally chose to play with the loadout they have equipped.
    As opposed to choosing what they spawn with, where a player can be immediately switching weapons.

    The idea to do it this way came from Youtube, which tries to discern a person intentionally watching a video, versus just quickly opening a window to try and register a view.

    Stats are also updated when the round ends, during which saving stats based on death is disabled.

    Format for the trie is as follows:

    "id"    "slot"   // Weapon slot that weapon is equipped in.
    "id_1"  "p1"     // Number of times the weapon was picked for that class.
    
## Comments

For logging custom weapon pick rates, I recommend identifying every custom weapon by a negative index lower than -1 to avoid confliction with normal TF2 weapon item definition indexes, and to avoid confliction with index -1, which is used to record the number of times a particular class was picked.
