#include "global.h"
#include "m_scene.h"

//   mSc_set_bank_status_after
//   mSc_clear_bank_status
//   Object_Exchange_keep_new_Player
//   mSc_secure_exchange_keep_bank 
//   mSc_background_dmacopy_controller 
//   mSc_dmacopy_data_bank 
//   mSc_bank_regist_check 
//   mSc_regist_initial_exchange_bank 
//   mSc_dmacopy_all_exchange_bank_sub
//   mSc_dmacopy_all_exchange_bank 
//   mSc_data_bank_ct 
//   mSc_decide_exchange_bank 
//   Scene_player_select 
//   Scene_ct 
//   Scene_Proc_Player_Ptr 
//   Scene_Proc_Ctrl_Actor_Ptr 
//   Scene_Proc_Actor_Ptr 
//   Scene_Proc_Object_Exchange_Bank_Ptr 
//   Scene_Proc_Door_Data_Ptr 
//   Door_info_ct 
//   Scene_Proc_Sound 
//   set_item_info
//   Scene_Proc_Field_ct 
//   Scene_Proc_MyRoom_ct 
//   Scene_Proc_ArrangeRoom_ct 
//   Scene_Proc_ArrangeFurniture_ct 
//   goto_other_scene 
//   goto_next_scene 
//   goto_emu_game 
//   return_emu_game 

#define OBJECT_BANK_COUNT 73

typedef struct {
    /* 0x000 */ s16 id;
    /* 0x004 */ UNK_PTR unk4; //ram_start
    /* 0x008 */ void* segment;
    /* 0x00C */ uintptr_t vrom;
    /* 0x010 */ size_t size;
    /* 0x014 */ char pad[0x3C];
    /* 0x050 */ s16 unk50;
    /* 0x052 */ char pad2[0x1];
    /* 0x053 */ u8 unk53;
} ObjectBank; // size = 0x54

typedef struct {
    /* 0x0000 */ ObjectBank bank[OBJECT_BANK_COUNT];
    /* 0x17F4 */ s32 numberOfBanks;
    /* 0x17F8 */ s32 unk17F8;
    /* 0x17FC */ s32 unk17FC;
    /* 0x1800 */ s32 unk1800;
    /* 0x1804 */ u32 unk1804;
    /* 0x1808 */ char pad[0x10];
    /* 0x1818 */ s32 unk1818;
} ObjectExchange; // size = 

typedef struct {
    char unk0;
} DoorInfo;

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C59B0_jp.s")
// s32 func_800C59B0_jp(ObjectExchange *objectExchange)
// {
//     ObjectBank *bank;
//     s32 ret;
//     s32 bankIndex;
//     s32 new_var;
//     int new_var2;
//     ret = -1;
//     new_var = OBJECT_BANK_COUNT;
//     new_var2 = objectExchange->unk17FC;
//     if (1)
//     {
//         bankIndex = new_var2;
//         bank = &objectExchange->bank[bankIndex];
//         for (; bankIndex < new_var;)
//         {
//             if (bank->id == 0)
//             {
//                 ret = bankIndex;
//                 break;
//             }
//             bankIndex++;
//             bank++;
//         }
//     }
//   return ret;
// }

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5A08_jp.s")


s32 func_800C59B0_jp(s32);                          /* extern */
s32 func_800C5A08_jp(s32);                          /* extern */

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5A60_jp.s")
s32 func_800C5A60_jp(s32 arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800C59B0_jp(arg0);
    var_v1 = temp_v0;
    if (temp_v0 == -1) {
        var_v1 = func_800C5A08_jp(arg0);
    }
    return var_v1;
}

// s32 func_800C5AA0_jp(ObjectBank* objectBank, ObjectExchange* objectExchange, s16 arg2);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5AA0_jp.s")

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5B30_jp.s")
void func_800C5B30_jp(ObjectBank* objectBank) {
    objectBank->id = (objectBank->id >= 0) ? objectBank->id : -objectBank->id;
    objectBank->unk53 = 0;
    objectBank->unk4 = objectBank->segment;
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5B5C_jp.s")
//mSc_clear_bank_status
void func_800C5B5C_jp(ObjectBank *objectBank)
{
    objectBank->id = 0;
    objectBank->size = 0;
    objectBank->segment = 0;
    objectBank->unk4 = 0;
}

void func_80026E10_jp(void*, uintptr_t, size_t, const char *file, s32);         /* extern */
s32 func_800C5AA0_jp(void*, void*, s16);            /* extern */

//objectspawn?
// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5B74_jp.s")
s32 func_800C5B74_jp(ObjectExchange* objectExchange, s16 id) {
    s32 ret = 0;

    if (objectExchange->numberOfBanks < OBJECT_BANK_COUNT) {
        ObjectBank* objectBank = &objectExchange->bank[objectExchange->numberOfBanks];

        if (func_800C5AA0_jp(objectBank, objectExchange, id) == 1)
        {
            //DmaMgr_RequestSyncDebug
            func_80026E10_jp(objectBank->segment, objectBank->vrom, objectBank->size, "../m_scene.c", 317);
            func_800C5B30_jp(objectBank);
            objectBank->unk50 = 1;
            objectExchange->numberOfBanks++;
            ret = 1;
        }
    }
    return ret;
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5C30_jp.s")
void func_800B1784_jp(s32);                            /* extern */
void func_800B190C_jp(s32);                            /* extern */
void func_800B1960_jp(s32, s32, s32);                      /* extern */
void func_800B19C4_jp(s32, s32, s32);                      /* extern */
void func_800B1A28_jp(s32);                            /* extern */
void func_800B1A60_jp(s32);                            /* extern */

//Object_Exchange_keep_new_Player
void func_800C5C30_jp(s32 arg0)
{
    func_800B1784_jp(arg0);
    func_800B190C_jp(arg0);
    func_800B190C_jp(arg0);
    func_800B1960_jp(arg0, 0, 0);
    func_800B19C4_jp(arg0, 0, 0);
    func_800B1960_jp(arg0, 1, 2);
    func_800B19C4_jp(arg0, 1, 2);
    func_800B1A28_jp(arg0);
    func_800B1A28_jp(arg0);
    func_800B1A60_jp(arg0);
}


#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5CC4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5D68_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5E10_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5EA0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5F0C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C5F64_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/mSc_bank_regist_check.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6144_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/mSc_regist_initial_exchange_bank.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C62C4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C639C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C65E4_jp.s")

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6678_jp.s")
void func_800C6678_jp(ObjectExchange *objectExchange)
{
    objectExchange->unk17F8 = objectExchange->numberOfBanks;
    objectExchange->unk1818 = objectExchange->unk1800;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6690_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C68C8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6960_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C69F4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6A28_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6A5C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6A90_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6AC4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6AD0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6AE0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6B50_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6BB0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6BD4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6BF8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6C10_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6D14_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6D5C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_scene/func_800C6E14_jp.s")
