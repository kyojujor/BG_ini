//--------------------------------------------------------------------
// 文件名:      LogDefine.h
// 内  容:
// 说  明:
// 创建日期:    2013年3月18日
// 创建人:
// 维护人:      胡添
// 版权所有:    苏州蜗牛电子有限公司
//--------------------------------------------------------------------

#ifndef __LogDefine_h__
#define __LogDefine_h__

// add by hutian 2013-4-26
//容器类定义 \Server\Cons\Res\logic_class.xml
//pKernel->CreateContainer(player, ...) 创建在玩家身上的容器为玩家容器
//
//创建在玩家容器上的物品必须记录log。
//物品销毁时如果物品所在容器为玩家容器，必须记录log。
//移入，移出，移动玩家容器的物品须记录log
//修改玩家容器的物品 Amount的地方须记录log
//排查lua
//
//原则上物品(item)操作不允许使用引擎的 pKernel->Place() pKernel->PlacePos() pKernel->PlaceTo() pKernel->Exchange() pKernel->ChangePos()
//必须使用ContainerBaseModule 相关函数。
//使用load_from_string  load_from_xml 时注意容器对象是否为玩家容器，是否要记录log
//
//pKernel->ClearChild(container)时，如果为玩家容器，则必须记录log。
//pKernel->CreateClone(container, ...)时，如果为玩家容器，则必须记录log。
//
//弱关联容器要查找与之关联的真实容器
//
//物品移动失败后一定要销毁，否则会造成对象泄漏
//销毁时使用 pKernel->DestroySelf(obj)，代替 pKernel->Destroy(scene,obj)，效率更高
//
//"ToolBox" "DepotBox" "EquipBox" "AddToolBox" "AddDepotBox" 为监控容器
//
//从其他容器进入到监控容器的log类型为玩家获得物品。
//反之为玩家失去物品。
//其他log类型为物品转移类型。


//$@ 1 = 角色物品日志
enum ITEM_LOG_TYPE
{
    //玩家获得物品 10000-19999
    ITEM_LOG_TYPE_MIN                           = 10000, //物品日志最小值

    IITE_LOG_TYPE_GET_ITEM_MIN                  = 10000, //$ 10000 = 获得物品日志类型最小值

    ITEM_LOG_TYPE_BUY_FROM_NPC                  = 10001, //$ 10001 = 玩家从NPC处购买
    ITEM_LOG_TYPE_BUY_FROM_CHARGE               = 10002, //$ 10002 = 点券购买计费商城物品
    ITEM_LOG_TYPE_GET_DAILY_PRIZE               = 10003, //$ 10003 = 获取每日奖励
    ITEM_LOG_TYPE_GET_ACTIVITY_PRIZE            = 10004, //$ 10004 = 获取活动奖励
    ITEM_LOG_TYPE_FRAGMENT_COMPOSE              = 10005, //$ 10005 = 获取碎片合成物品 | "Get From Fragment"
    ITEM_LOG_TYPE_GET_JOB_FORMULA               = 10006, //$ 10006 = 获取得到配方物品 |"Get From Formula"
    ITEM_LOG_TYPE_QUEST_AWARD_ITEM              = 10007, //$ 10007 = 获取任务奖励物品 |"Get Quest Award"
    ITEM_LOG_TYPE_SKILL_EVENT_GET_ITEM          = 10008, //$ 10008 = 技能事件得到道具 |"Get From SkillEvent"
    ITEM_LOG_TYPE_BEHAVIOR_GET_ITEM             = 10009, //$ 10009 = 触发器行为获得的物品 |"Get From Behavior"
    //ITEM_LOG_TYPE_GET_MERGE                     = 10010, //$ 10010 = 由于合并道具而增加
    //ITEM_LOG_TYPE_SPLIT_ITEM_MOVE               = 10011, //$ 10011 = 拆分物品造成的移动 |"Get From Split"
    ITEM_LOG_TYPE_CLONE_PASS_REWARD             = 10012, //$ 10012 = 副本通关奖励 |"Clone Pass Prize"
    ITEM_LOG_TYPE_OPEN_TREASURE_BOX_GET_ITEM    = 10013, //$ 10013 = 开宝箱道具得到宝箱 |"Get From TreasureBox"
    ITEM_LOG_TYPE_EW_RES_FIGHT_ITEM             = 10014, //$ 10014 = 能量井资源战奖励 |"Get EW Res Fight Prize"
    ITEM_LOG_TYPE_LIFEJOB_DECOMPOSE             = 10015, //$ 10015 = 副职分解 |"Get From Job Decompose"
    ITEM_LOG_TYPE_GM_CREATE                     = 10016, //$ 10016 = GM添加 |"Get From GM"
    ITEM_LOG_TYPE_PICK_DROP_QUEST_ITEM          = 10017, //$ 10017 = 获得任务道具 |"Get Quest Requirement"
    ITEM_LOG_TYPE_NEW_USER_LEAD_PRIZE_ITEM      = 10018, //$ 10018 = 新手引导得到的物品 |"Get Freshman Item"
    ITEM_LOG_TYPE_VIP_PACKET                    = 10019, //$ 10019 = 获得VIP礼包 |"Get VIP Package"
    ITEM_LOG_TYPE_PVP_QUEST_AWARD_ADD_ITEM      = 10020, //$ 10020 = 获得PVP任务奖励 |"Get PVP Award"
    ITEM_LOG_TYPE_FROM_MY_CHARGE_GOLD           = 10021, //$ 10021 = 金币购买计费商城物品
    ITEM_LOG_TYPE_GET_BATTLE_PRIZE_ITEM         = 10022, //$ 10022 = 战场奖励 |"Get Battlewar Prize"
    ITEM_LOG_TYPE_REVERT_ROLE_ITEM              = 10023, //$ 10023 = 重置角色加的物品 |"Revert Role Item"
    ITEM_LOG_TYPE_INIT_NEW_ROLE_EQUIP           = 10024, //$ 10024 = 初始化新手装备 创建角色时的装备 |"Create Role Equip"
    ITEM_LOG_TYPE_NEW_ROLE_LEAD_ADD_EQUIP       = 10025, //$ 10025 = 增加新手副本装备 |"New Role Clone Equip"
    ITEM_LOG_TYPE_CAPTURE_PET_ITEM              = 10026, //$ 10026 = 捕获的宠物 |"Get Capture Pet"
    ITEM_LOG_TYPE_COMPOUND_JEWEL_GROW           = 10027, //$ 10027 = 宝石合成 |"Create Item Jewel"
    ITEM_LOG_TYPE_GET_TASK_TOKEN                = 10028, //$ 10028 = 能量井 |"GetTaskToken"
    ITEM_LOG_TYPE_MOVE_ITEM_GAIN                = 10029, //$ 10029 = 移动物品获得物品
    ITEM_LOG_TYPE_PICK_UP_ITEM                  = 10030, //$ 10030 = 拾取掉落物品
    ITEM_LOG_TYPE_EXCHANGE_ITEM_GAIN            = 10031, //$ 10031 = 交易获得物品
    ITEM_LOG_TYPE_POST_GET                      = 10032, //$ 10032 = 通过邮件获得
    //ITEM_LOG_TYPE_GUILD_DEPOT_PUTIN             = 10033, //公会 仓库 物品存进
    ITEM_LOG_TYPE_PICK_DROP_PVP_QUEST_ITEM      = 10034, //$ 10034 = 获得PVP任务掉落道具
    ITEM_LOG_TYPE_NEW_ROLE_LEAD_RECOVER_EQUIP   = 10035, //$ 10035 = 恢复新手装备
    //ITEM_LOG_TYPE_PUT_ITEM_TO_BANK              = 10036, //放物品到银行
    ITEM_LOG_TYPE_GET_ITEM_FROM_RECLAIM_BOX     = 10037, //$ 10037 = 取回物品从回购栏
    ITEM_LOG_TYPE_COMPOUND_ROLL_BACK            = 10038, //$ 10038 = 装备合成不满意属性回滚
    ITEM_LOG_TYPE_REMOVE_INSCRIPTION_ITEM       = 10039, //$ 10039 = 获得铭刻拆除物品
    ITEM_LOG_TYPE_FROM_MY_CHARGE_BOX            = 10040, //$ 10040 = 玩家从我的物品栏提取
    ITEM_LOG_TYPE_GET_FROM_CHARGE               = 10041, //$ 10041 = 玩家从获取记录中购买
    ITEM_LOG_TYPE_BACK_STAGE_GET                = 10042, //$ 10042 = 玩家从后台发送的邮件中提取物品
    ITEM_LOG_TYPE_DEL_GET_LING_QI_ITEM          = 10043, //$ 10043 = 重铸刀峰战士铸造武器
    ITEM_LOG_TYPE_NETBAR_ADD_ITEM               = 10044, //$ 10044 = 蜗牛网吧特权添加道具

