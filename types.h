
#ifndef PWR_TYPES_H
#define PWR_TYPES_H

#include <stddef.h>
#include <stdint.h>

#define PWR_NULL NULL

typedef struct _Cntxt* PWR_Cntxt;
typedef struct _Grp*   PWR_Grp;
typedef struct _Obj*   PWR_Obj;
typedef struct _Status* PWR_Status;

typedef int PWR_CntxtState;

#define PWR_ERR_SUCCESS 0
#define PWR_ERR_FAILURE -1
#define PWR_ERR_NOT_IMPLEMENTED -2
#define PWR_ERR_EMPTY -3
#define PWR_ERR_INVALID -4
#define PWR_ERR_LENGTH -5

typedef int64_t PWR_Time; 

typedef enum {
    PWR_CNTXT_DEFAULT,	/* Required */
    PWR_CNTXT_VENDOR    /* Optional */
} PWR_CntxtType;

typedef enum {
    PWR_ROLE_APP,   /* Application */
    PWR_ROLE_MC,    /* Monitor and Control */
    PWR_ROLE_OS,    /* Operating System */
    PWR_ROLE_USER,  /* User */
    PWR_ROLE_RM,    /* Resource Manager */
    PWR_ROLE_ADMIN, /* Administrator */
    PWR_ROLE_MGR,   /* HPCS Manager */
    PWR_ROLE_ACC    /* Accounting */
} PWR_Role;

typedef enum {
    PWR_OBJ_PLATFORM,
    PWR_OBJ_CABINET, 
    PWR_OBJ_BOARD,
    PWR_OBJ_NODE,
    PWR_OBJ_SOCKET,
    PWR_OBJ_CORE,
    /* */
    PWR_OBJ_MEM,
    PWR_OBJ_NIC,
    PWR_OBJ_INVALID
} PWR_ObjType;

typedef enum {
    PWR_ATTR_NAME = 0,	    /* Required String */
    PWR_ATTR_FREQ,	    /* Required Float  */
    PWR_ATTR_MAX_PCAP,      /* Required Float  */
    PWR_ATTR_MIN_PCAP,      /* Required Float  */
    PWR_ATTR_MAX_POWER,     /* Required Float  */
    PWR_ATTR_MIN_POWER,     /* Required Float  */
    PWR_ATTR_AVG_POWER,     /* Required Float  */
    PWR_ATTR_POWER,         /* Required Float  */
    PWR_ATTR_VOLTAGE,       /* Required Float  */
    PWR_ATTR_CURRENT,       /* Required Float  */
    PWR_ATTR_ENERGY,        /* Required Float  */
    PWR_ATTR_PSTATE,	    /* Required Int    */
    PWR_ATTR_CSTATE,	    /* Required Int    */
    PWR_ATTR_SSTATE,	    /* Required Int    */
    PWR_ATTR_NUM_ATTRS,
    PWR_ATTR_INVALID = PWR_ATTR_NUM_ATTRS,	    /*  */
} PWR_AttrType;

typedef enum {
    PWR_ATTR_DATA_FLOAT,
    PWR_ATTR_DATA_INT,
    PWR_ATTR_DATA_STRING,
    PWR_ATTR_DATA_INVALID,
} PWR_AttrDataType;

typedef struct {
    PWR_Obj      obj;
    PWR_AttrType type;
    int          error;
} PWR_AttrAccessError;

typedef enum {
    PWR_ATTR_UNITS_1,
    PWR_ATTR_UNITS_KILO,
    PWR_ATTR_UNITS_MEGA,
    PWR_ATTR_UNITS_GIGA,
    PWR_ATTR_UNITS_TERA,
    PWR_ATTR_UNITS_PETA,
    PWR_ATTR_UNITS_EXA
} PWR_AttrUnits;

typedef enum {
    PWR_REGION_SERIAL,
    PWR_REGION_PARALLEL,
    PWR_REGION_COMPUTE,
    PWR_REGION_COMMUNICATE
} PWR_Hint;

#endif
