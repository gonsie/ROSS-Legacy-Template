//The header file template for a ROSS model
//This file includes:
// - the state and message structs
// - extern'ed command line arguments
// - custom mapping function prototypes (if needed)
// - any other needed structs, enums, unions, or #defines

#ifndef _model_h
#define _model_h

#include "ross.h"

//Example enumeration of message type... could also use #defines
typedef enum {
  HELLO,
  GOODBYE,
} message_type;

//Message struct
//   this contains all data sent in an event
typedef struct {
  message_type type;
  int contents;
  tw_lpid sender;
} message;


//State struct
//   this defines the state of each LP
typedef struct {
  int local_data_1;
  int local_data_2;
} state;


//Command Line Arguments
extern int setting_1;

//Global variables used by both main and driver
// - this defines the LP types
tw_lptype model_lps[];

/* 
//Custom mapping prototypes
void model_cutom_mapping(void);
tw_lp * model_mapping_to_lp(tw_lpid lpid);
tw_peid model_map(tw_lpid gid);
*/

#endif
