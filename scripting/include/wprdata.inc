#if defined __wprdata_0_included_
  #endinput
#endif
#define __wprdata_0_included_

enum (<<= 1)
{
    TFSlotBit_None          = (0 << 0),
    TFSlotBit_Primary       = (1 << 0), // 1
    TFSlotBit_Secondary,                // 2
    TFSlotBit_Melee,                    // 4
    TFSlotBit_Grenade,                  // 8
    TFSlotBit_DisguiseKit   = (1 << 3),
    TFSlotBit_Construction  = (1 << 3),
    TFSlotBit_Building,
    TFSlotBit_Watch         = (1 << 4),
    TFSlotBit_Destruction   = (1 << 4),
    TFSlotBit_PDA,
    TFSlotBit_Grapple       = (1 << 5),
    TFSlotBit_Item1,
    TFSlotBit_Item2,
    TFSlotBit_All = 0xFFFFFFFF
}

/*
    Summary:
        Returns the number of times that class has been picked by a player.

        The value returned is from a trie which caches the info from the database.

    Params:
        iClass                          The TF2 class to read from.

    Return:
        Number of times that class has been picked.
*/
native WPR_GetClassPicks(TFClassType:iClass);

/*
    Summary:
        Returns the number of times that weapon has been picked by a player.

        The value returned is from a trie which caches the info from the database.

    Params:
        iItemDefinitionIndex            The weapon's item definition index, as seen in the netprop "m_iItemDefinitionIndex"
        iClass                          The TF2 class to read from. TFClass_Unknown means to read from all classes, if it is an all-class weapon.
        iSlotBits                       Variable to write the TFSlotBits of the weapon to.
                                        This will return a bitfield, as weapons like the Strange Shotgun can equip to multiple slots.

    Return:
        Number of times that weapon has been picked.
*/
native WPR_GetWeaponPicks(iItemDefinitionIndex, TFClassType:iClass = TFClass_Unknown, &iSlotBits = 0);

/*
    Summary:
        Controls whether or not the main plugin will save things to the database manually or not.

        This is for custom game modes like Custom Weapons to prevent custom weapons from being saved to the database.
        These game modes would then need a plugin to use WPR_SetWeaponPicks() to track those manually.

        For example, I index custom weapons with a negative iItemDefinitionIndex to discern them from normal weapons.
        It's up to whatever reads the database to discern what they are.

    Params:
        iClient                         The player to set stat tracking on/off.
                                        You can pass 0 as the client to prevent the plugin from tracking everyone.
                                        This native will not do validation checks on what you pass, do that beforehand.
        bOn                             true = tracking enabled | false = tracking disabled

    Return:
        n/a
*/
native WPR_SetAutoTracking(iClient, bool:bOn);

stock WPR_SetPluginTracking(bool:bOn)
{
    WPR_SetAutoTracking(0, bOn);
}

/*
    Summary:
        Adds +1 weapon pick to the database for that entry.

    Params:
        iItemDefinitionIndex            The weapon's item definition index, as seen in the netprop "m_iItemDefinitionIndex"
                                        Pass -1 to record a TFClass being picked.
        iClass                          The TF2 class to write to.
        iSlot                           The TFWeaponSlot of the weapon. (Not a TFSlotBit)

    Return:
        n/a
*/
native WPR_IncrementWeaponPicks(iItemDefinitionIndex, TFClassType:iClass, iSlot = -1);

public SharedPlugin:__pl_customweaponstf = 
{
    name = "wprdata",
    file = "wprdata.smx",
#if defined REQUIRE_PLUGIN
    required = 1,
#else
    required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public __pl_customweaponstf_SetNTVOptional()
{
    MarkNativeAsOptional("WPR_GetClassPicks");
    MarkNativeAsOptional("WPR_GetWeaponPicks");
    MarkNativeAsOptional("WPR_SetAutoTracking");
    MarkNativeAsOptional("WPR_IncrementWeaponPicks");
}
#endif
