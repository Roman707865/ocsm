
/*
 * This file is part of OSMM module and header of PriorKnowledgeProvider submodule.
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

#ifndef PRIORKNOWLEDGEPROVIDER_H
#define PRIORKNOWLEDGEPROVIDER_H

#include "OSMModule.h"

class PriorKnowledgeProvider
{
public:
	/* output member function*/
	OSMModuleRequestResult& Output(OSMModuleRequestResult& res);
};

#endif // PRIORKNOWLEDGEPROVIDER_H