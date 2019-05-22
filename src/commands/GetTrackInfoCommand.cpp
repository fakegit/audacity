/**********************************************************************

   Audacity - A Digital Audio Editor
   Copyright 1999-2009 Audacity Team
   License: wxwidgets

   Dan Horgan
   Marty Goddard
******************************************************************//**

\file GetTrackInfoCommand.cpp
\brief Definitions for GetTrackInfoCommand and GetTrackInfoCommandType classes

\class GetTrackInfoCommand
\brief Obsolete.  GetInfo now does it.

*//*******************************************************************/

#include "../Audacity.h"
#include "GetTrackInfoCommand.h"

#include "../TrackPanel.h"
#include "../NoteTrack.h"
#include "../WaveTrack.h"
#include "../Shuttle.h"
#include "../ShuttleGui.h"
#include "CommandContext.h"

const int nTypes =3;
static const EnumValueSymbol kTypes[nTypes] =
{
   { XO("Tracks") },
   { XO("Clips") },
   { XO("Labels") },
};


GetTrackInfoCommand::GetTrackInfoCommand()
{
   mInfoType = 0;
}

bool GetTrackInfoCommand::DefineParams( ShuttleParams & S ){ 
   S.DefineEnum( mInfoType, wxT("Type"), 0, kTypes, nTypes );
   
   return true;
}

void GetTrackInfoCommand::PopulateOrExchange(ShuttleGui & S)
{
   S.AddSpace(0, 5);

   S.StartMultiColumn(2, wxALIGN_CENTER);
   {
      S.TieChoice( _("Types:"), mInfoType, LocalizedStrings( kTypes, nTypes ));
   }
   S.EndMultiColumn();
}



bool GetTrackInfoCommand::Apply(const CommandContext &context)
{
   return false;
}
