/* 
 * This file is part of OSMM module and implemention of PriorKnowledgeProvider submodule.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is submodule for provide lanes of road detail property.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 */
#include "PriorKnowledgeProvider.h"

int PriorKnowledgeProvider::GetWayWidth(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return 20;
	}
	else if (country == L"Austria")
	{
		return 20;
	}
	else if (country == L"Belarus")
	{
		return 20;
	}
	else if (country == L"Belgium")
	{
		return 20;
	}
	else if (country == L"Brazil")
	{
		return 20;
	}
	else if (country == L"Croatia")
	{
		return 20;
	}
	else if (country == L"Czechia")
	{
		return 20;
	}
	else if (country == L"Denmark")
	{
		return 20;
	}
	else if (country == L"Dominican Republic")
	{
		return 20;
	}
	else if (country == L"France")
	{
		return 20;
	}
	else if (country == L"Georgia")
	{
		return 20;
	}
	else if (country == L"Germany")
	{
		return 20;
	}
	else if (country == L"Greece")
	{
		return 20;
	}
	else if (country == L"Hungary")
	{
		return 20;
	}
	else if (country == L"Indonesia")
	{
		return 20;
	}
	else if (country == L"Iran")
	{
		return 20;
	}
	else if (country == L"Israel")
	{
		return 20;
	}
	else if (country == L"Italy")
	{
		return 20;
	}
	else if (country == L"Japan")
	{
		return 20;
	}
	else if (country == L"Korea")
	{
		return 20;
	}
	else if (country == L"Malaysia")
	{
		return 20;
	}
	else if (country == L"Netherlands")
	{
		return 20;
	}
	else if (country == L"New Zealand")
	{
		return 20;
	}
	else if (country == L"Norway")
	{
		return 20;
	}
	else if (country == L"Philippines")
	{
		return 20;
	}
	else if (country == L"Poland")
	{
		return 20;
	}
	else if (country == L"Portugal")
	{
		return 20;
	}
	else if (country == L"Romania")
	{
		return 20;
	}
	else if (country == L"Russia")
	{
		return 20;
	}
	else if (country == L"Spain")
	{
		return 20;
	}
	else if (country == L"Sweden")
	{
		return 20;
	}
	else if (country == L"Switzerland")
	{
		return 20;
	}
	else if (country == L"Turkey")
	{
		return 20;
	}
	else if (country == L"United Kingdom")
	{
		return 20;
	}
	else if (country == L"United States")
	{
		return 20;
	}
	else
	{
		return 20;
	}
}

int PriorKnowledgeProvider::GetMaxSpeed(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return 100;
	}
	else if (country == L"Austria")
	{
		return 100;
	}
	else if (country == L"Belarus")
	{
		return 100;
	}
	else if (country == L"Belgium")
	{
		return 100;
	}
	else if (country == L"Brazil")
	{
		return 100;
	}
	else if (country == L"Croatia")
	{
		return 100;
	}
	else if (country == L"Czechia")
	{
		return 100;
	}
	else if (country == L"Denmark")
	{
		return 100;
	}
	else if (country == L"Dominican Republic")
	{
		return 100;
	}
	else if (country == L"France")
	{
		return 100;
	}
	else if (country == L"Georgia")
	{
		return 100;
	}
	else if (country == L"Germany")
	{
		return 100;
	}
	else if (country == L"Greece")
	{
		return 100;
	}
	else if (country == L"Hungary")
	{
		return 100;
	}
	else if (country == L"Indonesia")
	{
		return 100;
	}
	else if (country == L"Iran")
	{
		return 100;
	}
	else if (country == L"Israel")
	{
		return 100;
	}
	else if (country == L"Italy")
	{
		return 100;
	}
	else if (country == L"Japan")
	{
		return 100;
	}
	else if (country == L"Korea")
	{
		return 100;
	}
	else if (country == L"Malaysia")
	{
		return 100;
	}
	else if (country == L"Netherlands")
	{
		return 100;
	}
	else if (country == L"New Zealand")
	{
		return 100;
	}
	else if (country == L"Norway")
	{
		return 100;
	}
	else if (country == L"Philippines")
	{
		return 100;
	}
	else if (country == L"Poland")
	{
		return 100;
	}
	else if (country == L"Portugal")
	{
		return 100;
	}
	else if (country == L"Romania")
	{
		return 100;
	}
	else if (country == L"Russia")
	{
		return 100;
	}
	else if (country == L"Spain")
	{
		return 100;
	}
	else if (country == L"Sweden")
	{
		return 100;
	}
	else if (country == L"Switzerland")
	{
		return 100;
	}
	else if (country == L"Turkey")
	{
		return 100;
	}
	else if (country == L"United Kingdom")
	{
		return 100;
	}
	else if (country == L"United States")
	{
		return 100;
	}
	else
	{
		return 100;
	}
}

