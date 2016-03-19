//--------------------------------------------------------------------
// �ļ���:      LogDefine.h
// ��  ��:
// ˵  ��:
// ��������:    2013��3��18��
// ������:
// ά����:      ����
// ��Ȩ����:    ������ţ�������޹�˾
//--------------------------------------------------------------------

#ifndef __LogDefine_h__
#define __LogDefine_h__

// add by hutian 2013-4-26
//�����ඨ�� \Server\Cons\Res\logic_class.xml
//pKernel->CreateContainer(player, ...) ������������ϵ�����Ϊ�������
//
//��������������ϵ���Ʒ�����¼log��
//��Ʒ����ʱ�����Ʒ��������Ϊ��������������¼log��
//���룬�Ƴ����ƶ������������Ʒ���¼log
//�޸������������Ʒ Amount�ĵط����¼log
//�Ų�lua
//
//ԭ������Ʒ(item)����������ʹ������� pKernel->Place() pKernel->PlacePos() pKernel->PlaceTo() pKernel->Exchange() pKernel->ChangePos()
//����ʹ��ContainerBaseModule ��غ�����
//ʹ��load_from_string  load_from_xml ʱע�����������Ƿ�Ϊ����������Ƿ�Ҫ��¼log
//
//pKernel->ClearChild(container)ʱ�����Ϊ���������������¼log��
//pKernel->CreateClone(container, ...)ʱ�����Ϊ���������������¼log��
//
//����������Ҫ������֮��������ʵ����
//
//��Ʒ�ƶ�ʧ�ܺ�һ��Ҫ���٣��������ɶ���й©
//����ʱʹ�� pKernel->DestroySelf(obj)������ pKernel->Destroy(scene,obj)��Ч�ʸ���
//
//"ToolBox" "DepotBox" "EquipBox" "AddToolBox" "AddDepotBox" Ϊ�������
//
//�������������뵽���������log����Ϊ��һ����Ʒ��
//��֮Ϊ���ʧȥ��Ʒ��
//����log����Ϊ��Ʒת�����͡�


//$@ 1 = ��ɫ��Ʒ��־
enum ITEM_LOG_TYPE
{
    //��һ����Ʒ 10000-19999
    ITEM_LOG_TYPE_MIN                           = 10000, //��Ʒ��־��Сֵ

    IITE_LOG_TYPE_GET_ITEM_MIN                  = 10000, //$ 10000 = �����Ʒ��־������Сֵ

    ITEM_LOG_TYPE_BUY_FROM_NPC                  = 10001, //$ 10001 = ��Ҵ�NPC������
    ITEM_LOG_TYPE_BUY_FROM_CHARGE               = 10002, //$ 10002 = ��ȯ����Ʒ��̳���Ʒ
    ITEM_LOG_TYPE_GET_DAILY_PRIZE               = 10003, //$ 10003 = ��ȡÿ�ս���
    ITEM_LOG_TYPE_GET_ACTIVITY_PRIZE            = 10004, //$ 10004 = ��ȡ�����
    ITEM_LOG_TYPE_FRAGMENT_COMPOSE              = 10005, //$ 10005 = ��ȡ��Ƭ�ϳ���Ʒ | "Get From Fragment"
    ITEM_LOG_TYPE_GET_JOB_FORMULA               = 10006, //$ 10006 = ��ȡ�õ��䷽��Ʒ |"Get From Formula"
    ITEM_LOG_TYPE_QUEST_AWARD_ITEM              = 10007, //$ 10007 = ��ȡ��������Ʒ |"Get Quest Award"
    ITEM_LOG_TYPE_SKILL_EVENT_GET_ITEM          = 10008, //$ 10008 = �����¼��õ����� |"Get From SkillEvent"
    ITEM_LOG_TYPE_BEHAVIOR_GET_ITEM             = 10009, //$ 10009 = ��������Ϊ��õ���Ʒ |"Get From Behavior"
    //ITEM_LOG_TYPE_GET_MERGE                     = 10010, //$ 10010 = ���ںϲ����߶�����
    //ITEM_LOG_TYPE_SPLIT_ITEM_MOVE               = 10011, //$ 10011 = �����Ʒ��ɵ��ƶ� |"Get From Split"
    ITEM_LOG_TYPE_CLONE_PASS_REWARD             = 10012, //$ 10012 = ����ͨ�ؽ��� |"Clone Pass Prize"
    ITEM_LOG_TYPE_OPEN_TREASURE_BOX_GET_ITEM    = 10013, //$ 10013 = ��������ߵõ����� |"Get From TreasureBox"
    ITEM_LOG_TYPE_EW_RES_FIGHT_ITEM             = 10014, //$ 10014 = ��������Դս���� |"Get EW Res Fight Prize"
    ITEM_LOG_TYPE_LIFEJOB_DECOMPOSE             = 10015, //$ 10015 = ��ְ�ֽ� |"Get From Job Decompose"
    ITEM_LOG_TYPE_GM_CREATE                     = 10016, //$ 10016 = GM��� |"Get From GM"
    ITEM_LOG_TYPE_PICK_DROP_QUEST_ITEM          = 10017, //$ 10017 = ���������� |"Get Quest Requirement"
    ITEM_LOG_TYPE_NEW_USER_LEAD_PRIZE_ITEM      = 10018, //$ 10018 = ���������õ�����Ʒ |"Get Freshman Item"
    ITEM_LOG_TYPE_VIP_PACKET                    = 10019, //$ 10019 = ���VIP��� |"Get VIP Package"
    ITEM_LOG_TYPE_PVP_QUEST_AWARD_ADD_ITEM      = 10020, //$ 10020 = ���PVP������ |"Get PVP Award"
    ITEM_LOG_TYPE_FROM_MY_CHARGE_GOLD           = 10021, //$ 10021 = ��ҹ���Ʒ��̳���Ʒ
    ITEM_LOG_TYPE_GET_BATTLE_PRIZE_ITEM         = 10022, //$ 10022 = ս������ |"Get Battlewar Prize"
    ITEM_LOG_TYPE_REVERT_ROLE_ITEM              = 10023, //$ 10023 = ���ý�ɫ�ӵ���Ʒ |"Revert Role Item"
    ITEM_LOG_TYPE_INIT_NEW_ROLE_EQUIP           = 10024, //$ 10024 = ��ʼ������װ�� ������ɫʱ��װ�� |"Create Role Equip"
    ITEM_LOG_TYPE_NEW_ROLE_LEAD_ADD_EQUIP       = 10025, //$ 10025 = �������ָ���װ�� |"New Role Clone Equip"
    ITEM_LOG_TYPE_CAPTURE_PET_ITEM              = 10026, //$ 10026 = ����ĳ��� |"Get Capture Pet"
    ITEM_LOG_TYPE_COMPOUND_JEWEL_GROW           = 10027, //$ 10027 = ��ʯ�ϳ� |"Create Item Jewel"
    ITEM_LOG_TYPE_GET_TASK_TOKEN                = 10028, //$ 10028 = ������ |"GetTaskToken"
    ITEM_LOG_TYPE_MOVE_ITEM_GAIN                = 10029, //$ 10029 = �ƶ���Ʒ�����Ʒ
    ITEM_LOG_TYPE_PICK_UP_ITEM                  = 10030, //$ 10030 = ʰȡ������Ʒ
    ITEM_LOG_TYPE_EXCHANGE_ITEM_GAIN            = 10031, //$ 10031 = ���׻����Ʒ
    ITEM_LOG_TYPE_POST_GET                      = 10032, //$ 10032 = ͨ���ʼ����
    //ITEM_LOG_TYPE_GUILD_DEPOT_PUTIN             = 10033, //���� �ֿ� ��Ʒ���
    ITEM_LOG_TYPE_PICK_DROP_PVP_QUEST_ITEM      = 10034, //$ 10034 = ���PVP����������
    ITEM_LOG_TYPE_NEW_ROLE_LEAD_RECOVER_EQUIP   = 10035, //$ 10035 = �ָ�����װ��
    //ITEM_LOG_TYPE_PUT_ITEM_TO_BANK              = 10036, //����Ʒ������
    ITEM_LOG_TYPE_GET_ITEM_FROM_RECLAIM_BOX     = 10037, //$ 10037 = ȡ����Ʒ�ӻع���
    ITEM_LOG_TYPE_COMPOUND_ROLL_BACK            = 10038, //$ 10038 = װ���ϳɲ��������Իع�
    ITEM_LOG_TYPE_REMOVE_INSCRIPTION_ITEM       = 10039, //$ 10039 = ������̲����Ʒ
    ITEM_LOG_TYPE_FROM_MY_CHARGE_BOX            = 10040, //$ 10040 = ��Ҵ��ҵ���Ʒ����ȡ
    ITEM_LOG_TYPE_GET_FROM_CHARGE               = 10041, //$ 10041 = ��Ҵӻ�ȡ��¼�й���
    ITEM_LOG_TYPE_BACK_STAGE_GET                = 10042, //$ 10042 = ��ҴӺ�̨���͵��ʼ�����ȡ��Ʒ
    ITEM_LOG_TYPE_DEL_GET_LING_QI_ITEM          = 10043, //$ 10043 = ��������սʿ��������
    ITEM_LOG_TYPE_NETBAR_ADD_ITEM               = 10044, //$ 10044 = ��ţ������Ȩ��ӵ���

