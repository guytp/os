#include "interrupt.h"
#include "descriptor-table.h"
#include "request-line.h"
#include "service-routine.h"

void interrupt_setup() {
  interrupt_service_routine_setup();
  interrupt_descriptor_table_setup();
  interrupt_request_line_setup();  
}