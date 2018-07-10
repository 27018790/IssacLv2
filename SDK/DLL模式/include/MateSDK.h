#pragma once

#ifndef IMPORT_MATESDK
#define MATESDK_STYLE __declspec(dllexport)
#else
#define MATESDK_STYLE __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C"
{
#endif

	//************************************
	// Method:    ConnectServer
	// FullName:  ConnectServer
	// Access:    public 
	// Returns:   MATESDK_STYLE int
	// Qualifier: ����һ��ZMQ ���������ṩ�����ִ����ɣ��磺tcp://127.0.0.1:19908
	// Parameter: const char * pstrZMQServerAddress
	//************************************
	MATESDK_STYLE int ConnectServer(const char* pstrZMQServerAddress);
	//************************************
	// Method:    Subscribe
	// FullName:  Subscribe
	// Access:    public 
	// Returns:   MATESDK_STYLE int
	// Qualifier: ����ĳ���������ݣ���ZBCJ,WDPK...
	// ���ַ���("")��ʾ����������������
	// Parameter: const char * pstrChannel
	//************************************
	MATESDK_STYLE int Subscribe(const char* pstrChannel);
	//************************************
	// Method:    GetData
	// FullName:  GetData
	// Access:    public 
	// Returns:   MATESDK_STYLE int�� 0��ʾ�ɹ�����0�Ǵ����룬��ʾʧ�ܣ������µ���ConnectServer.
	// Qualifier: ����һ������ѭ���е��ã����ϵؽ������飬buffer��������һ��JSON��
	// Parameter: char * buffer
	// Parameter: size_t szBuffLen
	//************************************
	MATESDK_STYLE int GetData(char* buffer, size_t szBuffLen);

	//************************************
	// Method:    Disconnect
	// FullName:  Disconnect
	// Access:    public 
	// Returns:   MATESDK_STYLE int
	// Qualifier: �Ͽ���ZMQ SERVER������
	// Parameter: const char * pstrZMQServerAddress��zmq�����ַ���
	//************************************
	MATESDK_STYLE int Disconnect(const char* pstrZMQServerAddress);

	//************************************
	// Method:    GetErrString_ZMQ
	// FullName:  GetErrString_ZMQ
	// Access:    public 
	// Returns:   MATESDK_STYLE void
	// Qualifier: ��ȡZMQ��������
	// Parameter: char * buff
	// Parameter: size_t szBuff
	//************************************
	MATESDK_STYLE void GetErrString_ZMQ(char* buff, size_t szBuff);

	//************************************
	// Method:    GetZMQErrNo_ZMQ
	// FullName:  GetZMQErrNo_ZMQ
	// Access:    public 
	// Returns:   MATESDK_STYLE int
	// Qualifier: ��ȡZMQ������
	//************************************
	MATESDK_STYLE int GetZMQErrNo_ZMQ();

#ifdef __cplusplus
}
#endif