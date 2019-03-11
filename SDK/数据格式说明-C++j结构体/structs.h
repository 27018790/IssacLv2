//////////////////////////////////////////////////////////////////////////
// ���ο������ݰ���ʽ����
// ��ϵͳ�ǽ�������UDP��ʽ��ʽ���㷢�͵�һ̨�����ϣ�������IP),���ο���ֻ��Ҫ����12415�˿ھͿ����յ�����
// Ȼ���ձ��ĵ�������������ʽ�������ݰ��Ϳ����յ�����
//////////////////////////////////////////////////////////////////////////
#pragma once
#pragma pack(push, 1)
#include <vector>

// �嵵�������ݽṹ
typedef struct QuoteL1
{
	short		usNumber;
	long		dwTim32; // time ����ʱ��
	long		lgOpen;  // ���̼�
	long		lgHigh;  // ��߼�
	long		lgLow;   // ��ͼ�
	long		lgNew;	 // ���¼�
	long		lgAllVol;// �ɽ�����
	union
	{
		struct{
			long		lgAllAmount; // �ɽ����-��δ���ܣ��ͻ������
			long		lgNeipan;	 // δ�������������ͻ������
		}DW;
		double dlbAmount;			 // ���ܺ�ɽ����ͻ�ʹ��
	};
	//long		lgAllAmount; // �ɽ����-��δ����
	//double		dblAmount;	 // ���ܺ�
	//long		lgMarketVal; // ����ֵ
	long		lgTotalDealtNum; // �ܳɽ�����
	long		lgPricesOfBid[5]; // �嵵���̼۸�
	long		lgVolumeOfBid[5]; // �嵵������
	long		lgPricesOfAsk[5]; // �嵵���̼۸�
	long		lgVolumeOfAsk[5]; // �嵵������
	//long		lgZero[2];
	//double		dblNeipan;
	long		lgNeipan;	// ���ܺ����������ͻ�ʹ��
	long		lgZero;
}QL1, *LPQL1;

typedef struct OrderDetail			// ���ί����ϸ�ṹ
{						
	char		market[2];			// �г�����SH,SZ
	short		usNumber;			// ��Ʊ�ڲ���ţ����ÿ���
	int			nNumOfOrders;		// orders data���ܳ���
	int			nOrdersData[0];		// ί�ж������ݣ�ע���������Ľ�����ʽΪ�� ��WORD(�۸�+WORD(��������Ϊ���̣�����Ϊ���̣�+INT(ί������������+INT...(ί�������飩����Ȼ���ظ���������Ľṹ��ֱ��
}ORDERDETAIL, *LPORDERDETAIL;	

// ʮ���������ݽṹ
typedef struct QuoteL2
{
	char		cMarket[2];
	short		usNumber;
	float		fltBuyEven;
	float		fltBuyVol;
	float		fltSellEven;
	float		fltSellVol;
	float		fltPricesOfBid[5];
	float		fltVolumeOfBid[5];
	float		fltPricesOfAsk[5];
	float		fltVolumeOfAsk[5];

}QuoteL2, *LPQuoteL2;
template<typename T>
struct _Datagram
{
	int  nDgType;
	UINT nCount;
	UINT nSize;
	struct Ext
	{
		char cCode[16];
		char cName[16];
		UINT nPrevClose;
		UINT nTopLtd;
		UINT nBotLtd;
		T	 quote;
	};

	Ext	extData[0];
};

template<typename T>
struct _DataPackage
{
	int nDgType;
	UINT nCount;
	UINT nSize;
	T date_t[0];
};

// ���߾������ݽṹ
typedef struct MarketBoardInfo{
	char	strCode[16];	//��Ʊ����
	char	strInfo[48];	//������Ϣ
}*LPMarketBoardInfo;

typedef struct _ZHUBIDATA_
{
	UINT32		lgTime;		//��ʳɽ�ʱ��
	UINT32		fltPrice;	//��ʳɽ��۸�
	INT			lgVolume;	//��ʳɽ���
}*LPZHUBIDATA, ZHUBIDATA;

typedef struct _BIGORDER_	// ������
{
	UINT32		unOrderPackId;	// �����ݰ�ID����������ʳɽ�����ƥ���
	UINT32		unBuyOrderId;	// �򵥴�ID,���ֽ���һ����־����λ3�ֽڱ�ʾ���ţ�ͬһ���󵥱���ֳɶ��С���ɽ�ʱ��ID��ͬ����ͻ��Լ���ֽ���
	UINT32		unSellOrderId;	// ������ID,���ֽ���һ����־����λ3�ֽڱ�ʾ���ţ�ͬһ���󵥱���ֳɶ��С���ɽ�ʱ��ID��ͬ����ͻ��Լ���ֽ���
	UINT32		unBuyPrice;		// �򵥼۸�
	UINT32		unSellPrice;	// �����۸�
	UINT32		unBuyVol;	// ����
	UINT32		unSellVol;	// ������
}*LPBIGORDER, BIGORDER;

