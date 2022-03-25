
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

int getSchedule(
	std::string object_name,
	tag_t * schedule_tag
	);

int getScheduleTask(
	std::string object_name,
	tag_t* schedule_task_tag
	);

int criarDependencia(
	tag_t sucessora, 
	tag_t predecessora, 
	int depType, 
	long lagTime, 
	tag_t *taskDep
	);

int criarDependencia2(
	tag_t sucessora, 
	tag_t predecessora, 
	int depType, 
	long lagTime, 
	tag_t *taskDep
	);

int criarDependencia3(
	// tag_t schedule_tag,
	tag_t sucessora_task_tag, 
	tag_t predecessora_task_tag, 
	int depType, 
	long lagTime, 
	tag_t *taskDep
	);