    IITE_LOG_TYPE_GET_ITEM_MAX                  = 19999, //$ 19999 = �����Ʒ��־�������ֵ

    //ITEM_LOG_TYPE_DROP_QUEST_ITEM               = 10008, // �����õ���
    //ITEM_LOG_TYPE_SPLIT_INC                     = 10012, // ������һ����Ʒ��������ӵ���Ʒ
    //ITEM_LOG_TYPE_REMOVE_JEWEL                  = 10013, // �����ʯ
    //ITEM_LOG_TYPE_FULL_ENERGY_ADD_ITEM          = 10014, // ���ܵõ�����Ʒ
    //ITEM_LOG_TYPE_COMPOUND_BLACK_GOLD           = 10015, // ����ڽ�ϳɲ���
    //ITEM_LOG_TYPE_EMPTY_ENERGY_ITEM             = 10016, // �ſճ��ܵõ�����Ʒ
    //ITEM_LOG_TYPE_ADD_ITEM_FOR_BEKILLED         = 10028, // ��ұ�ɱ�����ĵ���
    //ITEM_LOG_TYPE_DROP_PVP_QUEST_ITEM           = 10028, // ����PVP������Ʒ
    //ITEM_LOG_TYPE_CREATE_COMPLEX_DROP_ITEM      = 10030, // ���ӵ�����Ʒ
    //ITEM_LOG_TYPE_CREATE_SIMPLE_DROP_ITEM       = 10031, // �򵥵�����Ʒ
    //ITEM_LOG_TYPE_EW_BEG_FAIL_RETURN_MAT        = 10035, // �������ؾ߿�������ʧ�ܷ������˲���


    //���ʧȥ��Ʒ 20000-27999
    IITE_LOG_TYPE_LOSE_ITEM_MIN                 = 20000, //$ 20000 = ʧȥ��Ʒ��־������Сֵ

    ITEM_LOG_TYPE_DELETE                        = 20001, //$ 20001 = �����ɾ�� | "Lose Because Delete"
    ITEM_LOG_TYPE_CHUCK                         = 20002, //$ 20002 = ����Ҷ��� | "Lose Because Chuck"
    ITEM_LOG_TYPE_PUT_ITEM_TO_RECLAIM_BOX       = 20003, //$ 20003 = ����Ʒ���ع���  | "Sell To BaseShop"
    ITEM_LOG_TYPE_BACKSTAGE_MODIFY              = 20004, //$ 20004 = ��̨�༭�������ʱɾ������ | "Lose Because BackStage"
    ITEM_LOG_TYPE_DEL_QUEST_DEAD                = 20005, //$ 20005 = ��ɱ����������� | "Lose Because Dead"
    ITEM_LOG_TYPE_DECOMPOSE_DEL                 = 20006, //$ 20006 = �ֽ�װ�� | "Lose Because DeCompos"
    ITEM_LOG_TYPE_INHERIT_ENHANCE_CONSUME       = 20007, //$ 20007 = ǿ���̳����� | "Lose Because Enhance"
    ITEM_LOG_TYPE_FRAGMENT_COMPOSE_CONSUME      = 20008, //$ 20008 = ��Ƭ�ϳ����� | "Lose Because Compose"
    ITEM_LOG_TYPE_SAVE_STAR_SOUL_CONSUME        = 20009, //$ 20009 = ����ĳ�Ǽ�������� | "Lose Because StarSoul"
    ITEM_LOG_TYPE_MAC_RESET_CONSUME             = 20010, //$ 20010 = �����ʼ������ | "Lose Because MachineReset"
    ITEM_LOG_TYPE_EW_BEGIN_CARRIER_PRODUCE      = 20011, //$ 20011 = �����������ؾ�������˲������� | "EW Carrier Produce"
    ITEM_LOG_TYPE_RELIVE_CONSUME_ITEM           = 20012, //$ 20012 = �����������ĵ��� | "Lose Because Relive"
    ITEM_LOG_TYPE_ADD_LING_QI_ITEM_CONSUME      = 20013, //$ 20013 = ����սʿ�������� | "Lose Because Weapon Absorb"
    ITEM_LOG_TYPE_DEL_LING_QI_ITEM_CONSUME      = 20014, //$ 20014 = ����սʿ�������� | "Lose Because Weapon Recast"
    ITEM_LOG_TYPE_GIVE_UP_PVP_SPY_DEL_ITEM      = 20015, //$ 20015 = ����PVP��̽����ɾ������Ʒ | "Lose Because Giveup Spy"
    ITEM_LOG_TYPE_PVP_TRANSPORT_CONSUME_ITEM    = 20016, //$ 20016 = ����PVP��̽����ɾ������Ʒ | "Lose Because PVP Trans"
    ITEM_LOG_TYPE_PVP_SUBMIT_RECOVER_ITEM       = 20017, //$ 20017 = �ύPVP����ɾ������Ʒ | "Submit Task: "
    ITEM_LOG_TYPE_PVP_GIVEUP_RECOVER_ITEM       = 20018, //$ 20018 = ����PVP����ɾ������Ʒ | "Giveup Task: "
    ITEM_LOG_TYPE_PVP_DOFAIL_RECOVER_ITEM       = 20019, //$ 20019 = PVP����ʧ��ɾ������Ʒ | "Fail Task: "
    ITEM_LOG_TYPE_PVP_REFRESH_RECOVER_ITEM      = 20020, //$ 20020 = PVP����ˢ��ɾ������Ʒ | "Refresh Task: "
    ITEM_LOG_TYPE_SKILL_EVENT_CONSUME_ITEM      = 20021, //$ 20021 = �����¼����ĵ���Ʒ | "Lose Becaue SkillEvent"
    ITEM_LOG_TYPE_SKILL_CONSUME_ITEM            = 20022, //$ 20022 = �������ĵ���Ʒ | "Lose Because SkillConsume"
    ITEM_LOG_TYPE_UPGRADE_SKILL_CONSUME_ITEM    = 20023, //$ 20023 = �����������ĵ���Ʒ | "Lose Because SkillUpgrade"
    ITEM_LOG_TYPE_BEHAVIOR_DESTROY_ITEM         = 20024, //$ 20024 = ��������Ϊ���ĵ���Ʒ | "Lose Because Behavior"
    ITEM_LOG_TYPE_CONTRIBUTE_MAT_TO_EW          = 20025, //$ 20025 = ������������ | "Contribute To EW"
    ITEM_LOG_TYPE_PAY_ITEM_CONSUME              = 20026, //$ 20026 = �̵�������Ʒ֧������Ʒ | "Lose Because Pay"
    //ITEM_LOG_TYPE_COMPOSE_DEL                   = 20027, //װ���ϳ� | "Lose Because EquipCom"
    ITEM_LOG_TYPE_SUMMON_TEAMMATE_COST          = 20028, //$ 20028 = �ٻ��������� | "Lose Because Summon"
    ITEM_LOG_TYPE_NPC_SPRING_DEL_ITEM           = 20029, //$ 20029 = NPC����ʱɾ����Ʒ | "Lose Because NpcSpring"
    ITEM_LOG_TYPE_LAVE                          = 20030, //$ 20030 = ����װ��ϴ����ɵ����� | "Lose Because ItemLave"
    ITEM_LOG_TYPE_STRENG_EQUIP_MATERIAL         = 20031, //$ 20031 = װ��ǿ�����ĵĲ��� | "Lose Because Strengthen"
    ITEM_LOG_TYPE_JOB_FORMULA_MATERIAL          = 20032, //$ 20032 = ְҵ�䷽���ĵĲ��� | "Lose Because Formula"
    ITEM_LOG_TYPE_DEL_QUEST_CRITERIA_ITEM       = 20033, //$ 20033 = ������ɾ������ | "Lose Because QuestCriteria"
    ITEM_LOG_TYPE_DEL_QUEST_ITEM                = 20034, //$ 20034 = �ύ����ɾ��������� | "Lose Because Submit"
    ITEM_LOG_TYPE_PVP_QUEST_AWARD_DEL_ITEM      = 20035, //$ 20035 = PVP������ɾ������ | "Lose Because PVP Award"
    ITEM_LOG_TYPE_AH_CONSIGN                    = 20036, //$ 20036 = �����м���ɾ������Ʒ | "AH Consign"
    ITEM_LOG_TYPE_DEL_TRANSPORT_ITEM            = 20037, //$ 20037 = ����ɾ������ | "Lose Because Transmit"
    ITEM_LOG_TYPE_TEAM_TRANSMIT_CONSUME_ITEM    = 20038, //$ 20038 = ���鴫�����ĵ���Ʒ | "Lose Because TeamTrans"
    ITEM_LOG_TYPE_REDUCE_ARREST_CONSUME_ITEM    = 20039, //$ 20039 = ����ͨ�����ĵ���Ʒ | "Lose Because Arrest"
    ITEM_LOG_TYPE_ENCHASE_DESTROY_JEWEL         = 20040, //$ 20040 = ��Ƕ�۳��ı�ʯ | "Lose Because DestroyJewel"
    ITEM_LOG_TYPE_LEARN_FORMULA_CONSUME_ITEM    = 20041, //$ 20041 = ѧϰְҵ�䷽������Ʒ | "Lose Because Learn Formula"
    ITEM_LOG_TYPE_TRANSTODESIGNATE_CONSUME_ITEM = 20042, //$ 20042 = ����������Ʒ | "Lose Because Designate"
    ITEM_LOG_TYPE_TRANSTOGUILD_CONSUME_ITEM     = 20043, //$ 20043 = �����ټ�������Ʒ | "Lose Because GuildCall"
    ITEM_LOG_TYPE_TRANSTOFRIEND_CONSUME_ITEM    = 20044, //$ 20044 = �����ټ�������Ʒ | "Lose Because FriendCall"
    ITEM_LOG_TYPE_TRANSTOTEAM_CONSUME_ITEM      = 20045, //$ 20045 = �����ټ�������Ʒ | "Lose Because TeamCall"
    ITEM_LOG_TYPE_COMPOUND_DESTROY_JEWEL        = 20046, //$ 20046 = ��ʯ�ϳ�ɾ���ı�ʯ | "Del Jewel" "Create Jewel Fail"
    ITEM_LOG_TYPE_USE_SKILL_CONSUME_ITEM        = 20047, //$ 20047 = ʹ�ü���������Ʒ | "Use Skill: "
    ITEM_LOG_TYPE_TRIGGERTASK_CONSUME_ITEM      = 20048, //$ 20048 = ���񴥷�������Ʒ | "Lose Because TriggerTask"
    ITEM_LOG_TYPE_USER_EXP_ITEM                 = 20049, //$ 20049 = ʹ�þ��鵤 | "Use Exp Item"
    ITEM_LOG_TYPE_USE_CRYSTAL_ITEM              = 20050, //$ 20050 = ʹ���������� | "Use Crystal Item"
    ITEN_LOG_TYPE_USE_VIP_ITEM                  = 20051, //$ 20051 = ʹ��VIP���� | "User Vip Item"
    //ITEM_LOG_TYPE_SPLIT_DEC                     = 20052, //������Ʒ����ּ��ٵ���Ʒ | "Lose Because Split"
    ITEM_LOG_TYPE_GM_DEL                        = 20053, //$ 20053 = GMɾ�� | "GM Remove" "GM Clear"
    ITEM_LOG_TYPE_RETURN_TASK_TOKEN             = 20054, //$ 20054 = �������ʧ�ܷ����Ѿ���õ�����
    //ITEM_LOG_TYPE_LOSE_MERGE                    = 20055, //���ںϲ����߶�����
    ITEM_LOG_TYPE_INVALID                       = 20056, //$ 20056 = ITEM��������
    ITEM_LOG_TYPE_MOVE_ITEM_LOSE                = 20057, //$ 20057 = �ƶ���Ʒʧȥ��Ʒ
    ITEM_LOG_TYPE_EXCHANGE_ITEM_LOSE            = 20058, //$ 20058 = ����ʧȥ��Ʒ
    ITEM_LOG_TYPE_ADD_RIDE_POINT_LOSE           = 20059, //$ 20059 = ʹ������������� | "User add ride point Item"
    //ITEM_LOG_TYPE_GUILD_DEPOT_PUTOUT            = 20060, //���� �ֿ� ��Ʒȡ��
    ITEM_LOG_TYPE_NEW_ROLE_LEAD_SAVE_EQUIP      = 20061, //$ 20061 = ��������װ��
    ITEM_LOG_TYPE_INSCRIPTION_ITEM              = 20062, //$ 20062 = ���������Ʒ
    ITEM_LOG_TYPE_ADD_GET_LING_QI_ITEM          = 20063, //$ 20063 = ��õ���սʿ��������
    //ITEM_LOG_TYPE_DEL_GET_LING_QI_ITEM          = 20064, //��������սʿ��������
    ILL_WEB_SELL_ITEM                           = 20065, //$ 20065 = ���߷ŵ����½���ƽ̨
    ITEM_LOG_TYPE_ADDHOLE                       = 20066, //$ 20066 = װ�����
    ITEM_LOG_TYPE_POST_LOSE                     = 20067, //$ 20067 = �����ʼ�ʧȥ��Ʒ
    ITEM_LOG_TYPE_PUT_ITEM_TO_BANK              = 20068, //$ 20068 = ����Ʒ������
    ITEM_LOG_TYPE_GUILD_DEPOT_PUTIN             = 20069, //$ 20069 = ���� �ֿ� ��Ʒ���
    ITEM_LOG_TYPE_ENHANCE_ITEM                  = 20070, //$ 20070 = ��ü���ר����Ʒ
    ITEM_LOG_TYPE_ENERGY_LOSE                   = 20071, //$ 20071 = ���ܺ�ɾ������ITEM
    ITEM_LOG_TYPE_EXPIRED_TIME_LOSE             = 20072, //$ 20072 = ����ָ�����ڣ�ɾ��ITEM
    ITEM_LOG_TYPE_BAG_SELL_SUNDRIES             = 20073, //$ 20073 = ������������ɾ��ITEM

