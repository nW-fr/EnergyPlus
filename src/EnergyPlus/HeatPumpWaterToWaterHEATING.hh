// EnergyPlus, Copyright (c) 1996-2015, The Board of Trustees of the 
// University of Illinois and The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to receipt of any
// required approvals from the U.S. Dept. of Energy). All rights reserved.
//
// If you have questions about your rights to use or distribute this software,
// please contact Berkeley Lab's Innovation & Partnerships Office at
// IPO@lbl.gov.
//
// NOTICE: This Software was developed under funding from the U.S. Department
// of Energy and the U.S. Government consequently retains certain rights. As
// such, the U.S. Government has been granted for itself and others acting on
// its behalf a paid-up, nonexclusive, irrevocable, worldwide license in the
// Software to reproduce, distribute copies to the public, prepare derivative
// works, and perform publicly and display publicly, and to permit others to
// do so.
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley
//     National Laboratory, the University of Illinois, U.S. Dept. of Energy
//     nor the names of its contributors may be used to endorse or promote
//     products derived from this software without specific prior written
//     permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in
//     stand-alone form without changes from the version obtained under this
//     License, or (ii) Licensee makes a reference solely to the software
//     portion of its product, Licensee must refer to the software as
//     "EnergyPlus version X" software, where "X" is the version number
//     Licensee obtained under this License and may not use a different name
//     for the software. Except as specifically required in this Section (4),
//     Licensee shall not use in a company name, a product name, in
//     advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+"
//     or confusingly similar designation, without Lawrence Berkeley National
//     Laboratory's prior written consent
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// You are under no obligation whatsoever to provide any bug fixes, patches,
// or upgrades to the features, functionality or performance of the source
// code ("Enhancements") to anyone; however, if you choose to make your
// Enhancements available either publicly, or directly to Lawrence Berkeley
// National Laboratory, without imposing a separate written license agreement
// for such Enhancements, then you hereby grant the following license: a
// non-exclusive, royalty-free perpetual license to install, use, modify,
// prepare derivative works, incorporate into other computer software,
// distribute, and sublicense such enhancements or derivative works thereof,
// in binary and source code form.

#ifndef HeatPumpWaterToWaterHEATING_hh_INCLUDED
#define HeatPumpWaterToWaterHEATING_hh_INCLUDED

// ObjexxFCL Headers
#include <ObjexxFCL/Array1D.hh>

// EnergyPlus Headers
#include <EnergyPlus.hh>
#include <DataGlobals.hh>

namespace EnergyPlus {

namespace HeatPumpWaterToWaterHEATING {

	// Using/Aliasing

	// Data
	// MODULE PARAMETER DEFINITIONS
	extern std::string const ModuleCompName;
	extern std::string const ModuleCompNameUC;

	// DERIVED TYPE DEFINITIONS

	// Type Description of Heat Pump

	// Output Variables Type definition

	// MODULE VARIABLE DECLARATIONS:

	extern std::string GSHPRefrigerant; // Refrigerent name and index
	extern int GSHPRefrigIndex;

	extern int NumGSHPs; // number of Gshps specified in input
	extern Real64 LoadSideWaterMassFlowRate; // Load Side mass flow rate, water side Kg/s
	extern Real64 SourceSideWaterMassFlowRate; // Source Side mass flow rate, water side Kg/s
	extern Real64 Power; // power consumption Watts Joules/sec
	extern Real64 QLoad; // heat rejection from Load Side coil Joules
	extern Real64 QSource; // cooling capacity Joules
	extern Real64 SourceSideWaterOutletTemp; // Source Side outlet temperature �C
	extern Real64 SourceSideWaterInletTemp; // Source Side outlet temperature �C
	extern Real64 LoadSideWaterOutletTemp; // Source Side outlet temperature �C
	extern Real64 LoadSideWaterInletTemp; // Source Side outlet temperature �C
	extern Array1D_bool CheckEquipName;

	// SUBROUTINE SPECIFICATIONS FOR MODULE

	// Name Public routines, optionally name Private routines within this module

	// Types