int PriorKnowledgeProvider::GetLaneCount(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return 2;
	}
	else if (country == L"Austria")
	{
		return 2;
	}
	else if (country == L"Belarus")
	{
		return 2;
	}
	else if (country == L"Belgium")
	{
		return 2;
	}
	else if (country == L"Brazil")
	{
		return 2;
	}
	else if (country == L"Croatia")
	{
		return 2;
	}
	else if (country == L"Czechia")
	{
		return 2;
	}
	else if (country == L"Denmark")
	{
		return 2;
	}
	else if (country == L"Dominican Republic")
	{
		return 2;
	}
	else if (country == L"France")
	{
		return 2;
	}
	else if (country == L"Georgia")
	{
		return 2;
	}
	else if (country == L"Germany")
	{
		return 2;
	}
	else if (country == L"Greece")
	{
		return 2;
	}
	else if (country == L"Hungary")
	{
		return 2;
	}
	else if (country == L"Indonesia")
	{
		return 2;
	}
	else if (country == L"Iran")
	{
		return 2;
	}
	else if (country == L"Israel")
	{
		return 2;
	}
	else if (country == L"Italy")
	{
		return 2;
	}
	else if (country == L"Japan")
	{
		return 2;
	}
	else if (country == L"Korea")
	{
		return 2;
	}
	else if (country == L"Malaysia")
	{
		return 2;
	}
	else if (country == L"Netherlands")
	{
		return 2;
	}
	else if (country == L"New Zealand")
	{
		return 2;
	}
	else if (country == L"Norway")
	{
		return 2;
	}
	else if (country == L"Philippines")
	{
		return 2;
	}
	else if (country == L"Poland")
	{
		return 2;
	}
	else if (country == L"Portugal")
	{
		return 2;
	}
	else if (country == L"Romania")
	{
		return 2;
	}
	else if (country == L"Russia")
	{
		return 2;
	}
	else if (country == L"Spain")
	{
		return 2;
	}
	else if (country == L"Sweden")
	{
		return 2;
	}
	else if (country == L"Switzerland")
	{
		return 2;
	}
	else if (country == L"Turkey")
	{
		return 2;
	}
	else if (country == L"United Kingdom")
	{
		return 2;
	}
	else if (country == L"United States")
	{
		return 2;
	}
	else
	{
		return 2;
	}
}

