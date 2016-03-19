//--------------------------------------------------------------------
// 文件名:      SwitchDefine.h
// 内  容:      游戏开关统一类型定义
// 说  明:      需要与客户端脚本 \form_stage_main\switch\switch_define.lua  服务端配置 \ini\Rule\SwitchManager.xml 保持一致
// 创建日期:    2012年4月26日
// 创建人:      yinxiang
// 维护人:      胡添
// 版权所有:    苏州蜗牛电子有限公司
//--------------------------------------------------------------------
#ifndef _SWITCH_DEFINE_H_
#define _SWITCH_DEFINE_H_

// 公共数据域名定义
//#define SWITCH_DATA_NAME L"AA_Domain_Switch"  // 说明：前缀AA_是为了保证加载顺序排在第一个，牵扯到活动开关的，域名顺序要在开关模块后面

// 开关标志表
#define SWITCH_RECORD "Switch_Record"

// 需要设置开关的类型定义       //         必须保持一致 \ini\Rule\SwitchManager.xml  \form_stage_main\switch\switch_define.lua

//$@ Switch
enum ENUM_SWITCH_TYPE
{
    // 游戏功能开关
    ST_FUNCTION_MIN                         = 0,

    ST_FUNCTION_AUCTION_SELL                = 1,            // $ 1  = 拍卖行出售
    ST_FUNCTION_AUCTION_BUY                 = 2,            // $ 2  = 拍卖行购买
    ST_FUNCTION_SELL_BY_GOLD                = 3,            // $ 3  = 出售物品给NPC (得到金币)
    ST_FUNCTION_BUY_BY_GOLD                 = 4,            // $ 4  = 从NPC购买 (用金币)
    ST_FUNCTION_ITEM_STRENGTHEN             = 5,            // $ 5  = 装备强化
    ST_FUNCTION_ITEM_SLOT                   = 6,            // $ 6  = 装备打孔
    ST_FUNCTION_ITEM_ENCHASE                = 7,            // $ 7  = 装备镶嵌
    ST_FUNCTION_ITEM_REFINE                 = 8,            // $ 8  = 装备洗炼
    ST_FUNCTION_ITEM_INHERIT                = 9,            // $ 9  = 装备保值继承
    ST_FUNCTION_LIFE_PRODUCE                = 10,           // $ 10 = 生活职业制作
    ST_FUNCTION_BUY_BY_HUNT                 = 11,           // $ 11 = 从NPC购买 (用猎杀点数)
    ST_FUNCTION_BUY_BY_HEROIC               = 12,           // $ 12 = 从NPC购买 (用英勇点数)
    ST_FUNCTION_BUY_BY_DECAPITATE           = 13,           // $ 13 = 从NPC购买 (用斩首荣誉勋章)
    ST_FUNCTION_USE_BLACKGOLD               = 14,           // $ 14 = 使用黑金
    ST_FUNCTION_USE_TICKET                  = 15,           // $ 15 = 使用点券
    ST_FUNCTION_JEWEL_COMPOUND              = 16,           // $ 16 = 宝石合成
    ST_FUNCTION_EQUIP_COMPOUND              = 17,           // $ 17 = 装备合成
    ST_FUNCTION_WEBEXCHANGE                 = 18,           // $ 18 = 线下交易开关(蜗牛集市)
    ST_FUNCTION_EXCHANGE_ROLE               = 19,           // $ 19 = 角色交易开关(蜗牛集市)
    ST_LOG_TYPE_WEBEXCHANGE                 = 20,           // $ 20 = 线下交易平台日志(蜗牛集市)
    ST_FUNCTION_GPK_CLOSE                   = 21,           // $ 21 = 关闭GPK
    ST_FUNCTION_SPEED_CHECK                 = 22,           // $ 22 = 加速处罚功能开关
    ST_FUNCTION_DIRECT_DEAL                 = 23,           // $ 23 = 玩家间直接交易

    ST_FUNCTION_MAX,
};

#endif // _SWITCH_DEFINE_H_