	struct GshpSpecs
	{
		// Members
		std::string Name; // user identifier
		int WWHPPlantTypeOfNum; // equipment type num
		bool Available; // need an array of logicals--load identifiers of available equipment
		bool ON; // simulate the machine at it's operating part load ratio
		Real64 COP; // Coefficient of Performance of the machine
		Real64 NomCap; // Nominal Capcity of the HeatPump
		Real64 MinPartLoadRat; // Minimum operating Part Load Ratio
		Real64 MaxPartLoadRat; // Maximum operating Part Load Ratio
		Real64 OptPartLoadRat; // Optimal operating Part Load Ratio
		Real64 LoadSideVolFlowRate; // Design Flow Rate on the Load side m3/sec
		Real64 LoadSideDesignMassFlow; // Design flow rate (kg/s)
		Real64 SourceSideVolFlowRate; // Design Flow Rate on th Source Side m3/sec
		Real64 SourceSideDesignMassFlow; // Design flow rate (kg/s)
		int SourceSideInletNodeNum; // Node number on the inlet side of the plant
		int SourceSideOutletNodeNum; // Node number on the outlet side of the plant
		int LoadSideInletNodeNum; // Node number on the inlet side of the Load Side
		int LoadSideOutletNodeNum; // Node number on the outlet side of the Load Side
		Real64 SourceSideUACoeff; // Source Side heat transfer coeff W/K
		Real64 LoadSideUACoeff; // Load Side heat transfer coeff  W/K
		Real64 CompPistonDisp; // compressor piston displacement m3
		Real64 CompClearanceFactor; // compressor clearance factor
		Real64 CompSucPressDrop; // deltap ,  compressor suction and discharge pressure drop Pascals
		Real64 SuperheatTemp; // deltatsh , super heating  �C
		Real64 PowerLosses; // constant part of electro mechanical power losses  watts Joules/sec
		Real64 LossFactor; // loss factor used ot define the electro mechanical
		// loss that is supposed to be proportional to the theoretical power
		Real64 HighPressCutoff; // Maximum Design Pressure on the Load Side Pascals
		Real64 LowPressCutoff; // Minimum Design Pressure on the Source Side Pascals
		// Added by Arun 6-27-02
		// to implement cycletime - removed 9/10/2013 LKL
		bool IsOn;
		bool MustRun;
		//loop topology variables
		int SourceLoopNum; // source side plant loop index number
		int SourceLoopSideNum; // source side plant loop side index
		int SourceBranchNum; // source side plant loop branch index
		int SourceCompNum; // source side plant loop component index
		int LoadLoopNum; // load side plant loop index number
		int LoadLoopSideNum; // load side plant loop side index
		int LoadBranchNum; // load side plant loop branch index
		int LoadCompNum; // load side plant loop component index
		int CondMassFlowIndex; // index for criteria in PullCompInterconnectTrigger

		// Default Constructor
		GshpSpecs() :
			WWHPPlantTypeOfNum( 0 ),
			Available( false ),
			ON( false ),
			COP( 0.0 ),
			NomCap( 0.0 ),
			MinPartLoadRat( 0.0 ),
			MaxPartLoadRat( 0.0 ),
			OptPartLoadRat( 0.0 ),
			LoadSideVolFlowRate( 0.0 ),
			LoadSideDesignMassFlow( 0.0 ),
			SourceSideVolFlowRate( 0.0 ),
			SourceSideDesignMassFlow( 0.0 ),
			SourceSideInletNodeNum( 0 ),
			SourceSideOutletNodeNum( 0 ),
			LoadSideInletNodeNum( 0 ),
			LoadSideOutletNodeNum( 0 ),
			SourceSideUACoeff( 0.0 ),
			LoadSideUACoeff( 0.0 ),
			CompPistonDisp( 0.0 ),
			CompClearanceFactor( 0.0 ),
			CompSucPressDrop( 0.0 ),
			SuperheatTemp( 0.0 ),
			PowerLosses( 0.0 ),
			LossFactor( 0.0 ),
			HighPressCutoff( 0.0 ),
			LowPressCutoff( 0.0 ),
			IsOn( false ),
			MustRun( false ),
			SourceLoopNum( 0 ),
			SourceLoopSideNum( 0 ),
			SourceBranchNum( 0 ),
			SourceCompNum( 0 ),
			LoadLoopNum( 0 ),
			LoadLoopSideNum( 0 ),
			LoadBranchNum( 0 ),
			LoadCompNum( 0 ),
			CondMassFlowIndex( 0 )
		{}

