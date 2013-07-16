//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ISTEAMREMOTESTORAGE003_H
#define ISTEAMREMOTESTORAGE003_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "RemoteStorageCommon.h"

//-----------------------------------------------------------------------------
// Purpose: Functions for accessing, reading and writing files stored remotely 
//			and cached locally
//-----------------------------------------------------------------------------
class ISteamRemoteStorage003
{
public:
	virtual bool FileWrite( const char *pchFile, const void *pvData, int32 cubData ) = 0;
	virtual int32 FileRead( const char *pchFile, void *pvData, int32 cubDataToRead ) = 0;

	virtual bool FileForget( const char *pchFile ) = 0;
	virtual bool FileDelete( const char *pchFile ) = 0;
	virtual SteamAPICall_t FileShare( const char *pchFile ) = 0;

	virtual bool FileExists( const char *pchFile ) = 0;
	virtual bool FilePersisted( const char *pchFile ) = 0;
	virtual int32 GetFileSize( const char *pchFile ) = 0;
	virtual int64 GetFileTimestamp( const char *pchFile ) = 0;

	virtual int32 GetFileCount() = 0;
	virtual const char *GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes ) = 0;

	virtual bool GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes ) = 0;

	virtual bool IsCloudEnabledForAccount() = 0;
	virtual bool IsCloudEnabledThisApp() = 0;
	virtual bool SetCloudEnabledThisApp( bool bEnable ) = 0;

	virtual unknown_ret UGCDownload( unsigned long long ) = 0;
	virtual unknown_ret GetUGCDetails( unsigned long long, unsigned int *, char **, int *, CSteamID * ) = 0;
	virtual unknown_ret UGCRead( unsigned long long, void *, int ) = 0;
	virtual int32 GetCachedUGCCount() = 0;
	virtual unknown_ret GetCachedUGCHandle( int ) = 0;
};

#endif // ISTEAMREMOTESTORAGE003_H