int PriorKnowledgeProvider::GetLaneWidth(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return 6;
	}
	else if (country == L"Austria")
	{
		return 6;
	}
	else if (country == L"Belarus")
	{
		return 6;
	}
	else if (country == L"Belgium")
	{
		return 6;
	}
	else if (country == L"Brazil")
	{
		return 6;
	}
	else if (country == L"Croatia")
	{
		return 6;
	}
	else if (country == L"Czechia")
	{
		return 6;
	}
	else if (country == L"Denmark")
	{
		return 6;
	}
	else if (country == L"Dominican Republic")
	{
		return 6;
	}
	else if (country == L"France")
	{
		return 6;
	}
	else if (country == L"Georgia")
	{
		return 6;
	}
	else if (country == L"Germany")
	{
		return 6;
	}
	else if (country == L"Greece")
	{
		return 6;
	}
	else if (country == L"Hungary")
	{
		return 6;
	}
	else if (country == L"Indonesia")
	{
		return 6;
	}
	else if (country == L"Iran")
	{
		return 6;
	}
	else if (country == L"Israel")
	{
		return 6;
	}
	else if (country == L"Italy")
	{
		return 6;
	}
	else if (country == L"Japan")
	{
		return 6;
	}
	else if (country == L"Korea")
	{
		return 6;
	}
	else if (country == L"Malaysia")
	{
		return 6;
	}
	else if (country == L"Netherlands")
	{
		return 6;
	}
	else if (country == L"New Zealand")
	{
		return 6;
	}
	else if (country == L"Norway")
	{
		return 6;
	}
	else if (country == L"Philippines")
	{
		return 6;
	}
	else if (country == L"Poland")
	{
		return 6;
	}
	else if (country == L"Portugal")
	{
		return 6;
	}
	else if (country == L"Romania")
	{
		return 6;
	}
	else if (country == L"Russia")
	{
		return 6;
	}
	else if (country == L"Spain")
	{
		return 6;
	}
	else if (country == L"Sweden")
	{
		return 6;
	}
	else if (country == L"Switzerland")
	{
		return 6;
	}
	else if (country == L"Turkey")
	{
		return 6;
	}
	else if (country == L"United Kingdom")
	{
		return 6;
	}
	else if (country == L"United States")
	{
		return 6;
	}
	else
	{
		return 6;
	}
}

RoadMarking PriorKnowledgeProvider::GetLeftMarking(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return NONE;
	}
	else if (country == L"Austria")
	{
		return NONE;
	}
	else if (country == L"Belarus")
	{
		return NONE;
	}
	else if (country == L"Belgium")
	{
		return NONE;
	}
	else if (country == L"Brazil")
	{
		return NONE;
	}
	else if (country == L"Croatia")
	{
		return NONE;
	}
	else if (country == L"Czechia")
	{
		return NONE;
	}
	else if (country == L"Denmark")
	{
		return NONE;
	}
	else if (country == L"Dominican Republic")
	{
		return NONE;
	}
	else if (country == L"France")
	{
		return NONE;
	}
	else if (country == L"Georgia")
	{
		return NONE;
	}
	else if (country == L"Germany")
	{
		return NONE;
	}
	else if (country == L"Greece")
	{
		return NONE;
	}
	else if (country == L"Hungary")
	{
		return NONE;
	}
	else if (country == L"Indonesia")
	{
		return NONE;
	}
	else if (country == L"Iran")
	{
		return NONE;
	}
	else if (country == L"Israel")
	{
		return NONE;
	}
	else if (country == L"Italy")
	{
		return NONE;
	}
	else if (country == L"Japan")
	{
		return NONE;
	}
	else if (country == L"Korea")
	{
		return NONE;
	}
	else if (country == L"Malaysia")
	{
		return NONE;
	}
	else if (country == L"Netherlands")
	{
		return NONE;
	}
	else if (country == L"New Zealand")
	{
		return NONE;
	}
	else if (country == L"Norway")
	{
		return NONE;
	}
	else if (country == L"Philippines")
	{
		return NONE;
	}
	else if (country == L"Poland")
	{
		return NONE;
	}
	else if (country == L"Portugal")
	{
		return NONE;
	}
	else if (country == L"Romania")
	{
		return NONE;
	}
	else if (country == L"Russia")
	{
		return NONE;
	}
	else if (country == L"Spain")
	{
		return NONE;
	}
	else if (country == L"Sweden")
	{
		return NONE;
	}
	else if (country == L"Switzerland")
	{
		return NONE;
	}
	else if (country == L"Turkey")
	{
		return NONE;
	}
	else if (country == L"United Kingdom")
	{
		return NONE;
	}
	else if (country == L"United States")
	{
		return NONE;
	}
	else
	{
		return NONE;
	}
}

