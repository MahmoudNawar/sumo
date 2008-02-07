/****************************************************************************/
/// @file    Command_SaveTLSSwitchStates.h
/// @author  Daniel Krajzewicz
/// @date    08.05.2007
/// @version $Id$
///
// Writes the switch times of a tls into a file when the tls switches
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// copyright : (C) 2001-2007
//  by DLR (http://www.dlr.de/) and ZAIK (http://www.zaik.uni-koeln.de/AFS)
/****************************************************************************/
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef Command_SaveTLSSwitchStates_h
#define Command_SaveTLSSwitchStates_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <string>
#include <map>
#include <utils/common/Command.h>
#include <microsim/traffic_lights/MSTLLogicControl.h>


// ===========================================================================
// class declarations
// ===========================================================================
class MSTrafficLightLogic;
class OutputDevice;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class Command_SaveTLSSwitchStates
 * @brief Writes the switch times of a tls into a file when the tls switches
 *
 * @todo Revalidate this - as tls are not seting the link information directly ater being switched, the computed information may be delayed
 */
class Command_SaveTLSSwitchStates : public Command
{
public:
    /** @brief Constructor
     *
     * @param[in] tlls The logic to write state of
     * @param[in] od The output device to write the state into
     */
    Command_SaveTLSSwitchStates(const MSTLLogicControl::TLSLogicVariants &logics,
                                OutputDevice &od) throw();


    /// @brief Destructor
    ~Command_SaveTLSSwitchStates() throw();


    /** @brief Executes the command
     *
     * If the state or the active program has changed, the state is built
     *  using "buildStateList" and writes it to the output device.
     *
     * Returns always 1
     *
     * @return Always 1 (will be executed in next time step)
     * @todo Here, a discrete even (on switch / program change) would be appropriate
     */
    SUMOTime execute(SUMOTime currentTime) throw(ProcessError);


private:
    /// @brief The device to write to
    OutputDevice &myOutputDevice;

    /// @brief The traffic light logic to use
    const MSTLLogicControl::TLSLogicVariants &myLogics;

    /// @brief Storage for prior state
    std::string myPreviousState;

    /// @brief Storage for prior sub-id
    std::string myPreviousSubID;


private:
    /// @brief Invalidated copy constructor.
    Command_SaveTLSSwitchStates(const Command_SaveTLSSwitchStates&);

    /// @brief Invalidated assignment operator.
    Command_SaveTLSSwitchStates& operator=(const Command_SaveTLSSwitchStates&);

};


#endif

/****************************************************************************/

