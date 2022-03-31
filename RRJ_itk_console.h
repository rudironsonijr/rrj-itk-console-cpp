#include <iostream>
#include <string>
#include <stdio.h>
#include <base_utils/Mem.h>
#include <sstream>
#include <stdlib.h>


#include <base_utils/IFail.hxx>
#include <base_utils/ScopedSmPtr.hxx>
#include <base_utils/TcResultStatus.hxx>
#include <base_utils/TcBaseTypes.hxx>
#include <base_utils/TcTagList.hxx>
#include <schmgt/TaskDependency.hxx>
#include <metaframework/BusinessObjectRegistry.hxx>
#include <metaframework/CreateInput.hxx>
#include <metaframework/RootObject.hxx>
#include <metaframework/OperationInput.hxx>

#include <fclasses/tc_string.h>

#include <tc/emh.h>
#include <tc/tc_startup.h>
#include <tc/tc_errors.h>

#include <tcinit/tcinit.h>

#include <tccore/aom.h>
#include <tccore/aom_prop.h>
#include <tccore/grm.h>
#include <tccore/tctype.h>

#include <pom/enq/enq.h>

#include <base_utils/ErrorStoreBase.hxx>
#include <schmgt/schmgt_itk.h>
#include <schmgt/schmgt_bridge_itk.h>


/*================================================================================================*/
#define TaskDependencyClassName           "TaskDependency"
#define TaskDependencyRelType             TaskDependencyClassName

#define NOT_OK                            1
/*================================================================================================*/




using namespace std;
using namespace Teamcenter;

using Teamcenter::BusinessObjectRegistry;
using Teamcenter::RootObject;
using Teamcenter::OperationInput;
using Teamcenter::TaskDependency;
using Teamcenter::CreateInput;

/*================================================================================================*/
#define ERROR_CHECK(X) (report_error( __FILE__, __LINE__, #X, (X)))
static void report_error( char *file, int line, char *function, int return_code)
{
    if (return_code != ITK_ok)
    {
		char *error_msg_string;
		EMH_ask_error_text(return_code, &error_msg_string);
		printf("ERROR: %d ERROR MSG: %s.\n", return_code, error_msg_string);
        TC_write_syslog("ERROR: %d ERROR MSG: %s.\n", return_code, error_msg_string);
		printf ("FUNCTION: %s\nFILE: %s LINE: %d\n", function, file, line);
        TC_write_syslog("FUNCTION: %s\nFILE: %s LINE: %d\n", function, file, line);
		if(error_msg_string) MEM_free(error_msg_string);
	}
}
/*================================================================================================*/



extern int ITK_user_main(
	int argc,
	char* argv[]
	);