    IITE_LOG_TYPE_GET_ITEM_MAX                  = 19999, //$ 19999 = 获得物品日志类型最大值

    //ITEM_LOG_TYPE_DROP_QUEST_ITEM               = 10008, // 任务获得道具
    //ITEM_LOG_TYPE_SPLIT_INC                     = 10012, // 由于另一个物品被拆分增加的物品
    //ITEM_LOG_TYPE_REMOVE_JEWEL                  = 10013, // 拆除宝石
    //ITEM_LOG_TYPE_FULL_ENERGY_ADD_ITEM          = 10014, // 充能得到的物品
    //ITEM_LOG_TYPE_COMPOUND_BLACK_GOLD           = 10015, // 人造黑金合成产出
    //ITEM_LOG_TYPE_EMPTY_ENERGY_ITEM             = 10016, // 放空充能得到的物品
    //ITEM_LOG_TYPE_ADD_ITEM_FOR_BEKILLED         = 10028, // 玩家被杀产生的掉落
    //ITEM_LOG_TYPE_DROP_PVP_QUEST_ITEM           = 10028, // 掉落PVP任务物品
    //ITEM_LOG_TYPE_CREATE_COMPLEX_DROP_ITEM      = 10030, // 复杂掉落物品
    //ITEM_LOG_TYPE_CREATE_SIMPLE_DROP_ITEM       = 10031, // 简单掉落物品
    //ITEM_LOG_TYPE_EW_BEG_FAIL_RETURN_MAT        = 10035, // 能量井载具开启制造失败返还个人材料


    //玩家失去物品 20000-27999
    IITE_LOG_TYPE_LOSE_ITEM_MIN                 = 20000, //$ 20000 = 失去物品日志类型最小值

    ITEM_LOG_TYPE_DELETE                        = 20001, //$ 20001 = 被玩家删除 | "Lose Because Delete"
    ITEM_LOG_TYPE_CHUCK                         = 20002, //$ 20002 = 被玩家丢弃 | "Lose Because Chuck"
    ITEM_LOG_TYPE_PUT_ITEM_TO_RECLAIM_BOX       = 20003, //$ 20003 = 放物品到回购栏  | "Sell To BaseShop"
    ITEM_LOG_TYPE_BACKSTAGE_MODIFY              = 20004, //$ 20004 = 后台编辑玩家属性时删除道具 | "Lose Because BackStage"
    ITEM_LOG_TYPE_DEL_QUEST_DEAD                = 20005, //$ 20005 = 被杀掉落任务道具 | "Lose Because Dead"
    ITEM_LOG_TYPE_DECOMPOSE_DEL                 = 20006, //$ 20006 = 分解装备 | "Lose Because DeCompos"
    ITEM_LOG_TYPE_INHERIT_ENHANCE_CONSUME       = 20007, //$ 20007 = 强化继承消耗 | "Lose Because Enhance"
    ITEM_LOG_TYPE_FRAGMENT_COMPOSE_CONSUME      = 20008, //$ 20008 = 碎片合成消耗 | "Lose Because Compose"
    ITEM_LOG_TYPE_SAVE_STAR_SOUL_CONSUME        = 20009, //$ 20009 = 保存某星级组合消耗 | "Lose Because StarSoul"
    ITEM_LOG_TYPE_MAC_RESET_CONSUME             = 20010, //$ 20010 = 机体初始化消耗 | "Lose Because MachineReset"
    ITEM_LOG_TYPE_EW_BEGIN_CARRIER_PRODUCE      = 20011, //$ 20011 = 能量井开启载具制造个人材料消耗 | "EW Carrier Produce"
    ITEM_LOG_TYPE_RELIVE_CONSUME_ITEM           = 20012, //$ 20012 = 死亡复活消耗道具 | "Lose Because Relive"
    ITEM_LOG_TYPE_ADD_LING_QI_ITEM_CONSUME      = 20013, //$ 20013 = 刀峰战士武器吸收 | "Lose Because Weapon Absorb"
    ITEM_LOG_TYPE_DEL_LING_QI_ITEM_CONSUME      = 20014, //$ 20014 = 刀峰战士武器重铸 | "Lose Because Weapon Recast"
    ITEM_LOG_TYPE_GIVE_UP_PVP_SPY_DEL_ITEM      = 20015, //$ 20015 = 放弃PVP刺探任务删除的物品 | "Lose Because Giveup Spy"
    ITEM_LOG_TYPE_PVP_TRANSPORT_CONSUME_ITEM    = 20016, //$ 20016 = 传送PVP刺探任务删除的物品 | "Lose Because PVP Trans"
    ITEM_LOG_TYPE_PVP_SUBMIT_RECOVER_ITEM       = 20017, //$ 20017 = 提交PVP任务删除的物品 | "Submit Task: "
    ITEM_LOG_TYPE_PVP_GIVEUP_RECOVER_ITEM       = 20018, //$ 20018 = 放弃PVP任务删除的物品 | "Giveup Task: "
    ITEM_LOG_TYPE_PVP_DOFAIL_RECOVER_ITEM       = 20019, //$ 20019 = PVP任务失败删除的物品 | "Fail Task: "
    ITEM_LOG_TYPE_PVP_REFRESH_RECOVER_ITEM      = 20020, //$ 20020 = PVP任务刷新删除的物品 | "Refresh Task: "
    ITEM_LOG_TYPE_SKILL_EVENT_CONSUME_ITEM      = 20021, //$ 20021 = 技能事件消耗的物品 | "Lose Becaue SkillEvent"
    ITEM_LOG_TYPE_SKILL_CONSUME_ITEM            = 20022, //$ 20022 = 技能消耗的物品 | "Lose Because SkillConsume"
    ITEM_LOG_TYPE_UPGRADE_SKILL_CONSUME_ITEM    = 20023, //$ 20023 = 技能升级消耗的物品 | "Lose Because SkillUpgrade"
    ITEM_LOG_TYPE_BEHAVIOR_DESTROY_ITEM         = 20024, //$ 20024 = 触发器行为消耗的物品 | "Lose Because Behavior"
    ITEM_LOG_TYPE_CONTRIBUTE_MAT_TO_EW          = 20025, //$ 20025 = 给能量井捐献 | "Contribute To EW"
    ITEM_LOG_TYPE_PAY_ITEM_CONSUME              = 20026, //$ 20026 = 商店用来物品支付的物品 | "Lose Because Pay"
    //ITEM_LOG_TYPE_COMPOSE_DEL                   = 20027, //装备合成 | "Lose Because EquipCom"
    ITEM_LOG_TYPE_SUMMON_TEAMMATE_COST          = 20028, //$ 20028 = 召唤队友消耗 | "Lose Because Summon"
    ITEM_LOG_TYPE_NPC_SPRING_DEL_ITEM           = 20029, //$ 20029 = NPC触发时删除物品 | "Lose Because NpcSpring"
    ITEM_LOG_TYPE_LAVE                          = 20030, //$ 20030 = 由于装备洗点造成的消耗 | "Lose Because ItemLave"
    ITEM_LOG_TYPE_STRENG_EQUIP_MATERIAL         = 20031, //$ 20031 = 装备强化消耗的材料 | "Lose Because Strengthen"
    ITEM_LOG_TYPE_JOB_FORMULA_MATERIAL          = 20032, //$ 20032 = 职业配方消耗的材料 | "Lose Because Formula"
    ITEM_LOG_TYPE_DEL_QUEST_CRITERIA_ITEM       = 20033, //$ 20033 = 子任务删除道具 | "Lose Because QuestCriteria"
    ITEM_LOG_TYPE_DEL_QUEST_ITEM                = 20034, //$ 20034 = 提交任务删除任务道具 | "Lose Because Submit"
    ITEM_LOG_TYPE_PVP_QUEST_AWARD_DEL_ITEM      = 20035, //$ 20035 = PVP任务奖励删除道具 | "Lose Because PVP Award"
    ITEM_LOG_TYPE_AH_CONSIGN                    = 20036, //$ 20036 = 拍卖行寄售删除的物品 | "AH Consign"
    ITEM_LOG_TYPE_DEL_TRANSPORT_ITEM            = 20037, //$ 20037 = 传送删除道具 | "Lose Because Transmit"
    ITEM_LOG_TYPE_TEAM_TRANSMIT_CONSUME_ITEM    = 20038, //$ 20038 = 队伍传送消耗的物品 | "Lose Because TeamTrans"
    ITEM_LOG_TYPE_REDUCE_ARREST_CONSUME_ITEM    = 20039, //$ 20039 = 减少通缉消耗的物品 | "Lose Because Arrest"
    ITEM_LOG_TYPE_ENCHASE_DESTROY_JEWEL         = 20040, //$ 20040 = 镶嵌扣除的宝石 | "Lose Because DestroyJewel"
    ITEM_LOG_TYPE_LEARN_FORMULA_CONSUME_ITEM    = 20041, //$ 20041 = 学习职业配方消耗物品 | "Lose Because Learn Formula"
    ITEM_LOG_TYPE_TRANSTODESIGNATE_CONSUME_ITEM = 20042, //$ 20042 = 传送消耗物品 | "Lose Because Designate"
    ITEM_LOG_TYPE_TRANSTOGUILD_CONSUME_ITEM     = 20043, //$ 20043 = 公会召集消耗物品 | "Lose Because GuildCall"
    ITEM_LOG_TYPE_TRANSTOFRIEND_CONSUME_ITEM    = 20044, //$ 20044 = 朋友召集消耗物品 | "Lose Because FriendCall"
    ITEM_LOG_TYPE_TRANSTOTEAM_CONSUME_ITEM      = 20045, //$ 20045 = 队伍召集消耗物品 | "Lose Because TeamCall"
    ITEM_LOG_TYPE_COMPOUND_DESTROY_JEWEL        = 20046, //$ 20046 = 宝石合成删除的宝石 | "Del Jewel" "Create Jewel Fail"
    ITEM_LOG_TYPE_USE_SKILL_CONSUME_ITEM        = 20047, //$ 20047 = 使用技能消耗物品 | "Use Skill: "
    ITEM_LOG_TYPE_TRIGGERTASK_CONSUME_ITEM      = 20048, //$ 20048 = 任务触发消耗物品 | "Lose Because TriggerTask"
    ITEM_LOG_TYPE_USER_EXP_ITEM                 = 20049, //$ 20049 = 使用经验丹 | "Use Exp Item"
    ITEM_LOG_TYPE_USE_CRYSTAL_ITEM              = 20050, //$ 20050 = 使用能量晶体 | "Use Crystal Item"
    ITEN_LOG_TYPE_USE_VIP_ITEM                  = 20051, //$ 20051 = 使用VIP道具 | "User Vip Item"
    //ITEM_LOG_TYPE_SPLIT_DEC                     = 20052, //由于物品被拆分减少的物品 | "Lose Because Split"
    ITEM_LOG_TYPE_GM_DEL                        = 20053, //$ 20053 = GM删除 | "GM Remove" "GM Clear"
    ITEM_LOG_TYPE_RETURN_TASK_TOKEN             = 20054, //$ 20054 = 获得令牌失败返回已经获得的令牌
    //ITEM_LOG_TYPE_LOSE_MERGE                    = 20055, //由于合并道具而减少
    ITEM_LOG_TYPE_INVALID                       = 20056, //$ 20056 = ITEM到期销毁
    ITEM_LOG_TYPE_MOVE_ITEM_LOSE                = 20057, //$ 20057 = 移动物品失去物品
    ITEM_LOG_TYPE_EXCHANGE_ITEM_LOSE            = 20058, //$ 20058 = 交易失去物品
    ITEM_LOG_TYPE_ADD_RIDE_POINT_LOSE           = 20059, //$ 20059 = 使用坐骑点数道具 | "User add ride point Item"
    //ITEM_LOG_TYPE_GUILD_DEPOT_PUTOUT            = 20060, //公会 仓库 物品取出
    ITEM_LOG_TYPE_NEW_ROLE_LEAD_SAVE_EQUIP      = 20061, //$ 20061 = 保存新手装备
    ITEM_LOG_TYPE_INSCRIPTION_ITEM              = 20062, //$ 20062 = 获得铭刻物品
    ITEM_LOG_TYPE_ADD_GET_LING_QI_ITEM          = 20063, //$ 20063 = 获得刀峰战士铸造武器
    //ITEM_LOG_TYPE_DEL_GET_LING_QI_ITEM          = 20064, //重铸刀峰战士铸造武器
    ILL_WEB_SELL_ITEM                           = 20065, //$ 20065 = 道具放到线下交易平台
    ITEM_LOG_TYPE_ADDHOLE                       = 20066, //$ 20066 = 装备打孔
    ITEM_LOG_TYPE_POST_LOSE                     = 20067, //$ 20067 = 发送邮件失去物品
    ITEM_LOG_TYPE_PUT_ITEM_TO_BANK              = 20068, //$ 20068 = 放物品到银行
    ITEM_LOG_TYPE_GUILD_DEPOT_PUTIN             = 20069, //$ 20069 = 公会 仓库 物品存进
    ITEM_LOG_TYPE_ENHANCE_ITEM                  = 20070, //$ 20070 = 获得技能专精物品
    ITEM_LOG_TYPE_ENERGY_LOSE                   = 20071, //$ 20071 = 充能后删除充能ITEM
    ITEM_LOG_TYPE_EXPIRED_TIME_LOSE             = 20072, //$ 20072 = 到了指定日期，删除ITEM
    ITEM_LOG_TYPE_BAG_SELL_SUNDRIES             = 20073, //$ 20073 = 背包出售杂物删除ITEM