typedef struct _ZHUBILIST_
{
	CHAR		cMarket[2];
	USHORT		usNumber;
	DWORD		dwUnknown1;
	DWORD		dwUnknown2;
	ZHUBIDATA	zbDataList[0];
}*LPZHUBILIST, ZHUBILIST;

// �ٵ��̿���ϸ
typedef struct _MULTI_PANKOU_DETAIL_
{
	int	  sLevelNum;				// ����������Ϊ���̵�������Ϊ���̵�
	int	  nPrice;					// �̿ڼ۸�
	int   nVolume;					// �̿�ί����
	int	  nOrderNum;				// ί�б���
}MULTI_PANKOU_DETAIL, *LPMULTI_PANKOU_DETAIL;

// 
typedef struct _ZHUBIDATAGRAM_
{
	int		nDgType;	   // ��ʳɽ����ݰ����ͣ�4
	UINT	nCount;
	UINT	nLastestCount; // ��ʾzbDataList�����������������0��ʼ��
	UINT	nOrderPackId;
	char	strCode[16];
	char	strName[32];
	ZHUBIDATA	zbDataList[0];
}*LPZHUBIDATAGRAM, ZHUBIDATAGRAM;

typedef struct _ZHUBI_ORDER_DATAGRAM_
{
	int			nDgType; // 5		���ί�����ݰ����ͣ�5
	int			nSize;		//		������С������ǰ���nDgType	
	char		strCode[16];//		��Ʊ����
	char		strName[32];//		��Ʊ����
	ORDERDETAIL	orddObj;	//		ί����ϸ
}ZHUBI_ORDER_DATAGRAM, *LPZHUBI_ORDER_DATAGRAM;

typedef struct _BIG_ORDER_DATAGRAM_
{
	int			nDgType; // 8		�����ݰ����ͣ�8
	int			nCount; //			������
	char		strCode[16];//		��Ʊ����
	char		strName[32];//		��Ʊ����
	BIGORDER	bigOrders[0];	//	������		
}*LPBIGORDERDATAGRAM, BIGORDERDATAGRAM;

typedef struct _MULTI_PANKOU_DATAGRAM_
{
	int			nDlgType;// 6		�ٵ��̿�
	int			nSize;	//			������С
	char		strCode[16];//		��Ʊ����
	char		strName[32];//		��Ʊ����
	int			nLevelNum;	//		�ܵ���
	MULTI_PANKOU_DETAIL pkData[0];
}MULTI_PANKOU_DATAGRAM, *LPMULTI_PANKOU_DATAGRAM;

typedef struct _HIGH_LEVEL_QUOTE
{
	char	cUnknownChars[9];		//δ֪�ֽڣ�����
	char	market[2];				//�г�
	short	usNumber;				//��Ʊ�ڲ����룬���ÿ���
	float	fltAvgPriceBid;			//ί�����
	float	fltTotalVolBid;			//��������
	float	fltAvgPriceAsk;			//ί������
	float	fltTotalVolAsk;			//ί������
	float	fltBidPrices[5];		//�����۵���10��
	float	fltBidVolume[5];		//����������10��
	float	fltAskPrices[5];		//�����۵���10��
	float	fltAskVolume[5];		//����������10��
}HIGH_LEVEL_QUOTE, *LPHIGH_LEVEL_QUOTE;



typedef struct _HIGH_LVQUOTE_DATAGRAM_
{
	int			nDgType;	// 		���嵵�̿����ݰ����ͣ�6
	int			nSize;		//		������С������ǰ���nDgType	
	char		strCode[16];//		��Ʊ����
	char		strName[32];//		��Ʊ����
	HIGH_LEVEL_QUOTE	quoteObj;	//		���嵵����
}HIGH_LVQUOTE_DATAGRAM, *LPHIGH_LVQUOTE_DATAGRAM;

typedef struct _QIQUAN_DATA_
{
	short		sUnknown;
	unsigned	unTime;	   	//	UNIXʱ���
	char		code[12];  	//	����
	char		name[32];	//	����
	float		fLastClosePrice;	// ����
	float		fThisOpenPrice;		// ��
	float		fHighPrice;			// ���
	float		fLowPrice;			// ���
	float		fNewPrice;			// ����
	float		fTotalLots;			// ����
	float		fTotalAmonut;		// �ܶ�
	float		fBuyPrice1;			// ��һ��
	float		fBuyPrice2;			// �����
	float		fBuyPrice3;
	float		fBuyVol1;			// ��һ��
	float		fBuyVol2;
	float		fBuyVol3;

	float		fSellPrice1;		// ��һ��
	float		fSellPrice2;		// ������
	float		fSellPrice3;
	float		fSellVol1;			// ��һ��
	float		fSellVol2;
	float		fSellVol3;

	float		fBuyPrice4;			// ���ļ�
	float		fBuyVol4;
	float		fSellPrice4;		// ���ļ�
	float		fSellVol4;

	float		fBuyPrice5;			// �����
	float		fBuyVol5;
	float		fSellPrice5;		// �����
	float		fSellVol5;

	float		fUnknown;
	float		fTotalBuyLots;		// ������
	float		fTopPrice;			// ��ͣ
	float		fBottomPrice;		// ��ͣ
	float		fTotalPositions;	// �ֲܳ�
	float		fUnknow2;
	float		fUnknow3;
}QIQUAN_DATA, *LPQIQUAN_DATA;

