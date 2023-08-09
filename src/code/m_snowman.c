#include "global.h"
#include "m_snowman.h"
#include "m_common_data.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/mSN_check_life.s")
// s32 mSN_check_life(u16 *arg0, s32 arg1)
// {
//     s32 var_v1 = 0;

//     // if ((common_data.unk_1010C == 3) && ((( (*arg0 -40968) % 3) + arg1) < 3))
//     if ((common_data.unk_1010C == 3) && (*arg0 - 40968 < 3))
//     {
//         var_v1 = 1;
//     }

//     return var_v1;
// }

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/mSN_ClearSnowmanData.s")
void mSN_ClearSnowmanData(u16 *arg0, s32 arg1)
{
    bzero(&common_data.save.snowmanData[arg1], sizeof(SnowmanData));
    *arg0 = 0;
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/mSN_ClearSnowman.s")
s32 mSN_ClearSnowman(u16 *arg0)
{
    s32 var_v1 = 0;

    if ((*arg0 >= 0xA008) && (*arg0 < 0xA011))
    {
        mSN_ClearSnowmanData(arg0, (s32) (*arg0 + 0xFFFF5FF8) / 3);
        var_v1 = 1;
    }

    return var_v1;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/mSN_MeltSnowman.s")

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/mSN_get_free_space.s")
s32 mSN_get_free_space(void)
{
    SnowmanData* var_v0 = common_data.save.snowmanData;
    s32  var_v1 = 0;

    for (var_v1 = 0; var_v1 != 3; var_v1++)
    {
        if (var_v0->exists == 0)
        {
            return var_v1;
        }
        var_v0++;
    }

    return -1;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/func_800C8BC4_jp.s")
// u16 *mFI_GetUnitFG(s32, s32, s32);                  /* extern */
// s32 mFI_SetFG_common(s32, s32, s32, s32, s32);        /* extern */
// void mFI_Wpos2DepositOFF(s32, s32, s32);               /* extern */
// void mPB_keep_item(u16);                               /* extern */

// void func_800C8BC4_jp(void *arg0)
// {
//     u16 sp2E;
//     s32 sp28;
//     void *sp20;
//     s32 temp_v0_2;
//     void *temp_v0;

//     temp_v0 = arg0 + 4;
//     sp20 = temp_v0;
//     sp2E = *mFI_GetUnitFG(subroutine_arg0, temp_v0->unk4, temp_v0->unk8);
//     temp_v0_2 = mSN_get_free_space();
//     if (temp_v0_2 != -1)
//     {
//         sp28 = temp_v0_2;
//         mem_copy(&common_data.save.snowmanData[temp_v0_2], arg0, 4);
//         if (sp2E != 0)
//         {
//             mPB_keep_item(sp2E);
//             mFI_Wpos2DepositOFF(subroutine_arg0, sp20->unk4, sp20->unk8);
//         }
//         mFI_SetFG_common(((sp28 * 3) + 0xA008) & 0xFFFF, subroutine_arg1, sp20->unk4, sp20->unk8, 1);
//     }
// }

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/mSN_decide_msg.s")
f32 fqrand();                                       /* extern */

void mSN_decide_msg(void)
{
    common_data.unk_1074C = (s32) (fqrand() * 3.0f);
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/code/m_snowman/mSN_snowman_init.s")
void mSN_snowman_init(void)
{
    bzero(common_data.save.snowmanData, sizeof(SnowmanData[SNOWMAN_SAVE_COUNT]));
    mSN_decide_msg();
}