    IITE_LOG_TYPE_LOSE_ITEM_MAX                 = 27999, //$ 27999 = 失去物品日志类型最大值

    //ITEM_LOG_TYPE_SELL_TO_NPC                   = 20001, // 玩家出售给NPC
    //ITEM_LOG_TYPE_BLACK_MARKET_CONSIGN          = 20025, // 黑市寄售删除的物品
    //ITEM_LOG_TYPE_CLEAR_RECLAIM                 = 20027, // 清空回购栏物品
    //ITEM_LOG_TYPE_ARENA_QUEUE_SUCCESS           = 20028, // 竞技场排队成功删除物品
    //ITEM_LOG_TYPE_NEW_ROLE_LEAD_DEL_EQUIP       = 20036, // 新手引导装备
    //ITEM_LOG_TYPE_DEL_EMPTY_ENERGY_ITEM         = 20046, // 删除空充能物品 L"Use Skill: "
    //ITEM_LOG_TYPE_FULL_ENERGY_DEL_ITEM          = 20051, // 充能删除的物品
    //ITEM_LOG_TYPE_TRUMPET_DEL_ITEM              = 20053, // 世界喇叭消耗
    //ITEM_LOG_TYPE_OPEN_TREASURE_BOX             = 20003, // 开宝箱道具要删除原宝箱
    //ITEM_LOG_TYPE_SUBMIT_TOKEN                  = 20005, // 提交的能量井牌子
    //ITEM_LOG_TYPE_EQUIP_COMPOUND                = 20006, // 提交的能量井牌子
    //ITEM_LOG_TYPE_ENERGY_WELL_MATERIAL          = 20030, // 能量井充能消耗的材料
    //ITEM_LOG_TYPE_CONTRIBUTE_TO_NPC_ORG         = 20011, // 捐献给NPC组织物品

    //物品的转移 28000-29999
    IITE_LOG_TYPE_SHIFT_ITEM_MIN                = 28000, //$ 28000 = 转移物品日志类型最小值

    ITEM_LOG_TYPE_GUILD_DEPOT_CREATE            = 28001, //$ 28001 = 公会仓库物品创建
    ITEM_LOG_TYPE_GET_ITEM_FROM_WEAKBOX         = 28002, //$ 28002 = 从弱容器里取回物品
    ITEM_LOG_TYPE_MOVE_ITEM                     = 28003, //$ 28003 = 移动物品自身容器
    ITEM_LOG_TYPE_SWAP_ITEM                     = 28004, //$ 28004 = 交换物品
    ITEM_LOG_TYPE_TRANS_JOB_MOVE_EQUIP          = 28005, //$ 28005 = 转职移动不符合的衣服
    ITEM_LOG_TYPE_ARRANGE_ITEM                  = 28006, //$ 28006 = 排序
    ITEM_LOG_TYPE_BACK_STAGE_POST               = 28007, //$ 28007 = 通过后台邮件发送物品
    ITEM_LOG_TYPE_BIND                          = 28008, //$ 28008 = 绑定
    ITEM_LOG_TYPE_GET_MERGE                     = 28009, //$ 28009 = 由于合并道具而增加
    ITEM_LOG_TYPE_SPLIT_ITEM_MOVE               = 28010, //$ 28010 = 拆分物品造成的移动 |"Get From Split"
    ITEM_LOG_TYPE_COMPOSE_DEL                   = 28011, //$ 28011 = 装备合成 | "Lose Because EquipCom"
    ITEM_LOG_TYPE_SPLIT_DEC                     = 28012, //$ 28012 = 由于物品被拆分减少的物品 | "Lose Because Split"
    ITEM_LOG_TYPE_LOSE_MERGE                    = 28013, //$ 28013 = 由于合并道具而减少
    ITEM_LOG_TYPE_GUILD_DEPOT_PUTOUT            = 28014, //$ 28014 = 公会 仓库 物品取出
    ITEM_LOG_TYPE_RECLAIM_SORT                  = 28015, //$ 28015 = 回购栏物品重排序