    IITE_LOG_TYPE_LOSE_ITEM_MAX                 = 27999, //$ 27999 = ʧȥ��Ʒ��־�������ֵ

    //ITEM_LOG_TYPE_SELL_TO_NPC                   = 20001, // ��ҳ��۸�NPC
    //ITEM_LOG_TYPE_BLACK_MARKET_CONSIGN          = 20025, // ���м���ɾ������Ʒ
    //ITEM_LOG_TYPE_CLEAR_RECLAIM                 = 20027, // ��ջع�����Ʒ
    //ITEM_LOG_TYPE_ARENA_QUEUE_SUCCESS           = 20028, // �������Ŷӳɹ�ɾ����Ʒ
    //ITEM_LOG_TYPE_NEW_ROLE_LEAD_DEL_EQUIP       = 20036, // ��������װ��
    //ITEM_LOG_TYPE_DEL_EMPTY_ENERGY_ITEM         = 20046, // ɾ���ճ�����Ʒ L"Use Skill: "
    //ITEM_LOG_TYPE_FULL_ENERGY_DEL_ITEM          = 20051, // ����ɾ������Ʒ
    //ITEM_LOG_TYPE_TRUMPET_DEL_ITEM              = 20053, // ������������
    //ITEM_LOG_TYPE_OPEN_TREASURE_BOX             = 20003, // ���������Ҫɾ��ԭ����
    //ITEM_LOG_TYPE_SUBMIT_TOKEN                  = 20005, // �ύ������������
    //ITEM_LOG_TYPE_EQUIP_COMPOUND                = 20006, // �ύ������������
    //ITEM_LOG_TYPE_ENERGY_WELL_MATERIAL          = 20030, // �������������ĵĲ���
    //ITEM_LOG_TYPE_CONTRIBUTE_TO_NPC_ORG         = 20011, // ���׸�NPC��֯��Ʒ

    //��Ʒ��ת�� 28000-29999
    IITE_LOG_TYPE_SHIFT_ITEM_MIN                = 28000, //$ 28000 = ת����Ʒ��־������Сֵ

