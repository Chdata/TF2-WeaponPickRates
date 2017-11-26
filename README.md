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