    IITE_LOG_TYPE_SHIFT_ITEM_MAX                = 29998, //$ 29998 = 转移物品日志类型最大值
    ITEM_LOG_TYPE_MAX                           = 29999, //物品日志最大值

    //ITEM_LOG_TYPE_ORIGIN_PRIZE                  = 30005, //通过身份获得奖励
    //ITEM_LOG_TYPE_DEPOT_PUTIN                   = 20001, //仓库 物品存进
    //ITEM_LOG_TYPE_DEPOT_PUTOUT                  = 20002, //仓库 物品取出
    //ITEM_LOG_TYPE_ADDMAGIC                      = 25002, //装备附魔
    //ITEM_LOG_TYPE_ENCHASE                       = 25003, //镶嵌
    //ITEM_LOG_TYPE_UNENCHASE                     = 25004, //镶嵌拆除
};

//$@ 2  = 角色资金日志
// 增加资金的日志类型 30000-36999
enum CAPITAL_INC_LOGTYPE
{
    CAPITAL_LOG_INC_MINTYPE         = 30000,    //$ 30000 =  获得资金日志类型最小值

    // 资金来源为系统               30000-34999
    CLI_FROM_SYS_MIN                = 30000,    //

    CLI_BACKSTAGE                   = 30001,    //$ 30001 = 后台给玩家增加资金
    CLI_PICKUP_CAPITAL              = 30002,    //$ 30002 = 拾取掉落的资金
    CLI_QUERT_REWARD                = 30003,    //$ 30003 = 任务奖励
    CLI_EVENT_REWARD                = 30004,    //$ 30004 = 事件奖励
    CLI_CLONE_REWARD                = 30005,    //$ 30005 = 副本通关奖励
    CLI_GM_NOLIMIT                  = 30006,    //$ 30006 = gm命令(不受每日限额限制)
    CLI_PVP_REWARD                  = 30007,    //$ 30007 = PVP任务奖励,刺探，奇袭，空袭，押镖，刺杀替身
    CLI_ARENA_REWARD                = 30008,    //$ 30008 = 竞技场结算奖励
    CLI_VITALITY_REWARD             = 30009,    //$ 30009 = 活跃度日常奖励（每日引导活跃度奖励，每日引导推荐任务奖励）
    CLI_SYS_MAIL                    = 30010,    //$ 30010 = 系统邮件 提取资金
    CLI_REPAY                       = 30011,    //$ 30011 = 运营补偿
    CLI_VIP_GIFT                    = 30012,    //$ 30012 = VIP礼包奖励的金钱
    CLI_ENERGY_PAY                  = 30013,    //$ 30013 = 能量井居民工资发放
    CLI_BUY_CAPITAL                 = 30014,    //$ 30014 = 点数兑换得到资金
    CLI_GUILDMANORFIGHT_REWARD      = 30015,    //$ 30015 = 公会领地战奖励
    CLI_SHOPPINT                    = 30016,    //$ 30016 = 卖东西到商店获得资金
    CLI_BATTLEWAR                   = 30017,    //$ 30017 = 战场
    CLI_OFFLINE                     = 30018,    //$ 30018 = 离线
    CLI_AWARD                       = 30019,    //$ 30019 = 活动奖励
    CLI_EVERYDAYGUIDE               = 30020,    //$ 30020 = 游戏帮助
    CLI_GM                          = 30021,    //$ 30021 = gm命令
    CLI_BLACKMARKET_BILL            = 30022,    //$ 30022 = 黑市账单
    CLI_EXCHANGE_CASH               = 30023,    //$ 30023 = 点券兑换黑金 增加黑金
    CLI_EXCHANGE_GOLD               = 30024,    //$ 30024 = 黑金兑换金币 增加金币
    CLI_EWRESFIGHT                  = 30025,    //$ 30025 = 能量井战场
    CLI_ARENA                       = 30026,    //$ 30026 = 竞技场
    CLI_GET_DEPOT_CAPIAL            = 30027,    //$ 30027 = 从仓库取钱
    CLI_USE_ITEM                    = 30028,    //$ 30028 = 使用道具所得
    CLI_FAILURE_BACK                = 30029,    //$ 30029 = 因寄卖或者购买失败而退回资金
    CLI_EW_CONCONTRIBUTE            = 30030,    //$ 30030 = 玩家为能量井捐献制造载具的材料二获得的贡献点
    CLI_WEBEXCHANGE_CHARGE          = 30031,    //$ 30031 = 线下交易手续费
    CLI_CHARGE_INC                  = 30032,    //$ 30032 = 购买档案中获取
    CLI_PICK_FROM_MAIL              = 30033,    //$ 30033 = 邮箱中金钱类ITEM直接转换
    CLI_PICK_FROM_ITEM_BOX          = 30034,    //$ 30034 = 从宝箱中金钱类ITEM转换
    CLI_SELL_SUNDRIES               = 30035,    //$ 30035 = 背包处理杂物所得
    CLI_NETBAR_REWARD               = 30036,    //$ 30036 = 特权奖励

    CLI_FROM_SYS_MAX                = 34999,    //系统奖励资金的日志类型最大值 阀值

    // 资金来源为其他玩家           35000-36999
    CLI_FROM_PLAYER_MIN             = 35000,

    CLI_EXCHANGE                    = 35001,    //$ 35001 = 和玩家交易所得
    CLI_NORMAL_MAIL                 = 35002,    //$ 35002 = 从普通邮件提取

    CLI_FROM_PLAYER_MAX             = 35998,    //从玩家处获得资金日志类型最大值

    CAPITAL_LOG_INC_MAXTYPE         = 36999,    //$ 36999 = 获得资金日志类型最大值
};

// 特殊资金日志类型, 仅仅是日志
enum CAPITAL_SPECIAL_LOG_TYPE
{
    CLS_MAX_CAPITAL                 = 37001,    //$ 37001 = 资金超出最大值 没有被加上的部分
    CLS_DEC_POINT                   = 37002,    //$ 37002 = 游戏中消耗点券
};

// 扣除资金的日志类型 40000-49999
enum CAPITAL_DEC_LOGTYPE
{
    CAPITAL_DEC_MINTYPE             = 40000,    //$ 40000 = 失去资金日志类型最小值

    // 资金去向 被系统回收 40000-44999
    CLD_TO_SYS_MIN                  = 40000,