		// Member Constructor
		GshpSpecs(
			std::string const & Name, // user identifier
			int const WWHPPlantTypeOfNum, // equipment type num
			bool const Available, // need an array of logicals--load identifiers of available equipment
			bool const ON, // simulate the machine at it's operating part load ratio
			Real64 const COP, // Coefficient of Performance of the machine
			Real64 const NomCap, // Nominal Capcity of the HeatPump
			Real64 const MinPartLoadRat, // Minimum operating Part Load Ratio
			Real64 const MaxPartLoadRat, // Maximum operating Part Load Ratio
			Real64 const OptPartLoadRat, // Optimal operating Part Load Ratio
			Real64 const LoadSideVolFlowRate, // Design Flow Rate on the Load side m3/sec
			Real64 const LoadSideDesignMassFlow, // Design flow rate (kg/s)
			Real64 const SourceSideVolFlowRate, // Design Flow Rate on th Source Side m3/sec
			Real64 const SourceSideDesignMassFlow, // Design flow rate (kg/s)
			int const SourceSideInletNodeNum, // Node number on the inlet side of the plant
			int const SourceSideOutletNodeNum, // Node number on the outlet side of the plant
			int const LoadSideInletNodeNum, // Node number on the inlet side of the Load Side
			int const LoadSideOutletNodeNum, // Node number on the outlet side of the Load Side
			Real64 const SourceSideUACoeff, // Source Side heat transfer coeff W/K
			Real64 const LoadSideUACoeff, // Load Side heat transfer coeff  W/K
			Real64 const CompPistonDisp, // compressor piston displacement m3
			Real64 const CompClearanceFactor, // compressor clearance factor
			Real64 const CompSucPressDrop, // deltap ,  compressor suction and discharge pressure drop Pascals
			Real64 const SuperheatTemp, // deltatsh , super heating  �C
			Real64 const PowerLosses, // constant part of electro mechanical power losses  watts Joules/sec
			Real64 const LossFactor, // loss factor used ot define the electro mechanical
			Real64 const HighPressCutoff, // Maximum Design Pressure on the Load Side Pascals
			Real64 const LowPressCutoff, // Minimum Design Pressure on the Source Side Pascals
			bool const IsOn,
			bool const MustRun,
			int const SourceLoopNum, // source side plant loop index number
			int const SourceLoopSideNum, // source side plant loop side index
			int const SourceBranchNum, // source side plant loop branch index
			int const SourceCompNum, // source side plant loop component index
			int const LoadLoopNum, // load side plant loop index number
			int const LoadLoopSideNum, // load side plant loop side index
			int const LoadBranchNum, // load side plant loop branch index
			int const LoadCompNum ,// load side plant loop component index
			int const CondMassFlowIndex 
		) :
			Name( Name ),
			WWHPPlantTypeOfNum( WWHPPlantTypeOfNum ),
			Available( Available ),
			ON( ON ),
			COP( COP ),
			NomCap( NomCap ),
			MinPartLoadRat( MinPartLoadRat ),
			MaxPartLoadRat( MaxPartLoadRat ),
			OptPartLoadRat( OptPartLoadRat ),
			LoadSideVolFlowRate( LoadSideVolFlowRate ),
			LoadSideDesignMassFlow( LoadSideDesignMassFlow ),
			SourceSideVolFlowRate( SourceSideVolFlowRate ),
			SourceSideDesignMassFlow( SourceSideDesignMassFlow ),
			SourceSideInletNodeNum( SourceSideInletNodeNum ),
			SourceSideOutletNodeNum( SourceSideOutletNodeNum ),
			LoadSideInletNodeNum( LoadSideInletNodeNum ),
			LoadSideOutletNodeNum( LoadSideOutletNodeNum ),
			SourceSideUACoeff( SourceSideUACoeff ),
			LoadSideUACoeff( LoadSideUACoeff ),
			CompPistonDisp( CompPistonDisp ),
			CompClearanceFactor( CompClearanceFactor ),
			CompSucPressDrop( CompSucPressDrop ),
			SuperheatTemp( SuperheatTemp ),
			PowerLosses( PowerLosses ),
			LossFactor( LossFactor ),
			HighPressCutoff( HighPressCutoff ),
			LowPressCutoff( LowPressCutoff ),
			IsOn( IsOn ),
			MustRun( MustRun ),
			SourceLoopNum( SourceLoopNum ),
			SourceLoopSideNum( SourceLoopSideNum ),
			SourceBranchNum( SourceBranchNum ),
			SourceCompNum( SourceCompNum ),
			LoadLoopNum( LoadLoopNum ),
			LoadLoopSideNum( LoadLoopSideNum ),
			LoadBranchNum( LoadBranchNum ),
			LoadCompNum( LoadCompNum ),
			CondMassFlowIndex( CondMassFlowIndex )
		{}

	};

