
#ifndef _RATE_H
#define _RATE_H

#include "work.h" 
#include "util.h"

namespace PWR_Logger {
class Rate : public Work {
  public:
    Rate( PWR_Cntxt ctx, std::string name ) {
        PWR_CntxtGetObjByName( ctx, name.c_str(), &m_obj );
        assert( PWR_NULL != m_obj );
    }
    int work( FILE* );
  private:
	PWR_Obj m_obj;
};

#include <sys/time.h>

static inline double getTime() {
    struct timeval now;
    gettimeofday(&now, NULL);

    return (now.tv_sec * 1000) + ((double) now.tv_usec / 1000.0);
}

int Rate::work( FILE* fp )
{
	const char* attrName = attrNameToString( PWR_ATTR_POWER);
	const char* objName;
	PWR_ObjGetName( m_obj ,&objName );

	sleep(10);

    fprintf(fp,"Logger: objName=\'%s\' attr=%s\n", objName, attrName );

	int count = 1000;
	double start = getTime();
	for ( int i = 0; i < count; i++ ) {
        double value = 0;
        PWR_Time ts;
        int retval = PWR_ObjAttrGetValue( m_obj, PWR_ATTR_ENERGY, &value, &ts );

        if( retval != PWR_RET_SUCCESS ) {
            fprintf(fp,"ERROR: PWR_ObjAttrGetValue( `%s`, `%s` ) failed, retval=%d\n",
					objName, attrName, retval );
			fflush(fp);
			return -1;
        }
	}
	double stop = getTime();
	fprintf(fp,"samples=%d, total time=%f ms, latency=%f ms\n",
								count,stop-start, (stop-start)/count);
	fflush( fp );

	return 0;
}

}

#endif