    CLD_BACKSTAGE                   = 40001,    //$ 40001 = 因为后台编辑玩家属性而扣钱
    CLD_EQUIPMENT_STRENGE           = 40002,    //$ 40002 = 装备强化制作费用
    CLD_EQUIPMENT_INHERIT           = 40003,    //$ 40003 = 继承消耗费用
    CLD_FILLIN_JEM_TO_EQUIPMENT     = 40004,    //$ 40004 = 宝石合成费用
    //CLD_REMOVE_JEM_FROM_EQUIPMENT   = 40005,    //40005 = 装备宝石摘除消耗的费用
    //CLD_COMPOSE_JEM                 = 40006,    //40006 = 宝石合成消耗的费用
    CLD_COMPOSE_EQUIPMENT           = 40007,    //$ 40007 = 装备合成制作费用
    CLD_TRANSFER                    = 40008,    //$ 40008 = 传送消耗
    //CLD_SHOPPING                    = 40009,    //40009 = 购买商店物品消耗费用
    CLD_SEND_MAIL_CONSUME           = 40010,    //$ 40010 = 邮费
    //CLD_CONTACT                     = 40011,    //40011 = 社交行为
    CLD_AIRPORT                     = 40012,    //$ 40012 = 乘坐交通工具消耗
    CLD_LEARN_LIFE_SKILL            = 40013,    //$ 40013 = 学习生活职业
    CLD_MAKE_ITEM                   = 40014,    //$ 40014 = 配方制造道具消耗金钱
    CLD_CREATE_GUILD                = 40015,    //$ 40015 = 创建工会成功
    CLD_AUCTION_DEPOSIT             = 40016,    //$ 40016 = 拍卖行寄售时保管费
    CLD_AUCTION_TRANSACT_FEE        = 40017,    //$ 40017 = 拍卖行成交时手续费
    CLD_AUCTION_BID                 = 40018,    //$ 40018 = 拍卖行竞价
    CLD_AUCTION_AUTO_BID            = 40019,    //$ 40019 = 拍卖行自动竞价预付款
    CLD_AUCTION_FIXED_PRICE         = 40020,    //$ 40020 = 拍卖行一口价
    CLD_UPGRADE_SKILL               = 40021,    //$ 40021 = 技能升级
    CLD_EQUIPMENT_SERVICE           = 40022,    //$ 40022 = 装备维护保养修理
    CLD_NORMAL_SHOPPING             = 40023,    //$ 40023 = 普通商店消费
    CLD_COMPOSE_SUCCESS_BACK        = 40024,    //$ 40024 = 装备合成后退回功能消耗金钱
    CLD_CRITICAL_MAIL               = 40025,    //$ 40025 = 加急邮件的邮费
    //CLD_QUEST                       = 40026,    //40026 = 任务
    CLD_MAIL_CONSUME                = 40027,    //$ 40027 = 付费邮件
    CLD_PET_STRENGE                 = 40028,    //$ 40028 = 宠物系统机体强化
    CLD_ENERGYWELL_FILL             = 40029,    //$ 40029 = 能量井充能消耗金钱
    CLD_ENERGYWELL_MAKE_TOWER       = 40030,    //$ 40030 = 能量井魔法制造塔制造道具
    CLD_PVP_DEPOSIT                 = 40031,    //$ 40031 = PVP任务（押镖）押金
    CLD_BIND_ITEM                   = 40032,    //$ 40032 = 绑定物品
    CLD_RELIVE                      = 40033,    //$ 40033 = 复活
    CLD_BLADERUNNER                 = 40034,    //$ 40034 = 刀锋战士
    CLD_CLONE                       = 40035,    //$ 40035 = 副本
    CLD_DEAD                        = 40036,    //$ 40036 = 死亡
    CLD_INSCRIPTION                 = 40037,    //$ 40037 = 铭刻
    CLD_EXILE_ESCAPE                = 40038,    //$ 40038 = 贿赂
    CLD_SAVE_TODEPOT                = 40039,    //$ 40039 = 存钱进仓库
    CLD_ASKTOBUY                    = 40040,    //$ 40040 = 求购行
    CLD_ASKTOBUY_BILLFEE            = 40041,    //$ 40041 = 求购行挂单费
    CLD_ASKTOBUY_PRESTORED_FEE      = 40042,    //$ 40042 = 求购行挂单预存费
    CLD_ASKTOBUY_TRANSACT_FEE       = 40043,    //$ 40043 = 求购行成交手续费
    CLD_BLACKMARKET_FIXED_BID       = 40044,    //$ 40044 = 黑市一口价
    CLD_MAX_CAPITAL                 = 40045,    //$ 40045 = vip状态消失, 资金超出最大值部分被系统回收
    CLD_ARENA                       = 40046,    //$ 40046 = 战场
    CLD_ENCHASE                     = 40047,    //$ 40047 = 镶嵌
    CLD_OFFLINE                     = 40048,    //$ 40048 = 离线
    CLD_ORGANIZATION                = 40049,    //$ 40049 = npc组织
    CLD_TOOLBOX                     = 40050,    //$ 40050 = 背包
    CLD_EVERYDAY_REFRESH            = 40051,    //$ 40051 = 每日推荐刷新
    CLD_GM                          = 40052,    //$ 40052 = gm命令
    CLD_SLOTITEM                    = 40053,    //$ 40053 = 打孔
    CLD_ENEMY_CONVEY                = 40054,    //$ 40054 = 仇敌传送
    CLD_TOOBOX_OPEN_LINK            = 40055,    //$ 40055 = 背包快捷链接
    CLD_EXTBAG                      = 40056,    //$ 40056 = 扩展背包容量
    CLD_EXTDEPOT                    = 40057,    //$ 40057 = 扩展仓库容量
    CLD_OPEN_VIP                    = 40058,    //$ 40058 = 开通VIP
    CLD_PVP_QUICK_TRANS             = 40059,    //$ 40059 = 刺杀快速传送击杀
    CLD_PVP_ASK_KILL                = 40060,    //$ 40060 = 刺杀求助击杀
    CLD_PVP_ASK_HELP                = 40061,    //$ 40061 = 刺杀求助保护
    CLD_ENERGY_UPGRADE              = 40062,    //$ 40062 = 能量盾强化
    CLD_ITEM_RESET                  = 40063,    //$ 40063 = 装备洗点
    CLD_EXCHANGE_CASH               = 40064,    //$ 40064 = 点券兑换黑金 扣除点券
    CLD_SYSTEM_TAX                  = 40065,    //$ 40065 = 系统扣税
    CLD_ENEMY_FIND                  = 40066,    //$ 40066 = 仇敌查询
    CLD_FILL_ENERGY                 = 40067,    //$ 40067 = 充能
    CLD_EXCHANGE_GOLD               = 40068,    //$ 40068 = 黑金兑换金币 扣除黑金
    CLD_ENERGYWELL_ATTACK           = 40069,    //$ 40069 = 能量井宣战
    CLD_DEPLOY_CARRIER              = 40070,    //$ 40070 = 调配载具
    CLD_EXCHAGE_RIDE_POINT          = 40071,    //$ 40071 = 兑换坐骑点数
    CLD_GM_NOLIMIT                  = 40072,    //$ 40072 = gm命令(不受每日限额限制)
    CLD_BUY_CHARGE                  = 40073,    //$ 40073 = 购买档案收费
    CLD_SEL_CHARGE_MODE             = 40074,    //$ 40074 = 选择预购模式收费
    CLD_SKILLTYPE_UNLOCK            = 40075,    //$ 40075 = 消费开技能框
    CLD_EWCAR_PRODUCE               = 40076,    //$ 40076 = 能量井载具制造
    CLD_ENERGYWELL_BUY_RIDE         = 40077,    //$ 40077 = 能量井购买载具


    CLD_TO_SYS_MAX                  = 44999,    //被系统回收最大值

    // 资金去向 交易给其他玩家 45000-49999
    CLD_TO_PLAYER_MIN               = 45000,
    CLD_EXCHANGE                    = 45001,    //$ 45001 = 玩家之间的交易
    CLD_MAIL_ATTACHMENT             = 45002,    //$ 45002 = 发送邮件给其他玩家 附送资金
    CLD_WEBEXCHANGE                 = 45003,    //$ 45003 = 线下交易游戏币(new)
    CLD_WEBEXCHANGE_CHARGE          = 45004,    //$ 45004 = 线下交易税收

    CLD_TO_PLAYER_MAX               = 45998,    //玩家失去资金的日志类型的最大值 阀值 资金去向 流通中

    CAPITAL_DEC_MAXTYPE             = 49999,    //$ 49999 = 失去资金日志类型最大值
};

//$@ 3  = 玩家日志
enum PLAYER_LOGTYPE
{
    PLAYER_LOG_BEGIN                    = 50000,     //