    ITEM_LOG_TYPE_GUILD_DEPOT_CREATE            = 28001, //$ 28001 = ����ֿ���Ʒ����
    ITEM_LOG_TYPE_GET_ITEM_FROM_WEAKBOX         = 28002, //$ 28002 = ����������ȡ����Ʒ
    ITEM_LOG_TYPE_MOVE_ITEM                     = 28003, //$ 28003 = �ƶ���Ʒ��������
    ITEM_LOG_TYPE_SWAP_ITEM                     = 28004, //$ 28004 = ������Ʒ
    ITEM_LOG_TYPE_TRANS_JOB_MOVE_EQUIP          = 28005, //$ 28005 = תְ�ƶ������ϵ��·�
    ITEM_LOG_TYPE_ARRANGE_ITEM                  = 28006, //$ 28006 = ����
    ITEM_LOG_TYPE_BACK_STAGE_POST               = 28007, //$ 28007 = ͨ����̨�ʼ�������Ʒ
    ITEM_LOG_TYPE_BIND                          = 28008, //$ 28008 = ��
    ITEM_LOG_TYPE_GET_MERGE                     = 28009, //$ 28009 = ���ںϲ����߶�����
    ITEM_LOG_TYPE_SPLIT_ITEM_MOVE               = 28010, //$ 28010 = �����Ʒ��ɵ��ƶ� |"Get From Split"
    ITEM_LOG_TYPE_COMPOSE_DEL                   = 28011, //$ 28011 = װ���ϳ� | "Lose Because EquipCom"
    ITEM_LOG_TYPE_SPLIT_DEC                     = 28012, //$ 28012 = ������Ʒ����ּ��ٵ���Ʒ | "Lose Because Split"
    ITEM_LOG_TYPE_LOSE_MERGE                    = 28013, //$ 28013 = ���ںϲ����߶�����
    ITEM_LOG_TYPE_GUILD_DEPOT_PUTOUT            = 28014, //$ 28014 = ���� �ֿ� ��Ʒȡ��
    ITEM_LOG_TYPE_RECLAIM_SORT                  = 28015, //$ 28015 = �ع�����Ʒ������

    IITE_LOG_TYPE_SHIFT_ITEM_MAX                = 29998, //$ 29998 = ת����Ʒ��־�������ֵ
    ITEM_LOG_TYPE_MAX                           = 29999, //��Ʒ��־���ֵ

    //ITEM_LOG_TYPE_ORIGIN_PRIZE                  = 30005, //ͨ����ݻ�ý���
    //ITEM_LOG_TYPE_DEPOT_PUTIN                   = 20001, //�ֿ� ��Ʒ���
    //ITEM_LOG_TYPE_DEPOT_PUTOUT                  = 20002, //�ֿ� ��Ʒȡ��
    //ITEM_LOG_TYPE_ADDMAGIC                      = 25002, //װ����ħ
    //ITEM_LOG_TYPE_ENCHASE                       = 25003, //��Ƕ
    //ITEM_LOG_TYPE_UNENCHASE                     = 25004, //��Ƕ���
};

//$@ 2  = ��ɫ�ʽ���־
// �����ʽ����־���� 30000-36999
enum CAPITAL_INC_LOGTYPE
{
    CAPITAL_LOG_INC_MINTYPE         = 30000,    //$ 30000 =  ����ʽ���־������Сֵ

    // �ʽ���ԴΪϵͳ               30000-34999
    CLI_FROM_SYS_MIN                = 30000,    //

    CLI_BACKSTAGE                   = 30001,    //$ 30001 = ��̨����������ʽ�
    CLI_PICKUP_CAPITAL              = 30002,    //$ 30002 = ʰȡ������ʽ�
    CLI_QUERT_REWARD                = 30003,    //$ 30003 = ������
    CLI_EVENT_REWARD                = 30004,    //$ 30004 = �¼�����
    CLI_CLONE_REWARD                = 30005,    //$ 30005 = ����ͨ�ؽ���
    CLI_GM_NOLIMIT                  = 30006,    //$ 30006 = gm����(����ÿ���޶�����)
    CLI_PVP_REWARD                  = 30007,    //$ 30007 = PVP������,��̽����Ϯ����Ϯ��Ѻ�ڣ���ɱ����
    CLI_ARENA_REWARD                = 30008,    //$ 30008 = ���������㽱��
    CLI_VITALITY_REWARD             = 30009,    //$ 30009 = ��Ծ���ճ�������ÿ��������Ծ�Ƚ�����ÿ�������Ƽ���������
    CLI_SYS_MAIL                    = 30010,    //$ 30010 = ϵͳ�ʼ� ��ȡ�ʽ�
    CLI_REPAY                       = 30011,    //$ 30011 = ��Ӫ����
    CLI_VIP_GIFT                    = 30012,    //$ 30012 = VIP��������Ľ�Ǯ
    CLI_ENERGY_PAY                  = 30013,    //$ 30013 = �����������ʷ���
    CLI_BUY_CAPITAL                 = 30014,    //$ 30014 = �����һ��õ��ʽ�
    CLI_GUILDMANORFIGHT_REWARD      = 30015,    //$ 30015 = �������ս����
    CLI_SHOPPINT                    = 30016,    //$ 30016 = ���������̵����ʽ�
    CLI_BATTLEWAR                   = 30017,    //$ 30017 = ս��
    CLI_OFFLINE                     = 30018,    //$ 30018 = ����
    CLI_AWARD                       = 30019,    //$ 30019 = �����
    CLI_EVERYDAYGUIDE               = 30020,    //$ 30020 = ��Ϸ����
    CLI_GM                          = 30021,    //$ 30021 = gm����
    CLI_BLACKMARKET_BILL            = 30022,    //$ 30022 = �����˵�
    CLI_EXCHANGE_CASH               = 30023,    //$ 30023 = ��ȯ�һ��ڽ� ���Ӻڽ�
    CLI_EXCHANGE_GOLD               = 30024,    //$ 30024 = �ڽ�һ���� ���ӽ��
    CLI_EWRESFIGHT                  = 30025,    //$ 30025 = ������ս��
    CLI_ARENA                       = 30026,    //$ 30026 = ������
    CLI_GET_DEPOT_CAPIAL            = 30027,    //$ 30027 = �Ӳֿ�ȡǮ
    CLI_USE_ITEM                    = 30028,    //$ 30028 = ʹ�õ�������
    CLI_FAILURE_BACK                = 30029,    //$ 30029 = ��������߹���ʧ�ܶ��˻��ʽ�
    CLI_EW_CONCONTRIBUTE            = 30030,    //$ 30030 = ���Ϊ���������������ؾߵĲ��϶���õĹ��׵�
    CLI_WEBEXCHANGE_CHARGE          = 30031,    //$ 30031 = ���½���������
    CLI_CHARGE_INC                  = 30032,    //$ 30032 = ���򵵰��л�ȡ
    CLI_PICK_FROM_MAIL              = 30033,    //$ 30033 = �����н�Ǯ��ITEMֱ��ת��
    CLI_PICK_FROM_ITEM_BOX          = 30034,    //$ 30034 = �ӱ����н�Ǯ��ITEMת��
    CLI_SELL_SUNDRIES               = 30035,    //$ 30035 = ����������������
    CLI_NETBAR_REWARD               = 30036,    //$ 30036 = ��Ȩ����

    CLI_FROM_SYS_MAX                = 34999,    //ϵͳ�����ʽ����־�������ֵ ��ֵ

    // �ʽ���ԴΪ�������           35000-36999
    CLI_FROM_PLAYER_MIN             = 35000,

    CLI_EXCHANGE                    = 35001,    //$ 35001 = ����ҽ�������
    CLI_NORMAL_MAIL                 = 35002,    //$ 35002 = ����ͨ�ʼ���ȡ

    CLI_FROM_PLAYER_MAX             = 35998,    //����Ҵ�����ʽ���־�������ֵ

    CAPITAL_LOG_INC_MAXTYPE         = 36999,    //$ 36999 = ����ʽ���־�������ֵ
};

// �����ʽ���־����, ��������־
enum CAPITAL_SPECIAL_LOG_TYPE
{
    CLS_MAX_CAPITAL                 = 37001,    //$ 37001 = �ʽ𳬳����ֵ û�б����ϵĲ���
    CLS_DEC_POINT                   = 37002,    //$ 37002 = ��Ϸ�����ĵ�ȯ
};

// �۳��ʽ����־���� 40000-49999
enum CAPITAL_DEC_LOGTYPE
{
    CAPITAL_DEC_MINTYPE             = 40000,    //$ 40000 = ʧȥ�ʽ���־������Сֵ

    // �ʽ�ȥ�� ��ϵͳ���� 40000-44999
    CLD_TO_SYS_MIN                  = 40000,

