//--------------------------------------------------------------------
// �ļ���:      SwitchDefine.h
// ��  ��:      ��Ϸ����ͳһ���Ͷ���
// ˵  ��:      ��Ҫ��ͻ��˽ű� \form_stage_main\switch\switch_define.lua  ��������� \ini\Rule\SwitchManager.xml ����һ��
// ��������:    2012��4��26��
// ������:      yinxiang
// ά����:      ����
// ��Ȩ����:    ������ţ�������޹�˾
//--------------------------------------------------------------------
#ifndef _SWITCH_DEFINE_H_
#define _SWITCH_DEFINE_H_

// ����������������
//#define SWITCH_DATA_NAME L"AA_Domain_Switch"  // ˵����ǰ׺AA_��Ϊ�˱�֤����˳�����ڵ�һ����ǣ��������صģ�����˳��Ҫ�ڿ���ģ�����

// ���ر�־��
#define SWITCH_RECORD "Switch_Record"

// ��Ҫ���ÿ��ص����Ͷ���       //         ���뱣��һ�� \ini\Rule\SwitchManager.xml  \form_stage_main\switch\switch_define.lua

//$@ Switch
enum ENUM_SWITCH_TYPE
{
    // ��Ϸ���ܿ���
    ST_FUNCTION_MIN                         = 0,

    ST_FUNCTION_AUCTION_SELL                = 1,            // $ 1  = �����г���
    ST_FUNCTION_AUCTION_BUY                 = 2,            // $ 2  = �����й���
    ST_FUNCTION_SELL_BY_GOLD                = 3,            // $ 3  = ������Ʒ��NPC (�õ����)
    ST_FUNCTION_BUY_BY_GOLD                 = 4,            // $ 4  = ��NPC���� (�ý��)
    ST_FUNCTION_ITEM_STRENGTHEN             = 5,            // $ 5  = װ��ǿ��
    ST_FUNCTION_ITEM_SLOT                   = 6,            // $ 6  = װ�����
    ST_FUNCTION_ITEM_ENCHASE                = 7,            // $ 7  = װ����Ƕ
    ST_FUNCTION_ITEM_REFINE                 = 8,            // $ 8  = װ��ϴ��
    ST_FUNCTION_ITEM_INHERIT                = 9,            // $ 9  = װ����ֵ�̳�
    ST_FUNCTION_LIFE_PRODUCE                = 10,           // $ 10 = ����ְҵ����
    ST_FUNCTION_BUY_BY_HUNT                 = 11,           // $ 11 = ��NPC���� (����ɱ����)
    ST_FUNCTION_BUY_BY_HEROIC               = 12,           // $ 12 = ��NPC���� (��Ӣ�µ���)
    ST_FUNCTION_BUY_BY_DECAPITATE           = 13,           // $ 13 = ��NPC���� (��ն������ѫ��)
    ST_FUNCTION_USE_BLACKGOLD               = 14,           // $ 14 = ʹ�úڽ�
    ST_FUNCTION_USE_TICKET                  = 15,           // $ 15 = ʹ�õ�ȯ
    ST_FUNCTION_JEWEL_COMPOUND              = 16,           // $ 16 = ��ʯ�ϳ�
    ST_FUNCTION_EQUIP_COMPOUND              = 17,           // $ 17 = װ���ϳ�
    ST_FUNCTION_WEBEXCHANGE                 = 18,           // $ 18 = ���½��׿���(��ţ����)
    ST_FUNCTION_EXCHANGE_ROLE               = 19,           // $ 19 = ��ɫ���׿���(��ţ����)
    ST_LOG_TYPE_WEBEXCHANGE                 = 20,           // $ 20 = ���½���ƽ̨��־(��ţ����)
    ST_FUNCTION_GPK_CLOSE                   = 21,           // $ 21 = �ر�GPK
    ST_FUNCTION_SPEED_CHECK                 = 22,           // $ 22 = ���ٴ������ܿ���
    ST_FUNCTION_DIRECT_DEAL                 = 23,           // $ 23 = ��Ҽ�ֱ�ӽ���

    ST_FUNCTION_MAX,
};

#endif // _SWITCH_DEFINE_H_