    PLAYER_LOG_BUY_DIRECTDEPOT          = 50001,     //$ 50001 = 购买远程仓库
    PLAYER_LOG_BEGIN_PK                 = 50002,     //$ 50002 = PK开始
    PLAYER_LOG_PK_RESULT                = 50003,     //$ 50003 = PK结果
    PLAYER_LOG_GUILD                    = 50004,     //$ 50004 = 公会相关
    PLAYER_LOG_CLONE                    = 50005,     //$ 50005 = 副本相关
    PLAYER_LOG_EXCHANGE_ITEMS           = 50006,     //$ 50006 = 玩家交易物品
    PLAYER_LOG_EXCHANGE_MONEY           = 50007,     //$ 50007 = 玩家交易钱
    PLAYER_LOG_POST                     = 50008,     //$ 50008 = 邮件相关
    PLAYER_LOG_FRIEND                   = 50009,     //$ 50009 = 好友相关
    PLAYER_LOG_JOB                      = 50010,     //$ 50010 = 生活技能相关
    PLAYER_LOG_SKILL                    = 50011,     //$ 50011 = 技能相关（招式、内功、轻功、经脉）
    PLAYER_LOG_BUY_CHARGE_ITEM          = 50012,     //$ 50012 = 从计费系统购买道具
    PLAYER_LOG_ON_DEC_POINT             = 50013,     //$ 50013 = 收到计费扣除点券的消息
    PLAYER_LOG_SEND_NEW_MAIL            = 50014,     //$ 50014 = 发送新手邮件
    PLAYER_LOG_UNENTHRALL_BREAK_PLAYER  = 50015,     //$ 50015 = 防沉迷中超时踢玩家下线
    PLAYER_LOG_FLY_CANCEL               = 50016,     //$ 50016 = 玩家在单人交通工具上意外降落
    PLAYER_LOG_LOGIN                    = 50017,     //$ 50017 = 上线
    PLAYER_LOG_LOGOUT                   = 50018,     //$ 50018 = 下线
    PLAYER_LOG_GIFT                     = 50019,     //$ 50019 = 领取计费系统奖品
    PLAYER_LOG_WEBEXCHANGE_ROLE         = 50020,     //$ 50020 = 在蜗牛集市交易角色 角色被踢下线并冻结
    PLAYER_LOG_EVERYDAY                 = 50021,     //$ 50021 = 每日引导相关
    PLAYER_LOG_NETBAR_RIGHT             = 50022,     //$ 50022 = 网吧特权日志

    PLAYER_LOG_END                      = 50999,     //
};

//typedef enum _QUEST_LOG_TYPE
//{
//    QUEST_LOG_ACCEPTED              = 1,    // 接受任务
//    QUEST_LOG_REWARDED              = 2,    // 提交任务
//    QUEST_LOG_FAILED                = 3,    // 任务失败
//    QUEST_LOG_GIVEUP                = 4,    // 放弃任务
//} QUEST_LOG_TYPE;

//typedef enum _UPGRADE_LOG_TYPE
//{
//    UPGRADE_LOG_PLAYER              = 1,    // 角色升级
//    UPGRADE_LOG_SKILL               = 2,    // 角色技能升级
//    UPGRADE_LOG_ARRESTVALUE         = 3,    // PK值ARRESTVALUE变化
//    UPGRADE_LOG_ADDHONOR_PLAYER = 4,        // 荣誉添加类型:野外杀人
//    UPGRADE_LOG_ADDHONOR_QUEST = 5,         // 荣誉添加类型:任务
//    UPGRADE_LOG_ADDHONOR_EVENT = 6,         // 荣誉添加类型:事件
//    UPGRADE_LOG_ADDHONOR_ACTIVIT = 7,       // 荣誉添加类型:活动
//    UPGRADE_LOG_ADDHONOR_DAILY_GUIDE = 8,   // 荣誉添加类型:每日引导
//    UPGRADE_LOG_ADDHONOR_PVP_QUEST = 9,     // 荣誉添加类型:PVP任务
//    UPGRADE_LOG_ADDHONOR_BATTLEFIELD = 10,  // 荣誉添加类型:战场
//    UPGRADE_LOG_ADDHONOR_ARENA = 11,        // 荣誉添加类型:竞技场
//    UPGRADE_LOG_ADDHONOR_TRIGGER = 12,      // 荣誉添加类型:触发器
//} UPGRADE_LOG_TYPE;


// 玩家游戏主要行为分类
//enum DEED_TYPE
//{
//    DEED_BEGIN                      = 0,
//    DEED_COMPLETE                   = 1,
//    DEED_MID_COMPLETE               = 2,
//};


//typedef enum _EXP_LOG_TYPE
//{
//    ADDEXP_TYPE_NPC = 0,                // 经验添加类型:打怪
//    ADDEXP_TYPE_SCENE = 1,              // 经验添加类型:副本
//    ADDEXP_TYPE_QUEST = 2,              // 经验添加类型:任务
//    ADDEXP_TYPE_EVENT = 3,              // 经验添加类型:事件
//    ADDEXP_TYPE_ACTIVIT = 4,            // 经验添加类型:活动
//    ADDEXP_TYPE_DAILY_GUIDE = 5,        // 经验添加类型:每日引导
//    ADDEXP_TYPE_PVP_QUEST = 6,          // 经验添加类型:PVP任务
//    ADDEXP_TYPE_BATTLEFIELD = 7,        // 经验添加类型:战场
//    ADDEXP_TYPE_BATTLEFIELD_KILL = 8,   // 经验添加类型:击杀
//    ADDEXP_TYPE_PLAYER_BEKILLED = 9,    // 经验添加类型:被杀
//    ADDEXP_TYPE_TRIGGER = 10,           // 经验添加类型:触发器
//    ADDEXP_TYPE_ITEM_USE = 11,          // 使用道具增加
//    ADDEXP_TYPE_EWRESFIGHT = 12,        // 经验添加类型:能量井战场
//    ADDEXP_TYPE_ARENA,
//} EXP_LOG_TYPE;

//$@ 4  = 角色传送日志
enum TRANSMIT_LOG_TYPE
{
    TRANSMIT_LOG_BEGIN              = 51000,
    TRANSMIT_LOG_BACK_STAGE         = 51001,    //$ 51001 =极效平台
    TRANSMIT_LOG_GM                 = 51002,    //$ 51002 =GM命令

    TRANSMIT_LOG_END                = 51999,
};

//$@ 5  = 角色经验日志
enum EXPERIENCE_LOG_TYPE
{
    EXPERIENCE_LOG_BEGIN            = 52000,
    EXPERIENCE_LOG_NPC              = 52001,    //$ 52001 = 经验日志类型:打怪
    EXPERIENCE_LOG_CLONESCENE       = 52002,    //$ 52002 = 经验日志类型:副本
    EXPERIENCE_LOG_QUEST            = 52003,    //$ 52003 = 经验日志类型:任务
    EXPERIENCE_LOG_EVENT            = 52004,    //$ 52004 = 经验日志类型:事件
    EXPERIENCE_LOG_ACTIVIT          = 52005,    //$ 52005 = 经验日志类型:活动
    EXPERIENCE_LOG_DAILY_GUIDE      = 52006,    //$ 52006 = 经验日志类型:每日引导
    EXPERIENCE_LOG_PVP_QUEST        = 52007,    //$ 52007 = 经验日志类型:PVP任务
    EXPERIENCE_LOG_BATTLEFIELD      = 52008,    //$ 52008 = 经验日志类型:战场
    EXPERIENCE_LOG_TRIGGER          = 52009,    //$ 52009 = 经验日志类型:触发器
    EXPERIENCE_LOG_ITEM_USE         = 52010,    //$ 52010 = 经验日志类型:使用道具
    EXPERIENCE_LOG_EWRESFIGHT       = 52011,    //$ 52011 = 经验日志类型:能量井战场
    EXPERIENCE_LOG_ARENA            = 52012,    //$ 52012 = 经验日志类型:竞技场
    EXPERIENCE_LOG_NETBAR           = 52013,    //$ 52013 = 经验日志类型:网吧特权

    EXPERIENCE_LOG_END              = 52999,
    //EXPERIENCE_LOG_BATTLEFIELD_KILL = 12009,    // 经验日志类型:击杀
    //EXPERIENCE_LOG_PLAYER_BEKILLED  = 12010,    // 经验日志类型:被杀
};

//$@ 6  = 角色升级日志
enum UPGRADE_LOG_TYPE
{
    UPGRADE_LOG_BEGIN               = 53000,       //
    UPGRADE_LOG_PLAYER              = 53001,       //$ 53001 = 角色升级
    UPGRADE_LOG_SKILL               = 53002,       //$ 53002 = 角色技能升级
    //UPGRADE_LOG_ARRESTVALUE         = 53003,     // 53003 = PK值ARRESTVALUE变化
    UPGRADE_LOG_RANK                = 53004,       //$ 53004 = 军阶升级
    //UPGRADE_LOG_ADDHONOR_PLAYER      = 53004,       // 荣誉添加类型:野外杀人
    //UPGRADE_LOG_ADDHONOR_QUEST       = 53005,       // 荣誉添加类型:任务
    //UPGRADE_LOG_ADDHONOR_EVENT       = 53006,       // 荣誉添加类型:事件
    //UPGRADE_LOG_ADDHONOR_ACTIVIT     = 53007,       // 荣誉添加类型:活动
    //UPGRADE_LOG_ADDHONOR_DAILY_GUIDE = 53008,       // 荣誉添加类型:每日引导
    //UPGRADE_LOG_ADDHONOR_PVP_QUEST   = 53009,       // 荣誉添加类型:PVP任务
    //UPGRADE_LOG_ADDHONOR_BATTLEFIELD = 53010,       // 荣誉添加类型:战场
    //UPGRADE_LOG_ADDHONOR_ARENA       = 53011,       // 荣誉添加类型:竞技场
    //UPGRADE_LOG_ADDHONOR_TRIGGER     = 53012,       // 荣誉添加类型:触发器