    CLD_BACKSTAGE                   = 40001,    //$ 40001 = ��Ϊ��̨�༭������Զ���Ǯ
    CLD_EQUIPMENT_STRENGE           = 40002,    //$ 40002 = װ��ǿ����������
    CLD_EQUIPMENT_INHERIT           = 40003,    //$ 40003 = �̳����ķ���
    CLD_FILLIN_JEM_TO_EQUIPMENT     = 40004,    //$ 40004 = ��ʯ�ϳɷ���
    //CLD_REMOVE_JEM_FROM_EQUIPMENT   = 40005,    //40005 = װ����ʯժ�����ĵķ���
    //CLD_COMPOSE_JEM                 = 40006,    //40006 = ��ʯ�ϳ����ĵķ���
    CLD_COMPOSE_EQUIPMENT           = 40007,    //$ 40007 = װ���ϳ���������
    CLD_TRANSFER                    = 40008,    //$ 40008 = ��������
    //CLD_SHOPPING                    = 40009,    //40009 = �����̵���Ʒ���ķ���
    CLD_SEND_MAIL_CONSUME           = 40010,    //$ 40010 = �ʷ�
    //CLD_CONTACT                     = 40011,    //40011 = �罻��Ϊ
    CLD_AIRPORT                     = 40012,    //$ 40012 = ������ͨ��������
    CLD_LEARN_LIFE_SKILL            = 40013,    //$ 40013 = ѧϰ����ְҵ
    CLD_MAKE_ITEM                   = 40014,    //$ 40014 = �䷽����������Ľ�Ǯ
    CLD_CREATE_GUILD                = 40015,    //$ 40015 = ��������ɹ�
    CLD_AUCTION_DEPOSIT             = 40016,    //$ 40016 = �����м���ʱ���ܷ�
    CLD_AUCTION_TRANSACT_FEE        = 40017,    //$ 40017 = �����гɽ�ʱ������
    CLD_AUCTION_BID                 = 40018,    //$ 40018 = �����о���
    CLD_AUCTION_AUTO_BID            = 40019,    //$ 40019 = �������Զ�����Ԥ����
    CLD_AUCTION_FIXED_PRICE         = 40020,    //$ 40020 = ������һ�ڼ�
    CLD_UPGRADE_SKILL               = 40021,    //$ 40021 = ��������
    CLD_EQUIPMENT_SERVICE           = 40022,    //$ 40022 = װ��ά����������
    CLD_NORMAL_SHOPPING             = 40023,    //$ 40023 = ��ͨ�̵�����
    CLD_COMPOSE_SUCCESS_BACK        = 40024,    //$ 40024 = װ���ϳɺ��˻ع������Ľ�Ǯ
    CLD_CRITICAL_MAIL               = 40025,    //$ 40025 = �Ӽ��ʼ����ʷ�
    //CLD_QUEST                       = 40026,    //40026 = ����
    CLD_MAIL_CONSUME                = 40027,    //$ 40027 = �����ʼ�
    CLD_PET_STRENGE                 = 40028,    //$ 40028 = ����ϵͳ����ǿ��
    CLD_ENERGYWELL_FILL             = 40029,    //$ 40029 = �������������Ľ�Ǯ
    CLD_ENERGYWELL_MAKE_TOWER       = 40030,    //$ 40030 = ������ħ���������������
    CLD_PVP_DEPOSIT                 = 40031,    //$ 40031 = PVP����Ѻ�ڣ�Ѻ��
    CLD_BIND_ITEM                   = 40032,    //$ 40032 = ����Ʒ
    CLD_RELIVE                      = 40033,    //$ 40033 = ����
    CLD_BLADERUNNER                 = 40034,    //$ 40034 = ����սʿ
    CLD_CLONE                       = 40035,    //$ 40035 = ����
    CLD_DEAD                        = 40036,    //$ 40036 = ����
    CLD_INSCRIPTION                 = 40037,    //$ 40037 = ����
    CLD_EXILE_ESCAPE                = 40038,    //$ 40038 = ��¸
    CLD_SAVE_TODEPOT                = 40039,    //$ 40039 = ��Ǯ���ֿ�
    CLD_ASKTOBUY                    = 40040,    //$ 40040 = ����
    CLD_ASKTOBUY_BILLFEE            = 40041,    //$ 40041 = ���йҵ���
    CLD_ASKTOBUY_PRESTORED_FEE      = 40042,    //$ 40042 = ���йҵ�Ԥ���
    CLD_ASKTOBUY_TRANSACT_FEE       = 40043,    //$ 40043 = ���гɽ�������
    CLD_BLACKMARKET_FIXED_BID       = 40044,    //$ 40044 = ����һ�ڼ�
    CLD_MAX_CAPITAL                 = 40045,    //$ 40045 = vip״̬��ʧ, �ʽ𳬳����ֵ���ֱ�ϵͳ����
    CLD_ARENA                       = 40046,    //$ 40046 = ս��
    CLD_ENCHASE                     = 40047,    //$ 40047 = ��Ƕ
    CLD_OFFLINE                     = 40048,    //$ 40048 = ����
    CLD_ORGANIZATION                = 40049,    //$ 40049 = npc��֯
    CLD_TOOLBOX                     = 40050,    //$ 40050 = ����
    CLD_EVERYDAY_REFRESH            = 40051,    //$ 40051 = ÿ���Ƽ�ˢ��
    CLD_GM                          = 40052,    //$ 40052 = gm����
    CLD_SLOTITEM                    = 40053,    //$ 40053 = ���
    CLD_ENEMY_CONVEY                = 40054,    //$ 40054 = ��д���
    CLD_TOOBOX_OPEN_LINK            = 40055,    //$ 40055 = �����������
    CLD_EXTBAG                      = 40056,    //$ 40056 = ��չ��������
    CLD_EXTDEPOT                    = 40057,    //$ 40057 = ��չ�ֿ�����
    CLD_OPEN_VIP                    = 40058,    //$ 40058 = ��ͨVIP
    CLD_PVP_QUICK_TRANS             = 40059,    //$ 40059 = ��ɱ���ٴ��ͻ�ɱ
    CLD_PVP_ASK_KILL                = 40060,    //$ 40060 = ��ɱ������ɱ
    CLD_PVP_ASK_HELP                = 40061,    //$ 40061 = ��ɱ��������
    CLD_ENERGY_UPGRADE              = 40062,    //$ 40062 = ������ǿ��
    CLD_ITEM_RESET                  = 40063,    //$ 40063 = װ��ϴ��
    CLD_EXCHANGE_CASH               = 40064,    //$ 40064 = ��ȯ�һ��ڽ� �۳���ȯ
    CLD_SYSTEM_TAX                  = 40065,    //$ 40065 = ϵͳ��˰
    CLD_ENEMY_FIND                  = 40066,    //$ 40066 = ��в�ѯ
    CLD_FILL_ENERGY                 = 40067,    //$ 40067 = ����
    CLD_EXCHANGE_GOLD               = 40068,    //$ 40068 = �ڽ�һ���� �۳��ڽ�
    CLD_ENERGYWELL_ATTACK           = 40069,    //$ 40069 = ��������ս
    CLD_DEPLOY_CARRIER              = 40070,    //$ 40070 = �����ؾ�
    CLD_EXCHAGE_RIDE_POINT          = 40071,    //$ 40071 = �һ��������
    CLD_GM_NOLIMIT                  = 40072,    //$ 40072 = gm����(����ÿ���޶�����)
    CLD_BUY_CHARGE                  = 40073,    //$ 40073 = ���򵵰��շ�
    CLD_SEL_CHARGE_MODE             = 40074,    //$ 40074 = ѡ��Ԥ��ģʽ�շ�
    CLD_SKILLTYPE_UNLOCK            = 40075,    //$ 40075 = ���ѿ����ܿ�
    CLD_EWCAR_PRODUCE               = 40076,    //$ 40076 = �������ؾ�����
    CLD_ENERGYWELL_BUY_RIDE         = 40077,    //$ 40077 = �����������ؾ�


    CLD_TO_SYS_MAX                  = 44999,    //��ϵͳ�������ֵ

    // �ʽ�ȥ�� ���׸�������� 45000-49999
    CLD_TO_PLAYER_MIN               = 45000,
    CLD_EXCHANGE                    = 45001,    //$ 45001 = ���֮��Ľ���
    CLD_MAIL_ATTACHMENT             = 45002,    //$ 45002 = �����ʼ���������� �����ʽ�
    CLD_WEBEXCHANGE                 = 45003,    //$ 45003 = ���½�����Ϸ��(new)
    CLD_WEBEXCHANGE_CHARGE          = 45004,    //$ 45004 = ���½���˰��

    CLD_TO_PLAYER_MAX               = 45998,    //���ʧȥ�ʽ����־���͵����ֵ ��ֵ �ʽ�ȥ�� ��ͨ��

    CAPITAL_DEC_MAXTYPE             = 49999,    //$ 49999 = ʧȥ�ʽ���־�������ֵ
};

//$@ 3  = �����־
enum PLAYER_LOGTYPE
{
    PLAYER_LOG_BEGIN                    = 50000,     //

