/*=============================================================================
                Copyright (c) 2021 Siemens PLM Software
                   Unpublished - All Rights Reserved
===============================================================================
File description:

    Filename: HelloTc.c

===============================================================================*/

#include "RLRJ_itk_console.h"


using namespace Teamcenter;
using namespace std;


extern int ITK_user_main(
	int argc, 
	char* argv[]
	)
{
	ITK_set_journalling(TRUE);
	
	printf("\nAttempting auto login to Teamcenter...\n");

	if (ITK_auto_login() != ITK_ok )
	{
		int				index = 0;
		int				n_ifails = 0;
		const int*		severities = 0;
		const int*		ifails = 0;
		const char**	texts = NULL;
		
		EMH_ask_errors( &n_ifails, &severities, &ifails, &texts);
		printf("%3d error(s) with ITK_auto_login\n", n_ifails);
		for( index=0; index<n_ifails; index++)
		{
			printf("\tError #%d, %s\n", ifails[index], texts[index]);
		}
		return ifails[0];
	}
	else
	{
		printf("\nLogin Successful.\n");
		printf("\nHello Teamcenter !!!\n");

		////////////////////////////////////
		//
		// CODE
		//
		std::string providerName ("P7mSchPropsProvider");
		int startIndex = 0;
		int maxToReturn = 100000;
		int maxToLoad = 100000;
		ResultStatus rStat;
		// Criação do SearchCriteria
		Teamcenter::OperationInput* searchCriteriaInput = Teamcenter::BusinessObjectRegistry::instance().createInputObject( "SearchCriteria", "OperationInput" );
		if( searchCriteriaInput == NULL )
		{
			throw IFail();
		}
		// Parâmetro do Critério
		std::vector< tag_t > searchCriteriaInputs;
		std::vector< int > isNullVector;
		rStat = searchCriteriaInput->setString( "name", "p7mSCHcodigo", false );
		rStat = searchCriteriaInput->setString( "value", "*", false );
		searchCriteriaInputs.push_back( searchCriteriaInput->getTag() );
		isNullVector.push_back( 0 );
		// Instância do searchOperationInput
		Teamcenter::OperationInput* searchOperationInput = Teamcenter::BusinessObjectRegistry::instance().createInputObject( providerName.c_str(), "OperationInput" );
		if( searchOperationInput == NULL )
		{
			throw IFail();
		}
		rStat = searchOperationInput->setString( "providerName", providerName.c_str(), false );
		rStat = searchOperationInput->setTagArray( "searchCriteria", searchCriteriaInputs, &isNullVector ); 
		rStat = searchOperationInput->setInt( "startIndex", startIndex, false );
		rStat = searchOperationInput->setInt( "maxToReturn", maxToReturn, false );
		rStat = searchOperationInput->setInt( "maxToLoad", maxToLoad, false );

		// Instância do searchOperationOutput
		Teamcenter::OperationInput* searchOperationOutput = Teamcenter::BusinessObjectRegistry::instance().createInputObject( providerName.c_str(), "OperationInput" );
		if( searchOperationOutput == NULL )
		{
		throw IFail();
		}

		//////////////////////
		//   PERFORM SEARCH //
		//////////////////////
		// Instância do Provider
		Fnd0BaseProvider* provider = 0;
		provider = dynamic_cast< Fnd0BaseProvider *> ( Teamcenter::BusinessObjectRegistry::instance().createBusinessObject( providerName ) ) ;
		if( provider == 0 )
		{
		throw IFail();
		}
		rStat = provider->fnd0performSearch( searchOperationInput, searchOperationOutput );
		std::vector<tag_t> searchResults;
		std::vector<int> isNullVals;
		rStat = searchOperationOutput->getTagArray( "searchResults", searchResults, isNullVals);
		bool isNull = false;
		rStat = searchOperationOutput->getInt( "totalFound", searchResponse6.totalFound, isNull);
		rStat = searchOperationOutput->getInt( "totalLoaded", searchResponse6.totalLoaded, isNull );
		rStat = searchOperationOutput->getInt( "currentFTSIndexRow", searchResponse6.cursor.endIndex, isNull );
		rStat = searchOperationOutput->getInt( "currentFTSIndexRow", searchResponse6.endIndex, isNull );


		
		
		
	}
	
	ITK_exit_module(TRUE);
	
	return ITK_ok;
}