typedef struct _QIQUAN_DATA_BLOCK_
{
	int		nDgType;	   // ��Ȩ���ݰ����ͣ�10
	UINT	nCount;
	QIQUAN_DATA buff[0];
}QIQUAN_DATA_BLOCK, *LPQIQUAN_DATA_BLOCK;

typedef struct _KLINE_DATA_
{
	int unixDt;
	float open;
	float high;
	float low;
	float close;
	float volume;
	float amount;
	unsigned unknown;
}KLINEDATA,*LPKLINEDATA;
typedef struct _KLINE_DATA_BLOCK_
{
	int		nDgType;		// k�����ݰ����ͣ�11
	UINT	nCount;
	char	strCode[16];//		��Ʊ����
	char	strName[32];//		��Ʊ����
	KLINEDATA data[0];
};
//////////////////////////////////////////////////////////////////////////
// ���εĶ���Ϊ���ο���׼��
typedef const LPQuoteL2	   LPCQuoteL2;
typedef _Datagram<QuoteL1> L1DataGram;					// ���շ�ʹ�õ��嵵�������ݸ�ʽ
typedef _Datagram<QuoteL2> L2DataGram;					// ���շ�ʹ�õ�ʮ���������ݸ�ʽ
typedef ZHUBIDATAGRAM ZhubiDataGram;					// ���շ�ʹ�õ���ʳɽ����ݸ�ʽ
typedef _ZHUBI_ORDER_DATAGRAM_ ZhubiOrderDataGram;		// ���շ�ʹ�õ����ί�����ݸ�ʽ
typedef HIGH_LVQUOTE_DATAGRAM HightLvQuoteDataGram;		// ���շ�ʹ�õĸ��嵵�̿�����
typedef QIQUAN_DATA_BLOCK QiQuanDataGram;				// ���շ�ʹ�õ���Ȩ���ݸ�ʽ
typedef _KLINE_DATA_BLOCK_ KLINEDATABLOCK;				// ���շ�ʹ�õ�K�����ݸ�ʽ
//////////////////////////////////////////////////////////////////////////
// ���ǻ�����嵵�������ݿ�ṹ���ڲ�ʹ�ã������������漰
typedef struct FreeDataBlock
{
	short		usReserved;
	USHORT		usQuoteCount;
	QuoteL1		ql1Block[0];
}FreeDataBlock, *LPFreeDataBlock;

typedef const LPFreeDataBlock LPCFreeDataBlock;

typedef _DataPackage<MarketBoardInfo> DataPackage_MBI;  // ���շ�ʹ�õĶ��߾������ݸ�ʽ����UDP����

// ���ǻ�����嵵�������ݿ�ṹ���ڲ�ʹ�ã������������漰
typedef struct StockSignature
{
	short		usNumber;
	char		lpszCode[10];
	char		lpszName[20];
	char		chrReserved[24];
	UINT		nPrevClose;
	UINT		nTopLtd;
	UINT		nBotLtd;
}StockSig, *LPStockSig;

// ���ǻ�����嵵�������ݿ�ṹ���ڲ�ʹ�ã������������漰
typedef struct ShortStock
{
	char		cMarket[2];
	WORD		wdNumber;
	WORD		wdReserved3;
}*LPShortStock, ShortStock;

// ���ǻ�����嵵�������ݿ�ṹ���ڲ�ʹ�ã������������漰
typedef struct L2RequestParam
{
	WORD		wdRqSig;
	char		pcReserved1[5];
	DWORD		dwReserved2;
	WORD		wdStockCount;
	ShortStock sMarket[0];

	//L2RequestParam(){
	//	memset(this, 0, sizeof(L2RequestParam));
	//	
	//}

	LPVOID GetSubParam(){return &dwReserved2;}
}*LPL2RequestParam;

// ���ί�����ݽṹ
typedef struct OrderDetailBlock
{
	WORD	wdPrice;
	SHORT	buyOfSell;	//����Ϊ���̣�����Ϊ����
	int	 nNumber;
	int  nVolArray[0];
}OrderDetailBlock;

// ���ί�������ڲ��ṹ�����������漰
typedef struct OrderDetailHeader
{
	WORD wsNumber;
	WORD wdUnknown1;
	OrderDetailBlock odb;
}OrderDetailHeader;

typedef struct _FREEQUOTE_
{
	short		usNumber;
	long		dwTim32; // time
	long		lgOpen;
	long		lgHigh;
	long		lgLow;
	long		lgNew;
	long		lgAllVol;
	long		lgAllAmount;
	long		lgMarketVal;
	long		lgReserver2;
	long		lgPricesOfBid[5];
	long		lgVolumeOfBid[5];
	long		lgPricesOfAsk[5];
	long		lgVolumeOfAsk[5];
	long		lgZero[2];
	char		cMarket[2];
}*LPFREEQUOTE, FREEQUOTE;
#pragma pack(pop)