    PLAYER_LOG_BUY_DIRECTDEPOT          = 50001,     //$ 50001 = ����Զ�ֿ̲�
    PLAYER_LOG_BEGIN_PK                 = 50002,     //$ 50002 = PK��ʼ
    PLAYER_LOG_PK_RESULT                = 50003,     //$ 50003 = PK���
    PLAYER_LOG_GUILD                    = 50004,     //$ 50004 = �������
    PLAYER_LOG_CLONE                    = 50005,     //$ 50005 = �������
    PLAYER_LOG_EXCHANGE_ITEMS           = 50006,     //$ 50006 = ��ҽ�����Ʒ
    PLAYER_LOG_EXCHANGE_MONEY           = 50007,     //$ 50007 = ��ҽ���Ǯ
    PLAYER_LOG_POST                     = 50008,     //$ 50008 = �ʼ����
    PLAYER_LOG_FRIEND                   = 50009,     //$ 50009 = �������
    PLAYER_LOG_JOB                      = 50010,     //$ 50010 = ��������
    PLAYER_LOG_SKILL                    = 50011,     //$ 50011 = ������أ���ʽ���ڹ����Ṧ��������
    PLAYER_LOG_BUY_CHARGE_ITEM          = 50012,     //$ 50012 = �ӼƷ�ϵͳ�������
    PLAYER_LOG_ON_DEC_POINT             = 50013,     //$ 50013 = �յ��Ʒѿ۳���ȯ����Ϣ
    PLAYER_LOG_SEND_NEW_MAIL            = 50014,     //$ 50014 = ���������ʼ�
    PLAYER_LOG_UNENTHRALL_BREAK_PLAYER  = 50015,     //$ 50015 = �������г�ʱ���������
    PLAYER_LOG_FLY_CANCEL               = 50016,     //$ 50016 = ����ڵ��˽�ͨ���������⽵��
    PLAYER_LOG_LOGIN                    = 50017,     //$ 50017 = ����
    PLAYER_LOG_LOGOUT                   = 50018,     //$ 50018 = ����
    PLAYER_LOG_GIFT                     = 50019,     //$ 50019 = ��ȡ�Ʒ�ϵͳ��Ʒ
    PLAYER_LOG_WEBEXCHANGE_ROLE         = 50020,     //$ 50020 = ����ţ���н��׽�ɫ ��ɫ�������߲�����
    PLAYER_LOG_EVERYDAY                 = 50021,     //$ 50021 = ÿ���������
    PLAYER_LOG_NETBAR_RIGHT             = 50022,     //$ 50022 = ������Ȩ��־

    PLAYER_LOG_END                      = 50999,     //
};

//typedef enum _QUEST_LOG_TYPE
//{
//    QUEST_LOG_ACCEPTED              = 1,    // ��������
//    QUEST_LOG_REWARDED              = 2,    // �ύ����
//    QUEST_LOG_FAILED                = 3,    // ����ʧ��
//    QUEST_LOG_GIVEUP                = 4,    // ��������
//} QUEST_LOG_TYPE;

//typedef enum _UPGRADE_LOG_TYPE
//{
//    UPGRADE_LOG_PLAYER              = 1,    // ��ɫ����
//    UPGRADE_LOG_SKILL               = 2,    // ��ɫ��������
//    UPGRADE_LOG_ARRESTVALUE         = 3,    // PKֵARRESTVALUE�仯
//    UPGRADE_LOG_ADDHONOR_PLAYER = 4,        // �����������:Ұ��ɱ��
//    UPGRADE_LOG_ADDHONOR_QUEST = 5,         // �����������:����
//    UPGRADE_LOG_ADDHONOR_EVENT = 6,         // �����������:�¼�
//    UPGRADE_LOG_ADDHONOR_ACTIVIT = 7,       // �����������:�
//    UPGRADE_LOG_ADDHONOR_DAILY_GUIDE = 8,   // �����������:ÿ������
//    UPGRADE_LOG_ADDHONOR_PVP_QUEST = 9,     // �����������:PVP����
//    UPGRADE_LOG_ADDHONOR_BATTLEFIELD = 10,  // �����������:ս��
//    UPGRADE_LOG_ADDHONOR_ARENA = 11,        // �����������:������
//    UPGRADE_LOG_ADDHONOR_TRIGGER = 12,      // �����������:������
//} UPGRADE_LOG_TYPE;


// �����Ϸ��Ҫ��Ϊ����
//enum DEED_TYPE
//{
//    DEED_BEGIN                      = 0,
//    DEED_COMPLETE                   = 1,
//    DEED_MID_COMPLETE               = 2,
//};


//typedef enum _EXP_LOG_TYPE
//{
//    ADDEXP_TYPE_NPC = 0,                // �����������:���
//    ADDEXP_TYPE_SCENE = 1,              // �����������:����
//    ADDEXP_TYPE_QUEST = 2,              // �����������:����
//    ADDEXP_TYPE_EVENT = 3,              // �����������:�¼�
//    ADDEXP_TYPE_ACTIVIT = 4,            // �����������:�
//    ADDEXP_TYPE_DAILY_GUIDE = 5,        // �����������:ÿ������
//    ADDEXP_TYPE_PVP_QUEST = 6,          // �����������:PVP����
//    ADDEXP_TYPE_BATTLEFIELD = 7,        // �����������:ս��
//    ADDEXP_TYPE_BATTLEFIELD_KILL = 8,   // �����������:��ɱ
//    ADDEXP_TYPE_PLAYER_BEKILLED = 9,    // �����������:��ɱ
//    ADDEXP_TYPE_TRIGGER = 10,           // �����������:������
//    ADDEXP_TYPE_ITEM_USE = 11,          // ʹ�õ�������
//    ADDEXP_TYPE_EWRESFIGHT = 12,        // �����������:������ս��
//    ADDEXP_TYPE_ARENA,
//} EXP_LOG_TYPE;

//$@ 4  = ��ɫ������־
enum TRANSMIT_LOG_TYPE
{
    TRANSMIT_LOG_BEGIN              = 51000,
    TRANSMIT_LOG_BACK_STAGE         = 51001,    //$ 51001 =��Чƽ̨
    TRANSMIT_LOG_GM                 = 51002,    //$ 51002 =GM����

    TRANSMIT_LOG_END                = 51999,
};

//$@ 5  = ��ɫ������־
enum EXPERIENCE_LOG_TYPE
{
    EXPERIENCE_LOG_BEGIN            = 52000,
    EXPERIENCE_LOG_NPC              = 52001,    //$ 52001 = ������־����:���
    EXPERIENCE_LOG_CLONESCENE       = 52002,    //$ 52002 = ������־����:����
    EXPERIENCE_LOG_QUEST            = 52003,    //$ 52003 = ������־����:����
    EXPERIENCE_LOG_EVENT            = 52004,    //$ 52004 = ������־����:�¼�
    EXPERIENCE_LOG_ACTIVIT          = 52005,    //$ 52005 = ������־����:�
    EXPERIENCE_LOG_DAILY_GUIDE      = 52006,    //$ 52006 = ������־����:ÿ������
    EXPERIENCE_LOG_PVP_QUEST        = 52007,    //$ 52007 = ������־����:PVP����
    EXPERIENCE_LOG_BATTLEFIELD      = 52008,    //$ 52008 = ������־����:ս��
    EXPERIENCE_LOG_TRIGGER          = 52009,    //$ 52009 = ������־����:������
    EXPERIENCE_LOG_ITEM_USE         = 52010,    //$ 52010 = ������־����:ʹ�õ���
    EXPERIENCE_LOG_EWRESFIGHT       = 52011,    //$ 52011 = ������־����:������ս��
    EXPERIENCE_LOG_ARENA            = 52012,    //$ 52012 = ������־����:������
    EXPERIENCE_LOG_NETBAR           = 52013,    //$ 52013 = ������־����:������Ȩ

    EXPERIENCE_LOG_END              = 52999,
    //EXPERIENCE_LOG_BATTLEFIELD_KILL = 12009,    // ������־����:��ɱ
    //EXPERIENCE_LOG_PLAYER_BEKILLED  = 12010,    // ������־����:��ɱ
};

//$@ 6  = ��ɫ������־
enum UPGRADE_LOG_TYPE
{
    UPGRADE_LOG_BEGIN               = 53000,       //
    UPGRADE_LOG_PLAYER              = 53001,       //$ 53001 = ��ɫ����
    UPGRADE_LOG_SKILL               = 53002,       //$ 53002 = ��ɫ��������
    //UPGRADE_LOG_ARRESTVALUE         = 53003,     // 53003 = PKֵARRESTVALUE�仯
    UPGRADE_LOG_RANK                = 53004,       //$ 53004 = ��������
    //UPGRADE_LOG_ADDHONOR_PLAYER      = 53004,       // �����������:Ұ��ɱ��
    //UPGRADE_LOG_ADDHONOR_QUEST       = 53005,       // �����������:����
    //UPGRADE_LOG_ADDHONOR_EVENT       = 53006,       // �����������:�¼�
    //UPGRADE_LOG_ADDHONOR_ACTIVIT     = 53007,       // �����������:�
    //UPGRADE_LOG_ADDHONOR_DAILY_GUIDE = 53008,       // �����������:ÿ������
    //UPGRADE_LOG_ADDHONOR_PVP_QUEST   = 53009,       // �����������:PVP����
    //UPGRADE_LOG_ADDHONOR_BATTLEFIELD = 53010,       // �����������:ս��
    //UPGRADE_LOG_ADDHONOR_ARENA       = 53011,       // �����������:������
    //UPGRADE_LOG_ADDHONOR_TRIGGER     = 53012,       // �����������:������

    UPGRADE_LOG_END                 = 53999,       //
};

// $@ 7  = ��ɫ��Ʒ��ǿ��־
enum ITEM_CHANGE_LOG_TYPE
{
    ITEM_CHANGE_LOG_BEGIN           = 54000,    //
    ITEM_CHANGE_LOG_ENHANCE         = 54001,    //$ 54001 = װ��ǿ��  | CLIENT_CUSTOMMSG_STRENGTHEN_EXECUTE
    ITEM_CHANGE_LOG_COMPOUND_JEWEL  = 54002,    //$ 54002 = ��ʯ�ϳ�  | CLIENT_CUSTOMMSG_ENCHASE_COMPOUND
    ITEM_CHANGE_LOG_COMPOUND_EQUIP  = 54003,    //$ 54003 = װ���ϳ�  | CLIENT_CUSTOMMSG_COMPOUNDITEM
    ITEM_CHANGE_LOG_SLOT            = 54004,    //$ 54004 = װ�����  | CLIENT_CUSTIOMMSG_SLOTITEM
    ITEM_CHANGE_LOG_ENERGY_UPGRADE  = 54005,    //$ 54005 = ������ǿ��  | CLIENT_CUSTOMMSG_ENERGY_UPGRADE

    ITEM_CHANGE_LOG_END             = 54999,    //
};

// $@ 8  = ��ɫ��¼��־
enum LOGIN_LOG_TYPE
{
    LOGIN_LOG_BEGIN                 = 55000,    //
    LOGIN_LOG_RECOVER               = 55001,    //$ 55001 = ��¼������Ϸ
    LOGIN_LOG_CONTINUE              = 55002,    //$ 55002 = ������Ϸ(����)
    LOGIN_LOG_DISCONNECT            = 55003,    //$ 55003 = �Ͽ�����
    LOGIN_LOG_STORE                 = 55004,    //$ 55004 = ��ɫ�����˳�

    LOGIN_LOG_END                   = 55999,    //
};

//$@ 9  = ��ɫ�л�������־
enum SCENE_LOG_TYPE
{
    SCENE_LOG_BEGIN                 = 56000,    //
    SCENE_LOG_AFTERENTRYSCENE       = 56001,    //$ 56001 = ���볡��
    SCENE_LOG_LEAVESCENE            = 56002,    //$ 56002 = �뿪����

    SCENE_LOG_END                   = 56999,    //
};

//$@ 10 = ��ɫ������־
enum TASK_LOG_TYPE
{
    TASK_LOG_BEGIN                  = 57000,
    TASK_LOG_ACCEPT                 = 57001,    //$ 57001 = ��������
    TASK_LOG_REWARD                 = 57002,    //$ 57002 = �ύ����
    TASK_LOG_FAIL                   = 57003,    //$ 57003 = ����ʧ��
    TASK_LOG_GIVEUP                 = 57004,    //$ 57004 = ��������

    TASK_LOG_END                    = 57999,
};

//$@ 11 = ��ɫ����ɾ����־
enum CREATE_DELETE_LOG_TYPE
{
    CREATE_DELETE_LOG_BEGIN         = 58000,    //
    CREATE_DELETE_LOG_CREATE        = 58001,    //$ 58001 = ������ɫ
    CREATE_DELETE_LOG_DELETE        = 58002,    //$ 58002 = ɾ����ɫ

    CREATE_DELETE_LOG_END           = 58999,    //
};

//$@ 12 = ��ɫ������־
enum EXCHANGE_LOG_TYPE
{
    EXCHANGE_LOG_BEGIN              = 59000,    //
    EXCHANGE_LOG_EXCHANGE           = 59001,    //$ 59001 = ֱ�ӽ���
    EXCHANGE_LOG_COMMON_MAIL_SEND   = 59002,    //$ 59002 = ��ͨ�ʼ�(����)
    EXCHANGE_LOG_COMMON_MAIL_GET    = 59003,    //$ 59003 = ��ͨ�ʼ�(����)
    EXCHANGE_LOG_TRADE_MAIL_SEND    = 59004,    //$ 59004 = �����ʼ�(����)
    EXCHANGE_LOG_TRADE_MAIL_GET     = 59005,    //$ 59005 = �����ʼ�(����)
    EXCHANGE_LOG_TRADE_MAIL_PAY     = 59006,    //$ 59006 = �����ʼ�(����)
    EXCHANGE_LOG_MAIL_BACK          = 59007,    //$ 59007 = �ʼ�(����)
    EXCHANGE_LOG_COMMON_MAIL_FUND   = 59008,    //$ 59008 = ��ͨ�ʼ�(���ѿ�)
    EXCHANGE_LOG_MAIL_DEL           = 59009,    //$ 59009 = ɾ���ż�

    EXCHANGE_LOG_END                = 59999,    //
};

//$@ 13 = ��ɫ������־
enum GUILD_LOG_TYPE
{
    GUILD_LOG_BEGIN                 = 60000,
    GUILD_LOG_CREATE                = 60001,    //$ 60001 = ��������
    GUILD_LOG_ACCEPT_MEMBER         = 60002,    //$ 60002 = ��������������³�Ա
    GUILD_LOG_REJECT_MEMBER         = 60003,    //$ 60003 = �ܾ�������
    GUILD_LOG_SET_NOTICE            = 60004,    //$ 60004 = ���ù��ṫ����Ϣ
    GUILD_LOG_SET_AUTHORITY         = 60005,    //$ 60005 = ����ְλȨ��
    GUILD_LOG_QUIT_GUILD            = 60006,    //$ 60006 = �����˳�����
    GUILD_LOG_CHANGE_POSITION       = 60007,    //$ 60007 = �ı��Աְλ
    GUILD_LOG_DISBAND               = 60008,    //$ 60008 = ������ɢ����
    GUILD_LOG_CANCEL_DISBAND        = 60009,    //$ 60009 = ��Աֹͣ��ɢ����
    GUILD_LOG_QUIT_LEADER           = 60010,    //$ 60010 = ת�û᳤
    GUILD_LOG_DEL_MEMBER            = 60011,    //$ 60011 = �߳�����
    GUILD_LOG_DEPOT_SET_LEVEL       = 60012,    //$ 60012 = �ı乫��ֿ�����
    GUILD_LOG_DEPOT_ITEM_ADD        = 60013,    //$ 60013 = ���ӹ���ֿ���Ʒ
    GUILD_LOG_DEPOT_ITEM_SUB        = 60014,    //$ 60014 = ȡ������ֿ���Ʒ
    GUILD_LOG_DISBAND_RESULT        = 60015,    //$ 60015 = �����ɢ�ɹ�
    GUILD_LOG_OK_MEMBER             = 60016,    //$ 60016 = ���ͬ����빫��
    GUILD_LOG_CANCEL_MEMBER         = 60017,    //$ 60017 = ��Ҿܾ����빫��
    GUIID_LOG_CAPITAL_GOLD          = 60018,    //$ 60018 = ���׽�Ǯ
    GUILD_LOG_UP_LEVEL              = 60019,    //$ 60019 = ��������
    GUILD_LOG_STATE_RECRUIT         = 60020,    //$ 60020 = ���ù���Զ����ļ״̬���
    GUILD_LOG_MEM_DEGREE            = 60021,    //$ 60021 = ���ù����Ա�ȼ����
    GUILD_LOG_REMOVE_ITEM           = 60022,    //$ 60022 = ɾ���ֿ���Ʒ�ɹ�
    GUILD_LOG_ADD_CAPACITY          = 60023,    //$ 60023 = ���Ӳֿ������ɹ�
    GUILD_LOG_ADD_CAPITAL           = 60024,    //$ 60024 = �ֿ��ʽ����ӳɹ�
    GUILD_LOG_SUB_CAPITAL           = 60025,    //$ 60025 = �ֿ��ʽ���ٳɹ�
    GUILD_LOG_BUILD_RELATION        = 60026,    //$ 60026 = ���������ϵ�ɹ�
    GUILD_LOG_DISBAND_RELATION      = 60027,    //$ 60027 = ��ɢ�����ϵ�ɹ�

    GUILD_LOG_END                   = 60999,
};