    UPGRADE_LOG_END                 = 53999,       //
};

// $@ 7  = 角色物品增强日志
enum ITEM_CHANGE_LOG_TYPE
{
    ITEM_CHANGE_LOG_BEGIN           = 54000,    //
    ITEM_CHANGE_LOG_ENHANCE         = 54001,    //$ 54001 = 装备强化  | CLIENT_CUSTOMMSG_STRENGTHEN_EXECUTE
    ITEM_CHANGE_LOG_COMPOUND_JEWEL  = 54002,    //$ 54002 = 宝石合成  | CLIENT_CUSTOMMSG_ENCHASE_COMPOUND
    ITEM_CHANGE_LOG_COMPOUND_EQUIP  = 54003,    //$ 54003 = 装备合成  | CLIENT_CUSTOMMSG_COMPOUNDITEM
    ITEM_CHANGE_LOG_SLOT            = 54004,    //$ 54004 = 装备打孔  | CLIENT_CUSTIOMMSG_SLOTITEM
    ITEM_CHANGE_LOG_ENERGY_UPGRADE  = 54005,    //$ 54005 = 能量盾强化  | CLIENT_CUSTOMMSG_ENERGY_UPGRADE

    ITEM_CHANGE_LOG_END             = 54999,    //
};

// $@ 8  = 角色登录日志
enum LOGIN_LOG_TYPE
{
    LOGIN_LOG_BEGIN                 = 55000,    //
    LOGIN_LOG_RECOVER               = 55001,    //$ 55001 = 登录进入游戏
    LOGIN_LOG_CONTINUE              = 55002,    //$ 55002 = 继续游戏(顶号)
    LOGIN_LOG_DISCONNECT            = 55003,    //$ 55003 = 断开连接
    LOGIN_LOG_STORE                 = 55004,    //$ 55004 = 角色保存退出

    LOGIN_LOG_END                   = 55999,    //
};

//$@ 9  = 角色切换场景日志
enum SCENE_LOG_TYPE
{
    SCENE_LOG_BEGIN                 = 56000,    //
    SCENE_LOG_AFTERENTRYSCENE       = 56001,    //$ 56001 = 进入场景
    SCENE_LOG_LEAVESCENE            = 56002,    //$ 56002 = 离开场景

    SCENE_LOG_END                   = 56999,    //
};

//$@ 10 = 角色任务日志
enum TASK_LOG_TYPE
{
    TASK_LOG_BEGIN                  = 57000,
    TASK_LOG_ACCEPT                 = 57001,    //$ 57001 = 接受任务
    TASK_LOG_REWARD                 = 57002,    //$ 57002 = 提交任务
    TASK_LOG_FAIL                   = 57003,    //$ 57003 = 任务失败
    TASK_LOG_GIVEUP                 = 57004,    //$ 57004 = 放弃任务

    TASK_LOG_END                    = 57999,
};

//$@ 11 = 角色创建删除日志
enum CREATE_DELETE_LOG_TYPE
{
    CREATE_DELETE_LOG_BEGIN         = 58000,    //
    CREATE_DELETE_LOG_CREATE        = 58001,    //$ 58001 = 创建角色
    CREATE_DELETE_LOG_DELETE        = 58002,    //$ 58002 = 删除角色

    CREATE_DELETE_LOG_END           = 58999,    //
};

//$@ 12 = 角色交易日志
enum EXCHANGE_LOG_TYPE
{
    EXCHANGE_LOG_BEGIN              = 59000,    //
    EXCHANGE_LOG_EXCHANGE           = 59001,    //$ 59001 = 直接交易
    EXCHANGE_LOG_COMMON_MAIL_SEND   = 59002,    //$ 59002 = 普通邮件(寄信)
    EXCHANGE_LOG_COMMON_MAIL_GET    = 59003,    //$ 59003 = 普通邮件(收信)
    EXCHANGE_LOG_TRADE_MAIL_SEND    = 59004,    //$ 59004 = 付费邮件(寄信)
    EXCHANGE_LOG_TRADE_MAIL_GET     = 59005,    //$ 59005 = 付费邮件(收信)
    EXCHANGE_LOG_TRADE_MAIL_PAY     = 59006,    //$ 59006 = 付费邮件(付费)
    EXCHANGE_LOG_MAIL_BACK          = 59007,    //$ 59007 = 邮件(退信)
    EXCHANGE_LOG_COMMON_MAIL_FUND   = 59008,    //$ 59008 = 普通邮件(付费款)
    EXCHANGE_LOG_MAIL_DEL           = 59009,    //$ 59009 = 删除信件

    EXCHANGE_LOG_END                = 59999,    //
};

//$@ 13 = 角色公会日志
enum GUILD_LOG_TYPE
{
    GUILD_LOG_BEGIN                 = 60000,
    GUILD_LOG_CREATE                = 60001,    //$ 60001 = 创建公会
    GUILD_LOG_ACCEPT_MEMBER         = 60002,    //$ 60002 = 接受玩家入会添加新成员
    GUILD_LOG_REJECT_MEMBER         = 60003,    //$ 60003 = 拒绝玩家入会
    GUILD_LOG_SET_NOTICE            = 60004,    //$ 60004 = 设置公会公告信息
    GUILD_LOG_SET_AUTHORITY         = 60005,    //$ 60005 = 设置职位权限
    GUILD_LOG_QUIT_GUILD            = 60006,    //$ 60006 = 申请退出公会
    GUILD_LOG_CHANGE_POSITION       = 60007,    //$ 60007 = 改变成员职位
    GUILD_LOG_DISBAND               = 60008,    //$ 60008 = 帮主解散帮派
    GUILD_LOG_CANCEL_DISBAND        = 60009,    //$ 60009 = 官员停止解散公会
    GUILD_LOG_QUIT_LEADER           = 60010,    //$ 60010 = 转让会长
    GUILD_LOG_DEL_MEMBER            = 60011,    //$ 60011 = 踢出公会
    GUILD_LOG_DEPOT_SET_LEVEL       = 60012,    //$ 60012 = 改变公会仓库容量
    GUILD_LOG_DEPOT_ITEM_ADD        = 60013,    //$ 60013 = 增加公会仓库物品
    GUILD_LOG_DEPOT_ITEM_SUB        = 60014,    //$ 60014 = 取出公会仓库物品
    GUILD_LOG_DISBAND_RESULT        = 60015,    //$ 60015 = 公会解散成功
    GUILD_LOG_OK_MEMBER             = 60016,    //$ 60016 = 玩家同意加入公会
    GUILD_LOG_CANCEL_MEMBER         = 60017,    //$ 60017 = 玩家拒绝加入公会
    GUIID_LOG_CAPITAL_GOLD          = 60018,    //$ 60018 = 捐献金钱
    GUILD_LOG_UP_LEVEL              = 60019,    //$ 60019 = 公会升级
    GUILD_LOG_STATE_RECRUIT         = 60020,    //$ 60020 = 设置公会远程招募状态结果
    GUILD_LOG_MEM_DEGREE            = 60021,    //$ 60021 = 设置公会成员等级结果
    GUILD_LOG_REMOVE_ITEM           = 60022,    //$ 60022 = 删除仓库物品成功
    GUILD_LOG_ADD_CAPACITY          = 60023,    //$ 60023 = 增加仓库容量成功
    GUILD_LOG_ADD_CAPITAL           = 60024,    //$ 60024 = 仓库资金增加成功
    GUILD_LOG_SUB_CAPITAL           = 60025,    //$ 60025 = 仓库资金减少成功
    GUILD_LOG_BUILD_RELATION        = 60026,    //$ 60026 = 创建公会关系成功
    GUILD_LOG_DISBAND_RELATION      = 60027,    //$ 60027 = 解散公会关系成功

    GUILD_LOG_END                   = 60999,
};

//$@ 14 = 角色惩罚日志
enum PUNISH_LOG_TYPE
{
    PUNISH_LOG_BEGIN                = 61000,    //
    PUNISH_LOG_SILENCE              = 61001,    //$ 61001 = 禁言惩罚
    PUNISH_LOG_FREEZEN              = 61002,    //$ 61002 = 冻结惩罚
    PUNISH_LOG_EXILE3               = 61003,    //$ 61003 = 三级关押
    PUNISH_LOG_EXILE4               = 61004,    //$ 61004 = 四级关押
    PUNISH_LOG_END                  = 61999,    //
};