	struct ReportVars
	{
		// Members
		Real64 Power; // Power Consumption Watts
		Real64 Energy; // Energy Consumption Joules
		Real64 QLoad; // Load Side heat transfer rate Watts
		Real64 QLoadEnergy; // Load Side heat transfer Joules
		Real64 QSource; // Source Side heat transfer rate Watts
		Real64 QSourceEnergy; // Source Side heat transfer Joules
		Real64 LoadSideWaterInletTemp; // Load Side outlet temperature �C
		Real64 SourceSideWaterInletTemp; // Source Side outlet temperature �C
		Real64 LoadSideWaterOutletTemp; // Load Side outlet temperature �C
		Real64 SourceSideWaterOutletTemp; // Source Side outlet temperature �C
		Real64 LoadSidemdot; // Mass flow rate of the cooling water in Load Side Kg/s
		Real64 SourceSidemdot; // Mass flow rate of chilled water in Eavporator Kg/s
		int Running; // On reporting Flag

		// Default Constructor
		ReportVars() :
			Power( 0.0 ),
			Energy( 0.0 ),
			QLoad( 0.0 ),
			QLoadEnergy( 0.0 ),
			QSource( 0.0 ),
			QSourceEnergy( 0.0 ),
			LoadSideWaterInletTemp( 0.0 ),
			SourceSideWaterInletTemp( 0.0 ),
			LoadSideWaterOutletTemp( 0.0 ),
			SourceSideWaterOutletTemp( 0.0 ),
			LoadSidemdot( 0.0 ),
			SourceSidemdot( 0.0 ),
			Running( 0 )
		{}

		// Member Constructor
		ReportVars(
			Real64 const Power, // Power Consumption Watts
			Real64 const Energy, // Energy Consumption Joules
			Real64 const QLoad, // Load Side heat transfer rate Watts
			Real64 const QLoadEnergy, // Load Side heat transfer Joules
			Real64 const QSource, // Source Side heat transfer rate Watts
			Real64 const QSourceEnergy, // Source Side heat transfer Joules
			Real64 const LoadSideWaterInletTemp, // Load Side outlet temperature �C
			Real64 const SourceSideWaterInletTemp, // Source Side outlet temperature �C
			Real64 const LoadSideWaterOutletTemp, // Load Side outlet temperature �C
			Real64 const SourceSideWaterOutletTemp, // Source Side outlet temperature �C
			Real64 const LoadSidemdot, // Mass flow rate of the cooling water in Load Side Kg/s
			Real64 const SourceSidemdot, // Mass flow rate of chilled water in Eavporator Kg/s
			int const Running // On reporting Flag
		) :
			Power( Power ),
			Energy( Energy ),
			QLoad( QLoad ),
			QLoadEnergy( QLoadEnergy ),
			QSource( QSource ),
			QSourceEnergy( QSourceEnergy ),
			LoadSideWaterInletTemp( LoadSideWaterInletTemp ),
			SourceSideWaterInletTemp( SourceSideWaterInletTemp ),
			LoadSideWaterOutletTemp( LoadSideWaterOutletTemp ),
			SourceSideWaterOutletTemp( SourceSideWaterOutletTemp ),
			LoadSidemdot( LoadSidemdot ),
			SourceSidemdot( SourceSidemdot ),
			Running( Running )
		{}

	};

	// Object Data
	extern Array1D< GshpSpecs > GSHP; // dimension to number of machines
	extern Array1D< ReportVars > GSHPReport;

	// Functions

	void
	SimHPWatertoWaterHEATING(
		std::string const & GSHPType, // type ofGSHP
		std::string const & GSHPName, // user specified name ofGSHP
		int & CompIndex,
		bool const FirstHVACIteration,
		bool & InitLoopEquip, // If not zero, calculate the max load for operating conditions
		Real64 & MyLoad, // loop demand component will meet
		Real64 & MaxCap, // W - maximum operating capacity of GSHP
		Real64 & MinCap, // W - minimum operating capacity of GSHP
		Real64 & OptCap, // W - optimal operating capacity of GSHP
		int const LoopNum
	);

	void
	GetGshpInput();

	void
	InitGshp( int const GSHPNum ); // GSHP number

	void
	CalcGshpModel(
		std::string const & GSHPType, // type ofGSHP
		std::string const & GSHPName, // user specified name ofGSHP
		int const GSHPNum, // GSHP Number
		Real64 & MyLoad, // Operating Load
		bool const FirstHVACIteration
	);

	void
	UpdateGSHPRecords( int const GSHPNum ); // GSHP number

} // HeatPumpWaterToWaterHEATING

} // EnergyPlus

#endif