//$@ 14 = ��ɫ�ͷ���־
enum PUNISH_LOG_TYPE
{
    PUNISH_LOG_BEGIN                = 61000,    //
    PUNISH_LOG_SILENCE              = 61001,    //$ 61001 = ���Գͷ�
    PUNISH_LOG_FREEZEN              = 61002,    //$ 61002 = ����ͷ�
    PUNISH_LOG_EXILE3               = 61003,    //$ 61003 = ������Ѻ
    PUNISH_LOG_EXILE4               = 61004,    //$ 61004 = �ļ���Ѻ
    PUNISH_LOG_END                  = 61999,    //
};

//$@ 15 = ��ɫ������־
enum HONOR_LOG_TYPE
{
    HONOR_LOG_BEGIN                 = 62000,       //
    HONOR_LOG_KILL_PLAYER           = 62001,       //$ 62001 = �����������:Ұ��ɱ��
    HONOR_LOG_QUEST                 = 62002,       //$ 62002 = �����������:����
    HONOR_LOG_EVENT                 = 62003,       //$ 62003 = �����������:�¼�
    HONOR_LOG_ACTIVIT               = 62004,       //$ 62004 = �����������:�
    HONOR_LOG_DAILY_GUIDE           = 62005,       //$ 62005 = �����������:ÿ������
    HONOR_LOG_PVP_QUEST             = 62006,       //$ 62006 = �����������:PVP����
    HONOR_LOG_BATTLEFIELD           = 62007,       //$ 62007 = �����������:ս��
    HONOR_LOG_ARENA                 = 62008,       //$ 62008 = �����������:������
    HONOR_LOG_TRIGGER               = 62009,       //$ 62009 = �����������:������

    HONOR_LOG_END                   = 62999,       //
};

//$@ 16 = ��ɫ�淨��־
enum ENJOY_LOG_TYPE
{
    ENJOY_LOG_BEGIN                     = 63000,       //

    ENJOY_EVENTSPRING                   = 63001,       //$ 63001 = ��̬�¼�
    ENJOY_CLONE                         = 63002,       //$ 63002 = ����
    ENJOY_ARENA                         = 63003,       //$ 63003 = ������
    ENJOY_BATTLE                        = 63004,       //$ 63004 = ս��
    ENJOY_FRIST                         = 63005,       //$ 63005 = ���ָ���
    ENJOY_RISK                          = 63006,       //$ 63006 = ð��
    ENJOY_DUEL                          = 63007,       //$ 63007 = ����
    ENJOY_ENGWELL                       = 63008,       //$ 63008 = ������

    ENJOY_EVENTSPRING_LOG_START         = 63101,       //$ 63101 = ����:��̬�¼�
    ENJOY_EVENTSPRING_LOG_OVER          = 63102,       //$ 63102 = ����:��̬�¼�
    ENJOY_EVENTSPRING_LOG_PERSON_OVER   = 63103,       //$ 63103 = �¼�:��Ŀ�����

    ENJOY_CLONE_LOG_ENTRY               = 63201,       //$ 63201 = ����:����
    ENJOY_CLONE_LOG_OVER                = 63202,       //$ 63202 = ����:����
    ENJOY_CLONE_LOG_ERROR               = 63203,       //$ 63203 = �����뿪:����

    ENJOY_ARENA_LOG_ENTRY               = 63301,       //$ 63301 = ����:������
    ENJOY_ARENA_LOG_OVER_WIN            = 63302,       //$ 63302 = ����:������:ʤ��
    ENJOY_ARENA_LOG_OVER_LOSE           = 63303,       //$ 63303 = ����:������:ʧ��
    ENJOY_ARENA_LOG_OVER_TIE            = 63304,       //$ 63304 = ����:������:ƽ��
    ENJOY_ARENA_LOG_ERROR               = 63305,       //$ 63305 = �쳣:������

    ENJOY_BATTLE_LOG_ENTRY              = 63401,       //$ 63401 = ����:ս��
    ENJOY_BATTLE_LOG_OVER_WIN           = 63402,       //$ 63402 = ����:ս��:ʤ��
    ENJOY_BATTLE_LOG_OVER_LOSE          = 63403,       //$ 63403 = ����:ս��:ʧ��
    ENJOY_BATTLE_LOG_OVER_TIE           = 63404,       //$ 63404 = ����:ս��:ƽ��
    ENJOY_BATTLE_LOG_MIDWAY_LEVEL       = 63405,       //$ 63405 = ս��:��;�˳�
    ENJOY_BATTLE_LOG_ERROR              = 63406,       //$ 63406 = ս���е���(��һ���˳�ս��)

    ENJOY_FRIST_LOG_ENTRY               = 63501,       //$ 63501 = ����:���ָ���
    ENJOY_FRIST_LOG_OVER                = 63502,       //$ 63502 = ����:���ָ���
    ENJOY_FRIST_LOG_ERROR               = 63503,       //$ 63503 = �쳣:���ָ���

    ENJOY_RISK_LOG_START                = 63601,       //$ 63601 = ����ð������
    ENJOY_RISK_LOG_SUBMIT               = 63602,       //$ 63602 = �ύð������
    ENJOY_RISK_LOG_FAILED               = 63603,       //$ 63603 = ð������ʧ��
    ENJOY_RISK_LOG_GIVEUP               = 63604,       //$ 63604 = ����ð������

    ENJOY_DUEL_LOG_START                = 63701,       //$ 63701 = ��ʼ:����
    ENJOY_DUEL_LOG_OVER_WIN             = 63702,       //$ 63702 = ����:����:ʤ��
    ENJOY_DUEL_LOG_OVER_LOSE            = 63703,       //$ 63703 = ����:����:ʧ��
    ENJOY_DUEL_LOG_ERROR                = 63704,       //$ 63704 = ����:����

    ENJOY_ENGWELL_LOG_START             = 63801,       //$ 63801 = �μ�������ս��
    ENJOY_ENGWELL_LOG_LEAVE             = 63802,       //$ 63802 = �뿪������ս��
    ENJOY_ENGWELL_LOG_AWARD_WIN         = 63803,       //$ 63803 = ������ս���콱(ʤ��)
    ENJOY_ENGWELL_LOG_AWARD_LOSE        = 63804,       //$ 63804 = ������ս���콱(ʧ��)
    ENJOY_ENGWELL_LOG_BID_SUC           = 63805,       //$ 63805 = ���������������۳ɹ�
    ENJOY_ENGWELL_LOG_BID_FAIL          = 63806,       //$ 63806 = ����������������ʧ��
    ENJOY_ENGWELL_LOG_BID_BACK          = 63807,       //$ 63807 = ���������������۱������˻��ʽ�
    ENJOY_ENGWELL_LOG_BID_FINAL         = 63808,       //$ 63808 = �������������ɹ�

    ENJOY_LOG_END                       = 64999,       //
};

//$@ 17 = �Ƿ�������־
enum ILLEGAL_REQ_LOG_TYPE
{
    ILLEGAL_REQ_BEGIN                   = 65000,        //
    ILLEGAL_REQ_LOG                     = 65001,        //$ 65001 = �Ƿ�������־
    ILLEGAL_REQ_GPK_CHECK               = 65002,        //$ 65002 = GPK��⵽���
    ILLEGAL_REQ_MONITOR                 = 65003,        //$ 65003 = ����ƶ������Ϣ
    ILLEGAL_REQ_END                     = 65999,        //
};

//$@ 18 = ��������־
enum AUCTION_LOG_TYPE
{
    AUCTION_LOG_BEGIN                   = 66000,        //
    AUCTION_LOG_CONSIGN                 = 66001,        //$ 66001 = ���ۣ��۽�ҡ�����Ʒ��
    AUCTION_LOG_CANCEL_CONSIGN          = 66002,        //$ 66002 = ȡ�����ۣ�����Ʒ��
    AUCTION_LOG_BID                     = 66003,        //$ 66003 = ���ۣ��ۺڽ�
    AUCTION_LOG_FIXED_BID               = 66004,        //$ 66004 = һ�ڼۣ��ۺڽ�
    AUCTION_LOG_PRICE_BEATEN            = 66005,        //$ 66005 = ���۱������úڽ�
    AUCTION_LOG_BID_DOWN                = 66006,        //$ 66006 = �ɹ�������Ʒ������Ʒ��
    AUCTION_LOG_SOLD                    = 66007,        //$ 66007 = �ɹ�������Ʒ����Ǯ��
    AUCTION_LOG_TIME_OUT_SOLD           = 66008,        //$ 66008 = ��Ʒ�����¼��۳�����Ǯ��
    AUCTION_LOG_TIME_OUT_UNSOLD         = 66009,        //$ 66009 = ��Ʒ�����¼�δ�۳�������Ʒ��
    AUCTION_LOG_END                     = 66999,        //
};

#define  STR_TIME_MAX_LENGTH  64
#define  STR_LOG_COMMON_LENGTH  128
#define  STR_LOG_MAX_LENGTH     256
#define  STR_LOG_COMMENT_LENGTH  128

#endif  // __LogDefine_h__