//$@ 15 = 角色荣誉日志
enum HONOR_LOG_TYPE
{
    HONOR_LOG_BEGIN                 = 62000,       //
    HONOR_LOG_KILL_PLAYER           = 62001,       //$ 62001 = 荣誉添加类型:野外杀人
    HONOR_LOG_QUEST                 = 62002,       //$ 62002 = 荣誉添加类型:任务
    HONOR_LOG_EVENT                 = 62003,       //$ 62003 = 荣誉添加类型:事件
    HONOR_LOG_ACTIVIT               = 62004,       //$ 62004 = 荣誉添加类型:活动
    HONOR_LOG_DAILY_GUIDE           = 62005,       //$ 62005 = 荣誉添加类型:每日引导
    HONOR_LOG_PVP_QUEST             = 62006,       //$ 62006 = 荣誉添加类型:PVP任务
    HONOR_LOG_BATTLEFIELD           = 62007,       //$ 62007 = 荣誉添加类型:战场
    HONOR_LOG_ARENA                 = 62008,       //$ 62008 = 荣誉添加类型:竞技场
    HONOR_LOG_TRIGGER               = 62009,       //$ 62009 = 荣誉添加类型:触发器

    HONOR_LOG_END                   = 62999,       //
};

//$@ 16 = 角色玩法日志
enum ENJOY_LOG_TYPE
{
    ENJOY_LOG_BEGIN                     = 63000,       //

    ENJOY_EVENTSPRING                   = 63001,       //$ 63001 = 动态事件
    ENJOY_CLONE                         = 63002,       //$ 63002 = 副本
    ENJOY_ARENA                         = 63003,       //$ 63003 = 竞技场
    ENJOY_BATTLE                        = 63004,       //$ 63004 = 战场
    ENJOY_FRIST                         = 63005,       //$ 63005 = 新手副本
    ENJOY_RISK                          = 63006,       //$ 63006 = 冒险
    ENJOY_DUEL                          = 63007,       //$ 63007 = 决斗
    ENJOY_ENGWELL                       = 63008,       //$ 63008 = 能量井

    ENJOY_EVENTSPRING_LOG_START         = 63101,       //$ 63101 = 开启:动态事件
    ENJOY_EVENTSPRING_LOG_OVER          = 63102,       //$ 63102 = 结束:动态事件
    ENJOY_EVENTSPRING_LOG_PERSON_OVER   = 63103,       //$ 63103 = 事件:子目标完成

    ENJOY_CLONE_LOG_ENTRY               = 63201,       //$ 63201 = 进入:副本
    ENJOY_CLONE_LOG_OVER                = 63202,       //$ 63202 = 结束:副本
    ENJOY_CLONE_LOG_ERROR               = 63203,       //$ 63203 = 掉线离开:副本

    ENJOY_ARENA_LOG_ENTRY               = 63301,       //$ 63301 = 进入:竞技场
    ENJOY_ARENA_LOG_OVER_WIN            = 63302,       //$ 63302 = 结束:竞技场:胜利
    ENJOY_ARENA_LOG_OVER_LOSE           = 63303,       //$ 63303 = 结束:竞技场:失败
    ENJOY_ARENA_LOG_OVER_TIE            = 63304,       //$ 63304 = 结束:竞技场:平局
    ENJOY_ARENA_LOG_ERROR               = 63305,       //$ 63305 = 异常:竞技场

    ENJOY_BATTLE_LOG_ENTRY              = 63401,       //$ 63401 = 进入:战场
    ENJOY_BATTLE_LOG_OVER_WIN           = 63402,       //$ 63402 = 结束:战场:胜利
    ENJOY_BATTLE_LOG_OVER_LOSE          = 63403,       //$ 63403 = 结束:战场:失败
    ENJOY_BATTLE_LOG_OVER_TIE           = 63404,       //$ 63404 = 结束:战场:平局
    ENJOY_BATTLE_LOG_MIDWAY_LEVEL       = 63405,       //$ 63405 = 战场:中途退出
    ENJOY_BATTLE_LOG_ERROR              = 63406,       //$ 63406 = 战场中掉线(不一定退出战场)

    ENJOY_FRIST_LOG_ENTRY               = 63501,       //$ 63501 = 进入:新手副本
    ENJOY_FRIST_LOG_OVER                = 63502,       //$ 63502 = 结束:新手副本
    ENJOY_FRIST_LOG_ERROR               = 63503,       //$ 63503 = 异常:新手副本

    ENJOY_RISK_LOG_START                = 63601,       //$ 63601 = 接受冒险任务
    ENJOY_RISK_LOG_SUBMIT               = 63602,       //$ 63602 = 提交冒险任务
    ENJOY_RISK_LOG_FAILED               = 63603,       //$ 63603 = 冒险任务失败
    ENJOY_RISK_LOG_GIVEUP               = 63604,       //$ 63604 = 放弃冒险任务

    ENJOY_DUEL_LOG_START                = 63701,       //$ 63701 = 开始:决斗
    ENJOY_DUEL_LOG_OVER_WIN             = 63702,       //$ 63702 = 结束:决斗:胜利
    ENJOY_DUEL_LOG_OVER_LOSE            = 63703,       //$ 63703 = 结束:决斗:失败
    ENJOY_DUEL_LOG_ERROR                = 63704,       //$ 63704 = 逃跑:决斗

    ENJOY_ENGWELL_LOG_START             = 63801,       //$ 63801 = 参加能量井战场
    ENJOY_ENGWELL_LOG_LEAVE             = 63802,       //$ 63802 = 离开能量井战场
    ENJOY_ENGWELL_LOG_AWARD_WIN         = 63803,       //$ 63803 = 能量井战场领奖(胜利)
    ENJOY_ENGWELL_LOG_AWARD_LOSE        = 63804,       //$ 63804 = 能量井战场领奖(失败)
    ENJOY_ENGWELL_LOG_BID_SUC           = 63805,       //$ 63805 = 竞标能量井，出价成功
    ENJOY_ENGWELL_LOG_BID_FAIL          = 63806,       //$ 63806 = 竞标能量井，出价失败
    ENJOY_ENGWELL_LOG_BID_BACK          = 63807,       //$ 63807 = 竞标能量井，出价被顶，退回资金
    ENJOY_ENGWELL_LOG_BID_FINAL         = 63808,       //$ 63808 = 竞标能量井，成功

    ENJOY_LOG_END                       = 64999,       //
};

//$@ 17 = 非法请求日志
enum ILLEGAL_REQ_LOG_TYPE
{
    ILLEGAL_REQ_BEGIN                   = 65000,        //
    ILLEGAL_REQ_LOG                     = 65001,        //$ 65001 = 非法请求日志
    ILLEGAL_REQ_GPK_CHECK               = 65002,        //$ 65002 = GPK检测到外挂
    ILLEGAL_REQ_MONITOR                 = 65003,        //$ 65003 = 检测移动监控消息
    ILLEGAL_REQ_END                     = 65999,        //
};

//$@ 18 = 拍卖行日志
enum AUCTION_LOG_TYPE
{
    AUCTION_LOG_BEGIN                   = 66000,        //
    AUCTION_LOG_CONSIGN                 = 66001,        //$ 66001 = 寄售（扣金币、扣物品）
    AUCTION_LOG_CANCEL_CONSIGN          = 66002,        //$ 66002 = 取消寄售（得物品）
    AUCTION_LOG_BID                     = 66003,        //$ 66003 = 出价（扣黑金）
    AUCTION_LOG_FIXED_BID               = 66004,        //$ 66004 = 一口价（扣黑金）
    AUCTION_LOG_PRICE_BEATEN            = 66005,        //$ 66005 = 出价被顶（得黑金）
    AUCTION_LOG_BID_DOWN                = 66006,        //$ 66006 = 成功买下物品（得物品）
    AUCTION_LOG_SOLD                    = 66007,        //$ 66007 = 成功出售物品（得钱）
    AUCTION_LOG_TIME_OUT_SOLD           = 66008,        //$ 66008 = 物品到期下架售出（得钱）
    AUCTION_LOG_TIME_OUT_UNSOLD         = 66009,        //$ 66009 = 物品到期下架未售出（得物品）
    AUCTION_LOG_END                     = 66999,        //
};

#define  STR_TIME_MAX_LENGTH  64
#define  STR_LOG_COMMON_LENGTH  128
#define  STR_LOG_MAX_LENGTH     256
#define  STR_LOG_COMMENT_LENGTH  128

#endif  // __LogDefine_h__
