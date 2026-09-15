#include "modding.h"
#include "ultra64.h"
#include "common_structs.h"
#include "jetpac_int.h"

RECOMP_PATCH void func_jetpac_80026A3C(JetpacPlayerStruct *arg0) {
    Competitor *player = &D_jetpac_8002EC30.player[D_jetpac_8002EC30.player_index];
    if (arg0->spatial_state.unk1C.counter < 0xE) {
        arg0->spatial_state.unk1C.counter++;
        return;
    }
    func_jetpac_80025368(player);
}