RoadMarking PriorKnowledgeProvider::GetRightMarking(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return NONE;
	}
	else if (country == L"Austria")
	{
		return NONE;
	}
	else if (country == L"Belarus")
	{
		return NONE;
	}
	else if (country == L"Belgium")
	{
		return NONE;
	}
	else if (country == L"Brazil")
	{
		return NONE;
	}
	else if (country == L"Croatia")
	{
		return NONE;
	}
	else if (country == L"Czechia")
	{
		return NONE;
	}
	else if (country == L"Denmark")
	{
		return NONE;
	}
	else if (country == L"Dominican Republic")
	{
		return NONE;
	}
	else if (country == L"France")
	{
		return NONE;
	}
	else if (country == L"Georgia")
	{
		return NONE;
	}
	else if (country == L"Germany")
	{
		return NONE;
	}
	else if (country == L"Greece")
	{
		return NONE;
	}
	else if (country == L"Hungary")
	{
		return NONE;
	}
	else if (country == L"Indonesia")
	{
		return NONE;
	}
	else if (country == L"Iran")
	{
		return NONE;
	}
	else if (country == L"Israel")
	{
		return NONE;
	}
	else if (country == L"Italy")
	{
		return NONE;
	}
	else if (country == L"Japan")
	{
		return NONE;
	}
	else if (country == L"Korea")
	{
		return NONE;
	}
	else if (country == L"Malaysia")
	{
		return NONE;
	}
	else if (country == L"Netherlands")
	{
		return NONE;
	}
	else if (country == L"New Zealand")
	{
		return NONE;
	}
	else if (country == L"Norway")
	{
		return NONE;
	}
	else if (country == L"Philippines")
	{
		return NONE;
	}
	else if (country == L"Poland")
	{
		return NONE;
	}
	else if (country == L"Portugal")
	{
		return NONE;
	}
	else if (country == L"Romania")
	{
		return NONE;
	}
	else if (country == L"Russia")
	{
		return NONE;
	}
	else if (country == L"Spain")
	{
		return NONE;
	}
	else if (country == L"Sweden")
	{
		return NONE;
	}
	else if (country == L"Switzerland")
	{
		return NONE;
	}
	else if (country == L"Turkey")
	{
		return NONE;
	}
	else if (country == L"United Kingdom")
	{
		return NONE;
	}
	else if (country == L"United States")
	{
		return NONE;
	}
	else
	{
		return NONE;
	}
}

