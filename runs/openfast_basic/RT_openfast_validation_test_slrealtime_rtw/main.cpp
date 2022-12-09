/* Main generated for Simulink Real-Time model RT_openfast_validation_test */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "RT_openfast_validation_test.h"
#include "rte_RT_openfast_validation_test_parameters.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(RT_openfast_validation_test_step), slrealtime::TaskInfo::PERIODIC, 0.01, 0, 40);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo RT_openfast_validation_test_Info =
{
    "RT_openfast_validation_test",
    RT_openfast_validation_test_initialize,
    RT_openfast_validation_test_terminate,
    []()->char const*& { return RT_openfast_validation_test_M->errorStatus; },
    []()->unsigned char& { return RT_openfast_validation_test_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::getSegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, RT_openfast_validation_test_Info);
}
