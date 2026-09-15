#ifndef JETPAC_INTERNAL_H
#define JETPAC_INTERNAL_H

typedef struct {
    s32 posX;
    s32 posY;
    s32 frame_counter;
    rgba color;
} ExplosionSpriteState;

typedef struct {
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 counter;
} JetpacSpawningInfoSub;

typedef enum JetpacEntityState {
    JETPAC_ENTITY_STATE_DEAD = 0,
    JETPAC_ENTITY_STATE_ALLOCATED = 2,
    JETPAC_ENTITY_STATE_ACTIVE = 3,
    JETPAC_ENTITY_STATE_DYING = 4
} JetpacEntityState;

typedef struct {
    f32 posX;
    f32 posY;
    f32 velX;
    f32 velY;
    rgba color;
    JetpacEntityState entity_state;
    s32 is_facing_left;
    JetpacSpawningInfoSub unk1C;
} JetpacSpatialState;

typedef struct {
    JetpacSpatialState spatial_state;
    s32 is_flying;
    s32 ground_platform_index;
    s32 laser_delay_counter;
    ExplosionSpriteState explosion_sprite;
    u8 pad[0x100]; // lasers[4]
} JetpacPlayerStruct;

typedef struct JetpacPickupStruct JetpacPickupStruct;

typedef struct {
    uSprite *sprite[2];
    f32 posX;
    f32 posY;
    f32 velX;
    f32 velY;
    rgba color;
    s32 unk1C;
    s32 unk20;
    JetpacSpawningInfoSub unk24;
    s32 unk38;
    s32 point_bonus;
    s32 drop_type;
    void (*unk44)(JetpacPickupStruct*);
} JetpacPickupPrimary;

struct JetpacPickupStruct {
    JetpacPickupPrimary primary_info;
    void (*code)(JetpacPickupStruct*, s32);
};

typedef struct {
    s32 level;
    s32 current_score;
    s32 lives;
    s32 rocket_stage;
    s32 unk10;
    JetpacPickupStruct rocket_segments[3];
    JetpacPickupStruct fuel_item;
    s32 bonus_item_counter_limit;
    JetpacPickupStruct next_bonus_item;
} Competitor;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Competitor player[2];
    s32 player_index;
} JetpacGameStruct;

extern JetpacGameStruct D_jetpac_8002EC30;

void func_jetpac_80025368(Competitor *arg0);

#endif /* JETPAC_INTERNAL_H */