RoadMarkingColor PriorKnowledgeProvider::GetLeftMarkingColor(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return GREEN;
	}
	else if (country == L"Austria")
	{
		return GREEN;
	}
	else if (country == L"Belarus")
	{
		return GREEN;
	}
	else if (country == L"Belgium")
	{
		return GREEN;
	}
	else if (country == L"Brazil")
	{
		return GREEN;
	}
	else if (country == L"Croatia")
	{
		return GREEN;
	}
	else if (country == L"Czechia")
	{
		return GREEN;
	}
	else if (country == L"Denmark")
	{
		return GREEN;
	}
	else if (country == L"Dominican Republic")
	{
		return GREEN;
	}
	else if (country == L"France")
	{
		return GREEN;
	}
	else if (country == L"Georgia")
	{
		return GREEN;
	}
	else if (country == L"Germany")
	{
		return GREEN;
	}
	else if (country == L"Greece")
	{
		return GREEN;
	}
	else if (country == L"Hungary")
	{
		return GREEN;
	}
	else if (country == L"Indonesia")
	{
		return GREEN;
	}
	else if (country == L"Iran")
	{
		return GREEN;
	}
	else if (country == L"Israel")
	{
		return GREEN;
	}
	else if (country == L"Italy")
	{
		return GREEN;
	}
	else if (country == L"Japan")
	{
		return GREEN;
	}
	else if (country == L"Korea")
	{
		return GREEN;
	}
	else if (country == L"Malaysia")
	{
		return GREEN;
	}
	else if (country == L"Netherlands")
	{
		return GREEN;
	}
	else if (country == L"New Zealand")
	{
		return GREEN;
	}
	else if (country == L"Norway")
	{
		return GREEN;
	}
	else if (country == L"Philippines")
	{
		return GREEN;
	}
	else if (country == L"Poland")
	{
		return GREEN;
	}
	else if (country == L"Portugal")
	{
		return GREEN;
	}
	else if (country == L"Romania")
	{
		return GREEN;
	}
	else if (country == L"Russia")
	{
		return GREEN;
	}
	else if (country == L"Spain")
	{
		return GREEN;
	}
	else if (country == L"Sweden")
	{
		return GREEN;
	}
	else if (country == L"Switzerland")
	{
		return GREEN;
	}
	else if (country == L"Turkey")
	{
		return GREEN;
	}
	else if (country == L"United Kingdom")
	{
		return GREEN;
	}
	else if (country == L"United States")
	{
		return GREEN;
	}
	else
	{
		return GREEN;
	}
}

RoadMarkingColor PriorKnowledgeProvider::GetRightMarkingColor(const wstring& country, const wstring& highway)
{
	if (country == L"Australia")
	{
		return GREEN;
	}
	else if (country == L"Austria")
	{
		return GREEN;
	}
	else if (country == L"Belarus")
	{
		return GREEN;
	}
	else if (country == L"Belgium")
	{
		return GREEN;
	}
	else if (country == L"Brazil")
	{
		return GREEN;
	}
	else if (country == L"Croatia")
	{
		return GREEN;
	}
	else if (country == L"Czechia")
	{
		return GREEN;
	}
	else if (country == L"Denmark")
	{
		return GREEN;
	}
	else if (country == L"Dominican Republic")
	{
		return GREEN;
	}
	else if (country == L"France")
	{
		return GREEN;
	}
	else if (country == L"Georgia")
	{
		return GREEN;
	}
	else if (country == L"Germany")
	{
		return GREEN;
	}
	else if (country == L"Greece")
	{
		return GREEN;
	}
	else if (country == L"Hungary")
	{
		return GREEN;
	}
	else if (country == L"Indonesia")
	{
		return GREEN;
	}
	else if (country == L"Iran")
	{
		return GREEN;
	}
	else if (country == L"Israel")
	{
		return GREEN;
	}
	else if (country == L"Italy")
	{
		return GREEN;
	}
	else if (country == L"Japan")
	{
		return GREEN;
	}
	else if (country == L"Korea")
	{
		return GREEN;
	}
	else if (country == L"Malaysia")
	{
		return GREEN;
	}
	else if (country == L"Netherlands")
	{
		return GREEN;
	}
	else if (country == L"New Zealand")
	{
		return GREEN;
	}
	else if (country == L"Norway")
	{
		return GREEN;
	}
	else if (country == L"Philippines")
	{
		return GREEN;
	}
	else if (country == L"Poland")
	{
		return GREEN;
	}
	else if (country == L"Portugal")
	{
		return GREEN;
	}
	else if (country == L"Romania")
	{
		return GREEN;
	}
	else if (country == L"Russia")
	{
		return GREEN;
	}
	else if (country == L"Spain")
	{
		return GREEN;
	}
	else if (country == L"Sweden")
	{
		return GREEN;
	}
	else if (country == L"Switzerland")
	{
		return GREEN;
	}
	else if (country == L"Turkey")
	{
		return GREEN;
	}
	else if (country == L"United Kingdom")
	{
		return GREEN;
	}
	else if (country == L"United States")
	{
		return GREEN;
	}
	else
	{
		return GREEN;
	}
}
