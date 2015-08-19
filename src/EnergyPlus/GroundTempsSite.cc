// C++ Headers
#include <memory>

// ObjexxFCL Headers

// EnergyPlus Headers
#include <DataEnvironment.hh>
#include <InputProcessor.hh>
#include <GroundTempsManager.hh>

namespace EnergyPlus {

namespace GroundTemps {

	Real64
	ShallowGroundTemps::getGroundTemp()
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Return the ground temperature from Site:GroundTemperature:Shallow

		return surfaceGroundTemps( timeOfSimInMonths );
	}

	//******************************************************************************

	Real64
	ShallowGroundTemps::getGroundTempAtTimeInSeconds(
		Real64 const depth,
		Real64 const seconds
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in seconds

		// SUBROUTINE LOCAL VARIABLE DECLARATIONS:
		Real64 secPerMonth = 365 * 3600 * 24 / 12;
		int month;

		// Convert secs to months
		if ( seconds > 0.0 && seconds <= ( secPerMonth * 12 ) ) {
			month = ceil( seconds / ( secPerMonth * 12 ) );
		} else if ( seconds > ( secPerMonth * 12 ) ) {
			month = ceil( seconds / (secPerMonth * 12.0 ) );
			month = remainder( month, 12 );
		} else {
			ShowFatalError("Site:GroundTemperature:Shallow--Invalid time passed to ground temperature model");
		}

		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();
	}

	//******************************************************************************

	Real64
	ShallowGroundTemps::getGroundTempAtTimeInMonths(
		Real64 const depth,
		int const month
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in months

		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();

	}

	//******************************************************************************

	Real64
	BuildingSurfaceGroundTemps::getGroundTemp()
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature for Site:GroundTemperature:BuildingSurface

		return buildingSurfaceGroundTemps( timeOfSimInMonths );
	}

	//******************************************************************************

	Real64
	BuildingSurfaceGroundTemps::getGroundTempAtTimeInSeconds(
		Real64 const depth,
		Real64 const seconds
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in seconds

		// SUBROUTINE LOCAL VARIABLE DECLARATIONS:
		Real64 secPerMonth = 365 * 3600 * 24 / 12;
		int month;

		// Convert secs to months
		if ( seconds > 0.0 && seconds <= ( secPerMonth * 12 ) ) {
			month = ceil( seconds / ( secPerMonth * 12 ) );
		} else if ( seconds > ( secPerMonth * 12 ) ) {
			month = ceil( seconds / (secPerMonth * 12.0 ) );
			month = remainder( month, 12 );
		} else {
			ShowFatalError("Site:GroundTemperature:BuildingSurface--Invalid time passed to ground temperature model");
		}

		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();
	}

	//******************************************************************************

	Real64
	BuildingSurfaceGroundTemps::getGroundTempAtTimeInMonths(
		Real64 const depth,
		int const month
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in months

		// Set month
		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();
	}

	//******************************************************************************

	Real64
	FCFactorGroundTemps::getGroundTemp()
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature for Site:GroundTemperature:FCFactorMethod

		return fcFactorGroundTemps( timeOfSimInMonths );
	}

	//******************************************************************************

	Real64
	FCFactorGroundTemps::getGroundTempAtTimeInSeconds(
		Real64 const depth,
		Real64 const seconds
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in seconds

		// SUBROUTINE LOCAL VARIABLE DECLARATIONS:
		Real64 secPerMonth = 365 * 3600 * 24 / 12;
		int month;

		// Convert secs to months
		if ( seconds > 0.0 && seconds <= ( secPerMonth * 12 ) ) {
			month = ceil( seconds / ( secPerMonth * 12 ) );
		} else if ( seconds > ( secPerMonth * 12 ) ) {
			month = ceil( seconds / (secPerMonth * 12.0 ) );
			month = remainder( month, 12 );
		} else {
			ShowFatalError("Site:GroundTemperature:FCFactorMethod--Invalid time passed to ground temperature model");
		}

		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();
	}

	//******************************************************************************

	Real64
	FCFactorGroundTemps::getGroundTempAtTimeInMonths(
		Real64 const depth,
		int const month
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in months

		// Set month
		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();
	}

	//******************************************************************************

	Real64
	DeepGroundTemps::getGroundTemp()
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature for Site:GroundTemperature:Deep

		return deepGroundTemps( timeOfSimInMonths );
	}

	//******************************************************************************

	Real64
	DeepGroundTemps::getGroundTempAtTimeInSeconds(
		Real64 const depth,
		Real64 const seconds
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in seconds

		// SUBROUTINE LOCAL VARIABLE DECLARATIONS:
		Real64 secPerMonth = 365 * 3600 * 24 / 12;
		int month;

		// Convert secs to months
		if ( seconds > 0.0 && seconds <= ( secPerMonth * 12 ) ) {
			month = ceil( seconds / ( secPerMonth * 12 ) );
		} else if ( seconds > ( secPerMonth * 12 ) ) {
			month = ceil( seconds / (secPerMonth * 12.0 ) );
			month = remainder( month, 12 );
		} else {
			ShowFatalError("Site:GroundTemperature:Deep--Invalid time passed to ground temperature model");
		}

		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();
	}

	//******************************************************************************

	Real64
	DeepGroundTemps::getGroundTempAtTimeInMonths(
		Real64 const depth,
		int const month
	)
	{
		// SUBROUTINE INFORMATION:
		//       AUTHOR         Edwin Lee
		//       DATE WRITTEN   Summer 2011
		//       MODIFIED       Matt Mitchell, Summer 2015
		//       RE-ENGINEERED  na

		// PURPOSE OF THIS SUBROUTINE:
		// Returns the ground temperature when input time is in months

		// Set month
		timeOfSimInMonths = month;

		// Get and return ground temp
		return getGroundTemp();
	}

	//******************************************************************************

	//     NOTICE

	//     Copyright (c) 1996-2015 The Board of Trustees of the University of Illinois
	//     and The Regents of the University of California through Ernest Orlando Lawrence
	//     Berkeley National Laboratory.  All rights reserved.

	//     Portions of the EnergyPlus software package have been developed and copyrighted
	//     by other individuals, companies and institutions.  These portions have been
	//     incorporated into the EnergyPlus software package under license.   For a complete
	//     list of contributors, see "Notice" located in main.cc.

	//     NOTICE: The U.S. Government is granted for itself and others acting on its
	//     behalf a paid-up, nonexclusive, irrevocable, worldwide license in this data to
	//     reproduce, prepare derivative works, and perform publicly and display publicly.
	//     Beginning five (5) years after permission to assert copyright is granted,
	//     subject to two possible five year renewals, the U.S. Government is granted for
	//     itself and others acting on its behalf a paid-up, non-exclusive, irrevocable
	//     worldwide license in this data to reproduce, prepare derivative works,
	//     distribute copies to the public, perform publicly and display publicly, and to
	//     permit others to do so.

	//     TRADEMARKS: EnergyPlus is a trademark of the US Department of Energy.

}	// GroundTemps

}	// EnergyPlus
