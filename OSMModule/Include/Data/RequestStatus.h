#ifndef REQUESTSTATUS_H
#define REQUESTSTATUS_H

#include <xstring>

enum RequestStatus
{
	SUCCESS,
	FAILED,
	NOTFOUND
};

static inline wstring GetRequestStatusString(RequestStatus request_status)
{
	static wstring request_statuses[] =
	{
		L"SUCCESS",
		L"FAILED",
		L"NOTFOUND"
	};

	return request_statuses[(int)request_status];
}

#endif // REQUESTSTATUS_H
